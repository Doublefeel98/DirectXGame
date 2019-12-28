#include "ThrowApples.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/Enemy.h"
#include "Brick.h"
#include "WreckingBall.h"
#include "Trap.h"
#include "Jafar.h"
#include "Ground.h"
#include"Sound.h"

ThrowApples::ThrowApples() :CGameObject() {
	x = -5;
	y = -5;
	width = THROW_APPLE_BBOX_WIDTH;
	height = THROW_APPLE_BBOX_HEIGHT;

	AddAnimation(2200);		// throw apple

	AddAnimation(2201);		// throw apple break
	AddAnimation(5000);		// throw apple break boss
	isEnable = false;
	damage = 1;
	isBreak = false;
	isBreakBoss = false;
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
		if (isBreak)
		{
			animations[1]->Render(x, y);
		}
		else if (isBreakBoss)
		{
			animations[2]->Render(x, y);
		}
		else {
			animations[0]->Render(x, y);
			RenderBoundingBox();
		}
	}
}
void ThrowApples::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	if (isEnable) {
		if (animations[1]->IsLastFrame && isBreak) {
			isEnable = false;
			isBreak = false;
			animations[1]->reset();
			return;
		}
		if (isBreak)
		{
			return;
		}

		if (animations[2]->IsLastFrame && isBreakBoss) {
			isEnable = false;
			isBreakBoss = false;
			animations[2]->reset();
			return;
		}
		if (isBreakBoss)
		{
			return;
		}

		CGameObject::Update(dt);

		// Simple fall down
		vy += THROW_APPLE_GRAVITY * (dt / 2);


		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		for (UINT i = 0; i < coEvents.size(); i++)
		{
			LPCOLLISIONEVENT e = coEvents[i];
			if (!dynamic_cast<LPENEMY>(e->obj) && !dynamic_cast<Ground*>(e->obj))
			{
				coEvents.erase(coEvents.begin() + i);
			}
		}

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
			x += min_tx * dx;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
			y += min_ty * dy;

			if (nx != 0) vx = 0;
			if (ny != 0) vy = 0;

			// Collision logic with Enemy
			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];

				if (dynamic_cast<LPENEMY>(e->obj)) // if e->obj is Goomba 
				{
					LPENEMY enemy = dynamic_cast<LPENEMY>(e->obj);

					//enemy->GetColliderEffect()->SetEnable(true);
					if (enemy->isEnable) {
						enemy->SetHP(enemy->GetHP() - this->damage);
						if (dynamic_cast<Jafar*>(e->obj))
						{
							isBreakBoss = true;
							SetPosition(enemy->x + 3, y);
							if (enemy->state == JAFAR_STATE_SNAKE) {
								Sound::getInstance()->playOnce(SNAKE_MUSIC, "snake");
							}

						}
						else {
							int typeObject;
							typeObject = enemy->GetType();

							switch (typeObject) {
							case OBJECT_BAT:
								enemy->SetState(BAT_STATE_DIE);
								break;
							case OBJECT_NORMAL_PALACE_GUARD:
								enemy->SetState(NGUARD_STATE_SURPRISE);
								break;
							case OBJECT_THIN_PALACE_GUARD:
								enemy->SetState(TGUARD_STATE_SURPRISE);
								break;
							}
							isBreak = true;
							Sound::getInstance()->playOnce(SPLAT_MUSIC, "apple");
						}

					}
				}
			}
			//if (!isBreak)
			//{
			//	isEnable = false;
			//}
			//else if (!isBreakBoss)
			//{
			//	isEnable = false;
			//}
		}
	}
	else {
		x = -5;
		y = -5;
		vy = 0;
	}
}