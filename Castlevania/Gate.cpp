#include "Gate.h"

Gate::Gate()
{
}

void Gate::Render()
{
	animation_set->at(0)->Render(x, y);
}

void Gate::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

void Gate::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}

Gate::~Gate()
{
}
