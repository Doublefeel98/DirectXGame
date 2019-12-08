#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class ThrowApples : public CGameObject
{
private:
	bool isEnable;
	int damage;
public:
	ThrowApples();
	~ThrowApples();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void SetState(int state);
	void SetEnable(bool isEnable) { this->isEnable = isEnable; }
	bool IsEnable() { return this->isEnable; }
};
