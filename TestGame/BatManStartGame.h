#pragma once
#include "Define.h"
#include "../Framework/GameObject.h"

class BatManStartGame : public CGameObject
{
	CAnimation* getFrame;
	int ani;
public:
	void Update(DWORD dt);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	BatManStartGame();
	~BatManStartGame();
	int GetCurrentFrame();
	void SetAnimation(int ani) { this->ani = ani; }
	int GetAnimation() { return ani; }
};

