#pragma once
#include "RectangleP.h"
class SquareP :
	public RectangleP
{
	DECLARE_SERIAL(SquareP)
public:
	SquareP() {}
	SquareP(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};

