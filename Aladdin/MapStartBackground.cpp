#include "MapStartBackground.h"

void MapStartBackground::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void MapStartBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

MapStartBackground::MapStartBackground()
{
	AddAnimation(9000);
}
