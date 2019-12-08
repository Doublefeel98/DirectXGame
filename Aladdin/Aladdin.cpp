#include "Aladdin.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/debug.h"
#include "WreckingBall.h"
#include "Trap.h"

bool Aladdin::IsMoveCameraWhenLookingUp()
{
	if (IsLookingUp) {
		if ((GetTickCount() - timeLookUpStart) > 500)
		{
			return true;
		}
		//DebugOut(L"[INFO] test: %d\n", GetTickCount());
		//DebugOut(L"[INFO] test: %d\n",timeLookUpStart);
		//DebugOut(L"[INFO] test: %d\n", GetTickCount() - timeLookUpStart);
		//return true;
	}
	return false;
}

void Aladdin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//if (hp <= 0) {
	//	SetState(ALADDIN_STATE_DIE);
	//}

	DWORD now = GetTickCount();
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	vy += ALADDIN_GRAVITY * dt;

	throwApple->Update(dt, coObjects);
	sword->Update(dt, coObjects);


	if (this->GetState() == ALADDIN_STATE_IDLE) 
	{
		IsSit = false;
		ResetAnimationsSitDown();
	}
	else {
		timeIdleStart = 0;
		ResetAnimationIdle();
	}

	if (this->GetState() != ALADDIN_STATE_LOOKING_UP) {
		IsLookingUp = false;
		ResetAnimationsLookUp();
		timeLookUpStart = 0;
	}

	if (now - timeSitStart > ALADDIN_SIT_TIME)
	{
		int ani;
		if (nx > 0)
		{
			ani = ALADDIN_ANI_SIT_DOWN_RIGHT;
		}
		else {
			ani = ALADDIN_ANI_SIT_DOWN_LEFT;
		}
		animations[ani]->currentFrame = animations[ani]->frames.size() - 1;
	}

	if (now - timeLookUpStart > ALADDIN_LOOK_UP_TIME)
	{
		int ani;
		if (nx > 0)
		{
			ani = ALADDIN_ANI_LOOKING_UP_RIGHT;
		}
		else {
			ani = ALADDIN_ANI_LOOKING_UP_LEFT;
		}
		animations[ani]->currentFrame = animations[ani]->frames.size() - 1;
	}
		
	if (IsSlash)
	{
		if (IsSit)
		{
			if (nx > 0)
			{
				sword->SetState(SWORD_STATE_SIT_RIGHT);
				sword->SetPosition(x + ALADDIN_BBOX_WIDTH, y);
			}
			else {
				sword->SetState(SWORD_STATE_SIT_LEFT);
				sword->SetPosition(x, y);
			}
			if (now - timeAttackStart >= ALADDIN_SIT_ENABLE_SWORD_TIME)
			{
				if (!sword->IsFighting())
				{
					sword->SetEnable(true);
					sword->SetFighting(true);
				}
				
			}
			if (now - timeAttackStart > ALADDIN_SIT_ATTACK_TIME)
			{
				ResetAnimationsSlash();
				timeAttackStart = 0;
				IsSlash = false;
				SetState(ALADDIN_STATE_SIT_DOWN);
			}
		}
		else if (IsLookingUp)
		{
			if (nx > 0)
			{
				sword->SetState(SWORD_STATE_LOOKUP_RIGHT);
				sword->SetPosition(x + ALADDIN_BBOX_WIDTH, y);
			}
			else {
				sword->SetState(SWORD_STATE_LOOKUP_LEFT);
				sword->SetPosition(x, y);
			}
			if (now - timeAttackStart >= ALADDIN_LOOK_UP_ENABLE_SWORD_TIME)
			{
				if (!sword->IsFighting())
				{
					sword->SetEnable(true);
					sword->SetFighting(true);
				}
			}
			if (now - timeAttackStart > ALADDIN_LOOK_UP_ATTACK_TIME)
			{
				ResetAnimationsSlash();
				timeAttackStart = 0;
				IsSlash = false;
				SetState(ALADDIN_STATE_LOOKING_UP);
			}
		}
		else if (IsJump)
		{
			if (nx > 0)
			{
				sword->SetState(SWORD_STATE_JUMP_RIGHT);
				sword->SetPosition(x + ALADDIN_BBOX_WIDTH, y);
			}
			else {
				sword->SetState(SWORD_STATE_JUMP_LEFT);
				sword->SetPosition(x, y);
			}
			if (now - timeAttackStart >= ALADDIN_JUMP_ENABLE_SWORD_TIME)
			{
				if (!sword->IsFighting())
				{
					sword->SetEnable(true);
					sword->SetFighting(true);
				}
			}
			if (now - timeAttackStart > ALADDIN_JUMP_SLASH_TIME)
			{
				ResetAnimationsJump();
				timeAttackStart = 0;
				IsSlash = false;
				IsJump = false;
				SetState(ALADDIN_STATE_IDLE);
			}
		}
		else if (vx != 0)
		{
			if (now - timeAttackStart >= ALADDIN_RUN_ENABLE_SWORD_TIME)
			{
				if (!sword->IsFighting())
				{
					sword->SetEnable(true);
					sword->SetFighting(true);
				}
			}
			if (now - timeAttackStart > ALADDIN_RUN_SLASH_TIME)
			{
				ResetAnimationsSlash();
				timeAttackStart = 0;
				IsSlash = false;
				SetState(ALADDIN_STATE_WALKING_RIGHT);
			}
		}
		else {

			if (nx > 0)
			{
				sword->SetState(SWORD_STATE_RIGHT);
				sword->SetPosition(x + ALADDIN_BBOX_WIDTH, y -8);
			}
			else {
				sword->SetState(SWORD_STATE_LEFT);
				sword->SetPosition(x, y - 8);
			}
			if (now - timeAttackStart >= ALADDIN_ENABLE_SWORD_TIME)
			{
				if (!sword->IsFighting())
				{
					sword->SetEnable(true);
					sword->SetFighting(true);
				}
			}
			if (now - timeAttackStart > ALADDIN_ATTACK_TIME)
			{
				ResetAnimationsSlash();
				timeAttackStart = 0;
				IsSlash = false;
				if (IsJump) {
				}
				else {
					SetState(ALADDIN_STATE_IDLE);
				}
			}
		}		
	}
	else {
		sword->SetEnable(false);
		sword->SetFighting(false);
	}

	if(IsThrow)
	{
		if (IsSit)
		{
			if (now - timeThrowStart > ALADDIN_SIT_THROW_TIME)
			{
				throwApple->SetEnable(true);
				if (nx > 0)
				{
					throwApple->SetState(THROW_APPLE_STATE_RIGHT);
					throwApple->SetPosition(x + ALADDIN_BBOX_WIDTH + 3, y - 3);
				}
				else {
					throwApple->SetState(THROW_APPLE_STATE_LEFT);
					throwApple->SetPosition(x - 3, y - 3);
				}

				ResetAnimationsThrow();
				timeThrowStart = 0;
				IsThrow = false;
				SetState(ALADDIN_STATE_SIT_DOWN);
			}
		}
		else if (IsJump)
		{
			if (now - timeThrowStart > ALADDIN_JUMP_THROW_TIME)
			{
				throwApple->SetEnable(true);
				if (nx > 0)
				{
					throwApple->SetState(THROW_APPLE_STATE_RIGHT);
					throwApple->SetPosition(x + ALADDIN_BBOX_WIDTH + 3, y);
				}
				else {
					throwApple->SetState(THROW_APPLE_STATE_LEFT);
					throwApple->SetPosition(x - 3, y);
				}
				
				ResetAnimationsThrow();
				timeThrowStart = 0;
				IsThrow = false;
				IsJump = false;
				SetState(ALADDIN_STATE_IDLE);
			}
		}
		else if (vx > 0)
		{
			if (now - timeThrowStart > ALADDIN_RUN_THROW_TIME)
			{
				throwApple->SetEnable(true);
				if (nx > 0)
				{
					throwApple->SetState(THROW_APPLE_STATE_RIGHT);
					throwApple->SetPosition(x + ALADDIN_BBOX_WIDTH + 3, y);
				}
				else {
					throwApple->SetState(THROW_APPLE_STATE_LEFT);
					throwApple->SetPosition(x - 3, y);
				}
				ResetAnimationsThrow();
				timeThrowStart = 0;
				IsThrow = false;
				SetState(ALADDIN_STATE_IDLE);
			}
		}
		else
		{
			if (now - timeThrowStart > ALADDIN_THROW_TIME)
			{
				throwApple->SetEnable(true);
				if (nx > 0)
				{
					throwApple->SetState(THROW_APPLE_STATE_RIGHT);
					throwApple->SetPosition(x + ALADDIN_BBOX_WIDTH + 3, y);
				}
				else {
					throwApple->SetState(THROW_APPLE_STATE_LEFT);
					throwApple->SetPosition(x - 3, y);
				}

				ResetAnimationsThrow();
				timeThrowStart = 0;
				IsThrow = false;
				SetState(ALADDIN_STATE_IDLE);
			}
		}
	}

	//if (IsSlash == true && IsSit == true)
	//{
	//	if (now - timeStandStart > ALADDIN_STAND_TIME)
	//	{
	//		ResetAnimationsSlash();
	//		timeSittingSlashStart = 0;
	//		IsSlash = false;
	//		IsSit = false;
	//		SetState(ALADDIN_STATE_IDLE);
	//	}
	//}

	//if (IsStand)
	//{
	//	if (GetTickCount() - timeStandStart > ALADDIN_STAND_TIME)
	//	{
	//		ResetAnimationIdle();
	//		timeStandStart = 0;
	//		IsStand = false;
	//		SetState(ALADDIN_STATE_IDLE);
	//	}
	//}

	

	if (dy == 0)
	{
		IsJump = false;
		IsGround = true;
	}

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != ALADDIN_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	 // reset untouchable timer if untouchable time has passed
	if (now - untouchable_start > ALADDIN_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	if (IsHurt) {
		if (GetTickCount() - timeHurtableStart > ALADDIN_HURTABLE_TIME)
		{
			timeHurtableStart = 0;
			hurtable = 0;
			IsHurt = false;
		}
	}

	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Trap*>(coObjects->at(i)))
		{
			Trap* trap = dynamic_cast<Trap*>(coObjects->at(i));
			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			trap->GetBoundingBox(l2, t2, r2, b2);
			if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
				if (untouchable == 0)
				{
					if (trap->IsEnable())
					{
						if (hp > 0)
						{
							this->hp -= trap->GetDamage();
							StartUntouchable();
							StartHurting();
							SetState(ALADDIN_STATE_BE_ATTACKED);
							trap->SetEnable(false);
						}
						/*if (hp > 0)
						{
							this->hp -= trap->GetDamage();
							StartUntouchable();
							StartHurting();
							SetState(ALADDIN_STATE_BE_ATTACKED);
							trap->SetEnable(false);
						}*/
						//else
						//	SetState(ALADDIN_STATE_DIE);
					}
				}
			}
		}
		else if (dynamic_cast<WreckingBall*>(coObjects->at(i)))
		{
			WreckingBall* ball = dynamic_cast<WreckingBall*>(coObjects->at(i));
			float l1, t1, r1, b1, l2, t2, r2, b2;
			GetBoundingBox(l1, t1, r1, b1);
			ball->GetBoundingBox(l2, t2, r2, b2);
			if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
				if (untouchable == 0)
				{
					if (ball->IsEnable())
					{
						if (hp > 0)
						{
							this->hp -= ball->GetDamage();
							StartUntouchable();
							StartHurting();
							SetState(ALADDIN_STATE_BE_ATTACKED);
							ball->SetEnable(false);
						}
						/*if (hp > 0)
						{
							this->hp -= trap->GetDamage();
							StartUntouchable();
							StartHurting();
							SetState(ALADDIN_STATE_BE_ATTACKED);
							ball->SetEnable(false);
						}*/
						//else
						//	SetState(ALADDIN_STATE_DIE);
					}
				}
			}
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

		// block 
		x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty * dy + ny * 0.4f;

		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;

		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<Trap *>(e->obj))
			{
				Trap* trap = dynamic_cast<Trap*>(e->obj);

				if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (trap->IsEnable())
						{
							if (hp > 0)
							{
								this->hp -= trap->GetDamage();
								StartUntouchable();
								StartHurting();
								SetState(ALADDIN_STATE_BE_ATTACKED);
								trap->SetEnable(false);
							}
							/*if (hp > 0)
							{
								this->hp -= trap->GetDamage();
								StartUntouchable();
								StartHurting();
								SetState(ALADDIN_STATE_BE_ATTACKED);
								trap->SetEnable(false);
							}*/
							//else
							//	SetState(ALADDIN_STATE_DIE);
						}
					}
				}
			}
			else if (dynamic_cast<WreckingBall*>(e->obj))
			{
				WreckingBall* ball = dynamic_cast<WreckingBall*>(e->obj);

				if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (ball->IsEnable())
						{
							if (hp > 0)
							{
								this->hp -= ball->GetDamage();
								StartUntouchable();
								StartHurting();
								SetState(ALADDIN_STATE_BE_ATTACKED);
								ball->SetEnable(false);
							}
							/*if (hp > 0)
							{
								this->hp -= trap->GetDamage();
								StartUntouchable();
								StartHurting();
								SetState(ALADDIN_STATE_BE_ATTACKED);
								ball->SetEnable(false);
							}*/
							//else
							//	SetState(ALADDIN_STATE_DIE);
						}
					}
				}
			}
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}


