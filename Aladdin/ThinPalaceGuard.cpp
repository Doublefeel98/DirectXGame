#include "ThinPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void ThinPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}

void ThinPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	//if (wait) {
	//	left = x + 65;
	//	top = y + 25;
	//	right = left + THIN_GUARD_BBOX_WIDTH_WAIT;
	//	bottom = top + THIN_GUARD_BBOX_HEIGHT;
	//}
	//else if (wave) {
	//	left = x + 15;
	//	top = y + 25;
	//	right = left + THIN_GUARD_BBOX_WIDTH_WAVE;
	//	bottom = top + THIN_GUARD_BBOX_HEIGHT;
	//}
	//else  if (walk){
	//	left = x + 50;
	//	top = y + 25;
	//	right = left + THIN_GUARD_BBOX_WIDTH_WALK;
	//	bottom = top + THIN_GUARD_BBOX_HEIGHT;
	//}
	//else {
	//	left = x + 60;
	//	top = y + 25;
	//	right = left + THIN_GUARD_BBOX_WIDTH_SURPISE;
	//	bottom = top + THIN_GUARD_BBOX_HEIGHT;
	//}
}
void ThinPalaceGuard::Render() {
	//if (wait) {
	//	animations[THIN_GUARD_ANI_WAIT]->Render(x, y, 255);
	//}
	//else if (wave) {
	//	animations[THIN_GUARD_ANI_WAVE]->Render(x, y, 255);
	//}
	//else if(walk){
	//	animations[THIN_GUARD_ANI_WALK]->Render(x, y, 255);
	//}
	//else {
	//	animations[THIN_GUARD_ANI_SURPRISE]->Render(x, y, 255);
	//}
	//RenderBoundingBox();
}


ThinPalaceGuard::ThinPalaceGuard() :CGameObject() {
	width = THIN_GUARD_BBOX_WIDTH_WAIT;
	height = THIN_GUARD_BBOX_HEIGHT;

	wait = false; wave = false; walk = false; surprise = true;
	HP = THIN_GUARD_MAX_HP;

	AddAnimation(201);		// idle right
	AddAnimation(202);		// idle left

	AddAnimation(203);		// walk right
	AddAnimation(204);		// walk left

	AddAnimation(205);		// attack right
	AddAnimation(206);		// attack left

	AddAnimation(207);		// suprise right
	AddAnimation(208);		// suprise left

}
ThinPalaceGuard::~ThinPalaceGuard() {

}