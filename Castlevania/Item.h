#pragma once
#include "../Framework/GameObject.h"
#include "MoneyEffect.h"
class Item;
typedef Item* LPITEM;
class Item : public CGameObject
{
	int typeItem;
	void RandomType();
	void RandomItem();
	void RandomWeapon();
	void Init();
	DWORD timeStartEnable;
	bool IsGround;
	bool IsFirstTime;
	MoneyEffect* moneyEffect;
	DWORD timeDisplay;
	int timeDisplayMax;
	bool is_grow_up;
	float start_y;
public:
	Item();
	Item(int typeItem);
	~Item();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void TurnOnTimeStartEnable();
	int GetTypeItem() { return typeItem; }
	MoneyEffect* GetMoneyEffect() { return moneyEffect; }
	void Enable();
	void SetIsGrowUp(bool is_grow_up);
};
