#include"Trap.h"

Trap::Trap() :CGameObject() {
	width = TRAP_BBOX_WIDTH;
	height = TRAP_BBOX_HEIGHT;

	enabled = false;

	AddAnimation(2042);
}
Trap::~Trap() {

}
void Trap::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (animations[TRAP_ANI_WAIT]->currentFrame >= 4 && animations[TRAP_ANI_WAIT]->currentFrame <= 7) {
		left = x;
		top = y;
		right = left + TRAP_BBOX_WIDTH;
		bottom = top + TRAP_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void Trap::Render() {

	animations[TRAP_ANI_WAIT]->Render(x, y, 255);
	RenderBoundingBox();
}
void Trap::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	if (animations[TRAP_ANI_WAIT]->currentFrame >= 4 && animations[TRAP_ANI_WAIT]->currentFrame <= 7) {
		enabled = true;
	}
	enabled = false;
}