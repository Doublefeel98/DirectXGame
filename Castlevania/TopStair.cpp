#include "TopStair.h"

TopStair::TopStair(int _nx)
{
	nx = _nx;
}

void TopStair::Render()
{
	RenderBoundingBox();
}

void TopStair::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + 8;
	b = y + 8;
}

TopStair::~TopStair()
{
}
