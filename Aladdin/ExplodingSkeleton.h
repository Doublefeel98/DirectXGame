#pragma once
#include "../Framework/Enemy.h"
#include "Define.h"
#include "Bone.h"
class ExplodingSkeleton : public CEnemy
{
private:
	Bone* bones;
	int ani;
public:
	ExplodingSkeleton();
	~ExplodingSkeleton();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};