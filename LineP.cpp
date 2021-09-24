#include "pch.h"
#include "LineP.h"

IMPLEMENT_SERIAL(LineP, CObject, 1)

LineP::LineP(CPoint p1, CPoint p2) : Figure(p1, p2)
{
}

void LineP::Draw(CDC* dc) const
{
    CPoint p1 = getP1();
    CPoint p2 = getP2();
    dc->MoveTo(p1);
    dc->LineTo(p2);
}