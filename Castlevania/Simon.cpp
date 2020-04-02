#include "Simon.h"
#include "Define.h"
#include "Brick.h"
#include "Torch.h"
#include "Item.h"
#include "../Framework/Game.h"
#include "Candle.h"
#include "../Framework/debug.h"

Simon* Simon::__instance = NULL;

Simon::Simon()
{
	AddAnimation(100);		// idle left
	AddAnimation(101);		// idle right

	AddAnimation(102);		// walking left
	AddAnimation(103);		// walking right

	AddAnimation(104);		// sitting down left
	AddAnimation(105);		// sitting down right

	AddAnimation(106);		// fighting left
	AddAnimation(107);		// fighting right

	AddAnimation(108);		// sit down fighting left
	AddAnimation(109);		// sit down fighting right

	level = 0;
	hp = SIMON_HP;
	energy = 5;
	score = 0;
	life = 3;

	untouchable = 0;
	untouchable_start = 0;

	IsFighting = false;
	IsJump = false;
	IsSit = false;
	IsRun = false;

	checkPointX = 0.0f;
	checkPointY = 0.0f;

	timeAttackStart = 0;

	whip = new Whip();
}

Simon* Simon::GetInstance()
{
	if (__instance == NULL) __instance = new Simon();
	return __instance;
}

void Simon::SetState(int state)
{
	CGameObject::SetState(state);
	DWORD currentTime = GetTickCount();
	switch (state)
	{
	case SIMON_STATE_WALKING_RIGHT:
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		break;
	case SIMON_STATE_WALKING_LEFT:
		vx = -SIMON_WALKING_SPEED;
		nx = -1;
		break;
	case SIMON_STATE_JUMP:
		IsJump = true;
		IsGround = false;
		vy = -SIMON_JUMP_SPEED_Y;
	case SIMON_STATE_IDLE:
		IsSit = false;
		break;
	case SIMON_STATE_DIE:
		vy = -SIMON_DIE_DEFLECT_SPEED;
		break;
	case SIMON_STATE_SIT_DOWN:
		vx = 0;
		IsSit = true;
		break;
	case SIMON_STATE_FIGHTING:
		vx = 0;
		IsFighting = true;
		timeAttackStart = currentTime;
		whip->SetState(WHIP_STATE_PREPARE);
		break;
	}
}

int Simon::GetLevelWhip()
{
	return this->whip->GetLevel();
}

void Simon::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDead)
	{
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else
	{
		int boxWidth = SIMON_BBOX_WIDTH;
		int boxHeight = SIMON_BBOX_HEIGHT;
		//switch (state)
		//{
		//case SIMON_STATE_JUMP:
		//	boxWidth = SIMON_JUMP_BBOX_WIDTH;
		//	boxHeight = SIMON_JUMP_BBOX_HEIGHT;
		//	break;
		//case SIMON_STATE_RUN_JUMP:
		//	boxWidth = SIMON_JUMP_BBOX_WIDTH;
		//	boxHeight = SIMON_JUMP_BBOX_HEIGHT;
		//	break;
		//}
		left = x;
		top = y;
		right = left + boxWidth;
		bottom = top + boxHeight;
	}
}

