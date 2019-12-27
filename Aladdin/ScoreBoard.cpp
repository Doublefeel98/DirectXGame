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

	appleCount = new AppleCount(0);
	appleCount->x = SCREEN_WIDTH - 70;
	appleCount->y = SCREEN_HEIGHT - 60;

	appleNumber = new AppleNumber();
	appleNumber->x = SCREEN_WIDTH - 55;
	appleNumber->y = SCREEN_HEIGHT - 57;

	pennyCount = new PennyCount(0);
	pennyCount->x = SCREEN_WIDTH - 110;
	pennyCount->y = SCREEN_HEIGHT - 65;

	pennyNumber = new PennyNumber();
	pennyNumber->x = SCREEN_WIDTH - 90;
	pennyNumber->y = SCREEN_HEIGHT - 57;

	life = new Life(0);
	life->x = 20;
	life->y = SCREEN_HEIGHT - 68;

	lifeNumber = new LifeNumber();
	lifeNumber->x = 48;
	lifeNumber->y = SCREEN_HEIGHT - 57;
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
	wstring scoreString = to_wstring(aladdin->GetCountPoint());
	wstring appleNumberString = to_wstring(aladdin->GetCountApple());
	wstring pennyNumberString = to_wstring(aladdin->GetCountPenny());
	wstring lifeNumberString = to_wstring(aladdin->GetCountLife());

	while (timeString.length() < 4)
		timeString = L"0" + timeString;


	wstring stageString = to_wstring(this->stage);
	while (stageString.length() < 2)
		stageString = L"0" + stageString;

	information = L"SCORE_00000 TIME " + timeString + L" STAGE " + stageString + L"\n";

	score->Update(scoreString);
	hp->Update(aladdin->GetHP());
	appleNumber->Update(appleNumberString);
	pennyNumber->Update(pennyNumberString);
	lifeNumber->Update(lifeNumberString);
}

void ScoreBoard::Render()
{
	/*RECT newRect;
	SetRect(&newRect, 0, 0, SCREEN_WIDTH, 200);
	font->DrawText(spriteHandler, information.c_str(), -1, &rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));*/
	score->Render();
	hp->Render();
	appleCount->Render();
	appleNumber->Render();
	pennyCount->Render();
	pennyNumber->Render();
	life->Render();
	lifeNumber->Render();
}
