#include "Brick.h"
#include "Define.h"

Brick::Brick()
{
}

void Brick::Render()
{
	switch (type)
	{
	default:
		break;
	}

	RenderBoundingBox();
}

void Brick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = l + 32;
	b = t + 32;
}
