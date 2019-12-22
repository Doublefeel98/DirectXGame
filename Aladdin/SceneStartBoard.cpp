#include "SceneStartBoard.h"

SceneStartBoard::SceneStartBoard()
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

	mapStartBackGround = new MapStartBackground();
	mapStartBackGround->x = 0;
	mapStartBackGround->y = 0;

	intro = new Intro();
	intro->x = 40;
	intro->y = 20;

	pressStart = new PressStart();
	pressStart->x = 65;
	pressStart->y = 140;
}

SceneStartBoard::~SceneStartBoard()
{
}

void SceneStartBoard::Update()
{
}

void SceneStartBoard::Render()
{
	/*RECT newRect;
	SetRect(&newRect, 0, 0, SCREEN_WIDTH, 200);
	font->DrawText(spriteHandler, information.c_str(), -1, &rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));*/

	mapStartBackGround->Render();
	intro->Render();
	pressStart->Render();
}
