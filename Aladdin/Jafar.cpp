#include "Jafar.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"
#include "Define.h"
#include "Aladdin.h"

void Jafar::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	if (!isDead) {
		CEnemy::Update(dt, coObject);
		D3DXVECTOR3 alaPosition = Aladdin::GetInstance()->GetPosition();

		nx = this->x >= alaPosition.x ? -1 : 1;


	}
}

void Jafar::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + JAFAR_BBOX_WIDTH;
	bottom = top + JAFAR_BBOX_HEIGHT;
}

void Jafar::SetState(int state)
{
	CEnemy::SetState(state);
}

void Jafar::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}

Jafar::Jafar() : CEnemy()
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