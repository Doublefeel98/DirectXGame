#include "NormalPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/Scene.h"

void NormalPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{

	if (!isDead) {
		CEnemy::Update(dt, coObject);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		nx = this->x >= alaPosition.x ? -1 : 1;

		if (state == NGUARD_STATE_WALK)
		{
			x += dx;
			y += dy;
		}
		else if (state == NGUARD_STATE_SURPRISE)
		{
			if (GetTickCount() - timeBeAttack > 700)
			{
				state = NGUARD_STATE_SLASH;
				timeBeAttack = GetTickCount();
				resetAniSlash();
				resetAniStab();
			}
			return;
		}


		if (abs(this->x - alaPosition.x) < GUARD_DELTA_X && abs(this->y - alaPosition.y) < ALADDIN_BBOX_HEIGHT)
		{
			if (!init)
			{
				init = true;
				startX = this->x;
				startY = this->y;

				SetState(NGUARD_STATE_WALK);
			}
			else if (abs(startX - this->x) < GUARD_DELTA_WALK_X) {
				SetState(NGUARD_STATE_WALK);
			}
			else {
				DWORD now = GetTickCount();
				guardSword->SetEnable(false);
				guardSword->SetFighting(false);
				if (nx > 0)
				{
					guardSword->SetState(GUARD_SWORD_SLASH_STATE_RIGHT);
					guardSword->SetPosition(x + GUARD_BBOX_WIDTH + 17, y + 10);
				}
				else {
					guardSword->SetState(GUARD_SWORD_SLASH_STATE_LEFT);
					guardSword->SetPosition(x - 17, y + 10);
				}
				if (now - timeSlash >= 300 && timeSlash != 0)
				{
					if (!guardSword->IsFighting())
					{
						guardSword->SetEnable(true);
						guardSword->SetFighting(true);
						if(nx > 0)
							guardSword->SetPosition(x + GUARD_BBOX_WIDTH + 17, y + 10);
						else
							guardSword->SetPosition(x - 17, y + 10);
					}
				}
				else if (now - timeStab >= 100 && timeStab != 0)
				{
					if (!guardSword->IsFighting())
					{
						guardSword->SetEnable(true);
						guardSword->SetFighting(true);
						if (nx > 0)
							guardSword->SetPosition(x + GUARD_BBOX_WIDTH + 17, y + 10);
						else
							guardSword->SetPosition(x - 17, y + 10);					
					}
				}
				if (now - timeStab > 600 && timeStab != 0)
				{
					guardSword->SetEnable(false);
				}
				else if (now - timeSlash > 400 && timeSlash != 0)
				{
					guardSword->SetEnable(false);
				}

				if (timeSlash == 0 && timeStab == 0)
				{
					timeSlash = now;
					SetState(NGUARD_STATE_SLASH);
				}
				else if (now - timeSlash > 1090 && timeSlash != 0)
				{
					SetState(NGUARD_STATE_STAB);
					timeSlash = 0;
					timeStab = now;
					resetAniSlash();
				}
				else if (now - timeStab > 600 && timeStab != 0) {
					timeStab = 0;
					resetAniStab();
				}
			}
		}
		else {
			SetState(NGUARD_STATE_WAIT);
		}
	}
	guardSword->Update(dt, coObject);
}

void NormalPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	int posX = x, posY = y;
	if (isDead) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		int boxWidth = GUARD_BBOX_WIDTH;
		int boxHeight = GUARD_BBOX_HEIGHT;
		left = x;
		right = left + boxWidth;
		top = y;
		bottom = top + boxHeight;
		//switch (state)
		//{
		//case NGUARD_STATE_WALK:

		//	break;
		//case NGUARD_STATE_WAIT:

		//	break;
		//case NGUARD_STATE_STAB:
		//	if (nx <= 0){
		//		posX = x + 30;
		//	}				
		//	boxWidth = GUARD_STAB_BBOX_WIDTH;
		//	boxHeight = GUARD_STAB_BBOX_HEIGHT;
		//	break;
		//case NGUARD_STATE_SLASH:
		//	if (nx <= 0) {
		//		posX = x + 28;
		//	}
		//	boxWidth = GUARD_SLASH_BBOX_WIDTH;
		//	boxHeight = GUARD_SLASH_BBOX_HEIGHT;
		//	break;
		//case NGUARD_STATE_SURPRISE:
		//	boxWidth = GUARD_SURSPRISE_BBOX_WIDTH;
		//	boxHeight = GUARD_SURPRISE_BBOX_HEIGHT;
		//	break;
		//default:
		//	break;
		//}
		//if (ani == -1)
		//{
		//	left = posX;
		//	top = posY;
		//	right = left + boxWidth;
		//	bottom = top + boxHeight;
		//}
		//else {
		//	int currentFrame = animations[ani]->getCurrentFrame();
		//	if (currentFrame != -1)
		//	{
		//		left = posX + animations[ani]->frames[currentFrame]->GetSprite()->dx;
		//		top = posY + animations[ani]->frames[currentFrame]->GetSprite()->dy;
		//	}
		//	else {
		//		left = posX;
		//		top = posY;
		//	}
			//right = left + boxWidth;
			//bottom = top + boxHeight;

		//}
	}
}

