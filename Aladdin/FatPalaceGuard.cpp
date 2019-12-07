#include "FatPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void FatPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt);

}

void FatPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void FatPalaceGuard::SetState(int state)
{
	CGameObject::SetState(state);
}

void FatPalaceGuard::Render()
{

}

FatPalaceGuard::FatPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH_WAIT;
	height = GUARD_BBOX_HEIGHT;

	wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	HP = GUARD_MAX_HP;

	AddAnimation(221);		// idle right
	AddAnimation(222);		// idle left

	AddAnimation(223);		// walk right
	AddAnimation(224);		// walk left

	AddAnimation(225);		// attack right
	AddAnimation(226);		// attack left

	AddAnimation(227);		// suprise right
	AddAnimation(228);		// suprise left

}

FatPalaceGuard::~FatPalaceGuard()
{

}