void Aladdin::Render()
{
	DWORD now = GetTickCount();
	float posX = x, posY = y;
	int ani;
	if (state == ALADDIN_STATE_DIE)
		ani = ALADDIN_ANI_DIE;
	else
	{
		if (vx == 0)
		{
			DWORD dt = now - timeIdleStart;
			if (nx > 0)
			{
				ani = ALADDIN_ANI_IDLE_RIGHT;
				
				if (dt >= ALADDIN_LOOKAROUND_TIME && dt < ALADDIN_STAND_TIME)
				{		
					posY = y - 3;
					ani = ALADDIN_ANI_LOOK_AROUND_RIGHT;
					
				}
				else if(dt > ALADDIN_STAND_TIME)
				{
					posY = y - 25;
					ani = ALADDIN_ANI_STANDING_RIGHT;	
				}
			}
			else
			{
				ani = ALADDIN_ANI_IDLE_LEFT;
				if (dt >= ALADDIN_LOOKAROUND_TIME && dt < ALADDIN_STAND_TIME)
				{
					posY = y - 3;
					ani = ALADDIN_ANI_LOOK_AROUND_LEFT;

				}
				else if(dt > ALADDIN_STAND_TIME)
				{
					posY = y - 25;
					ani = ALADDIN_ANI_STANDING_LEFT;
				}
			}
		}
		else if (vx > 0) 
		{
			posY = y - 7;
			ani = ALADDIN_ANI_WALKING_RIGHT;
		}	
		else
		{
			posY = y - 7;
			ani = ALADDIN_ANI_WALKING_LEFT;
		}

		if (IsSit)
		{
			if (IsSlash)
			{
				if (nx > 0)
				{
					ani = ALADDIN_ANI_SITTING_SLASH_RIGHT;
				}
				else {
					ani = ALADDIN_ANI_SITTING_SLASH_LEFT;
				}
				posY = y + 17;
			}
			else if (IsJump == true)
			{
				if (nx > 0)
					ani = ALADDIN_ANI_JUMPING_RIGHT;
				else
					ani = ALADDIN_ANI_JUMPING_LEFT;
			}
			else {
				posY = y;
				if (nx > 0)
				{
					ani = ALADDIN_ANI_SIT_DOWN_RIGHT;
				}
				else
					ani = ALADDIN_ANI_SIT_DOWN_LEFT;
			}
		}
		else {
			if (IsSlash)
			{
				if (nx > 0) 
				{
					if (vx > 0)
					{
						posY = y - 8;
						ani = ALADDIN_ANI_RUN_SLASH_RIGHT;
					}
					else
					{ 
						ani = ALADDIN_ANI_STANDING_SLASH_RIGHT;
						posY = y - 23;
					}					
				}
				else
				{
					if (vx < 0)
					{
						posY = y - 8;
						ani = ALADDIN_ANI_RUN_SLASH_LEFT;
					}
					else
					{
						ani = ALADDIN_ANI_STANDING_SLASH_LEFT;
						posY = y - 23;
					}
				}				
			}
		}
		if (IsJump)
		{
			if (nx > 0) 
			{
				if (IsSlash)
				{
					ani = ALADDIN_ANI_JUMPING_SLASH_RIGHT;
				}
				else
				{
					if (vx > 0)
						ani = ALADDIN_ANI_RUN_JUMP_RIGHT;
					else
						ani = ALADDIN_ANI_JUMPING_RIGHT;
				}	
			}
			else
			{
				if (IsSlash)
				{
					ani = ALADDIN_ANI_JUMPING_SLASH_LEFT;
				}
				else
				{
					if (vx < 0)
						ani = ALADDIN_ANI_RUN_JUMP_LEFT;
					else
						ani = ALADDIN_ANI_JUMPING_LEFT;
				}
			}
		}
		if (IsLookingUp)
		{
			if (IsSlash)
			{
				posY = y - 32;
				if (nx > 0)
					ani = ALADDIN_ANI_LOOKING_UP_SLASH_RIGHT;
				else
					ani = ALADDIN_ANI_LOOKING_UP_SLASH_LEFT;
			}
			else
			{
				posY = y - 8;
				if (nx > 0)
					ani = ALADDIN_ANI_LOOKING_UP_RIGHT;

				else
					ani = ALADDIN_ANI_LOOKING_UP_LEFT;
			}
		}
		if (IsThrow)
		{
			if (IsSit)
			{
				posY = y + 3;
				if (nx > 0)
					ani = ALADDIN_ANI_SITTING_THROW_APPLE_RIGHT;
				else
					ani = ALADDIN_ANI_SITTING_THROW_APPLE_LEFT;
			}
			else if (IsJump)
			{
				if (nx > 0)
					ani = ALADDIN_ANI_JUMPING_THROW_APPLE_RIGHT;
				else
					ani = ALADDIN_ANI_JUMPING_THROW_APPLE_LEFT;
			}
			else
			{				
				if (nx > 0)
				{
					if (vx > 0)
					{
						ani = ALADDIN_ANI_RUN_THROW_RIGHT;
						posY = y - 10;
					}
					else
					{
						ani = ALADDIN_ANI_THROW_APPLE_RIGHT;
						posY = y - 10;
					}
				}					
				else
				{
					if (vx < 0)
					{
						ani = ALADDIN_ANI_RUN_THROW_LEFT;
						posY = y - 10;
					}
					else
					{
						ani = ALADDIN_ANI_THROW_APPLE_LEFT;
						posY = y - 10;
					}
				}
			}
		}
		if (IsHurt) {
			if (nx > 0)
			{
				ani = ALADDIN_ANI_BE_ATTACKED_RIGHT;
			}
			else 
			{
				ani = ALADDIN_ANI_BE_ATTACKED_LEFT;
			}
		}
	}
	int alpha = 255;
	if (untouchable) alpha = 128;

	animations[ani]->Render(posX, posY, alpha);

	RenderBoundingBox();

	throwApple->Render();

	//render bouding box sword for test
	sword->Render();
}

