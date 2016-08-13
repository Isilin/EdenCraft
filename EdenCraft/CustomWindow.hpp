/**
 * @file	CustomWindow.h
 *
 * @brief	Declares the custom Windows Form.
 */

#pragma once

#include "SFML\Graphics\RenderWindow.hpp"

/**
 * @class	CustomWindow
 *
 * @brief	Form for viewing the custom.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

class CustomWindow : public sf::RenderWindow
{
public:
	CustomWindow();
	~CustomWindow();

	void initialize();

private:
	sf::VideoMode modeWindow;
	std::string titleWindow;
	unsigned int style;
	sf::ContextSettings settings;
};

