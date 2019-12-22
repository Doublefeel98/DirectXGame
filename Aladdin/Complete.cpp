#include "Complete.h"

void Complete::Render()
{
	animations[0]->Render(x, y, 255, false);
}

void Complete::Update(int hp)
{

}

void Complete::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}

Complete::Complete()
{
	AddAnimation(9110);
}
