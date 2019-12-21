#pragma once
#include "Aladdin.h"
#include <string>
#include "Define.h"
#include "../Framework/Game.h"
#include "HP.h"
#include "Life.h"
#include "Score.h"
#include "AppleCount.h"
#include "AppleNumber.h"
#include "PennyCount.h"
#include "PennyNumber.h"
#include "Life.h"
#include "LifeNumber.h"

class ScoreBoard
{
	RECT rect;
	Aladdin* aladdin;
	ID3DXFont* font;
	LPDIRECT3DDEVICE9 d3ddv;
	LPD3DXSPRITE spriteHandler;
	CSprite* sprite;
	wstring information;

	HP *hp;
	Score* score;
	AppleCount* appleCount;
	AppleNumber* appleNumber;
	PennyCount* pennyCount;
	PennyNumber* pennyNumber;
	Life* life;
	LifeNumber* lifeNumber;

	int bossHP;
	int time;
	int item;
	int energy;
	//int life;
	int stage;
public:
	ScoreBoard(Aladdin* aladdin, int bossHP);
	~ScoreBoard();
	void Update(int bossHP, int time, int life, int stage);
	void Render();
};

