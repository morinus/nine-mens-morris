#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Button.h"

/*
	Class for handling points/intersections on the game board.
*/

class Point : public Button
{
private:
	int id;
	Piece* piece = nullptr;
	bool isSelected = false;

	std::vector<Point*> connectedPoints;

public:
	// Constructor
	Point(int id, sf::Vector2f position);

	// Accessors
	Piece* GetPiece();
	const bool IsOccupied() const;
	const bool IsSelected() const;
	const int GetId() const;

	// Functions
	void PlacePiece(Piece* piece);
	void RemovePiece();
	void Deselect();
	void ConnectPoint(Point* point);
	void Update(sf::RenderWindow* window);
};

