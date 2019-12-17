#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Penny : public CGameObject
{
private:
	bool isAte;
public:
	Penny();
	~Penny();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	void setAte(bool ate) { isAte = ate; }
	bool IsAte() { return isAte; }
};
