/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "graphic/pch.hpp"
#include "graphic/model/obj_loader.hpp"

#include "utility/file_system.hpp"
#include "utility/formats.hpp"
#include "renderer/shader.hpp"
#include "core/resource.hpp"
#include "renderer/image.hpp"
#include "graphic/material/phong_material.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using material::PhongMaterial;

			void OBJLoader::loadFromFile(const std::string & filename)
			{
				auto file = std::ifstream(filename, std::ios::in);
				if (!file.is_open()) {
					throw FileException(FileCodeError::BAD_PATH, filename);
				}

				auto parser = ParserOBJ();
				parser.load(file);
				file.close();

				this->load(filename, parser);
			}

			void OBJLoader::loadFromString(const std::string & content)
			{
				auto stream = std::istringstream(content);
				if (!stream) {
					throw FileException(FileCodeError::PARSE_ERROR, "std::stringstream");
				}

				auto parser = ParserOBJ();
				parser.load(stream);

				this->load("", parser);
			}

			void OBJLoader::loadFromStream(std::istream & stream)
			{
				auto parser = ParserOBJ();
				parser.load(stream);

				this->load("", parser);
			}

			void OBJLoader::load(const std::string & filename, ParserOBJ & parser)
			{
				this->clear();
				this->_meshes.resize(parser.getObjects().size());

				auto relativePath = filename.substr(0, filename.find_last_of('/') + 1);

				for (auto n = std::size_t{ 0 }; n < parser.getMaterials().size(); ++n) {
					auto materialFilename = relativePath + parser.getMaterials()[n];
					if (!std::filesystem::exists(materialFilename)) {
						throw FileException(FileCodeError::BAD_PATH, materialFilename);
					}
					auto materialFile = std::ifstream(materialFilename, std::ios::in);
					if (!materialFile.is_open()) {
						throw FileException(FileCodeError::BAD_PATH, materialFilename);
					}

					auto parserMaterial = ParserMTL();
					parserMaterial.load(materialFile);
					auto material = parserMaterial.getMaterials()[0];

					auto materialResource = makeResource<Material>(material.name);
					auto materialVisitor = PhongMaterial();
					materialVisitor.setMaterial(*materialResource);
					materialVisitor.initialize();

					materialVisitor.setAmbient(std::get<FloatVector3u>(material.ambient.value));
					materialVisitor.setDiffuse(std::get<FloatVector3u>(material.diffuse.value));
					materialVisitor.setSpecular(std::get<FloatVector3u>(material.specular.value));
					materialVisitor.setShininess(material.specularExponent);

					if (!material.mapDiffuse.empty()) {
						auto diffuseMap = makeResource<Texture2D>(material.mapDiffuse);
						if (diffuseMap->getData().empty()) {
							diffuseMap->loadFromFile(Texture::TypeTarget::TEXTURE_2D, relativePath + material.mapDiffuse);
						}
						diffuseMap->bind(Texture::Target::TEXTURE_2D);
						diffuseMap->generateMipmap();
						materialVisitor.setDiffuseMap(diffuseMap);
					}

					if (!material.mapSpecular.empty()) {
						auto specularMap = makeResource<Texture2D>(material.mapSpecular);
						if (specularMap->getData().empty()) {
							specularMap->loadFromFile(Texture::TypeTarget::TEXTURE_2D, relativePath + material.mapSpecular);
						}
						specularMap->bind(Texture::Target::TEXTURE_2D);
						specularMap->generateMipmap();
						materialVisitor.setSpecularMap(specularMap);
					}
				}

				for (auto n = std::size_t{ 0 }; n < parser.getObjects().size(); ++n) {
					auto & object = parser.getObjects()[n];
					this->_meshes[n] = makeResource<Mesh>(object.getName());

					auto & submeshes = this->_meshes[n]->getSubmeshes();
					submeshes.resize(object.getGroups().size());

					auto g = 0;
					for (auto & group : object.getGroups()) {
						submeshes[g].material = makeResource<Material>(group.second.material);
						for (auto & it : group.second.faces) {
							auto & f = object.getFaces()[it];
							if (object.getFaceFormat().size > 3) {
								/* Basic triangulation, working only for full convex polygons. */
								auto face = std::vector<unsigned int>(object.getFaceFormat().size);

								auto i = 0;
								for (auto & fElement : f) {
									auto vertex = Mesh::Vertex();

									if (fElement._v > 0) {
										vertex._position[0] = object.getVertices()[fElement._v - 1][0];
										vertex._position[1] = object.getVertices()[fElement._v - 1][1];
										vertex._position[2] = object.getVertices()[fElement._v - 1][2];
									}

									if (fElement._vn > 0) {
										vertex._normal = object.getVerticesNormal()[fElement._vn - 1];
									}
									if (fElement._vt > 0) {
										vertex._textureCoordinate = object.getVerticesTexture()[fElement._vt - 1];
									}

									auto index = object.getVertexIndice(fElement);
									this->_meshes[n]->insertVertex(index, std::move(vertex));

								//	auto index = this->_meshes[n]->addVertex(std::move(vertex));
									if (object.getFaceFormat().clockwise == ObjectOBJ::Clockwise::CCW) {
										face[i] = static_cast<unsigned int>(index);
									}
									else {
										face[object.getFaceFormat().size - 1 - i] = static_cast<unsigned int>(index);
									}
									++i;
								}

								for (auto j = std::size_t{ 0 }; j < object.getFaceFormat().size - 2; ++j) {
									submeshes[g].mesh.addFace({ face[0], face[j + 1], face[j + 2] });
								}
							}
							else {
								auto face = Submesh::Face{};

								auto i = 0;
								for (auto & fElement : f) {
									auto vertex = Mesh::Vertex{};

									if (fElement._v > 0) {
										vertex._position[0] = object.getVertices()[fElement._v - 1][0];
										vertex._position[1] = object.getVertices()[fElement._v - 1][1];
										vertex._position[2] = object.getVertices()[fElement._v - 1][2];
									}

									if (fElement._vn > 0) {
										vertex._normal = object.getVerticesNormal()[fElement._vn - 1];
									}
									if (fElement._vt > 0) {
										vertex._textureCoordinate = object.getVerticesTexture()[fElement._vt - 1];
									}
									auto index = object.getVertexIndice(fElement);
									this->_meshes[n]->insertVertex(index, std::move(vertex));
								//	auto index = this->_meshes[n]->addVertex(std::move(vertex));
									if (object.getFaceFormat().clockwise == ObjectOBJ::Clockwise::CCW) {
										face[i] = static_cast<unsigned int>(index);
									}
									else {
										face[object.getFaceFormat().size - 1 - i] = static_cast<unsigned int>(index);
									}
									++i;
									// TODO: what append if there is more than 3 vertices in the face ? (array<unsigned int, 3>)
								}

								submeshes[g].mesh.addFace(std::move(face));
							}
						}
						++g;
					}

					for (auto & vertex : this->_meshes[n]->getVertices()) {
						vertex._normal = vertex._normal.normalize();
					}
				}
			}

			void OBJLoader::clear()
			{
				this->_meshes.clear();
			}
		} // namespace model
	} // namespace graphic
} // namespace ece
