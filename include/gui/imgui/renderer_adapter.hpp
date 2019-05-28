/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.    ooooo     ooo ooooo
															 d8P'  `Y8b   `888'     `8' `888'
															888            888       8   888
															888            888       8   888
															888     ooooo  888       8   888
															`88.    .88'   `88.    .8'   888
															 `Y8bood8P'      `YbodP'    o888o


				This file is part of EdenCraft Engine - GUI module.
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

#ifndef IMGUI_RENDERER_ADAPTER_HPP
#define IMGUI_RENDERER_ADAPTER_HPP

#include "gui/pch.hpp"
#include "gui/config.hpp"
#include "renderer/shader.hpp"

struct ImDrawData;

namespace ece
{
	namespace gui
	{
		namespace imgui
		{
			/**
			 * @class RendererAdapter
			 * @brief
			 */
			class ECE_GUI_API RendererAdapter
			{
			public:
				/**
				 * @fn RendererAdapter() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				RendererAdapter() noexcept = default;

				/**
				 * @fn RendererAdapter(const RendererAdapter & copy) noexcept
				 * @param[in] copy The RendererAdapter to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				RendererAdapter(const RendererAdapter & copy) noexcept = default;

				/**
				 * @fn RendererAdapter(RendererAdapter && move) noexcept
				 * @param[in] move The RendererAdapter to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				RendererAdapter(RendererAdapter && move) noexcept = default;

				/**
				 * @fn ~RendererAdapter() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~RendererAdapter() noexcept = default;

				/**
				 * @fn RendererAdapter & operator=(const RendererAdapter & copy) noexcept
				 * @param[in] copy The RendererAdapter to copy from.
				 * @return The RendererAdapter copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				RendererAdapter & operator=(const RendererAdapter & copy) noexcept = default;

				/**
				 * @fn RendererAdapter & operator=(RendererAdapter && move) noexcept
				 * @param[in] move The RendererAdapter to move.
				 * @return The RendererAdapter moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				RendererAdapter & operator=(RendererAdapter && move) noexcept = default;

				void init();
				void newFrame();
				void shutdown();
				void render();

				void renderDrawLists(ImDrawData* draw_data);
				void setupRenderState(ImDrawData * draw_data, int fb_width, int fb_height, Handle vao);
				bool createFontsTexture();
				void destroyFontsTexture();
				bool createDeviceObjects();
				void destroyDeviceObjects();

			private:
				unsigned int _fontTexture;
				int _attribLocationTex;
				int _attribLocationProjMtx;
				int _attribLocationVtxPos;
				int _attribLocationVtxUV;
				int _attribLocationVtxColor;
				unsigned int _vbo;
				unsigned int _ibo;

				std::shared_ptr<ece::EnhancedShader> _program;
			};
		} // namespace imgui
	} // namespace gui
} // namespace ece

#endif // IMGUI_RENDERER_ADAPTER_HPP