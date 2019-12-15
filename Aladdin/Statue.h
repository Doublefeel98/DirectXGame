#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Statue : public CGameObject
{
private:

public:
	Statue();
	~Statue();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
