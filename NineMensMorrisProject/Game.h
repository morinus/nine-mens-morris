#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Text.h"

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
	int piecesPerPlayer;

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
	void ChangeGameState(GameState newGameState);
};
