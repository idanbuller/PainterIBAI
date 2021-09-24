#include "pch.h"
#include "RectangleP.h"

IMPLEMENT_SERIAL(RectangleP, CObject, 1)

RectangleP::RectangleP(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
}
