#include "Apple.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Apple::Apple() :CGameObject()
{
	width = THROW_APPLE_BBOX_WIDTH;
	height = THROW_APPLE_BBOX_HEIGHT;

	AddAnimation(2115);
	AddAnimation(2116);

	isEnable = true;
	isAte = false;
}
Apple::~Apple()
{

}
void Apple::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable && !isAte) {
		left = x;
		top = y;
		right = left + width;
		bottom = top + height;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void Apple::Render()
{
	
	if (isEnable && !isAte)
	{
		animations[0]->Render(x, y, 255);
	}
	else if (isEnable && isAte)
	{

		animations[1]->Render(x, y, 255);
	}
}
void Apple::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) 
{
	CGameObject::Update(dt);
	if (animations[1]->IsLastFrame) {
		isEnable = false;
	}
}