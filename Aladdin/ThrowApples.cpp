#include "ThrowApples.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
ThrowApples::ThrowApples() :CGameObject() {
	width =	APPLE_BBOX_WIDTH;
	height =APPLE_BBOX_HEIGHT;

	enabled = true;

	AddAnimation(2115);
}
ThrowApples::~ThrowApples() {

}
void ThrowApples::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (enabled) {
		left = x;
		top = y;
		right = left + APPLE_BBOX_WIDTH;
		bottom = top + APPLE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void ThrowApples::Render() {
	if (enabled) {
		animations[APPLE_ANI_WAIT]->Render(x, y, 255);
		RenderBoundingBox();
	}
}
void ThrowApples::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	
}