/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															  .oooooo.                                
															 d8P'  `Y8b                               
															888           .ooooo.  oooo d8b  .ooooo.  
															888          d88' `88b `888""8P d88' `88b 
															888          888   888  888     888ooo888 
															`88b    ooo  888   888  888     888    .o 
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P' 
                                          
                                          

				This file is part of EdenCraft Engine - Core module.
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

#include "core/resource/resource_container.hpp"

#include <typeinfo>

namespace ece
{
	namespace core
	{
		namespace resource
		{

			template <class Resource, class... Args>
			void ResourceManager::loadResource(const std::string & identifier, Args&&... args)
			{
				auto extension = identifier.substr(identifier.find_last_of('.') + 1);
				if (this->_loaders.find(extension) != this->_loaders.end()) {
					this->loadResource(identifier, this->_loaders[extension]);
				}
				else {
					std::string errorMessage = "It is not possible to identify a loader for the resource "
						+ identifier
						+ ". Please, provide a loader explicitly for this resource.";
					ServiceLoggerLocator::getService().logError(errorMessage);
				}
			}

			template <class Resource>
			void ResourceManager::unloadResource(const std::string & identifier)
			{
				auto extension = identifier.substr(identifier.find_last_of('.') + 1);
				if (this->_unloaders.find(extension) != this->_unloaders.end()) {
					this->unloadResource(identifier, this->_unloaders[extension]);
				}
				else {
					std::string errorMessage = "It is not possible to identify an unloader for the resource "
						+ identifier
						+ ". Please, provide an unloader explicitly for this resource.";
					ServiceLoggerLocator::getService().logError(errorMessage);
				}
			}

			template <class Resource>
			ResourceHandler<Resource> ResourceManager::getResource(const std::string & identifier)
			{
				return static_cast<ResourceContainer<Resource>(this->_resources[std::type_index(typeid(Resource))]).getResource(identifier);
			}
		} // namespace resource
	} // namespace core
} // namespace ece