#ifndef RENDER_WINDOW_HPP
#define RENDER_WINDOW_HPP

#include <vector>
#include <memory>

#include "window_refactor/window.hpp"
#include "common_renderer/renderer.hpp"
#include "common_renderer/base_context_opengl.hpp"

namespace ece
{
	class RenderWindow: public Window
	{
	public:
		RenderWindow();
		RenderWindow(const RenderWindow & copy) = default;
		RenderWindow(RenderWindow && move) = default;

		~RenderWindow();

		RenderWindow & operator=(const RenderWindow & copy) = default;
		RenderWindow & operator=(RenderWindow && move) = default;

		void open();
		void clear();
		void display();

	private:
		std::vector<std::shared_ptr<Renderer>> renderers;
		std::shared_ptr<BaseContextOpenGL> context;
	};
}

#endif // RENDER_WINDOW_HPP
