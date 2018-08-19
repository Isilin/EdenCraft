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

#ifndef STAGING_HPP
#define STAGING_HPP

#include "renderer/config.hpp"
#include "utility/mathematics/matrix4u.hpp"

namespace ece
{
	namespace renderer
	{
		namespace pipeline
		{
			using utility::mathematics::FloatMatrix4u;

			/**
			 * @class Staging
			 * @brief
			 */
			class ECE_RENDERER_API Staging
			{
			public:
				/**
				 * @fn constexpr Staging() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Staging() noexcept = default;

				/**
				 * @fn Staging(const Staging & copy) noexcept
				 * @param[in] copy The Staging to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Staging(const Staging & copy) noexcept = default;

				/**
				 * @fn Staging(Staging && move) noexcept
				 * @param[in] move The Staging to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Staging(Staging && move) noexcept = default;

				/**
				 * @fn ~Staging() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Staging() noexcept = default;

				/**
				 * @fn Staging & operator=(const Staging & copy) noexcept
				 * @param[in] copy The Staging to copy from.
				 * @return The Staging copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Staging & operator=(const Staging & copy) noexcept = default;

				/**
				 * @fn Staging & operator=(Staging && move) noexcept
				 * @param[in] move The Staging to move.
				 * @return The Staging moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Staging & operator=(Staging && move) noexcept = default;

				FloatMatrix4u _view;
				FloatMatrix4u _projection;
			};
		} // namespace pipeline
	} // namespace renderer
} // namespace ece

#endif // STAGING_HPP
