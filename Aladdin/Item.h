#pragma once
#include "../Framework/GameObject.h"

class Item;
typedef Item* LPITEM;

class Item :public CGameObject
{
	CSprite* sprite;
	int itemType;
	CAnimation* anirender;
public:
	Item();
	Item(int itemType);
	~Item();
	void SetState(int state);
	int GetCurrentFrame();
	void Render();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	int GetItemType() { return itemType; }
};