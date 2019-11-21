#include"Box.h"

Box::Box()
{
}

Box::Box(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Box::SetingBox(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

bool Box::IsOverlap(Box otherBox)
{
	return !(this->x > (otherBox.x + otherBox.w) || (this->x + this->w) < otherBox.x || this->y<(otherBox.y - otherBox.h) || (this->y - this->h)>otherBox.y);
}


Box::~Box()
{
}