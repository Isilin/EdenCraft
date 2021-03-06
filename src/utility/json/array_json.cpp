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

#include "utility/json/array_json.hpp"

#include "utility/json/object_json.hpp"

#include <algorithm>

namespace ece
{
	std::shared_ptr<NodeJSON> ArrayJSON::addNull()
	{
		this->_children.push_back(std::make_shared<NullJSON>(std::to_string(this->_children.size()), nullptr, this->shared_from_this()));
		return this->_children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addBoolean(const bool value)
	{
		this->_children.push_back(std::make_shared<BooleanJSON>(std::to_string(this->_children.size()), value, this->shared_from_this()));
		return this->_children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addInteger(const int value)
	{
		this->_children.push_back(std::make_shared<IntegerJSON>(std::to_string(this->_children.size()), value, this->shared_from_this()));
		return this->_children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addDouble(const double value)
	{
		this->_children.push_back(std::make_shared<DoubleJSON>(std::to_string(this->_children.size()), value, this->shared_from_this()));
		return this->_children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addString(const std::string & value)
	{
		this->_children.push_back(std::make_shared<StringJSON>(std::to_string(this->_children.size()), value, this->shared_from_this()));
		return this->_children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addObject()
	{
		this->_children.push_back(std::make_shared<ObjectJSON>(this->shared_from_this()));
		return this->_children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addArray()
	{
		this->_children.push_back(std::make_shared<ArrayJSON>(this->shared_from_this()));
		return this->_children.back();
	}

	void ArrayJSON::remove(const std::shared_ptr<NodeJSON>& child)
	{
		auto it = std::find_if(this->begin(), this->end(), 
				[child](const std::shared_ptr<NodeJSON> & element){ return child.get() == element.get(); });
		if (it != this->end()) {
			this->_children.erase(it);
		}
	}
}
