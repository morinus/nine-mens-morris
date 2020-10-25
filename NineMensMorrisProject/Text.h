#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ErrorMessageStrings.h"

/*
	Class for handling and rendering text objects.
*/

class Text
{
private:
	// Variables
	sf::Vector2f position;
	sf::Font font;
	sf::Text text;

public:
	// Constructor
	Text(sf::Vector2f position, sf::String text);

	// Functions
	void Init();
	void Render(sf::RenderWindow* window);
	void SetPosition(sf::Vector2f position);
	void SetText(std::string string);
	void SetColor(sf::Color color);
	void SetCharacterSize(int size);
};

