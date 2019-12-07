#pragma once
#include "../Framework/Enemy.h"
#include "Define.h"

class ThinPalaceGuard : public CEnemy
{
private:
	bool wait, wave, walk, surprise;	// indicate which state a bat object is currently in
	int HP;
public:
	ThinPalaceGuard();
	~ThinPalaceGuard();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
