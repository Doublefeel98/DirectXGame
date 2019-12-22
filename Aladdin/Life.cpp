#include "Life.h"

void Life::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void Life::Update(int hp)
{
	this->life = life;
}

void Life::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

Life::Life(int life)
{
	this->life = life;
	AddAnimation(2130);
}
