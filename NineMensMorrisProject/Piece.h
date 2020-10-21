#pragma once

#include <iostream>>
#include <SFML/Graphics.hpp>

#define ERROR_LOADING_TEXTURE "Error loading texture!"

/*
	Class for handling game pieces.
*/

enum Ownership
{
	PlayerOne,
	PlayerTwo
};

class Piece
{
private:
	// Variables
	sf::Vector2f position;
	sf::Vector2f startingPosition;
	sf::Texture pieceTexture;
	sf::Sprite pieceSprite;
	Ownership pieceOwnership;

	void LoadTexture();
public:
	// Constructor
	Piece(Ownership pieceOwnership, sf::Vector2f startingPosition);

	// Functions
	void SetPosition(sf::Vector2f position);
	void Render(sf::RenderWindow* window);
};

