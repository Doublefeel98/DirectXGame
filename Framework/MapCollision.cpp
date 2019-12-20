#include "MapCollision.h"
#include "Camera.h"



MapCollision::MapCollision()
{
}

void MapCollision::Render()
{
	RenderBoundingBox();
}


void MapCollision::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}

MapCollision::MapCollision(int width, int height)
{
	this->width = width;
	this->height = height;
}


MapCollision::~MapCollision()
{
}
