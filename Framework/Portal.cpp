#include "Portal.h"


CPortal::CPortal(float _x, float _y, int _with, int _height, int scene_id, int position)
{
	this->scene_id = scene_id;
	x = _x;
	y = _y;
	width = _with;
	height = _height;
	this->position = position;
}

void CPortal::Render()
{
	RenderBoundingBox();
}

void CPortal::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}
