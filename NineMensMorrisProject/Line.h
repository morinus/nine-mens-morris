#pragma once

#include "Point.h"

class Line
{
private:
	std::vector<Point*> connectedPoints;
	bool isEnabled = false;

public:
	Line();
	~Line();

	void ConnectPoint(Point* point);
	void Disable();
	const bool IsEnabled() const;
	bool IsMillCompleted();
};

