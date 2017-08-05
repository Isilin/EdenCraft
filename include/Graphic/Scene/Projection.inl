//#include "glm\gtx\transform.hpp"
#include "Mathematics\Transform.hpp"

namespace ece
{
	inline Projection::Projection(): projection(FloatMatrix4u::Identity())
	{
		//this->projection = glm::perspective(20.0f, static_cast<float>(RATIO_4_3), 0.3f, 30.0f);
		this->projection = ece::perspective(20.0f, static_cast<float>(RATIO_4_3), 0.3f, 30.0f);
	}

	inline void Projection::setProjection(const double FOV, const Ratio ratio, const double nearClipping, const double farClipping)
	{
		/*this->projection = glm::perspective(static_cast<float>(FOV), 
											static_cast<float>(ratio), 
											static_cast<float>(nearClipping), 
											static_cast<float>(farClipping));*/
		this->projection = ece::perspective(static_cast<float>(FOV),
											static_cast<float>(ratio),
											static_cast<float>(nearClipping),
											static_cast<float>(farClipping));
	}

	//inline const glm::mat4 & Projection::getProjection() const { return this->projection; }

	inline const FloatMatrix4u & Projection::getProjection() const { return this->projection; }
}