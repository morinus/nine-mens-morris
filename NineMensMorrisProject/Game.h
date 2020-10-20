#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game
{
private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	// Private functions
	void InitVariables();
	void InitWindow();

public:
	// Construtor & Destructor
	Game();
	virtual ~Game();

	// Accessors
	const bool GetWindowIsOpen() const;

	// Functions
	void UpdatePollEvents();
	void Update();
	void Render();
};
