#include "Jafar.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void Jafar::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt, coObject);

}

void Jafar::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

}

void Jafar::SetState(int state)
{
	CGameObject::SetState(state);
}

void Jafar::Render()
{

}

Jafar::Jafar() : CGameObject()
{
	width = JAFAR_BBOX_WIDTH;
	height = JAFAR_BBOX_HEIGHT;

	AddAnimation(700);		// idle right
	AddAnimation(701);		// idle left
				 
	AddAnimation(702);		// attack right
	AddAnimation(703);		// attack left

	AddAnimation(704);		// fire right
	AddAnimation(705);		// fire left
}

Jafar::~Jafar()
{

}