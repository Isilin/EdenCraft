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

#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "graphic/animation/transformation.hpp"

namespace ece
{
	/**
	 * @class Rotation
	 * @extends Transformation
	 * @brief Define a mathematic rotation.
	 */
	class Rotation: public Transformation
	{
	public:
		/**
		 * @fn Rotation() noexcept 
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		Rotation() noexcept = default;

		/**
		 * @fn Rotation(const Rotation & copy) noexcept 
		 * @param[in] copy The rotation to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Rotation(const Rotation & copy) noexcept = default;

		/**
		 * @fn Rotation(Rotation && move) noexcept 
		 * @param[in] move The rotation to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Rotation(Rotation && move) noexcept = default;

		/**
		 * @fn ~Rotation() noexcept 
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Rotation() noexcept = default;

		/**
		 * @fn Rotation & operator=(const Rotation & copy) noexcept 
		 * @param[in] coppy The rotation to copy from.
		 * @return The rotation copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Rotation & operator=(const Rotation & copy) noexcept = default;

		/**
		 * @fn Rotation & operator=(Rotation && move) noexcept 
		 * @param[in] move The rotation to move.
		 * @return The rotation moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Rotation & operator=(Rotation && move) noexcept = default;
	};
}

#endif // ROTATION_HPP