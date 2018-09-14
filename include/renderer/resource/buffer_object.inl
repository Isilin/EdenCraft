/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

namespace ece
{
	namespace renderer
	{
		namespace resource
		{
			using namespace opengl;

			inline BufferObject::BufferObject(const BufferType type, const Usage usage) noexcept: _type(type), _usage(usage) { this->_handle = OpenGL::genBuffers(); }

			inline void BufferObject::bind() const { OpenGL::bindBuffer(this->_type, this->_handle); }

			template<template <class...> class T, class... TT, typename enabled>
			void BufferObject::bufferData(const T<TT...> & data, const BufferObject::Method method, const int offset)
			{
				this->bind();
				OpenGL::bufferData<T, TT...>(this->_type, data, this->getBufferUsage(method), offset);
			}

			inline void BufferObject::terminate()
			{
				OpenGL::deleteBuffer(this->_handle);
				this->_handle = 0;
			}

			inline BufferUsage BufferObject::getDrawMode() const noexcept
			{
				if (this->_usage == Usage::STATIC) {
					return BufferUsage::STATIC_DRAW;
				}
				else if (this->_usage == Usage::DYNAMIC) {
					return BufferUsage::DYNAMIC_DRAW;
				}
				else {
					return BufferUsage::STREAM_DRAW;
				}
			}

			inline BufferUsage BufferObject::getReadMode() const noexcept
			{
				if (this->_usage == Usage::STATIC) {
					return BufferUsage::STATIC_READ;
				}
				else if (this->_usage == Usage::DYNAMIC) {
					return BufferUsage::DYNAMIC_READ;
				}
				else {
					return BufferUsage::STREAM_READ;
				}
			}

			inline BufferUsage BufferObject::getCopyMode() const noexcept
			{
				if (this->_usage == Usage::STATIC) {
					return BufferUsage::STATIC_COPY;
				}
				else if (this->_usage == Usage::DYNAMIC) {
					return BufferUsage::DYNAMIC_COPY;
				}
				else {
					return BufferUsage::STREAM_COPY;
				}
			}

			inline BufferUsage BufferObject::getBufferUsage(const BufferObject::Method method) const noexcept
			{
				if (method == Method::READ) {
					return this->getReadMode();
				}
				else if (method == Method::DRAW) {
					return this->getDrawMode();
				}
				else {
					return this->getCopyMode();
				}
			}
		} // namespace resource
	} // namespace renderer
} // namespace ece