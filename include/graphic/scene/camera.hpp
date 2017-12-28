#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "graphic/model/movable.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/matrix4u.hpp"
//#include "glm\glm.hpp"

namespace ece
{

	class Camera
	{
	public:
		inline Camera();
		Camera(const Camera & copy) = default;
		Camera(Camera && move) = default;

		~Camera() = default;

		Camera & operator=(const Camera & copy) = default;
		Camera & operator=(Camera && move) = default;

		inline void lookAt(const Movable & object);
		inline void lookAt(const FloatVertex3u & target);
		inline void lookUpTo(const FloatVector3u & direction);
		inline void moveTo(const Movable & object);
		inline void moveTo(const FloatVertex3u & position);
		inline void moveIn(const FloatVector3u & direction);

		//inline glm::mat4 getCamera() const;
		inline FloatMatrix4u getCamera() const;

	private:
		void updatePosition(const FloatVertex3u & position, const FloatVertex3u & target);

		FloatVertex3u position;
		FloatVertex3u target;
		FloatVector3u upAxis;
	};
}

#include "graphic/scene/camera.inl"

#endif // CAMERA_HPP