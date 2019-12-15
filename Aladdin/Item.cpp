#include "Item.h"

void Item::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}

Item::Item()
{
}

Item::Item(int itemType)
{
}

Item::~Item()
{

}

void Item::SetState(int state)
{
}

int Item::GetCurrentFrame()
{
	return 0;
}

void Item::Render()
{

}

void Item::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - 1;
	top = y;
	right = x + width;
	bottom = y + height;
}
