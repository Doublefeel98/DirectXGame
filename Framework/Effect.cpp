#include "Effect.h"


void Effect::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);

	LPANIMATION temp = new CAnimation(ani->defaultTime, ani->IsLoop);
	temp->frames = ani->frames;
	animations.push_back(temp);
}

Effect::Effect()
{
}

Effect::~Effect()
{
}
