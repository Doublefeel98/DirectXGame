#include "Ball.h"
void Ball::Render()
{
	RenderBoundingBox();
}

void Ball::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + BALL_WIDTH;
	bottom = y + BALL_HEIGHT;
}

void Ball::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount() - untouchable_start > BALL_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	// No collision occured, proceed normally


	// clean up collision events
	//for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}