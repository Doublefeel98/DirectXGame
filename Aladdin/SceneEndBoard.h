#pragma once
#include <string>
#include "Aladdin.h"
#include "Define.h"
#include "../Framework/Game.h"
#include "MapEndBackground.h"
#include "Complete.h"

class SceneEndBoard
{
	RECT rect;
	ID3DXFont* font;
	LPDIRECT3DDEVICE9 d3ddv;
	LPD3DXSPRITE spriteHandler;
	CSprite* sprite;
	wstring information;

	MapEndBackground* mapEndBackground;
	Complete* complete;

public:
	SceneEndBoard();
	~SceneEndBoard();
	void Update();
	void Render();
};

