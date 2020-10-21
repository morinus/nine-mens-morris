#include "Point.h"

Point::Point()
{

}

const Piece Point::GetPiece() const
{
	return *this->piece;
}

const bool Point::HasPlacedPiece() const
{
	return this->piece != nullptr;
}

const int Point::GetId() const
{
	return this->id;
}

void Point::Init(int id, sf::Vector2f position)
{
	this->id = id;
	this->position = position;
	this->piece = nullptr;
}

void Point::PlacePiece(Piece* piece)
{
	this->piece = piece;
}

void Point::RemovePiece()
{
	this->piece = nullptr;
}
