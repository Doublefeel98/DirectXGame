#include "Vase.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Vase::Vase() :CGameObject() {
	width =	VASE_BBOX_WIDTH;
	height =VASE_BBOX_HEIGHT;

	isEnable = true;
	isAte = false;

	AddAnimation(2114);		//idle
	AddAnimation(2119);		//stop
	AddAnimation(2113);		//active
}
Vase::~Vase() {

}
void Vase::GetBoundingBox(float& left, float& top, float& right, float& bottom)
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
void Vase::Render()
{
	if (isEnable && !isAte)
	{
		animations[0]->Render(x, y, 255);
	}
	else if (isEnable && isAte)
	{
		animations[2]->Render(x, y, 255);
	}
	else if (!isEnable)
	{
		animations[1]->Render(x, y);
	}
}
void Vase::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	if (animations[2]->IsLastFrame) {
		isEnable = false;		
	}
}