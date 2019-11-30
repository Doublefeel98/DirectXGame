#include"Stone.h"

Stone::Stone() :CGameObject() {
	width = STONE_BBOX_WIDTH;
	height = STONE_BBOX_HEIGHT;

	enabled = false;

	AddAnimation(2040);
}
Stone::~Stone() {

}
void Stone::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (animations[BALL_ANI_WAIT]->currentFrame >= 3 && animations[BALL_ANI_WAIT]->currentFrame <= 7) {
		left = x + 5;
		top = y;
		right = left + STONE_BBOX_WIDTH;
		bottom = top + STONE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void Stone::Render() {

	animations[STONE_ANI_WAIT]->Render(x, y, 255);
	RenderBoundingBox();
}
void Stone::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	if (animations[STONE_ANI_WAIT]->currentFrame >= 3 && animations[STONE_ANI_WAIT]->currentFrame <= 7) {
		enabled = true;
	}
	else enabled = false;
}