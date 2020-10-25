#pragma once

#include "Point.h"

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
	bool IsMillCompleted();
};

