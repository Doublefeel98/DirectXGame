#include "PennyCount.h"

void PennyCount::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void PennyCount::Update(int hp)
{
	this->pennyCount = pennyCount;
}

void PennyCount::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

PennyCount::PennyCount(int pennyCount)
{
	this->pennyCount = pennyCount;
	AddAnimation(2119);
}
