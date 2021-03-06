﻿#include "Fleamen.h"
#include "Define.h"
#include "Simon.h"
#include "../Framework/Ground.h"

Fleamen::Fleamen() :Enemy()
{
	this->hp = FLEAMEN_HP;
	isEnable = true;
	damage = FLEAMEN_DAMAGE;

	SetState(FLEAMEN_STATE_IDLE);

	point = 500;

	timeJump = 0;
}

void Fleamen::FromVector(vector<string> tokens)
{
	CGameObject::FromVector(tokens);
	startX = x;
	startY = y;
}

Fleamen::~Fleamen()
{
}

void Fleamen::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	Enemy::Update(dt, coObjects);
	if (!isDead && isEnable && !Enemy::IsStop) {

		float simonX, simonY;

		Simon::GetInstance()->GetPosition(simonX, simonY);

		nx = this->x >= simonX ? -1 : 1;

		if (state != FLEAMEN_STATE_IDLE) {
			vy += FLEAMEN_GRAVITY * dt;
		}


		if (state == FLEAMEN_STATE_IDLE) {
			if (abs(this->x - simonX) <= FLEAMEN_DISTANCE_ATTACK_X) {
				SetState(FLEAMEN_STATE_JUMP);
			}
		}
		else if (state == FLEAMEN_STATE_COMEBACK) {
			nx = old_nx;
			if ((nx > 0 && x_back <= x) || (nx < 0 && x_back >= x)) {
				SetState(FLEAMEN_STATE_WAITTING);
			}
		}
		else if (state == FLEAMEN_STATE_WAITTING) {
			if (GetTickCount() - time_waiting > 500) {
				SetState(FLEAMEN_STATE_ATTACK);
			}
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

			bool isCollision = false;

			// TODO: This is a very ugly designed function!!!!
			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);

			// how to push back Mario if collides with a moving objects, what if Mario is pushed this way into another object?
			//if (rdx != 0 && rdx!=dx)
			//	x += nx*abs(rdx); 

			// block every object first!

			bool is_colision_top = false;

			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];

				if (dynamic_cast<Ground*>(e->obj)) // if e->obj is Goomba 
				{
					isCollision = true;
					is_colision_top = e->ny > 0;
				}
			}

			if (!isCollision)
			{
				x += dx;
				y += dy;
			}
			else {
				x += min_tx * dx + nx * 0.4f;
				y += min_ty * dy + ny * 0.4f;

				if (nx != 0) vx = 0;
				if (ny != 0) vy = 0;

				if (state == FLEAMEN_STATE_ATTACK) {

					DWORD now = GetTickCount();
					if (!is_colision_top) {
						if (timeJump == 0) {
							timeJump = now;
							vy = -FLEAMEN_SPEED_Y;
						}
						else if (now - timeJump >= 1000) {
							timeJump = now;
							vy = -FLEAMEN_SPEED_Y * 2;
						}
						else {
							vy = -FLEAMEN_SPEED_Y;
						}
					}


					if (this->nx > 0) {
						vx = FLEAMEN_SPEED_X;
					}
					else {
						vx = -FLEAMEN_SPEED_X;
					}
				}
				else if (state == FLEAMEN_STATE_COMEBACK) {
					if (this->nx > 0) {
						vx = FLEAMEN_SPEED_X;
					}
					else {
						vx = -FLEAMEN_SPEED_X;
					}

					vy = -FLEAMEN_SPEED_Y;
				}
				else if (state == FLEAMEN_STATE_WAITTING) {
					vy = -FLEAMEN_SPEED_Y;
					vx = 0;
				}
				else if (state == FLEAMEN_STATE_JUMP) {
					SetState(FLEAMEN_STATE_ATTACK);
				}
			}
		}
	}
}

void Fleamen::Render()
{
	if (!isDead && isEnable) {
		int posX = x, posY = y;
		int ani = 0;
		switch (state)
		{
		case FLEAMEN_STATE_IDLE:
		{
			if (nx > 0) {
				ani = FLEAMEN_ANI_IDLE_RIGHT;
			}
			else {
				ani = FLEAMEN_ANI_IDLE_LEFT;
			}
		}
		break;
		case FLEAMEN_STATE_WAITTING:
		case FLEAMEN_STATE_COMEBACK:
		case FLEAMEN_STATE_JUMP:
		case FLEAMEN_STATE_ATTACK:
		{
			if (nx > 0) {
				ani = FLEAMEN_ANI_ATTACK_RIGHT;
			}
			else {
				ani = FLEAMEN_ANI_ATTACK_LEFT;
			}
		}
		break;
		default:
			break;
		}

		animation_set->at(ani)->Render(posX, posY, Enemy::IsStop);
		RenderBoundingBox();
	}

	Enemy::Render();
}

void Fleamen::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		right = left + FLEAMEN_BBOX_WIDTH;
		top = y;
		bottom = top + FLEAMEN_BBOX_HEIGHT;
	}
}

void Fleamen::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case FLEAMEN_STATE_IDLE:
		break;
	case FLEAMEN_STATE_JUMP:
		if (nx > 0) {
			vx = FLEAMEN_JUMP_SPEED_X;
		}
		else {
			vx = -FLEAMEN_JUMP_SPEED_X;
		}
		vy = -FLEAMEN_JUMP_SPEED_Y;
		break;
	case FLEAMEN_STATE_WAITTING:
		vx = 0;
		time_waiting = GetTickCount();
	case FLEAMEN_STATE_COMEBACK:
	{
		old_nx = nx;
		if (nx > 0) {
			x_back = x + FLEAMEN_DISTANCE_WAITING_X + FLEAMEN_BBOX_WIDTH;
		}
		else {
			x_back = x - SIMON_BBOX_WIDTH - FLEAMEN_DISTANCE_WAITING_X;
		}
	}
	break;
	case FLEAMEN_STATE_ATTACK:
	{
	}
	break;
	}
}
