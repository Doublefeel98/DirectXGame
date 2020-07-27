#pragma once
#include <string>
#include <vector>
#include "../Framework/Game.h"
#include "../Framework/Sprites.h"

// GAME OVER
#define GAMEOVER_SELECT_CONTINUE 0
#define GAMEOVER_SELECT_END 1

class OverScene
{
	ID3DXFont* font;
	RECT rectLineTitle;
	RECT rectLineOne;
	RECT rectLineTwo;
	LPDIRECT3DDEVICE9 d3ddv;
	wstring lineTitle;
	wstring lineOne;
	wstring lineTwo;
	CSprite* sprite;
	LPD3DXSPRITE spriteHandler;
	int selected;

	static OverScene* __instance;
public:

	static OverScene* GetInstance();
	void SetSelected(int _selected) { this->selected = _selected; }
	int GetSelected() { return this->selected; }
	OverScene();
	~OverScene();
	void Render();
};
