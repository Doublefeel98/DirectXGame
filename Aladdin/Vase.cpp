#include "Vase.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Vase::Vase() :CGameObject() {
	width =	VASE_BBOX_WIDTH;
	height =VASE_BBOX_HEIGHT;

	enabled = true;

	AddAnimation(2114);
	AddAnimation(2113);
}
Vase::~Vase() {

}
void Vase::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (enabled) {
		left = x;
		top = y;
		right = left + VASE_BBOX_WIDTH;
		bottom = top + VASE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void Vase::Render() {
	if (enabled) {
		animations[VASE_ANI_WAIT]->Render(x, y, 255);
		RenderBoundingBox();
	}
	else {
		animations[VASE_ANI_ACTIVE]->Render(x, y, 255);
		RenderBoundingBox();
	}
}
void Vase::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}