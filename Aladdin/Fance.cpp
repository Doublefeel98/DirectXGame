#include "Fance.h"
#include "Define.h"

Fance::Fance()
{
	AddAnimation(2070);		//fance
}

void Fance::Render()
{
	animations[0]->Render(x, y);
}

void Fance::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + FANCE_BBOX_WIDTH;
	b = y + FANCE_BBOX_HEIGHT;
}
