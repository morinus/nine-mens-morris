#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
protected:
	sf::Vector2f size;
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Texture buttonTexture;

	bool isPressed = false;
	bool isJustReleased = false;

public:
	// Constructor & Destructor
	Button();
	~Button();

	// Accessors
	sf::Vector2f GetPosition();

	// Functions
	void Render(sf::RenderWindow* window);
	void SetPosition(sf::Vector2f position);
	bool IsMouseOver(sf::RenderWindow* window);
	bool IsMousePressed();
};

