#include "Iago.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void Iago::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt, coObject);

}

void Iago::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void Iago::SetState(int state)
{
	CGameObject::SetState(state);
}

void Iago::Render()
{

}

Iago::Iago() : CGameObject()
{
	width = IAGO_BBOX_WIDTH;
	height = IAGO_BBOX_HEIGHT;
}

Iago::~Iago()
{

}