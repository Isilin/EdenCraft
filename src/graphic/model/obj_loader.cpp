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

#include "graphic/model/obj_loader.hpp"

#include "utility/file_system/file.hpp"
#include "utility/enum.hpp"
#include "utility/wavefront/parser_obj.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using utility::file_system::File;
			using utility::debug::FileException;
			using utility::FileCodeError;
			using utility::wavefront::ParserOBJ;

			void OBJLoader::loadFromFile(const std::string & filename)
			{
				std::ifstream file(filename, std::ios::out);
				if (!file.is_open()) {
					throw FileException(FileCodeError::BAD_PATH, filename);
				}

				ParserOBJ parser;
				parser.load(file);

				auto object = parser.getObjects()[0];
				for (auto & f : object.getFaces()) {
					Mesh::Face face;

                    int i = 0;
					for (auto & fElement : f) {
						Mesh::Vertex vertex;
						vertex._position[0] = object.getVertices()[fElement._v - 1][0];
						vertex._position[1] = object.getVertices()[fElement._v - 1][1];
						vertex._position[2] = object.getVertices()[fElement._v - 1][2];

						vertex._normal = object.getVerticesNormal()[fElement._vn - 1];
						vertex._textureCoordinate = object.getVerticesTexture()[fElement._vt - 1];
						auto index = this->_mesh.addVertex(vertex);
						//face.push_back(index);
                        face[i] = index;
                        ++i;
                        // TODO: what append if there is more than 3 vertices in the face ? (array<unsigned int, 3>)
					}

					this->_mesh.addFace(std::move(face));
				}
			}

			void OBJLoader::loadFromString(const std::string & content)
			{
				std::istringstream stream(content);
				if (!stream) {
					throw FileException(FileCodeError::PARSE_ERROR, "std::stringstream");
				}

				ParserOBJ parser;
				parser.load(stream);
			}

			void OBJLoader::loadFromMemory(const void * /*content*/)
			{
				/* NOT IMPLEMENTED YET*/
			}
		} // namespace model
	} // namespace graphic
} // namespace ece
