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

	AddAnimation(300);		// idle right
	AddAnimation(301);		// idle left
				 
	AddAnimation(302);		// attack right
	AddAnimation(303);		// attack left

	AddAnimation(304);		// fire right
	AddAnimation(305);		// fire left
}

Jafar::~Jafar()
{

}