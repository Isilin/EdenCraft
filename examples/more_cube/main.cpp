#include "core/application/application.hpp"

#include "renderer/common/render_window.hpp"
#include "renderer/common/enhanced_shader.hpp"
#include "utility/log/service_logger.hpp"
#include "renderer/opengl/vao.hpp"
#include "renderer/common/renderer.hpp"
#include "utility/file_system/parser_bmp.hpp"

#include <iostream>

int main()
{
	try {
		ece::Application app;

		ece::RenderWindow window;

		ece::WindowSetting settings;
		settings._position = ece::IntVector2u{ 10, 10 };
		settings._title = "WGL window testing";

		window.setContextMaximumVersion(ece::Version<2>{4, 0});

		window.open();
		window.getVideoMode().setSamples(0);
		window.updateVideoMode();
		window.setSettings(settings);
		window.limitUPS(100);

		ece::Renderer renderer;
		//renderer.setPolygonMode(ece::PolygonMode::LINE);

		/*const std::vector<float> points{ 0.0f, 0.5f,
										 0.5f, -0.5f,
										-0.5f, -0.5f };

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f };
										  
		const std::vector<unsigned int> index{ 0, 1, 2 };*/

		const std::vector<float> points{ -0.5f, -0.5f,
										 -0.5f,  0.5f,
										  0.5f,  0.5f,
										  0.5f, -0.5f
		};

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f,
										  0.0f, 1.0f, 1.0f
		};

		const std::vector<float> texPos{ 1.0f, 1.0f, 
											1.0f, 0.0f,
											0.0f, 0.0f,
											0.0f, 1.0f
		};

		const std::vector<unsigned int> index{ 0, 1, 2, 2, 3, 0 };

		/*const std::vector<float> points{ -0.5f, -0.5f, 0.5,
										-0.5f,  0.5f, 0.5,
										0.5f,  0.5f, 0.5,
										0.5f, -0.5f,  0.5,
										0.0f, 0.0f, -0.5,
										0.0f,  1.0f, -0.5,
										1.0f,  1.0f, -0.5,
										1.0f, 0.0f,  -0.5,
		};

		const std::vector<float> colours{ 1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f,
										  0.0f, 1.0f, 1.0f,
										  1.0f, 0.0f, 0.0f,
										  0.0f, 1.0f, 0.0f,
										  0.0f, 0.0f, 1.0f,
										  0.0f, 1.0f, 1.0f
		};

		const std::vector<unsigned int> index{ 0, 1, 2, 
											   2, 3, 0,
											   2, 7, 3,
											   2, 6, 3,
											   4, 5, 6,
											   6, 7, 4,
											   4, 5, 0,
											   5, 1, 0,
											   1, 5, 6,
											   6, 2, 1,
											   0, 4, 7,
											   7, 3, 0
		};*/

		ece::VAO vao;
		vao.addAttribute(0, 2, false, 0, ece::BufferType::ARRAY_BUFFER, points, ece::BufferUsage::STATIC_DRAW);
		vao.addAttribute(1, 3, false, 0, ece::BufferType::ARRAY_BUFFER, colours, ece::BufferUsage::STATIC_DRAW);
		vao.addAttribute(2, 2, false, 0, ece::BufferType::ARRAY_BUFFER, texPos, ece::BufferUsage::STATIC_DRAW);
		vao.addIndices(index, ece::BufferUsage::STATIC_DRAW);

		ece::ShaderStage fsSource, vsSource;
		fsSource.loadFromFile(ece::ShaderType::FRAGMENT_SHADER, "../examples/more_cube/shader.frag");
		vsSource.loadFromFile(ece::ShaderType::VERTEX_SHADER, "../examples/more_cube/shader.vert");
		ece::EnhancedShader program;
		program.setStage(fsSource);
		program.setStage(vsSource);
		program.link();
		renderer.setProgram(program);

		ece::ParserBMP parserBMP;
		parserBMP.loadFromFile("../examples/more_cube/test.bmp");

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, parserBMP.getWidth(), parserBMP.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &parserBMP.getBuffer()[0]);
		glGenerateMipmap(GL_TEXTURE_2D);


		glUniform1i(glGetUniformLocation(program.getHandle(), "theTexture"), 0);

		ece::InputEvent event;
		while (1) {
			window.clear();

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			renderer.drawPrimitives(ece::PrimitiveMode::TRIANGLES, vao);
			if (window.pollEvent(event)) {
			}
			window.display();
		}
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return 0;
}