#pragma once

#include "Point.h"

class Line
{
private:
	bool isEnabled = false;

public:
	Line();
	~Line();

	std::vector<Point*> connectedPoints;

	void ConnectPoint(Point* point);
	void Disable();
	const bool IsEnabled() const;
	bool IsMillCompleted();
};

