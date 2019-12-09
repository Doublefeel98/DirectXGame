#include"WreckingBall.h"

WreckingBall::WreckingBall() :CGameObject() {
	width = BALL_BBOX_WIDTH;
	height = BALL_BBOX_HEIGHT;

	isEnable = false;
	timeStartDelay = 0;

	AddAnimation(2043);
	damage = 1;
}
WreckingBall::~WreckingBall() {

}
void WreckingBall::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (animations[BALL_ANI_WAIT]->currentFrame >= 9 && animations[BALL_ANI_WAIT]->currentFrame <= 19) {
		left = x + 6;
		top = y + 25;
		right = left + BALL_BBOX_WIDTH;
		bottom = top + BALL_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void WreckingBall::Render() {
	if (isDelay) {
		if (timeStartDelay == 0) {
			timeStartDelay = GetTickCount();
			animations[0]->frames[0]->GetSprite()->Draw(x, y);
		}
		else {
			if (GetTickCount() - timeStartDelay > 2800)
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
		animations[BALL_ANI_WAIT]->Render(x, y, 255);
		RenderBoundingBox();
	}
}

void WreckingBall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject) {
	CGameObject::Update(dt);
	if (animations[BALL_ANI_WAIT]->currentFrame >= 9 && animations[BALL_ANI_WAIT]->currentFrame <= 19) {
		isEnable = true;
	}
	else isEnable = false;
}