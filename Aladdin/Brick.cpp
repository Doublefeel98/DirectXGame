#include "Brick.h"

void Brick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt);
	if (animations[0]->currentFrame >= 4 && animations[0]->currentFrame <= 6) {
		isEnable = true;
	}
	else isEnable = false;
}


void Brick::Render()
{
	if (isDelay) {
		if (timeStartDelay == 0) {
			timeStartDelay = GetTickCount();
			animations[0]->frames[0]->GetSprite()->Draw(x, y);
		}
		else {
			if (GetTickCount() - timeStartDelay > 2600)
			{
				animations[0]->Render(x, y);
				RenderBoundingBox();
			}
			else {
				animations[0]->frames[0]->GetSprite()->Draw(x, y);
			}
		}
	}
	else {
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}
}

void Brick::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (animations[0]->currentFrame >= 4 && animations[0]->currentFrame <= 6) 
	{
		left = x;
		top = y;
		right = x + BRICK_BBOX_WIDTH;
		bottom = y + BRICK_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
	
}

Brick::Brick() :CGameObject() {
	width = BRICK_BBOX_WIDTH;
	height = BRICK_BBOX_WIDTH;

	isEnable = false;
	timeStartDelay = 0;

	AddAnimation(2040);
}
Brick::~Brick() {

}