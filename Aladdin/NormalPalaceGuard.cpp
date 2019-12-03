#include "NormalPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

NormalPalaceGuard::NormalPalaceGuard() :CGameObject() {
	width = GUARD_BBOX_WIDTH_WAIT;
	height = GUARD_BBOX_HEIGHT;

	wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	HP = GUARD_MAX_HP;

	AddAnimation(2200);
	AddAnimation(2201);
	AddAnimation(2202);
	AddAnimation(2203);
	AddAnimation(2204);
	AddAnimation(2205);
	AddAnimation(2206);

}
NormalPalaceGuard::~NormalPalaceGuard() {

}
void NormalPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (wait || surprise || jump) {
		left = x + 65;
		top = y + 25;
		right = left + GUARD_BBOX_WIDTH_WAIT;
		bottom = top + GUARD_BBOX_HEIGHT;
	}
	else if (stab) {
		left = x + 15;
		top = y + 25;
		right = left + GUARD_BBOX_WIDTH_STAB;
		bottom = top + GUARD_BBOX_HEIGHT;
	}
	else if(wave){
		left = x + 5;
		top = y + 25;
		right = left + GUARD_BBOX_WIDTH_WAVE;
		bottom = top + GUARD_BBOX_HEIGHT;
	}
	else {
		left = x + 25;
		top = y + 45;
		right = left + GUARD_BBOX_WIDTH_DIE;
		bottom = top + GUARD_BBOX_HEIGHT;
	}
}
void NormalPalaceGuard::Render() {
	if (wait) {
		animations[GUARD_ANI_WAIT]->Render(x, y, 255);
	}
	else if (stab) {
		animations[GUARD_ANI_STAB]->Render(x, y, 255);
	}
	else if (wave) {
		animations[GUARD_ANI_WAVE]->Render(x, y, 255);
	}
	else if (surprise) {
		animations[GUARD_ANI_SURPRISE]->Render(x, y, 255);
	}
	else if (jump) {
		animations[GUARD_ANI_JUMP]->Render(x, y, 255);
	}
	else{
		animations[GUARD_ANI_DIE_SHADOW]->Render(x, y, 255);
		animations[GUARD_ANI_DIE]->Render(x, y, 255);

	}
	RenderBoundingBox();
}

void NormalPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}