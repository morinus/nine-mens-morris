#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

/*
	Class that acts as the game engine.
*/

enum GameState
{
	PLACING,
	MOVING,
	REMOVING,
	ENDGAME
};

class Game
{
private:
	// Variables
	GameState currentGameState;
	Board* board;
	int currentPlayerIndex;

	// Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	// Private functions
	void InitVariables();
	void InitWindow();
	void ChangeGameState(GameState newGameState);
	void UpdatePollEvents();
	void ProcessCurrentGameState();
	void ChangeTurn();

public:
	// Construtor & Destructor
	Game();
	virtual ~Game();

	// Accessors
	const bool GetWindowIsOpen() const;

	// Functions
	void Update();
	void Render(int deltaTime);
};
