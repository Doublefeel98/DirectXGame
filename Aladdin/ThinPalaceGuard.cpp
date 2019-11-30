#include "ThinPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include"ThinPalaceGuard.h"

ThinPalaceGuard::ThinPalaceGuard() :CGameObject() {
	width = THIN_GUARD_BBOX_WIDTH_WAIT;
	height = THIN_GUARD_BBOX_HEIGHT;

	wait = false; wave = false; walk = false; surprise = true;
	HP = THIN_GUARD_MAX_HP;

	AddAnimation(2303);
	AddAnimation(2301);
	AddAnimation(2300);
	AddAnimation(2302);

}
ThinPalaceGuard::~ThinPalaceGuard() {

}
void ThinPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (wait) {
		left = x + 65;
		top = y + 25;
		right = left + THIN_GUARD_BBOX_WIDTH_WAIT;
		bottom = top + THIN_GUARD_BBOX_HEIGHT;
	}
	else if (wave) {
		left = x + 15;
		top = y + 25;
		right = left + THIN_GUARD_BBOX_WIDTH_WAVE;
		bottom = top + THIN_GUARD_BBOX_HEIGHT;
	}
	else  if (walk){
		left = x + 50;
		top = y + 25;
		right = left + THIN_GUARD_BBOX_WIDTH_WALK;
		bottom = top + THIN_GUARD_BBOX_HEIGHT;
	}
	else {
		left = x + 60;
		top = y + 25;
		right = left + THIN_GUARD_BBOX_WIDTH_SURPISE;
		bottom = top + THIN_GUARD_BBOX_HEIGHT;
	}
}
void ThinPalaceGuard::Render() {
	if (wait) {
		animations[THIN_GUARD_ANI_WAIT]->Render(x, y, 255);
	}
	else if (wave) {
		animations[THIN_GUARD_ANI_WAVE]->Render(x, y, 255);
	}
	else if(walk){
		animations[THIN_GUARD_ANI_WALK]->Render(x, y, 255);
	}
	else {
		animations[THIN_GUARD_ANI_SURPRISE]->Render(x, y, 255);
	}
	RenderBoundingBox();
}

void ThinPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}