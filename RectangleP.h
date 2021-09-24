#pragma once
#include "Figure.h"
class RectangleP :
    public Figure
{
    DECLARE_SERIAL(RectangleP)
public:
    RectangleP() {}
    RectangleP(CPoint p1, CPoint p2);
};