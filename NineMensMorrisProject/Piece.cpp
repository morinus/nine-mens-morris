#include "Piece.h"
#include "Point.h"

Piece::Piece(OwnershipType pieceOwnership, sf::Vector2f position)
{
	this->pieceOwnership = pieceOwnership;
	this->originalPosition = position;
	this->Button::position = position;
	this->targetPosition = position;
	this->pieceState = PieceState::UNPLACED;
	this->LoadTexture();
}

PieceState Piece::GetPieceState()
{
	return this->pieceState;
}

Point* Piece::GetConnectedPoint()
{
	return this->connectedPoint;
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

void Piece::ConnectPoint(Point * point)
{
	this->connectedPoint = point;
}

void Piece::Remove()
{
	this->connectedPoint->RemovePiece();
	this->connectedPoint = nullptr;
	this->targetPosition = this->originalPosition;
	this->rect.setFillColor(sf::Color::Red);
}

void Piece::Move(Point * point)
{
	this->connectedPoint->EmptyPoint();
	this->ConnectPoint(point);
	this->SetPosition(point->GetPosition());
	point->PlacePiece(this);
}

void Piece::Reset()
{
	this->connectedPoint = nullptr;
	this->isJustReleased = false;
	this->isPressed = false;
	this->SetPosition(this->originalPosition);
	this->pieceState = PieceState::UNPLACED;
}

void Piece::Render(sf::RenderWindow* window, int deltaTime)
{
	float weight = this->moveLerpWeight * (deltaTime * 0.001f);
	weight = weight > 1.0f ? 1.0f : weight;
	sf::Vector2f distance = this->targetPosition - Button::position;

	Button::position = (this->GetPosition() + distance * weight);
	Button::rect.setPosition(Button::position - sf::Vector2f(16.0f, 16.0f));

	Button::Render(window);
}
