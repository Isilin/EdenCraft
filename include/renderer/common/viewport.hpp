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

#ifndef VIEWPORT
#define VIEWPORT

#include "renderer/config.hpp"
#include "utility/mathematics/rectangle.hpp"

namespace ece
{
	namespace renderer
	{
		namespace common
		{
			using utility::mathematics::Rectangle;

			/**
			 * @class Viewport
			 * @brief
			 */
			class ECE_RENDERER_API Viewport
			{
			public:
				/**
				 * @fn constexpr Viewport() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Viewport() noexcept = default;

				/**
				 * @fn Viewport(const Viewport & copy) noexcept
				 * @param[in] copy The Viewport to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Viewport(const Viewport & copy) noexcept = default;

				/**
				 * @fn Viewport(Viewport && move) noexcept
				 * @param[in] move The Viewport to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Viewport(Viewport && move) noexcept = default;

				/**
				 * @fn ~Viewport() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Viewport() noexcept = default;

				/**
				 * @fn Viewport & operator=(const Viewport & copy) noexcept
				 * @param[in] copy The Viewport to copy from.
				 * @return The Viewport copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Viewport & operator=(const Viewport & copy) noexcept = default;

				/**
				 * @fn Viewport & operator=(Viewport && move) noexcept
				 * @param[in] move The Viewport to move.
				 * @return The Viewport moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Viewport & operator=(Viewport && move) noexcept = default;

				inline void resetViewport(const Rectangle<float> & bounds) noexcept;

				inline void setViewportRatio(const Rectangle<float> & ratio) noexcept;

				inline const Rectangle<float> & getViewport() const noexcept;

				inline const Rectangle<float> & getViewportRatio() const noexcept;

				inline bool isRatioUsed() const noexcept;

			private:
				Rectangle<float> _bounds;
				Rectangle<float> _ratio;
			};
		} // namespace common
	} // namespace renderer
} // namespace ece

#include "renderer/common/viewport.inl"

#endif // VIEWPORT