void NormalPalaceGuard::SetState(int stateNew)
{
	CEnemy::SetState(stateNew);
	switch (stateNew)
	{
	case NGUARD_STATE_IDLE:
		vx = 0;
		break;
	case NGUARD_STATE_WALK:
		if (nx > 0)
		{
			vx = GUARD_WALKING_SPEED;
		}
		else {
			vx = -GUARD_WALKING_SPEED;
		}
		break;
	case NGUARD_STATE_WAIT:
		vx = 0;
		break;
	case NGUARD_STATE_STAB:
		vx = 0;
		break;
	case NGUARD_STATE_SLASH:
		vx = 0;
		break;
	case NGUARD_STATE_SURPRISE:
		timeBeAttack = GetTickCount();
		vx = 0;
		break;
	default:
		break;
	}
}

void NormalPalaceGuard::Render()
{
	if (!isDead) {
		int posX = x, posY = y;
		switch (state)
		{
		case NGUARD_STATE_IDLE:
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_IDLE_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_IDLE_LEFT;
			}
			break;
		case NGUARD_STATE_WALK:
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_WALK_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_WALK_LEFT;
			}
			break;
		case NGUARD_STATE_WAIT:
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_WAIT_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_WAIT_LEFT;
			}
			break;
		case NGUARD_STATE_STAB:
			posY = y - 19;
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_ATTACK_STAB_LEFT;
			}
			break;
		case NGUARD_STATE_SLASH:
			posY = y - 19;
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT;
			}
			break;
		case NGUARD_STATE_SURPRISE:
			posY = y - 15;
			if (nx > 0)
			{
				ani = NORMAL_GUARD_ANI_SURPRISE_RIGHT;
			}
			else {
				ani = NORMAL_GUARD_ANI_SURPRISE_LEFT;
			}
			break;
		default:
			break;
		}

		animations[ani]->Render(posX, posY);
		RenderBoundingBox();

		guardSword->Render();
	}
}

void NormalPalaceGuard::resetAniSlash()
{
	animations[NORMAL_GUARD_ANI_ATTACK_SLASH_RIGHT]->reset();
	animations[NORMAL_GUARD_ANI_ATTACK_SLASH_LEFT]->reset();
}

void NormalPalaceGuard::resetAniStab()
{
	animations[NORMAL_GUARD_ANI_ATTACK_STAB_RIGHT]->reset();
	animations[NORMAL_GUARD_ANI_ATTACK_STAB_LEFT]->reset();
}

void NormalPalaceGuard::resetAniSurprise()
{
	animations[NORMAL_GUARD_ANI_SURPRISE_RIGHT]->reset();
	animations[NORMAL_GUARD_ANI_SURPRISE_LEFT]->reset();
}

NormalPalaceGuard::NormalPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH;
	height = GUARD_BBOX_HEIGHT;

	//wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	hp = GUARD_MAX_HP;
	state = NGUARD_STATE_IDLE;
	type = OBJECT_NORMAL_PALACE_GUARD;
	finalAni = false;
	timeSlash = 0;
	timeStab = 0;

	guardSword = new GuardSword();

	ani = -1;

	AddAnimation(300);		// idle right
	AddAnimation(301);		// idle left

	AddAnimation(302);		// walk right
	AddAnimation(303);		// walk left

	AddAnimation(304);		// wait right
	AddAnimation(305);		// wait left

	AddAnimation(306);		// attack stab right
	AddAnimation(307);		// attack stab left

	AddAnimation(308);		// attack slash right
	AddAnimation(309);		// attack slash left

	AddAnimation(310);		// surprise right
	AddAnimation(311);		// surprise left
}

NormalPalaceGuard::~NormalPalaceGuard()
{

}