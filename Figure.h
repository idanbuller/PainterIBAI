#pragma once
#include <afx.h>
class Figure :
	public CObject
{
	DECLARE_SERIAL(Figure)

	CPoint P1;
	CPoint P2;
public:


	Figure() {}
	Figure(CPoint p1, CPoint p2) :
		P1(p1), P2(p2)
	{
	}
	void Serialize(CArchive& ar);

	virtual void Draw(CDC* dc) const
	{
		dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	}
	CPoint getP1() const
	{
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	//virtual bool isInside(const CPoint& P) const;
	//virtual void Shift(int dx, int dy);
};

