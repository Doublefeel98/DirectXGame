#pragma once
#include "Aladdin.h"
#include <string>
#include "Define.h"
#include "../Framework/Game.h"

class ScoreBoard
{
	RECT rect;
	Aladdin* aladdin;
	ID3DXFont* font;
	LPDIRECT3DDEVICE9 d3ddv;
	LPD3DXSPRITE spriteHandler;
	CSprite* sprite;
	wstring information;

	int bossHP;
	int score;
	int time;
	int item;
	int energy;
	int life;
	int stage;
public:
	ScoreBoard(Aladdin* aladdin, int bossHP);
	~ScoreBoard();
	void Update(int bossHP, int time, int life, int stage);
	void Render();
};

