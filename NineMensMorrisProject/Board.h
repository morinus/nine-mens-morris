#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Piece.h"
#include "ErrorMessageStrings.h"
#include "Line.h"

/*
	Class that is responsible for handling the game board.
*/

// Board setup
#define PIECES_PER_PLAYER 9

class Board
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::Sprite background;

	std::vector<Point *> points;
	std::vector<Piece *> pieces;
	std::vector<Line* > lines;

	Point* currentlySelectedPoint = nullptr;
	Piece* currentlySelectedPiece = nullptr;


	// Private functions
	void InitBackground();
	void InitPoints();
	void InitLines();
	void InitPieces();

public:
	// Constructor & Destructor
	Board();
	virtual ~Board();

	// Accessors
	Piece* GetCurrentlySelectedPiece();
	Point* GetCurrentlySelectedPoint();
	bool HasUnplacedPieces();

	// Functions
	void Render(sf::RenderWindow* window, int deltaTime);
	void Update(sf::RenderWindow* window);
	void DeselectEverything();
	Piece* GetNextAvailablePiece(int currentPlayerIndex);
	bool CheckIfLineIsCompletedForCurrentPlayer(int currentPlayerIndex);
};