#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
#include "Aladdin.h"
class Star : public CGameObject
{
private:
	Aladdin* aladdin;
	vector<LPGAMEOBJECT> objects;
	int ny;
public:
	Star();
	~Star();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);
};

