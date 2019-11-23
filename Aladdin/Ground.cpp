#include "Ground.h"
Ground::Ground()
{
	width = GROUND_BBOX_WIDTH;
	height = GROUND_BBOX_HEIGHT;
}
void Ground::Render()
{
	//RenderBoundingBox();
}

void Ground::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + GROUND_BBOX_WIDTH;
	b = y + GROUND_BBOX_HEIGHT;
}
