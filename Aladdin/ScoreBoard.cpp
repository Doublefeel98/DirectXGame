#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(Aladdin* aladdin, int bossHP)
{
	this->bossHP = bossHP;
	this->aladdin = aladdin;
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

	hp = new HP(8);
	hp->x = 10;
	hp->y = 10;

	score = new Score();
	score->x = SCREEN_WIDTH - 70;
	score->y = 10;
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::Update(int bossHP, int time, int life, int stage)
{
	this->time = time;
	this->stage = stage;
	this->bossHP = bossHP;

	wstring timeString = to_wstring(this->time);

	while (timeString.length() < 4)
		timeString = L"0" + timeString;


	wstring stageString = to_wstring(this->stage);
	while (stageString.length() < 2)
		stageString = L"0" + stageString;

	information = L"SCORE_00000 TIME " + timeString + L" STAGE " + stageString + L"\n";

	score->Update(timeString);
	hp->Update(aladdin->GetHP());
}

void ScoreBoard::Render()
{
	/*RECT newRect;
	SetRect(&newRect, 0, 0, SCREEN_WIDTH, 200);
	font->DrawText(spriteHandler, information.c_str(), -1, &rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));*/
	score->Render();
	hp->Render();
}
