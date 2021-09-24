#include "pch.h"
#include "SquareP.h"

IMPLEMENT_SERIAL(SquareP, CObject, 1)

SquareP::SquareP(CPoint p1, CPoint p2)
	:RectangleP(p1, p2)
{
}
void SquareP::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Rectangle(p1.x, p1.y, p1.x + (p2.x - p1.x), p1.y + (p2.x - p1.x));
}