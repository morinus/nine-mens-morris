#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"

/*
	Class for handling points/intersections on the game board.
*/

class Point
{
private:
	int id;
	sf::Vector2f position;

	Piece* piece = nullptr;

public:
	// Constructor
	Point();

	// Accessors
	const Piece GetPiece() const;
	const bool HasPlacedPiece() const;
	const int GetId() const;

	// Functions
	void Init(int id, sf::Vector2f position);
	void PlacePiece(Piece* piece);
	void RemovePiece();
};

