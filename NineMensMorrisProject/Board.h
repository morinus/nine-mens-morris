#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Piece.h"
#include "ErrorMessageStrings.h"
#include "Line.h"
#include "Text.h"

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

	std::vector<Point*> points;
	std::vector<Piece*> pieces;
	std::vector<Line* > lines;

	Point* currentlySelectedPoint = nullptr;
	Point* currentTargetPoint = nullptr;
	Piece* currentlySelectedPiece = nullptr;

	Text* playerOneTitleText;
	Text* playerTwoTitleText;
	Text* currentPlayerText;
	Text* currentActionText;


	// Private functions
	void InitBackground();
	void InitPoints();
	void InitLines();
	void InitPieces();
	void InitTexts();

public:
	// Constructor & Destructor
	Board();
	virtual ~Board();

	// Accessors
	Piece* GetCurrentlySelectedPiece();
	Point* GetCurrentlySelectedPoint();
	Point* GetCurrentTargetPoint();
	bool HasUnplacedPieces();

	// Functions
	void Render(sf::RenderWindow* window, int deltaTime);
	void Update(sf::RenderWindow* window);
	void DeselectEverything();
	void SetCurrentlySelectedPiece(Piece* piece);
	void SetCurrentlySelectedPoint(Point* point);
	void SetCurrentPlayerText(std::string string);
	void SetCurrentActionText(std::string string);
	void DisableAllLines();
	bool CheckIfCurrentPlayerWon(int currentPlayer);
	bool CheckIfLineIsCompletedForCurrentPlayer(int currentPlayerIndex);
	Piece* GetNextAvailablePiece(int currentPlayerIndex);
};