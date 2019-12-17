#include "GenieBonusLevel.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
GenieBonusLevel::GenieBonusLevel() :CGameObject() {
	width = GENNIE_BBOX_WIDTH;
	height = GENNIE_BBOX_HEIGHT;

	isEnable = true;
	isAte = false;

	AddAnimation(2112);
	AddAnimation(2111);
	AddAnimation(2117);
}
GenieBonusLevel::~GenieBonusLevel() {

}
void GenieBonusLevel::GetBoundingBox(float& left, float& top, float& right, float& bottom)
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
void GenieBonusLevel::Render() 
{
	if (isEnable && !isAte)
	{
		animations[0]->Render(x, y, 255);
	}
	else if (isEnable && isAte)
	{
		animations[GENNIE_ANI_EFFECT]->Render(x, y, 255);
	}
}
void GenieBonusLevel::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) 
{
	CGameObject::Update(dt);
	if (animations[GENNIE_ANI_EFFECT]->IsLastFrame) {
		isEnable = false;
	}
}