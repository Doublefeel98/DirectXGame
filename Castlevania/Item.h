#pragma once
#include "../Framework/GameObject.h"

class Item;
typedef Item* LPITEM;
class Item : public CGameObject
{
	int typeItem;
	void RandomType();
	void RandomItem();
	void RandomWeapon();
	void Init();
public:
	Item();
	Item(int typeItem);
	~Item();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	int GetTypeItem() { return typeItem; }
};

