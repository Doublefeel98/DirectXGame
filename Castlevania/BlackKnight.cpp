#include "BlackKnight.h"
#include "Define.h"
#include "../Framework/Ground.h"

BlackKnight::BlackKnight(float startX, float startY)
{
	this->startX = startX;
	this->startY = startY;

	this->hp = BLACK_KNIGHT_HP;
	isEnable = true;
	damage = BLACK_KNIGHT_DAMAGE;

	Enemy::Enemy();

	SetState(BLACK_KNIGHT_STATE_WALKING);

	point = 400;
}

BlackKnight::~BlackKnight()
{
}

void BlackKnight::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Enemy::Update(dt, coObjects);
	if (!isDead && isEnable) {

		if (vx > 0 && abs(x - startX) > BLACK_KNIGHT_DISTANCE_X) {
			x = startX + BLACK_KNIGHT_DISTANCE_X;
			vx = -vx;
			nx = -1;
		}

		if (vx < 0 && x <= startX) {
			x = startX;
			vx = -vx;
			nx = 1;
		}

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		if (coEvents.size() == 0) {
			x += dx;
			y += dy;
		}
		else {
			float min_tx, min_ty, nx = 0, ny;
			float rdx = 0;
			float rdy = 0;

			bool isColisionGround = false;

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
					x += min_tx * dx + nx * 0.4f;
					y += min_ty * dy + ny * 0.4f;

					if (nx != 0) vx = 0;
					if (ny != 0) vy = 0;

					isColisionGround = true;
				}
			}

			if (!isColisionGround)
			{
				x += dx;
				y += dy;
			}
		}
	}
}

void BlackKnight::Render()
{
	if (!isDead && isEnable) {
		int posX = x, posY = y;
		int ani = 0;
		switch (state)
		{
		case BLACK_KNIGHT_STATE_WALKING:
		{
			if (nx > 0) {
				ani = BLACK_KNIGHT_ANI_WALKING_RIGHT;
			}
			else {
				ani = BLACK_KNIGHT_ANI_WALKING_LEFT;
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

void BlackKnight::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		right = left + BLACK_KNIGHT_BBOX_WIDTH;
		top = y;
		bottom = top + BLACK_KNIGHT_BBOX_HEIGHT;
	}
}

void BlackKnight::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case BLACK_KNIGHT_STATE_DIE:
		isDead = true;
		isEnable = false;
		break;
	case BLACK_KNIGHT_STATE_WALKING:
		vx = -BLACK_KNIGHT_WALKING_SPEED;
		nx = -1;
	}
}
