#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class ExplodingSkeleton : public CGameObject
{
private:
	int HP;
public:
	ExplodingSkeleton();
	~ExplodingSkeleton();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};