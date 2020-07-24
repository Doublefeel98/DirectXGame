#include "Effect.h"


void Effect::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);

	//LPANIMATION temp = new CAnimation(ani->GetDefaultTime(), ani->IsLoop());
	//temp->SetFrames(ani->getFrames());
	animations.push_back(ani);
}

Effect::Effect()
{
}

Effect::~Effect()
{
}

void Effect::SetAnimationSet(int ani_set_id)
{
	CAnimationSets* animation_sets = CAnimationSets::GetInstance();
	LPANIMATION_SET ani_set = animation_sets->Get(ani_set_id);
	SetAnimationSet(ani_set);
}
