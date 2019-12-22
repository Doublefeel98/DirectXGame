#include "Intro.h"

void Intro::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void Intro::Update(int hp)
{

}

void Intro::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}

Intro::Intro()
{
	AddAnimation(9010);
}
