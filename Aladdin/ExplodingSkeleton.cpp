#include "ExplodingSkeleton.h"
#include <algorithm>
#include "../Framework/debug.h"

#include "../Framework/Game.h"

void ExplodingSkeleton::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt);

}

void ExplodingSkeleton::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	//if (animations[SKELETON_ANI_WAIT]->currentFrame >= 2 && animations[SKELETON_ANI_WAIT]->currentFrame <= 8) {
	//	left = x;
	//	top = y + 10;
	//	right = left + SKELETON_BBOX_WIDTH_WIDE;
	//	bottom = top + SKELETON_BBOX_HEIGHT;
	//}
	//else {
	//	left = x + 25;
	//	top = y + 10;
	//	right = left + SKELETON_BBOX_WIDTH;
	//	bottom = top + SKELETON_BBOX_HEIGHT;
	//}

	left = x;
	top = y;
	right = x + SKELETON_BBOX_WIDTH;

	if (state == CENEMY_STATE_DIE)
		bottom = y + 0;
	else
		bottom = y + SKELETON_BBOX_HEIGHT;
}
void ExplodingSkeleton::SetState(int state)
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
void ExplodingSkeleton::Render() 
{
	animations[SKELETON_ANI_STAND_UP_RIGHT]->Render(x, y, 255);
	RenderBoundingBox();
	
}

ExplodingSkeleton::ExplodingSkeleton() : CEnemy()
{
	width = SKELETON_BBOX_WIDTH;
	height = SKELETON_BBOX_HEIGHT;

	HP = SKELETON_MAX_HP;

	AddAnimation(240);		// wait right
	AddAnimation(241);		// wait left

	AddAnimation(242);		// stand up right
	AddAnimation(243);		// stand up left
}

ExplodingSkeleton::~ExplodingSkeleton() {

}