#include"Trap.h"

Trap::Trap() :CGameObject() {
	width = TRAP_BBOX_WIDTH;
	height = TRAP_BBOX_HEIGHT;

	isEnable = false;
	timeStartDelay = 0;

	AddAnimation(2042);
	damage = 1;
}
Trap::~Trap() {

}
void Trap::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (animations[TRAP_ANI_WAIT]->currentFrame >= 4 && animations[TRAP_ANI_WAIT]->currentFrame <= 7) {
		left = x + 10;
		top = y + 4;
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
void Trap::Render() 
{
	if (isDelay) {
		if (timeStartDelay == 0) {
			timeStartDelay = GetTickCount();
			animations[0]->frames[0]->GetSprite()->Draw(x, y);
		}
		else {
			if (GetTickCount() - timeStartDelay > 1800)
			{
				animations[0]->Render(x, y);
				RenderBoundingBox();
			}
			else {
				animations[0]->frames[0]->GetSprite()->Draw(x, y);
			}
		}
	}
	else
	{
		animations[0]->Render(x, y, 255);
		RenderBoundingBox();
	}
}
void Trap::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	if (animations[TRAP_ANI_WAIT]->currentFrame >= 4 && animations[TRAP_ANI_WAIT]->currentFrame <= 7) {
		isEnable = true;
	}
	else {
		isEnable = false;
	}
	
}