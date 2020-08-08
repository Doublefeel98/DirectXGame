#include "BlackKnight.h"
#include "Define.h"
#include "../Framework/Ground.h"
#include "../Framework/BoundingMap.h"

void BlackKnight::Hurted(int damage)
{
	this->prev_hp = hp;
	Enemy::Hurted(damage);
}

BlackKnight::BlackKnight() :Enemy()
{
	this->hp = BLACK_KNIGHT_HP;
	isEnable = true;
	damage = BLACK_KNIGHT_DAMAGE;
	nx = -1;
	SetState(BLACK_KNIGHT_STATE_WALKING);

	point = 400;
}

void BlackKnight::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	startX = x;
	startY = y;
	if (tokens.size() > 9) {
		distanceX = atof(tokens[9].c_str());
	}
	else {
		distanceX = BLACK_KNIGHT_DISTANCE_X;
	}
}

BlackKnight::~BlackKnight()
{
}

void BlackKnight::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Enemy::Update(dt, coObjects);
	if (!isDead && isEnable && !Enemy::IsStop) {

		if (vx > 0 && abs(x - startX) > distanceX) {
			x = startX + distanceX;
			vx = -vx;
			nx = -1;
		}

		if (vx < 0 && x <= startX) {
			x = startX;
			vx = -vx;
			nx = 1;
		}

		vy += SIMON_GRAVITY * dt;

		// check hurted
		if (this->prev_hp > hp) {
			SetState(BLACK_KNIGHT_STATE_HURT);
			this->prev_hp = hp;
		}

		if (state == BLACK_KNIGHT_STATE_HURT)
		{
			if (GetTickCount() - time_hurt >= 500)
			{
				SetState(BLACK_KNIGHT_STATE_WALKING);
			}
		}

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();

		CalcPotentialCollisions(coObjects, coEvents);

		if (coEvents.size() == 0) {
			if (state != BLACK_KNIGHT_STATE_HURT) {
				x += dx;
			}
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
					isColisionGround = true;
				}
			}

			if (!isColisionGround)
			{
				x += dx;
				y += dy;
			}
			else {
				x += min_tx * dx + nx * 0.4f;
				y += min_ty * dy + ny * 0.4f;

				if (nx != 0) vx = 0;
				if (ny != 0) vy = 0;
			}
		}
	}
}

void BlackKnight::Render()
{
	if (!isDead && isEnable) {
		int posX = x, posY = y;
		int ani = 0;

		if (nx > 0) {
			ani = BLACK_KNIGHT_ANI_WALKING_RIGHT;
		}
		else {
			ani = BLACK_KNIGHT_ANI_WALKING_LEFT;
		}

		if (state == BLACK_KNIGHT_STATE_HURT)
		{
			animation_set->at(ani)->Render(posX, posY, true);
		}
		else {
			animation_set->at(ani)->Render(posX, posY, Enemy::IsStop);
		}

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
	case BLACK_KNIGHT_STATE_HURT:
		time_hurt = GetTickCount();
		break;
	case BLACK_KNIGHT_STATE_WALKING:
		vx = nx * BLACK_KNIGHT_WALKING_SPEED;
		break;
	}
}
