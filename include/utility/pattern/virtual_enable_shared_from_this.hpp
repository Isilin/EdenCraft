/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef VIRTUAL_ENABLE_SHARED_FROM_THIS_HPP
#define VIRTUAL_ENABLE_SHARED_FROM_THIS_HPP

#include "utility/config.hpp"

#include <memory>

// see: https://stackoverflow.com/questions/15549722/double-inheritance-of-enable-shared-from-this
// see: https://stackoverflow.com/questions/14939190/boost-shared-from-this-and-multiple-inheritance

namespace ece
{
	namespace utility
	{
		namespace pattern
		{
			class virtual_base_enable_shared_from_this : public std::enable_shared_from_this<virtual_base_enable_shared_from_this>
			{
			public:
				virtual ~virtual_base_enable_shared_from_this() {}
			};

			template<typename T>
			struct virtual_enable_shared_from_this : virtual virtual_base_enable_shared_from_this
			{
				using base_type = virtual_base_enable_shared_from_this;

			public:
				std::shared_ptr<T> shared_from_this()
				{
					std::shared_ptr<T> result(base_type::shared_from_this(), static_cast<T*>(this));
					return result;
				}

				std::shared_ptr<T const> shared_from_this() const
				{
					std::shared_ptr<T const> result(base_type::shared_from_this(), static_cast<T const*>(this));
					return result;
				}

				std::weak_ptr<T> weak_from_this()
				{
					std::shared_ptr<T> result(base_type::weak_from_this().lock(), static_cast<T*>(this));
					return result;
				}

				std::weak_ptr<T const> weak_from_this() const
				{
					std::shared_ptr<T const> result(base_type::weak_from_this().lock(), static_cast<T const*>(this));
					return result;
				}
			};
		} // namespace pattern
	} // namespace utility
} // namespace ece

#endif // VIRTUAL_ENABLE_SHARED_FROM_THIS_HPP