void Aladdin::SetState(int state)
{
	CGameObject::SetState(state);
	DWORD currentTime = GetTickCount();
	switch (state)
	{
	case ALADDIN_STATE_WALKING_RIGHT:
		vx = ALADDIN_WALKING_SPEED;
		nx = 1;
		break;
	case ALADDIN_STATE_WALKING_LEFT:
		vx = -ALADDIN_WALKING_SPEED;
		nx = -1;
		break;
	case ALADDIN_STATE_JUMP:
		//IsSit = false;
		IsJump = true;
		IsGround = false;
		vy = -ALADDIN_JUMP_SPEED_Y;
	case ALADDIN_STATE_IDLE:
		IsSit = false;
		vx = 0;
		if (timeIdleStart == 0)
		{
			timeIdleStart = currentTime;
		}
		break;
	case ALADDIN_STATE_DIE:
		vy = -ALADDIN_DIE_DEFLECT_SPEED;
		break;
	//case ALADDIN_STATE_STANDING:
	//	vx = 0;
	//	IsStand = true;
	//	timeStandStart = currentTime;
	//	break;
	case ALADDIN_STATE_SIT_DOWN:
		vx = 0;
		IsSit = true;
		timeSitStart = currentTime;
		break;
	case ALADDIN_STATE_STANDING_SLASH:
		vx = 0;
		IsSlash = true;
		timeAttackStart = currentTime;
		break;
	case ALADDIN_STATE_SITTING_SLASH:
		vx = 0;
		IsSit = true;
		IsSlash = true;
		if (timeSitStart == 0)
		{
			timeSitStart = currentTime;
		}
		timeAttackStart = currentTime;
		break;
	case ALADDIN_STATE_LOOKING_UP:
		vx = 0;
		IsLookingUp = true;
		if (timeLookUpStart == 0)
		{
			timeLookUpStart = currentTime;
		}
		break;
	case ALADDIN_STATE_LOOKING_UP_SLASH:
		vx = 0;
		IsLookingUp = true;
		IsSlash = true;
		if (timeLookUpStart == 0)
		{
			timeLookUpStart = currentTime;
		}
		timeAttackStart = currentTime;
		break;
	case ALADDIN_STATE_THROW_APPLE:
		vx = 0;
		IsThrow = true;
		if (timeThrowStart == 0)
		{
			timeThrowStart = currentTime;
		}
		break;
	case ALADDIN_STATE_SITTING_THROW_APPLE:
		vx = 0;
		IsSit = true;
		IsThrow = true;		
		if (timeSitStart == 0)
		{
			timeSitStart = currentTime;
		}
		timeThrowStart = currentTime;
		break;
	case ALADDIN_STATE_RUN_JUMP:
		vx = ALADDIN_WALKING_SPEED;
		nx = 1;
		vy = -ALADDIN_JUMP_SPEED_Y;
		IsJump = true;
		IsGround = false;		
		if (timeRunJumpStart == 0)
		{
			timeRunJumpStart = currentTime;
		}
		break;
	case ALADDIN_STATE_RUN_SLASH:
		vx = ALADDIN_WALKING_SPEED;
		nx = 1;
		IsSlash = true;
		if (timeAttackStart == 0)
		{
			timeAttackStart == currentTime;
		}
		break;
	case ALADDIN_STATE_RUN_THROW:
		vx = ALADDIN_WALKING_SPEED;
		nx = 1;
		IsThrow = true;
		if (timeThrowStart == 0)
		{
			timeThrowStart == currentTime;
		}
		break;
	case ALADDIN_STATE_JUMPING_SLASH:
		nx = 1;
		vy = -ALADDIN_JUMP_SPEED_Y;
		IsJump = true;
		IsSlash = true;
		IsGround = false;
		if (timeJumpSlashStart == 0)
		{
			timeJumpSlashStart = 0;
		}
		break;
	case ALADDIN_STATE_JUMPING_THROW_APPLE:
		nx = 1;
		vy = -ALADDIN_JUMP_SPEED_Y;
		IsJump = true;
		IsThrow = true;
		if (timeJumpThrowStart == 0)
		{
			timeJumpThrowStart = 0;
		}
		break;
	case ALADDIN_STATE_BE_ATTACKED:
		IsGround = false;
		/*if (nx > 0)
		{
			vx = -0.1;
		}
		if (nx < 0)
		{
			vx = 0.1;
		}*/
		//if (dy <= 0 || vy >= 0 || dy > 0)
		//	vy = -0.4;
		break;
	}
}

