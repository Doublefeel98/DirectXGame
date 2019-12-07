#include "Heart.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
Heart::Heart() :CGameObject() {
	width = THROW_APPLE_BBOX_WIDTH;
	height = THROW_APPLE_BBOX_HEIGHT;

	enabled = true;

	AddAnimation(2117);
}
Heart::~Heart() {

}
void Heart::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (enabled) {
		left = x;
		top = y + 5;
		right = left + HEART_BBOX_WIDTH;
		bottom = top + HEART_BBOX_HEIGH;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void Heart::Render() {
	if (enabled) {
		animations[HEART_ANI_WAIT]->Render(x, y, 255);
		RenderBoundingBox();
	}
}
void Heart::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);

}