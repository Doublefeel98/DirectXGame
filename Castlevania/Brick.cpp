#include "Brick.h"
#include "Define.h"

Brick::Brick()
{
	AddAnimation(200);
	AddAnimation(201);
}

void Brick::Render()
{
	switch (type)
	{
	case OBJECT_BRICK_OUT_CASTLE:
		animations[0]->Render(x, y);
		break;
	case OBJECT_BRICK_SENCE_ONE:
		animations[0]->Render(x, y);
		break;
	default:
		break;
	}

	RenderBoundingBox();
}

void Brick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + 32;
	b = y + 32;
}
