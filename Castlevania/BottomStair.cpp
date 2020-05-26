#include "BottomStair.h"

BottomStair::BottomStair(int _nx)
{
	nx = _nx;
}

void BottomStair::Render()
{
	RenderBoundingBox();
}

void BottomStair::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + 16;
	b = y + 8;
}

BottomStair::~BottomStair()
{
}
