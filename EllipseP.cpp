#include "pch.h"
#include "EllipseP.h"

IMPLEMENT_SERIAL(EllipseP, CObject, 1)


EllipseP::EllipseP(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
}
void EllipseP::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}