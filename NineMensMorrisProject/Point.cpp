#include "Point.h"

Point::Point(int id, sf::Vector2f position)
{
	this->id = id;
	this->piece = nullptr;
	this->Button::position = position;
	this->Button::rect.setSize(sf::Vector2f(32.0f, 32.0f));
	this->Button::rect.setPosition(position - sf::Vector2f(16.0f, 16.0f));
	this->Button::rect.setFillColor(sf::Color::Transparent);
}

Piece* Point::GetPiece()
{
	return this->piece;
}

const bool Point::IsOccupied() const
{
	return this->piece != nullptr;
}

const bool Point::IsSelected() const
{
	return this->isSelected;
}

const int Point::GetId() const
{
	return this->id;
}

void Point::PlacePiece(Piece* piece)
{
	piece->SetPieceState(PieceState::PLACED);
	this->piece = piece;
}

void Point::RemovePiece()
{
	this->piece->SetPieceState(PieceState::REMOVED);
	this->piece = nullptr;
}

void Point::EmptyPoint()
{
	this->piece = nullptr;
}

void Point::Deselect()
{
	this->isSelected = false;
}

void Point::ConnectPoint(Point* point)
{
	this->connectedPoints.push_back(point);
}

bool Point::IsConnectedTo(Point* point)
{
	for (auto connectedPoint : connectedPoints)
	{
		if (connectedPoint == point)
		{
			return true;
		}
	}

	return false;
}

bool Point::HasFreeConnectedPoints()
{
	for (auto connectedPoint : connectedPoints)
	{
		if (connectedPoint->GetPiece() == nullptr)
		{
			return true;
		}
	}

	return false;
}

void Point::Update(sf::RenderWindow* window)
{
	if (this->isJustReleased)
	{
		this->isJustReleased = false;
		this->isSelected = true;
	}

	if (this->IsMouseOver(window) && this->IsMousePressed())
	{
		this->isPressed = true;
	}

	if (this->IsMouseOver(window) && !this->IsMousePressed())
	{
		if (isPressed)
		{
			this->isJustReleased = true;
			this->isPressed = false;
		}
	}
}
