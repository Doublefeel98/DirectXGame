#include "Penny.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Penny::Penny() :CGameObject() {
	width = PENNY_BBOX_WIDTH;
	height = PENNY_BBOX_HEIGHT;

	isEnable = true;
	isAte = false;

	AddAnimation(2110);
	AddAnimation(2116);
}
Penny::~Penny() {

}
void Penny::GetBoundingBox(float& left, float& top, float& right, float& bottom)
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
void Penny::Render() 
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
void Penny::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	if (animations[1]->IsLastFrame) {
		isEnable = false;
	}
}