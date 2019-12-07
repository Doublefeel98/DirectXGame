#pragma once
#include "../Framework/Enemy.h"
#include "Define.h"

class NormalPalaceGuard : public CEnemy
{
private:
	bool wait, stab, wave, surprise, jump, die;	// indicate which state a bat object is currently in
	int HP;
public:
	NormalPalaceGuard();
	~NormalPalaceGuard();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};

