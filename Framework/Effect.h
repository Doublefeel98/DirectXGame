#pragma once
#include "Textures.h"
#include "Sprites.h"
#include  "Animations.h"
class Effect
{
protected:
	int x, y;
	DWORD timeDelay;
	bool isEnable;
	vector<LPANIMATION> animations;
	LPANIMATION_SET animation_set;
public:
	virtual void Render() {}
	virtual void Update(DWORD dt) {}
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetEnable(bool IsEnable) { this->isEnable = IsEnable; }
	virtual void AddAnimation(int aniId);
	Effect();
	~Effect();
	void SetAnimationSet(int ani_set_id);
	void SetAnimationSet(LPANIMATION_SET ani_set) { animation_set = ani_set; }
};
