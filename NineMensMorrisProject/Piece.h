#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ErrorMessageStrings.h"
#include "Button.h"

// Fix to avoid recursive referencing
class Point;

/*
	Class for handling game pieces.
*/

enum class OwnershipType
{
	PLAYERONE,
	PLAYERTWO
};

enum class PieceState
{
	UNPLACED,
	PLACED,
	REMOVED
};

class Piece : public Button
{
private:
	// Variables
	float moveLerpWeight = 10.0f;

	sf::Vector2f targetPosition;
	sf::Vector2f originalPosition;
	OwnershipType pieceOwnership;
	PieceState pieceState;
	Point* connectedPoint = nullptr;

	void LoadTexture();
public:
	// Constructor
	Piece(OwnershipType pieceOwnership, sf::Vector2f position);

	// Accessors
	PieceState GetPieceState();
	Point* GetConnectedPoint();
	OwnershipType GetOwnershipType();

	// Functions
	void SetPosition(sf::Vector2f position);
	void SetPieceState(PieceState newState);
	void ConnectPoint(Point* point);
	void Remove();
	void Move(Point* point);
	void Reset();
	void Render(sf::RenderWindow* window, int deltaTime);
};

