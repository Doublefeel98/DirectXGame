#include "Star.h"
#include <algorithm>
#include <math.h>
#include "../Framework/Game.h"

Star::Star() : CGameObject()
{
	AddAnimation(704);

	isEnable = true;
	aladdin = Aladdin::GetInstance();
	objects.push_back(aladdin);
	vy = 0;
	ny = 0;
}

Star::~Star()
{
}

void Star::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	if (isEnable)
	{
		float l1, t1, r1, b1, l2, t2, r2, b2;
		GetBoundingBox(l1, t1, r1, b1);
		aladdin->GetBoundingBox(l2, t2, r2, b2);
		if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {

			if (nx > 0)
			{
				aladdin->vx -= STAR_GRAVITATION;
			}
			else {
				aladdin->vx += STAR_GRAVITATION;
			}


			isEnable = false;

			return;
		}


		CGameObject::Update(dt, colliable_objects);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		nx = this->x >= alaPosition.x ? -1 : 1;

		float posX = alaPosition.x + ALADDIN_BBOX_WIDTH - STAR_BBOX_WIDTH;
		float posY = alaPosition.y + ALADDIN_BBOX_HEIGHT - STAR_BBOX_HEIGHT;
		ny = this->y >= posY ? -1 : 1;


		float sX = abs(posX - x);
		float sY = abs(posY - y);

		float dtaX = STAR_SPEED * dt;

		float speedY = (sY * dtaX) / (sX * dt);

		vy = ny * speedY;

		if (nx > 0)
		{
			SetState(STAR_STATE_RIGHT);
		}
		else
		{
			SetState(STAR_STATE_LEFT);
		}

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();
		CalcPotentialCollisions(&objects, coEvents);

		// No collision occured, proceed normally
		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else
		{
			if (nx > 0)
			{
				aladdin->vx -= STAR_GRAVITATION;
			}
			else {
				aladdin->vx += STAR_GRAVITATION;
			}

			isEnable = false;
		}

		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];

	}
	else
	{
		x = 0;
		y = 0;
	}
}

void Star::Render()
{
	if (isEnable)
	{
		animations[0]->Render(x, y);
		RenderBoundingBox();
	}
}

void Star::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable)
	{
		left = x;
		top = y;
		right = left + STAR_BBOX_WIDTH;
		bottom = top + STAR_BBOX_HEIGHT;
	}
	else {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
}

void Star::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case STAR_STATE_RIGHT:
		vx = STAR_SPEED;
		break;
	case STAR_STATE_LEFT:
		vx = -STAR_SPEED;
		break;
	default:
		break;
	}
}
