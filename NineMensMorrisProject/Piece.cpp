#include "Piece.h"

void Piece::LoadTexture()
{
	std::string textureName = this->pieceOwnership == Ownership::PlayerOne ? "white_piece.png" : "black_piece.png";

	if (!this->pieceTexture.loadFromFile("Textures/" + textureName))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	pieceSprite = sf::Sprite(this->pieceTexture);
	pieceSprite.setPosition(this->startingPosition);
}

Piece::Piece(Ownership pieceOwnership, sf::Vector2f startingPosition)
{
	this->pieceOwnership = pieceOwnership;
	this->startingPosition = startingPosition;
	this->LoadTexture();
}

void Piece::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

void Piece::Render(sf::RenderWindow* window)
{
	window->draw(this->pieceSprite);
}
