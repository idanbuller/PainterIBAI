//Develop by 
// Avichai Iluz 208626234
// Idan Buller 
//
#pragma once
#include "Figure.h"
class LineP :
    public Figure
{

    DECLARE_SERIAL(LineP)
public:
    LineP() {}
    LineP(CPoint p1, CPoint p2);
    void Draw(CDC* dc)const;
};