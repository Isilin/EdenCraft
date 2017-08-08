#ifndef RENDER_QUEUE_HPP
#define RENDER_QUEUE_HPP

#include "renderable\renderable.hpp"
#include "opengl\open_gl_util.hpp"
#include "program.hpp"
#include "mathematics\matrix4u.hpp"

namespace ece
{
	class RenderQueue
	{
	public:
		RenderQueue() = default;
		RenderQueue(const RenderQueue & copy) = default;
		RenderQueue(RenderQueue && move) = default;

		~RenderQueue() = default;

		RenderQueue & operator=(const RenderQueue & copy) = default;
		RenderQueue & operator=(RenderQueue && move) = default;

		void render(const FloatMatrix4u & VP, Renderable & object);

	private:
		Program program;
	};
}

#endif // RENDER_QUEUE_HPP