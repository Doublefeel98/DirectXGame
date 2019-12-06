#include "Apple.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Apple::Apple() :CGameObject()
{
	width = APPLE_BBOX_WIDTH;
	height = APPLE_BBOX_HEIGHT;

	enabled = true;

	AddAnimation(2115);
}
Apple::~Apple() 
{

}
void Apple::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y + 5;
	right = left + PENNY_BBOX_WIDTH;
	bottom = top + PENNY_BBOX_HEIGHT;
}
void Apple::Render() 
{
	animations[APPLE_ANI_WAIT]->Render(x, y, 255);
}
void Apple::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}