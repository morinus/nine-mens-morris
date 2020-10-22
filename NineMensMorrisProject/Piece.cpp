#include "Piece.h"

Piece::Piece(OwnershipType pieceOwnership, sf::Vector2f startingPosition)
{
	this->pieceOwnership = pieceOwnership;
	this->Button::position = startingPosition;
	this->targetPosition = startingPosition;
	this->pieceState = PieceState::UNPLACED;
	this->LoadTexture();
}

PieceState Piece::GetPieceState()
{
	return this->pieceState;
}

OwnershipType Piece::GetOwnershipType()
{
	return this->pieceOwnership;
}

void Piece::LoadTexture()
{
	std::string textureName = this->pieceOwnership == OwnershipType::PLAYERONE ? "white_piece.png" : "black_piece.png";

	if (!this->buttonTexture.loadFromFile("Textures/" + textureName))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	this->Button::rect.setTexture(&this->buttonTexture);
	this->Button::rect.setPosition(this->targetPosition);
}

void Piece::SetPosition(sf::Vector2f position)
{
	this->targetPosition = position;
}

void Piece::SetPieceState(PieceState newState)
{
	this->pieceState = newState;
}

void Piece::Render(sf::RenderWindow* window, float deltaTime)
{
	float weight = this->moveLerpWeight * (deltaTime * 0.001f);
	weight = weight > 1.0f ? 1.0f : weight;
	sf::Vector2f distance = this->targetPosition - Button::position;

	Button::position = (this->GetPosition() + distance * weight);
	Button::rect.setPosition(Button::position - sf::Vector2f(16.0f, 16.0f));

	Button::Render(window);
}
