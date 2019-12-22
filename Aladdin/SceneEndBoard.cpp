#include "SceneEndBoard.h"

SceneEndBoard::SceneEndBoard()
{
	this->d3ddv = CGame::GetInstance()->d3ddv;
	this->spriteHandler = CGame::GetInstance()->spriteHandler;

	font = NULL;

	D3DXFONT_DESC FontDesc = {
		20,
		13,
		10,
		10,
		false,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY,
		FF_DONTCARE, L"resources\\font\\prstart.ttf" };


	D3DXCreateFontIndirect(d3ddv, &FontDesc, &font);
	SetRect(&rect, 0, 20, SCREEN_WIDTH, 85);
	information = L"SCORE_000000 TIME 0000 STAGE 00\n";

	mapEndBackground = new MapEndBackground();
	mapEndBackground->x = 0;
	mapEndBackground->y = 0;

	complete = new Complete();
	complete->x = 40;
	complete->y = 20;
}

SceneEndBoard::~SceneEndBoard()
{
}

void SceneEndBoard::Update()
{
}

void SceneEndBoard::Render()
{
	/*RECT newRect;
	SetRect(&newRect, 0, 0, SCREEN_WIDTH, 200);
	font->DrawText(spriteHandler, information.c_str(), -1, &rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));*/

	mapEndBackground->Render();
	complete->Render();
}
