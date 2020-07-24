#include "BottomStair.h"

BottomStair::BottomStair()
{
}

void BottomStair::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	nx = atoi(tokens[9].c_str());
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
