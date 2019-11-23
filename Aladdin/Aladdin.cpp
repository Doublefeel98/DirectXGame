#include "Aladdin.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void Aladdin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	vy += ALADDIN_GRAVITY * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	if (this->GetState() != ALADDIN_STATE_SIT_DOWN) 
	{
		IsSit = false;
		ResetAnimationsSitDown();
	}

	if (this->GetState() != ALADDIN_STATE_STANDING_SLASH)
		IsSlash = false;

	// turn off collision when die 
	if (state != ALADDIN_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	if (IsSlash)
	{
		if (GetTickCount() - timeAttackStart > ALADDIN_ATTACK_TIME)
		{
			ResetAnimationsSlash();
			timeAttackStart = 0;
			IsSlash = false;
			SetState(ALADDIN_STATE_IDLE);
		}
	}

	if (dy == 0)
	{
		IsJump = false;
		IsGround = true;
	}

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount() - untouchable_start > ALADDIN_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
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

		// Collision logic with Goombas
		//for (UINT i = 0; i < coEventsResult.size(); i++)
		//{
		//	LPCOLLISIONEVENT e = coEventsResult[i];

		//	if (dynamic_cast<CGoomba*>(e->obj)) // if e->obj is Goomba 
		//	{
		//		CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

		//		// jump on top >> kill Goomba and deflect a bit 
		//		if (e->ny < 0)
		//		{
		//			if (goomba->GetState() != GOOMBA_STATE_DIE)
		//			{
		//				goomba->SetState(GOOMBA_STATE_DIE);
		//				vy = -MARIO_JUMP_DEFLECT_SPEED;
		//			}
		//		}
		//		else if (e->nx != 0)
		//		{
		//			if (untouchable == 0)
		//			{
		//				if (goomba->GetState() != GOOMBA_STATE_DIE)
		//				{
		//					if (level > MARIO_LEVEL_SMALL)
		//					{
		//						level = MARIO_LEVEL_SMALL;
		//						StartUntouchable();
		//					}
		//					else
		//						SetState(MARIO_STATE_DIE);
		//				}
		//			}
		//		}
		//	}
		//}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

//void Aladdin::Render()
//{
//	int ani;
//	if (state == ALADDIN_STATE_DIE)
//		ani = ALADDIN_ANI_DIE;
//	else
//	{
//		if (vx == 0)
//		{
//			ani = ALADDIN_ANI_IDLE_RIGHT;
//			if (nx > 0) isFlip = false;
//			else isFlip = true;
//			//ani = ALADDIN_ANI_IDLE_STANDING_LEFT;
//			//if (nx > 0) isFlip = false;
//			//else isFlip = true;
//		}
//		else {
//			ani = ALADDIN_ANI_WALKING_RIGHT;
//			if(vx > 0)
//				isFlip = false;
//			else isFlip = true;
//		}
//	}
//
//	int alpha = 255;
//	if (untouchable) alpha = 128;
//	if (isFlip)
//	{
//		animations[ani]->RenderFlipOx(x, y, alpha);
//	}
//	else {
//		animations[ani]->Render(x, y, alpha);
//	}
//	
//	RenderBoundingBox();
//}

void Aladdin::Render()
{
	float posX = x, posY = y;
	int ani;
	if (state == ALADDIN_STATE_DIE)
		ani = ALADDIN_ANI_DIE;
	else
	{
		if (vx == 0)
		{
			if (nx > 0)
				ani = ALADDIN_ANI_IDLE_RIGHT;
			else
				ani = ALADDIN_ANI_IDLE_LEFT;
		}
		else if (vx > 0) {
			posY = y - 7;
			ani = ALADDIN_ANI_WALKING_RIGHT;
		}	
		else
		{
			posY = y - 7;
			ani = ALADDIN_ANI_WALKING_LEFT;
		}
		if (IsSit == true)
		{
			if (nx > 0)
				ani = ALADDIN_ANI_SIT_DOWN_RIGHT;
			else
				ani = ALADDIN_ANI_SIT_DOWN_LEFT;
		}
		if (IsJump == true) {
			if (nx > 0)
				ani = ALADDIN_ANI_JUMPING_RIGHT;
			else
				ani = ALADDIN_ANI_JUMPING_LEFT;
		}
		if (IsSlash == true) {
			if (nx > 0) {
				ani = ALADDIN_ANI_STANDING_SLASH_RIGHT;
			}
			else {
				ani = ALADDIN_ANI_STANDING_SLASH_LEFT;
			}
			posY = y - 23;
		}
	}
	int alpha = 255;
	if (untouchable) alpha = 128;

	animations[ani]->Render(posX, posY, alpha);

	RenderBoundingBox();
}

void Aladdin::SetState(int state)
{
	CGameObject::SetState(state);

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
		IsJump = true;
		IsGround = false;
		vy = -ALADDIN_JUMP_SPEED_Y;
	case ALADDIN_STATE_IDLE:
		vx = 0;
		break;
	case ALADDIN_STATE_DIE:
		vy = -ALADDIN_DIE_DEFLECT_SPEED;
		break;
	case ALADDIN_STATE_STANDING:
		vx = 0;
		break;
	case ALADDIN_STATE_SIT_DOWN:
		vx = 0;
		IsSit = true;
		break;
	case ALADDIN_STATE_STANDING_SLASH:
		vx = 0;
		IsSlash = true;
		timeAttackStart = GetTickCount();
		break;
	}
}

void Aladdin::ResetAnimationsSlash()
{
	resetAni(ALADDIN_ANI_STANDING_SLASH_LEFT);
	resetAni(ALADDIN_ANI_STANDING_SLASH_RIGHT);
}

void Aladdin::ResetAnimationsSitDown()
{
	resetAni(ALADDIN_ANI_SIT_DOWN_RIGHT);
	resetAni(ALADDIN_ANI_SIT_DOWN_LEFT);
}

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
	untouchable = 0;

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
}

Aladdin::~Aladdin()
{

}

