#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

#define TIME_DISPLAY 300

class KeyStartObject : public CGameObject
{
private:
	DWORD timeDisplay;
	CSprite* sprite;
public:
	void Update(DWORD dt);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	KeyStartObject(int width, int height);
	~KeyStartObject();
};

