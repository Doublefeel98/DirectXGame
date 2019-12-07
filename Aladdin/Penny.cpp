#include "Penny.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Penny::Penny() :CGameObject() {
	width = THROW_APPLE_BBOX_WIDTH;
	height = THROW_APPLE_BBOX_HEIGHT;

	enabled = true;

	AddAnimation(2110);
}
Penny::~Penny() {

}
void Penny::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (enabled) {
		left = x;
		top = y + 5;
		right = left + PENNY_BBOX_WIDTH;
		bottom = top + PENNY_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void Penny::Render() {
	if (enabled) {
		animations[PENNY_ANI_WAIT]->Render(x, y, 255);
		RenderBoundingBox();
	}
}
void Penny::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}