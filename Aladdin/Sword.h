#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"
class Sword : public CGameObject
{
private:
	bool isEnable;
public:
	Sword();
	~Sword();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);
	void SetEnable(bool isEnable) { this->isEnable = isEnable; }
	bool IsEnable() { return this->isEnable; }
};

