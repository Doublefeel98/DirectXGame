#include "Statue.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void Statue::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt, coObject);

}

void Statue::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void Statue::SetState(int state)
{
	CGameObject::SetState(state);
}

void Statue::Render()
{

}

Statue::Statue() : CGameObject()
{
	width = STATUE_BBOX_WIDTH;
	height = STATUE_BBOX_HEIGHT;

	AddAnimation(320);		// fly right
	AddAnimation(321);		// fly left

	AddAnimation(322);		// die right
	AddAnimation(323);		// die left
}

Statue::~Statue()
{

}