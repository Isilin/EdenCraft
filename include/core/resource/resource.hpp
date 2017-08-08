#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "type.hpp"

#include <string>

namespace ece
{
	class Resource
	{
	public:
		Resource() = default;
		Resource(const Resource & copy) = default;
		Resource(Resource && move) = default;

		inline virtual ~Resource() = 0;

		Resource & operator=(const Resource & copy) = default;
		Resource & operator=(Resource && move) = default;

		inline void setType(const ResourceType & type);
		inline void setName(const std::string & name);

		inline const ResourceType & getType() const;
		inline const std::string & getName() const;

	protected:
		ResourceType type;
		std::string name;
	};
}

#include "resource\resource.inl"

#endif // RESOURCE_HPP