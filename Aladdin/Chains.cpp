#include "Chains.h"

Chains::Chains()
{
}

void Chains::Render()
{
	RenderBoundingBox();
}

void Chains::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + width;
	b = y + height;
}

void Chains::Update(DWORD dt)
{

}
