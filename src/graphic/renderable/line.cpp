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
#include "graphic/renderable/line.hpp"

#include "renderer/opengl.hpp"
#include "renderer/shader.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			Line::Line() noexcept: Renderable(), _begin(), _end(), _color(), _width(1.0f), _vertices()
			{
				this->_mode = PrimitiveMode::LINES;

				auto layout = renderer::buffer::BufferLayout{};
				layout.add<float>(3, false, false, false);
				layout.add<float>(3, false, false, false);

				if (this->_width > 1.0f) {
					OpenGL::enable(Capability::LINE_SMOOTH);
				}
				else {
					OpenGL::disable(Capability::LINE_SMOOTH);
				}
				OpenGL::lineWidth(this->_width);

				this->_vertices.write({ this->_begin, this->_color, this->_end, this->_color });
				this->_vertexArray.attach(this->_vertices, layout);
			}

			Line::Line(const FloatVector3u & begin, const FloatVector3u & end, const FloatVector3u & color, const float width) noexcept : Renderable(), _begin(begin), _end(end), _color(color), _width(width), _vertices()
			{
				this->_mode = PrimitiveMode::LINES;

				auto layout = renderer::buffer::BufferLayout{};
				layout.add<float>(3, false, false, false);
				layout.add<float>(3, false, false, false);

				if (this->_width > 1.0f) {
					OpenGL::enable(Capability::LINE_SMOOTH);
				}
				else {
					OpenGL::disable(Capability::LINE_SMOOTH);
				}
				OpenGL::lineWidth(this->_width);

				this->_vertices.write({ this->_begin, this->_color, this->_end, this->_color });
				this->_vertexArray.attach(this->_vertices, layout);
			}

			void Line::draw([[maybe_unused]] std::shared_ptr<Shader> program)
			{
				this->_vertexArray.bind();
				this->_state.apply();
				if (this->isInstancingEnabled()) {
					OpenGL::drawArraysInstanced(this->_mode, 0, static_cast<ece::size_t>(this->_vertices.size() * 3), this->_numberOfInstances);
				}
				else {
					OpenGL::drawArrays(this->_mode, 0, static_cast<ece::size_t>(this->_vertices.size() * 3));
				}
			}
		} // namespace renderable
	} // namespace graphic
} // namespace ece