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
	// Variables
	int id;
	Piece* piece = nullptr;
	bool isSelected = false;

	std::vector<Point*> connectedPoints;

public:
	// Constructor
	Point(int id, sf::Vector2f position);
	virtual ~Point();

	// Accessors
	Piece* GetPiece();
	const bool IsOccupied() const;
	const bool IsSelected() const;
	const int GetId() const;

	// Functions
	void PlacePiece(Piece* piece);
	void RemovePiece();
	void EmptyPoint();
	void Deselect();
	void ConnectPoint(Point* point);
	void Reset();
	const bool IsConnectedTo(Point* point) const;
	const bool HasFreeConnectedPoints() const;
	void Update(sf::RenderWindow* window);
};

