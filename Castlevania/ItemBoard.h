#pragma once
#include"../Framework/Effect.h"
class ItemBoard : public Effect
{
	CSprite* sprite;
	int type;
public:
	ItemBoard(int type);
	void SetType(int type);
	~ItemBoard();
	void Render();
};
