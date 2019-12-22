#include "MapEndBackground.h"

void MapEndBackground::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void MapEndBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

MapEndBackground::MapEndBackground()
{
	AddAnimation(9100);
}
