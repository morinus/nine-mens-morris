#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/*
	Class which handles button-like behavior.
*/

class Button
{
protected:
	// Variables
	sf::Vector2f size;
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Texture buttonTexture;

	bool isPressed = false;
	bool isJustReleased = false;

public:
	// Constructor & Destructor
	Button();
	virtual ~Button();

	// Accessors
	sf::Vector2f GetPosition();

	// Functions
	void Render(sf::RenderWindow* window);
	void SetPosition(sf::Vector2f position);
	bool IsMouseOver(sf::RenderWindow* window);
	bool IsMousePressed();
};

