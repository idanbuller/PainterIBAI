#pragma once
#include "Figure.h"
class EllipseP :
	public Figure
{
	DECLARE_SERIAL(EllipseP)
public:
	EllipseP() {}
	EllipseP(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};