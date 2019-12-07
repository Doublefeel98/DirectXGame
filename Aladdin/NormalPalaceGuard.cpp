#include "NormalPalaceGuard.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void NormalPalaceGuard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt);

}

void NormalPalaceGuard::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + GUARD_BBOX_WIDTH_WAIT;

	if (state == CENEMY_STATE_DIE)
		bottom = y + 0;
	else
		bottom = y + GUARD_BBOX_HEIGHT;
}

void NormalPalaceGuard::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case CENEMY_STATE_DIE:
		x = -5;
		y = -5;
		vx = 0;
		vy = 0;
		break;
	}
}

void NormalPalaceGuard::Render()
{
	animations[NORMAL_GUARD_ANI_WAIT_LEFT]->Render(x, y, 255);
	RenderBoundingBox();
}

NormalPalaceGuard::NormalPalaceGuard() : CEnemy()
{
	width = GUARD_BBOX_WIDTH_WAIT;
	height = GUARD_BBOX_HEIGHT;

	wait = false; stab = false; wave = false; jump = false; surprise = false; die = true;
	HP = GUARD_MAX_HP;

	AddAnimation(211);		// idle right
	AddAnimation(212);		// idle left

	AddAnimation(213);		// walk right
	AddAnimation(214);		// walk left

	AddAnimation(215);		// wait right
	AddAnimation(216);		// wait left

	AddAnimation(217);		// attack right
	AddAnimation(218);		// attack left

	AddAnimation(219);		// suprise right
	AddAnimation(220);		// suprise left

}

NormalPalaceGuard::~NormalPalaceGuard()
{

}