#include "Bat.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include"Bat.h"

Bat::Bat() :CGameObject() {
	width = BAT_BBOX_WIDTH_WAIT;
	height = BAT_BBOX_HEIGHT;
	
	wait = true; fly = false; rotate = false; die = false;
	HP = BAT_MAX_HP;

	//AddAnimation(2100);		
	//AddAnimation(2101);
	//AddAnimation(2102);
	//AddAnimation(2103);

}
Bat::~Bat() {

}
void Bat::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

	if (wait) {
		left = x;
		top = y + 5;
		right = left + BAT_BBOX_WIDTH_WAIT;
		bottom = top + BAT_BBOX_HEIGHT;
	}else if (fly) {
		left = x;
		top = y + 10;
		right = left + BAT_BBOX_WIDTH_FLY;
		bottom = top + BAT_BBOX_HEIGHT;
	} else if (rotate) {
		left = x;
		top = y + 10;
		right = left + BAT_BBOX_WIDTH_ROTATE;
		bottom = top + BAT_BBOX_HEIGHT;
	} else{
		left = x;
		top = y;
		right = left + BAT_BBOX_WIDTH_DIE;
		bottom = top + BAT_BBOX_HEIGHT;
	}
}
void Bat::Render() {
	if (wait) {
		animations[BAT_ANI_WAIT]->Render(x, y, 255);
		RenderBoundingBox();
	}
	else if (fly) {
		animations[BAT_ANI_FLY]->Render(x, y, 255);
		RenderBoundingBox();
	}
	else if (rotate) {
		animations[BAT_ANI_ROTATE]->Render(x, y, 255);
		RenderBoundingBox();
	}
	else {
		animations[BAT_ANI_DIE]->Render(x, y, 255);
		RenderBoundingBox();
	}
	
}

void Bat::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	
}