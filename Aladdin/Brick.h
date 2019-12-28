#pragma once
#include "../Framework/GameObject.h"
#include"Define.h"

class Brick : public CGameObject
{
private:
	bool isDelay, sound;
	DWORD timeStartDelay;
public:
	Brick();
	~Brick();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void setDelay() { this->isDelay = true; }
};