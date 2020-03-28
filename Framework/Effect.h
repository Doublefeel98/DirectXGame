#pragma once
#include "Textures.h"
#include "Sprites.h"
class Effect
{
protected:
	int x, y;
	DWORD timeDelay;
	bool isEnable;
	vector<LPANIMATION> animations;
public:
	virtual void Render() {}
	virtual void Update(DWORD dt) {}
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetEnable(bool IsEnable) { this->isEnable = IsEnable; }
	virtual void AddAnimation(int aniId);
	Effect();
	~Effect();
};

