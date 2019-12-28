#include "GuardSword.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "../Framework/Enemy.h"
#include "../Framework/debug.h"
#include "Aladdin.h"
GuardSword::GuardSword()
{
	x = -5;
	y = -5;
	width = GUARD_SWORD_STAB_BBOX_WIDTH;
	height = GUARD_SWORD_STAB_BBOX_HEIGHT;
	isEnable = false;
	vx = 0;
	vy = 0;
	damage = 1;
}

GuardSword::~GuardSword()
{

}

void GuardSword::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isEnable) {
		CGameObject::Update(dt);
		Aladdin* aladdin = Aladdin::GetInstance();

		float l1, t1, r1, b1, l2, t2, r2, b2;
		GetBoundingBox(l1, t1, r1, b1);
		aladdin->GetBoundingBox(l2, t2, r2, b2);

		if (CGame::isColliding(l1, t1, r1, b1, l2, t2, r2, b2)) {
				//enemy->GetColliderEffect()->SetEnable(true);
				//aladdin->SetHP(aladdin->GetHP() - this->damage);
				//aladdin->SetState(ALADDIN_STATE_BE_ATTACKED);
				aladdin->StartHurting(damage);
				this->isEnable = false;
		}
	}
	else {
		x = -5;
		y = -5;
	}
}

void GuardSword::Render()
{
	RenderBoundingBox();
}

void GuardSword::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isEnable) {

		left = x;
		top = y;
		switch (state)
		{
		case GUARD_SWORD_SLASH_STATE_LEFT:
			left = x - GUARD_SWORD_SLASH_BBOX_WIDTH;
			right = x;
			bottom = top + GUARD_SWORD_SLASH_BBOX_HEIGHT;
			break;
		case GUARD_SWORD_SLASH_STATE_RIGHT:
			right = left + GUARD_SWORD_SLASH_BBOX_WIDTH;
			bottom = top + GUARD_SWORD_SLASH_BBOX_HEIGHT;
			break;
		case GUARD_SWORD_STAB_STATE_LEFT:
			left = x - GUARD_SWORD_STAB_BBOX_WIDTH;
			right = x;
			bottom = top + GUARD_SWORD_STAB_BBOX_HEIGHT;
			break;
		case GUARD_SWORD_STAB_STATE_RIGHT:
			right = left + GUARD_SWORD_STAB_BBOX_WIDTH;
			bottom = top + GUARD_SWORD_STAB_BBOX_HEIGHT;
			break;
		case TGUARD_SWORD_STATE_LEFT:
			left = x - TGUARD_SWORD_BBOX_WIDTH;
			right = x;
			bottom = top + TGUARD_SWORD_BBOX_HEIGHT;
			break;
		case TGUARD_SWORD_STATE_RIGHT:
			right = left + TGUARD_SWORD_BBOX_WIDTH;
			bottom = top + TGUARD_SWORD_BBOX_HEIGHT;
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

void GuardSword::SetState(int state)
{
	CGameObject::SetState(state);
}