void Aladdin::ResetAnimationsSlash()
{
	resetAni(ALADDIN_ANI_STANDING_SLASH_LEFT);
	resetAni(ALADDIN_ANI_STANDING_SLASH_RIGHT);

	resetAni(ALADDIN_ANI_SITTING_SLASH_LEFT);
	resetAni(ALADDIN_ANI_SITTING_SLASH_RIGHT);

	resetAni(ALADDIN_ANI_LOOKING_UP_SLASH_LEFT);
	resetAni(ALADDIN_ANI_LOOKING_UP_SLASH_RIGHT);

	resetAni(ALADDIN_ANI_RUN_SLASH_LEFT);
	resetAni(ALADDIN_ANI_RUN_SLASH_RIGHT);
}

void Aladdin::ResetAnimationsSitDown()
{
	resetAni(ALADDIN_ANI_SIT_DOWN_RIGHT);
	resetAni(ALADDIN_ANI_SIT_DOWN_LEFT);
}

void Aladdin::ResetAnimationsLookUp()
{
	resetAni(ALADDIN_ANI_LOOKING_UP_RIGHT);
	resetAni(ALADDIN_ANI_LOOKING_UP_LEFT);
}

void Aladdin::ResetAnimationIdle()
{
	resetAni(ALADDIN_ANI_LOOK_AROUND_LEFT);
	resetAni(ALADDIN_ANI_LOOK_AROUND_RIGHT);

	resetAni(ALADDIN_ANI_STANDING_LEFT);
	resetAni(ALADDIN_ANI_STANDING_RIGHT);
}

