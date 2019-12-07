#include "ThrowApples.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/Enemy.h"

ThrowApples::ThrowApples() :CGameObject() {
	x = -5;
	y = -5;
	width =	THROW_APPLE_BBOX_WIDTH;
	height = THROW_APPLE_BBOX_HEIGHT;

	AddAnimation(2200);		// throw apple
	
	AddAnimation(2201);		// throw apple break
	AddAnimation(2202);
	AddAnimation(2203);
	AddAnimation(2204);
	isEnable = false;
}
ThrowApples::~ThrowApples() {

}
void ThrowApples::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable) {
		left = x;
		top = y;
		right = left + THROW_APPLE_BBOX_WIDTH;
		bottom = top + THROW_APPLE_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}
void ThrowApples::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case THROW_APPLE_STATE_RIGHT:
		vx = THROW_APPLE_SPEED;
		nx = 1;
		break;
	case THROW_APPLE_STATE_LEFT:
		vx = -THROW_APPLE_SPEED;
		nx = -1;
		break;
	}
}
void ThrowApples::Render() {
	if (isEnable) {
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}
}
void ThrowApples::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	
	if (isEnable) {
		CGameObject::Update(dt);

		// Simple fall down
		vy += THROW_APPLE_GRAVITY * (dt/2);

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else {

			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			// block 
			//x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
			//y += min_ty * dy + ny * 0.4f;

			//if (nx != 0) vx = 0;
			//if (ny != 0) vy = 0;

			// Collision logic with Enemy
			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];

				if (dynamic_cast<LPENEMY>(e->obj)) // if e->obj is Goomba 
				{
					LPENEMY enemy = dynamic_cast<LPENEMY>(e->obj);

					if (enemy->GetState() != CENEMY_STATE_DIE)
					{
						enemy->SetState(CENEMY_STATE_DIE);
					}

					// jump on top >> kill Goomba and deflect a bit 
					/*if (e->ny < 0)
					{
						if (enemy->GetState() != CENEMY_STATE_DIE)
						{
							enemy->SetState(CENEMY_STATE_DIE);
						}
					}*/
				}
			}

			isEnable = false;
		}
	}
	else {
		x = -5;
		y = -5;
		vy = 0;
	}
}