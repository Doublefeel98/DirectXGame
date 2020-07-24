#include "BatStartGame.h"

void BatStartGame::Update(DWORD dt)
{
	if (GetTickCount() - time_start > 3990) {
		ani = 1;
	}
}

void BatStartGame::Render()
{
	animation_set->at(ani)->RenderWithoutCamera(184, 104, is_pause_ani);
}

BatStartGame::BatStartGame()
{
	time_start = GetTickCount();
	ani = 0;
	is_pause_ani = false;
}

BatStartGame::~BatStartGame()
{
}

void BatStartGame::ReStart()
{
	ani = 0;
}
