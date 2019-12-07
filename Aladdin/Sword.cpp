#include "Sword.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/Enemy.h"

Sword::Sword()
{
	x = -5;
	y = -5;
	width = SWORD_BBOX_WIDTH;
	height = SWORD_BBOX_HEIGHT;
	isEnable = false;
	vx = 0;
	vy = 0;
}

Sword::~Sword()
{

}

void Sword::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isEnable) {
		CGameObject::Update(dt);

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

				}
			}
		}
	}
	else {
		x = -5;
		y = -5;
	}
}

void Sword::Render()
{
	RenderBoundingBox();
}

void Sword::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable) {

		left = x;
		top = y;
		switch (state)
		{
		case SWORD_STATE_RIGHT:
			right = left + SWORD_BBOX_WIDTH;
			bottom = top + SWORD_BBOX_HEIGHT;
			break;
		case SWORD_STATE_LEFT:
			left = x - SWORD_BBOX_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_HEIGHT;
			break;

		case SWORD_STATE_SIT_RIGHT:
			right = left + SWORD_BBOX_SIT_WIDTH;
			bottom = top + SWORD_BBOX_SIT_HEIGHT;
			break;
		case SWORD_STATE_SIT_LEFT:
			left = x - SWORD_BBOX_SIT_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_SIT_HEIGHT;
			break;

		case SWORD_STATE_JUMP_RIGHT:
			right = left + SWORD_BBOX_JUMP_WIDTH;
			bottom = top + SWORD_BBOX_JUMP_HEIGHT;
			break;
		case SWORD_STATE_JUMP_LEFT:
			left = x - SWORD_BBOX_JUMP_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_JUMP_HEIGHT;
			break;

		case SWORD_STATE_LOOKUP_RIGHT:
			right = left + SWORD_BBOX_LOOKUP_WIDTH;
			bottom = top + SWORD_BBOX_LOOKUP_HEIGHT;
			break;
		case SWORD_STATE_LOOKUP_LEFT:
			left = x - SWORD_BBOX_LOOKUP_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_LOOKUP_HEIGHT;
			break;

		case SWORD_STATE_RUN_RIGHT:
			right = left + SWORD_BBOX_RUN_WIDTH;
			bottom = top + SWORD_BBOX_RUN_HEIGHT;
			break;
		case SWORD_STATE_RUN_LEFT:
			left = x - SWORD_BBOX_RUN_WIDTH;
			right = x;
			bottom = top + SWORD_BBOX_RUN_HEIGHT;
			break;
		default:
			break;
		}
		
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}

void Sword::SetState(int state)
{
	CGameObject::SetState(state);
}
