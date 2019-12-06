#include "GenieBonusLevel.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
GenieBonusLevel::GenieBonusLevel() :CGameObject() {
	width = GENNIE_BBOX_WIDTH;
	height = GENNIE_BBOX_HEIGHT;

	enabled = true;

	AddAnimation(2112);
	AddAnimation(2111);
}
GenieBonusLevel::~GenieBonusLevel() {

}
void GenieBonusLevel::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (enabled) {
		left = x;
		top = y;
		right = left + GENNIE_BBOX_WIDTH;
		bottom = top + GENNIE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void GenieBonusLevel::Render() {
	//if (enabled) {
	//	animations[GENNIE_ANI_WAIT]->Render(x, y, 255);
	//	RenderBoundingBox();
	//}
	//else {
	//	animations[GENNIE_ANI_ACTIVE]->Render(x, y, 255);
	//	RenderBoundingBox();
	//}
	animations[GENNIE_ANI_ACTIVE]->Render(x, y, 255);
}
void GenieBonusLevel::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}