/**
 * @file	Game.hpp
 *
 * @brief	Declares the game class.
 */

#pragma once

#include <memory>
#include <vector>

#include "Core\Window\BaseWindow.hpp"

/**
 * @class	Game
 *
 * @brief	A game.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

class Game
{
public:
	static std::weak_ptr<Game> getInstance();

	~Game();

	void run();

	void start();
	void stop();
	bool isRunningGame();

private:
	static std::shared_ptr<Game> instance;

	Window::BaseWindow window;
	Window::BaseWindow windowBis;
	bool isRunning;

	Game();

	void initialize();
	void update();
	void render();
	void close();
};
