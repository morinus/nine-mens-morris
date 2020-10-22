#pragma once

#include <iostream>>
#include <SFML/Graphics.hpp>
#include "ErrorMessageStrings.h"
#include "Button.h"

/*
	Class for handling game pieces.
*/

enum OwnershipType
{
	PLAYERONE,
	PLAYERTWO
};

enum PieceState
{
	UNPLACED,
	PLACED
};

class Piece : public Button
{
private:
	// Variables
	float moveLerpWeight = 10.0f;

	sf::Vector2f targetPosition;
	OwnershipType pieceOwnership;
	PieceState pieceState;

	void LoadTexture();
public:
	// Constructor
	Piece(OwnershipType pieceOwnership, sf::Vector2f startingPosition);

	// Accessors
	PieceState GetPieceState();
	OwnershipType GetOwnershipType();

	// Functions
	void SetPosition(sf::Vector2f position);
	void SetPieceState(PieceState newState);
	void Render(sf::RenderWindow* window, float deltaTime);
};

