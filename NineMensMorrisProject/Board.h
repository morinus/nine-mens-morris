#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Piece.h"

/*
	Class that is responsible for handling the game board.
*/

// Board setup
#define PIECES_PER_PLAYER 9

// Error messages
#define ERROR_LOADING_TEXTURE "Error loading texture!"
#define ERROR_ILLEGAL_MOVE "This cannot make this move."
#define ERROR_ILLEGAL_REMOVE "You cannot remove this piece."

class Board
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::Sprite background;

	Point points[24];
	std::vector<Piece *> pieces;

	Piece* currentlySelectedPiece = nullptr;


	// Private functions
	void InitBackground();
	void InitPoints();
	void InitPieces();

public:
	// Constructor & Destructor
	Board();
	virtual ~Board();

	// Functions
	void Render(sf::RenderWindow* window);
};