void Aladdin::ResetAnimationsThrow()
{
	resetAni(ALADDIN_ANI_THROW_APPLE_RIGHT);
	resetAni(ALADDIN_ANI_THROW_APPLE_LEFT);

	resetAni(ALADDIN_ANI_SITTING_THROW_APPLE_RIGHT);
	resetAni(ALADDIN_ANI_SITTING_THROW_APPLE_LEFT);

	resetAni(ALADDIN_ANI_RUN_THROW_LEFT);
	resetAni(ALADDIN_ANI_RUN_THROW_RIGHT);
}

void Aladdin::ResetAnimationsJump()
{
	resetAni(ALADDIN_ANI_RUN_JUMP_RIGHT);
	resetAni(ALADDIN_ANI_RUN_JUMP_LEFT);

	resetAni(ALADDIN_ANI_JUMPING_SLASH_RIGHT);
	resetAni(ALADDIN_ANI_JUMPING_SLASH_LEFT);

	resetAni(ALADDIN_ANI_JUMPING_THROW_APPLE_RIGHT);
	resetAni(ALADDIN_ANI_JUMPING_THROW_APPLE_LEFT);
}

void Aladdin::ResetAllAnimation()
{
	ResetAnimationIdle();
	ResetAnimationsSitDown();
	ResetAnimationsLookUp();
	ResetAnimationsSlash();
	ResetAnimationsThrow();
	ResetAnimationsJump();
}


