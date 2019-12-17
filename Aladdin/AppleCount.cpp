#include "AppleCount.h"

void AppleCount::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void AppleCount::Update(int hp)
{
	this->appleCount = appleCount;
}

void AppleCount::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

AppleCount::AppleCount(int appleCount)
{
	this->appleCount = appleCount;
	AddAnimation(2115);
}
