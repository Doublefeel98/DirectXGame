#include "Pilar.h"
#include "Define.h"

Pilar::Pilar()
{
	AddAnimation(2050);		//pilar 1
	AddAnimation(2051);		//pilar 2

	AddAnimation(2052);		//pilar 3
	AddAnimation(2053);		//pilar 4
}

void Pilar::Render()
{
	if (state < 4)
	{
		animations[state]->Render(x, y);
	}
}


void Pilar::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + 0;
	b = y + 0;
	if (state == PILAR_STATE_5)
	{
		r = x + PILAR_BBOX_WIDTH_5;
		b = y + PILAR_BBOX_HEIGHT_5;
	}
}
