#include "NormalPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void NormalPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CEnemy::Update(dt, coObject);
	if (isDead) {
		x = -5;
		y = -5;
		vx = 0;
		vy = 0;
	}
}

void NormalPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + GUARD_BBOX_WIDTH_WAIT;

	if (isDead)
		bottom = y + 0;
	else
		bottom = y + GUARD_BBOX_HEIGHT;
}

void NormalPalaceGuard::SetState(int state)
{
	CEnemy::SetState(state);
}

void NormalPalaceGuard::Render()
{
	if (isEnable)
	{
		animations[NORMAL_GUARD_ANI_WAIT_LEFT]->Render(x, y, 255);
		CEnemy::Render();
		RenderBoundingBox();
	}
}

NormalPalaceGuard::NormalPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH_WAIT;
	height = GUARD_BBOX_HEIGHT;

	wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	hp = GUARD_MAX_HP;

	AddAnimation(211);		// idle right
	AddAnimation(212);		// idle left

	AddAnimation(213);		// walk right
	AddAnimation(214);		// walk left

	AddAnimation(215);		// wait right
	AddAnimation(216);		// wait left

	AddAnimation(217);		// attack stab right
	AddAnimation(218);		// attack stab left

	AddAnimation(219);		// attack slash right
	AddAnimation(220);		// attack slash left

	AddAnimation(221);		// suprise right
	AddAnimation(222);		// suprise left

}

NormalPalaceGuard::~NormalPalaceGuard()
{

}