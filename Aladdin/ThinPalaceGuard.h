#pragma once
#include "../Framework/Enemy.h"
#include "Define.h"
#include "Aladdin.h"
#define LEFT false
#define RIGHT true

class ThinPalaceGuard : public CEnemy
{
private:
	bool finalAni, sound;	// indicate which state a bat object is currently in
	int direction = LEFT;
	float startX, startY;
	bool init;
	DWORD timeAttack;
	DWORD timeBeAttack;
	void resetAniAttack();
	void resetAniSurprise();
	int ani;
public:
	ThinPalaceGuard();
	~ThinPalaceGuard();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void SetState(int state);
};
