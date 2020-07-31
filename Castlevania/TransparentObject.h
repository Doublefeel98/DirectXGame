#pragma once
#include "../Framework/GameObject.h"
class TransparentObject : public CGameObject
{

public:
	float item_x, item_y;
	bool is_grow_up;
	TransparentObject();
	virtual void FromVector(vector<string> tokens);
	~TransparentObject();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};