//void Aladdin::ResetAnimation()
//{
//	resetAni(ALADDIN_ANI_STANDING_SLASH_LEFT);
//	resetAni(ALADDIN_ANI_STANDING_SLASH_RIGHT);
//}
//
//void Aladdin::ResetAnimation()
//{
//	resetAni(ALADDIN_ANI_LOOKING_UP_RIGHT);
//	resetAni(ALADDIN_ANI_LOOKING_UP_LEFT);
//}

void Aladdin::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + ALADDIN_BBOX_WIDTH;
	bottom = top + ALADDIN_BBOX_HEIGHT;
}

Aladdin::Aladdin() : CGameObject()
{
	width = ALADDIN_BBOX_WIDTH;
	height = ALADDIN_BBOX_HEIGHT;

	IsJump = false;
	IsSit = false;
	IsSlash = false;
	IsLookingUp = false;
	IsStand = false;
	IsThrow = false;
	IsGround = false;
	untouchable = 0;

	throwApple = new ThrowApples();
	sword = new Sword();

	level = 0;
	untouchable = 0;
	untouchable_start = 0;
	timeAttackStart = 0;
	timeSittingSlashStart = 0;
	timeStandStart = 0;
	timeIdleStart = 0;
	timeSitStart = 0;
	timeLookUpStart = 0;
	timeThrowStart = 0;
	timeRunJumpStart = 0;
	timeJumpSlashStart = 0;
	timeJumpThrowStart = 0;

	hp = ALADDIN_MAX_HP;

	AddAnimation(100);		// idle right
	AddAnimation(101);		//idle left

	AddAnimation(104);		// sitting down right
	AddAnimation(105);		// sitting down left

	AddAnimation(106);		// looking up right
	AddAnimation(107);		// looking up right

	AddAnimation(102);		// standing right
	AddAnimation(103);		// standing left
	
	AddAnimation(110);		// walking right
	AddAnimation(111);		// walking left
	AddAnimation(112);		// stop right
	AddAnimation(113);		// stop left

	AddAnimation(120);		// jump right
	AddAnimation(121);		// jump left
	AddAnimation(122);		// run jump right
	AddAnimation(123);		// run jump left
	AddAnimation(124);		// run slash right
	AddAnimation(125);		// run slash left
	AddAnimation(126);		// run throw right
	AddAnimation(127);		// run throw left

	AddAnimation(131);		// standing slash right
	AddAnimation(132);		// standing slash left
	AddAnimation(133);		// sitting slash right
	AddAnimation(134);		// sitting slash left
	AddAnimation(135);		// looking up slash right
	AddAnimation(136);		// looking up slash left
	AddAnimation(137);		// jumping slash right
	AddAnimation(138);		// jumping slash left

	AddAnimation(140);		//throw apple right
	AddAnimation(141);		//throw apple left
	AddAnimation(142);		//sitting throw apple right
	AddAnimation(143);		//sitting throw apple left
	AddAnimation(144);		//jumping throw apple right
	AddAnimation(145);		//jumping throw apple left

	AddAnimation(150);		//climbing
	AddAnimation(151);		//falling after climbing
	AddAnimation(152);		//climbing slash right
	AddAnimation(153);		//climbing slash left
	AddAnimation(154);		//climbing throw apple right
	AddAnimation(155);		//climbing throw apple left

	AddAnimation(161);		//ride the carpet right
	AddAnimation(162);		//ride the carpet left

	AddAnimation(163);		//look arounf right
	AddAnimation(164);		//look around left

	AddAnimation(165);		//be attacked right
	AddAnimation(166);		//be attacked left

}

Aladdin::~Aladdin()
{

}

