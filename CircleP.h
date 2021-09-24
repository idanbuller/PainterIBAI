#pragma once
#include "EllipseP.h"
class CircleP :
	public EllipseP
{
	DECLARE_SERIAL(CircleP)
public:
	CircleP() {}
	CircleP(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};
