#include "TopStair.h"

TopStair::TopStair()
{
}

void TopStair::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	nx = atoi(tokens[9].c_str());
}

void TopStair::Render()
{
	RenderBoundingBox();
}

void TopStair::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}

TopStair::~TopStair()
{
}
