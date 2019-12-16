#include "FatPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void FatPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CEnemy::Update(dt, coObject);

}

void FatPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void FatPalaceGuard::SetState(int state)
{
	CEnemy::SetState(state);
}

void FatPalaceGuard::Render()
{

}

FatPalaceGuard::FatPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH_WAIT;
	height = GUARD_BBOX_HEIGHT;

	wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	hp = GUARD_MAX_HP;

	AddAnimation(400);		// idle right
	AddAnimation(401);		// idle left

	AddAnimation(402);		// walk right
	AddAnimation(403);		// walk left

	AddAnimation(404);		// attack right
	AddAnimation(405);		// attack left

	AddAnimation(406);		// suprise right
	AddAnimation(407);		// suprise left

}

FatPalaceGuard::~FatPalaceGuard()
{

}