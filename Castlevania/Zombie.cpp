#include "Zombie.h"
#include "Define.h"
#include "../Framework/Ground.h"
#include "../Framework/BoundingMap.h"
#include "Simon.h"
#include <time.h>
#include <stdlib.h>

Zombie::Zombie() : Enemy()
{
	hp = 1;

	damage = 2;
	point = 100;

	srand(time(NULL));
	direction = rand() % 100 + 1 > 50 ? -1 : 1;

	SetState(ZOOMBIE_STATE_HIDE);
}

void Zombie::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	startX = x;
	startY = y;
	direction = atoi(tokens[9].c_str());
}

Zombie::~Zombie()
{
}

void Zombie::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Enemy::Update(dt, coObjects);
	if (!isDead && isEnable) {

		float simonX, simonY;

		Simon::GetInstance()->GetPosition(simonX, simonY);

		int t_nx = this->x >= simonX ? -1 : 1;

		if (state == ZOOMBIE_STATE_HIDE) {
			if (t_nx == direction) {
				if (t_nx > 0) {
					float d_x = simonX - this->x;
					if (d_x >= ZOOMBIE_DISTANCE_ATTACK_X) {
						nx = direction;
						SetState(ZOOMBIE_STATE_WALKING);
					}
				}
				else {
					float d_x = this->x - simonX;
					if (d_x <= ZOOMBIE_DISTANCE_ATTACK_X && d_x > 0) {
						nx = direction;
						SetState(ZOOMBIE_STATE_WALKING);
					}
				}

			}
		}


		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		for (UINT i = 0; i < coEvents.size(); i++)
		{
			LPCOLLISIONEVENT e = coEvents[i];
			if (!(dynamic_cast<Ground*>(e->obj) || dynamic_cast<BoundingMap*>(e->obj)))
				coEvents.erase(coEvents.begin() + i);
		}

		if (coEvents.size() == 0) {
			x += dx;
			y += dy;

			isGrounded = false;
		}
		else {
			float min_tx, min_ty, nx = 0, ny;
			float rdx = 0;
			float rdy = 0;

			// TODO: This is a very ugly designed function!!!!
			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);

			// how to push back Mario if collides with a moving objects, what if Mario is pushed this way into another object?
			//if (rdx != 0 && rdx!=dx)
			//	x += nx*abs(rdx); 

			// block every object first!

			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];

				if (dynamic_cast<Ground*>(e->obj))
				{
					isGrounded = true;
					if (e->ny < 0)
					{
						x += dx;
						y += min_ty * dy + ny * 0.1f;
						if (ny != 0) vy = 0;
					}
					if (e->nx != 0)
					{
						x += dx;
						y += 1;
						if (ny != 0) vy = 0;
					}
				}

				if (dynamic_cast<BoundingMap*>(e->obj))
				{
					SetState(ZOOMBIE_STATE_WALKING);
				}
			}
		}
		for (UINT i = 0; i < coEvents.size(); i++)
		{
			delete coEvents[i];
		}
		if (!isGrounded)
			vy += 0.001 * dt;
	}
}

void Zombie::Render()
{
	if (!isDead && isEnable && state != ZOOMBIE_STATE_HIDE) {
		int posX = x, posY = y;
		int ani = 0;
		switch (state)
		{
		case ZOOMBIE_STATE_WALKING:
		{
			if (nx > 0) {
				ani = ZOOMBIE_ANI_WALKING_RIGHT;
			}
			else {
				ani = ZOOMBIE_ANI_WALKING_LEFT;
			}
		}
		break;
		default:
			break;
		}

		animation_set->at(ani)->Render(posX, posY);
		RenderBoundingBox();
	}

	Enemy::Render();
}

void Zombie::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		right = left + ZOOMBIE_BBOX_WIDTH;
		top = y;
		bottom = top + ZOOMBIE_BBOX_HEIGHT;
	}
}

void Zombie::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case ZOOMBIE_STATE_WALKING:
		vx = nx * ZOOMBIE_WALKING_SPEED;
		break;
	case ZOOMBIE_STATE_DEAD:
	{
		isDead = true;
		isEnable = false;
	}
	break;
	}
}
