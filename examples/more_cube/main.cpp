/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooo        ooooo                                .oooooo.                .o8
															`88.       .888'                               d8P'  `Y8b              "888
															 888b     d'888   .ooooo.  oooo d8b  .ooooo.  888          oooo  oooo   888oooo.   .ooooo.
															 8 Y88. .P  888  d88' `88b `888""8P d88' `88b 888          `888  `888   d88' `88b d88' `88b
															 8  `888'   888  888   888  888     888ooo888 888           888   888   888   888 888ooo888
															 8    Y     888  888   888  888     888    .o `88b    ooo   888   888   888   888 888    .o
															o8o        o888o `Y8bod8P' d888b    `Y8bod8P'  `Y8bood8P'   `V88V"V8P'  `Y8bod8P' `Y8bod8P'



				This file is part of EdenCraft Engine - MoreCube sample.
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

#include "window/common/windowed_application.hpp"
#include "renderer/rendering.hpp"
#include "utility/log.hpp"
#include "graphic/scene.hpp"
#include "renderer/resource.hpp"
#include "graphic/model.hpp"
#include "graphic/renderable.hpp"
#include "utility/mathematics.hpp"
#include "core/resource.hpp"
#include "utility/time.hpp"
#include "render_system.hpp"

#include <ctime>
#include <string>

namespace ece
{
	using namespace renderer;

	using window::common::WindowedApplication;
	using window::common::WindowSetting;
	using window::event::InputEvent;
	using utility::time::FramePerSecond;
	using window::event::InputEvent;
}

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app);
ece::Object::Reference createBox(ece::Scene & scene, const std::size_t chunkSize);
void setScene(ece::Scene & scene);

int main()
{
	std::srand(static_cast<unsigned int>(time(nullptr)));

	try {
		ece::WindowedApplication app;
		auto window = createMainWindow(app);

		RenderSystem renderSystem;
		auto & scene = renderSystem.getScene();
		setScene(scene);

        auto element = createBox(scene, 100);
		element->prepare();

		auto & eventHandler = window.lock()->getEventHandler();
		eventHandler.onKeyPressed.connect([](const ece::InputEvent & event, ece::Window & window) {
			if (event._key == ece::Keyboard::Key::A) {
				std::cerr << 'A' << std::endl;
			}
			else if (event._key == ece::Keyboard::Key::ESCAPE) {
				window.close();
			}
		});
		window.lock()->onWindowClosed.connect([&app]() {
			app.stop();
		});

		ece::FramePerSecond fps(ece::FramePerSecond::FPSrate::FRAME_60);

		app.onPostUpdate.connect([&window, &fps, &element]() {
			window.lock()->setTitle("Test - Frame " + std::to_string(fps.getFPS()));
			window.lock()->clear(ece::BLACK);
			element->applyTransformation(ece::rotate(ece::FloatVector3u{ 0.0f, 1.0f, 1.0f }, 0.005f));
		});
		app.onPostRender.connect([&renderSystem, &window]() {
			renderSystem.update();
			window.lock()->display();
			window.lock()->processEvents();
		});
		
		app.run();
	}
	catch (std::runtime_error & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError(e.what());
	}

	return 0;
}

std::weak_ptr<ece::RenderWindow> createMainWindow(ece::WindowedApplication & app)
{
	auto window = app.addWindow<ece::RenderWindow>();

	ece::WindowSetting settings;
	settings._position = ece::IntVector2u{ 10, 10 };
	settings._title = "Test";

	window.lock()->setContextMaximumVersion(ece::Version<2>{4, 0});

	window.lock()->open();
	window.lock()->getVideoMode().setSamples(0);
	window.lock()->updateVideoMode();
	window.lock()->setSettings(settings);
	window.lock()->maximize();
	window.lock()->limitUPS(100);

	ece::Viewport viewport;
	viewport.resetViewport(ece::Rectangle<float>(0.0f, 0.0f, 1920.0f, 1080.0f));
	viewport.setViewportRatio(ece::Rectangle<float>(0.0f, 0.0f, 1.0f, 1.0f));
	window.lock()->setViewport(viewport);

	return std::move(window);
}

ece::Object::Reference createBox(ece::Scene & scene, const std::size_t chunkSize)
{
	auto element = scene.addObject();

	{
		ece::OBJLoader loader;
		loader.loadFromFile("../../examples/more_cube/cube.obj");
		//auto mesh = std::make_shared<ece::Mesh>(loader.getMesh());
		auto mesh = ece::makeResource<ece::Mesh>("cube_mesh", ece::makeCube(0.5f));
		element->setMesh(mesh);
	}

	{
		auto material = std::make_shared<ece::PhongMaterial>();
		material->setShininess(41.5f);

		auto box = ece::makeResource<ece::Texture2D>("box");
		box->loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/box.bmp");
		material->setDiffuseMap(box);

		auto box_specular = ece::makeResource<ece::Texture2D>("box_specular");
		box_specular->loadFromFile(ece::TextureTypeTarget::TEXTURE_2D, "../../examples/more_cube/box_specular.bmp");
		material->setSpecularMap(box_specular);
		element->setMaterial(material);
	}

	for (std::size_t i = 0; i < chunkSize; ++i) {
		for (std::size_t j = 0; j < chunkSize; ++j) {
			for (std::size_t k = 0; k < chunkSize; ++k) {
				element->addInstance(ece::translate(ece::FloatVector3u{ -50.0f + i * 1.5f, -50.0f + j * 1.5f, -50.0f + k * 1.5f }));
			}
		}
	}

	return element;
}

void setScene(ece::Scene & scene)
{
	{
		auto light = ece::makeSpotLight(1.0f, 0.8f, 1.0f, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 3.0f }, { 0.0f, 0.0f, -1.0f }, 1.0f, 0.14f, 0.07f, 10.0f, 15.0f);
		scene.addLight(light);
		//light->setColor({ std::sin(std::rand() * 2.0f), std::sin(std::rand() * 0.7f), std::sin(std::rand() * 1.3f) });
		// ####################
	}

	{
		auto & camera = scene.getCamera();
		//		camera.setOrthographic(ece::Rectangle<float>(0, 0, window.getSize()[0] * 0.5f, window.getSize()[1] * 1.0f), 0.0f, 100.0f); // TODO: using window.getViewportSize() ?
		camera.setPerspective(45, /*window.getSize()[0] / window.getSize()[1]*/1920.0f / 1080.0f, 0.1, 100.0);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });
	}
	scene.updateCamera();
}