void Simon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	DWORD now = GetTickCount();
	CGameObject::Update(dt);

	// Simple fall down
	vy += SIMON_GRAVITY * dt;

	if (IsFighting)
	{
		whip->SetPosition(this->x, this->y, IsSit);
		whip->Update(dt, coObjects);
		if (now - timeAttackStart > (SIMON_ATTACK_TIME - 100))
		{
			whip->SetState(WHIP_STATE_HIT);
		}
		if (now - timeAttackStart > SIMON_ATTACK_TIME)
		{
			timeAttackStart = 0;
			IsFighting = false;
			whip->ResetAnimation();
			ResetAnimationFighting();
		}
	}

	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Item*>(coObjects->at(i))) {
			Item* item = dynamic_cast<Item*>(coObjects->at(i));

			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			item->GetBoundingBox(l2, t2, r2, b2);

			if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2))
			{
				if (!item->IsDead() && item->IsEnable()) {
					item->SetDead(true);
					item->SetEnable(false);
				}
			}
		}
	}


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != SIMON_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount() - untouchable_start > SIMON_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT e = coEvents[i];
		if (dynamic_cast<Torch*>(e->obj) || dynamic_cast<Candle*>(e->obj))
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
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);


		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<Item*>(e->obj))
			{
				Item* item = dynamic_cast<Item*>(e->obj);
				if (!item->IsDead() && item->IsEnable())
				{
					switch (item->GetType())
					{
					case ITEM_WHIP:
						if (whip->GetLevel() < WHIP_LEVEL_3)
						{
							whip->SetLevel(whip->GetLevel() + 1);
						}
						break;
					case ITEM_SMALL_HEART:
						energy += 1;
						break;
					case ITEM_BIG_HEART:
						energy += 5;
						break;
					}
					item->SetDead(true);
					item->SetEnable(false);
				}
			}
			if (dynamic_cast<Brick*>(e->obj))
			{
				//BrickOutCastle* brickOutCastle = dynamic_cast<BrickOutCastle*>(e->obj);

				// block 
				if (e->ny < 0)
				{
					x += min_tx * dx + nx * 0.4f;
					y += min_ty * dy + ny * 0.4f;

					if (nx != 0) vx = 0;
					if (ny != 0) vy = 0;
				}

				if (IsJump)
				{
					//SetState(SIMON_STATE_IDLE);
					IsJump = false;
				}
			}
			else {
				x += dx;
				if (ny < 0)
					y += dy + ny * 0.7f;
				else if (ny > 0)
					y += dy + ny * -0.7f;
			}
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Simon::Render()
{
	int ani;
	float posX = x, posY = y;
	if (state == SIMON_STATE_DIE)
		ani = SIMON_ANI_DIE;
	else
	{
		if (IsSit) {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_SIT_DOWN_FIGHTING_RIGHT;
				else ani = SIMON_ANI_SIT_DOWN_FIGHTING_LEFT;
			}
			else if (nx != 0)
			{
				if (nx > 0) ani = SIMON_ANI_SIT_DOWN_RIGHT;
				else ani = SIMON_ANI_SIT_DOWN_LEFT;
			}
		}
		else if (IsJump) {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_RIGHT;
				else ani = SIMON_ANI_FIGHTING_LEFT;
			}
			else if (nx != 0)
			{
				if (nx > 0) ani = SIMON_ANI_SIT_DOWN_RIGHT;
				else ani = SIMON_ANI_SIT_DOWN_LEFT;
				posY = y - 16;
			}
		}
		else {
			if (IsFighting)
			{
				if (nx > 0) ani = SIMON_ANI_FIGHTING_RIGHT;
				else ani = SIMON_ANI_FIGHTING_LEFT;
			}
			else {
				if (vx == 0)
				{
					if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
					else ani = SIMON_ANI_IDLE_LEFT;
				}
				else
				{
					if (vx > 0)
						ani = SIMON_ANI_WALKING_RIGHT;
					else ani = SIMON_ANI_WALKING_LEFT;
				}
			}
		}

	}

	if (IsFighting)
	{
		whip->SetPosition(this->x, this->y, IsSit);
		whip->Render(nx > 0);
	}

	int alpha = 255;
	if (untouchable) alpha = 128;
	animations[ani]->Render(posX, posY, alpha);

	RenderBoundingBox();
}

void Simon::ResetCheckpoint()
{
	this->x = checkPointX;
	this->y = checkPointY;
	this->hp = SIMON_MAX_HP;
}

void Simon::ResetAnimationFighting()
{
	resetAni(SIMON_ANI_FIGHTING_RIGHT);
	resetAni(SIMON_ANI_FIGHTING_LEFT);

	resetAni(SIMON_ANI_SIT_DOWN_FIGHTING_RIGHT);
	resetAni(SIMON_ANI_SIT_DOWN_FIGHTING_LEFT);
}
