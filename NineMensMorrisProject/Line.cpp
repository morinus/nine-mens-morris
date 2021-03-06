#include "Line.h"

Line::Line()
{
}


Line::~Line()
{
}

void Line::ConnectPoint(Point* point)
{
	this->connectedPoints.push_back(point);
}

void Line::Disable()
{
	this->isEnabled = false;
}

const bool Line::IsEnabled() const
{
	return this->isEnabled;
}

bool Line::IsMillCompleted(int currentPlayerIndex)
{
	for (auto point : this->connectedPoints)
	{
		if (point->GetPiece() == nullptr)
		{
			return false;
		}

		OwnershipType pieceOwnershipType = point->GetPiece()->GetOwnershipType();
		if ((OwnershipType)currentPlayerIndex != pieceOwnershipType)
		{
			return false;
		}
	}

	if (this->isEnabled)
	{
		return false;
	}

	this->isEnabled = true;

	return true;
}
