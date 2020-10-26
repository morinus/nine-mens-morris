#pragma once

#include "Point.h"

/*
	Class that is responsible for tracking and handling mills (3 of the same piece in a line).
*/

class Line
{
private:
	// Variables
	bool isEnabled = false;

public:
	// Constructor & Destructor
	Line();
	~Line();

	// Public variables
	std::vector<Point*> connectedPoints;

	// Functions
	void ConnectPoint(Point* point);
	void Disable();
	const bool IsEnabled() const;
	bool IsMillCompleted(int currentPlayerIndex);
};

