#include "CastlevaniaRescoures.h"
#include "Define.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../Framework/Helper.h"
#include "../Framework/debug.h"

void CastlevaniaRescoures::LoadTextures()
{
	textures->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(ID_TEX_SIMON, L"resources\\textures\\simon.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_BRICK_OUT_CASTLE, L"resources\\textures\\brickoutcastle.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_BRICK_SCENE_ONE, L"resources\\textures\\bricksceneone.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_CANDLE, L"resources\\textures\\candle.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_TORCH, L"resources\\textures\\torch.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_WHIP, L"resources\\textures\\whip.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_ITEM_WHIP, L"resources\\textures\\item_whip.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_HEART, L"resources\\textures\\item_heart.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_COLLISION_EFFECT, L"resources\\textures\\collidioneffect.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_DEAD_EFFECT, L"resources\\textures\\deadeffect.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_HP, L"resources\\textures\\hp.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_BOARD_HEART, L"resources\\textures\\item_board_heart.png", D3DCOLOR_XRGB(255, 0, 255));

	//textures->Add(ID_TEX_MAP_OUT_CASTLE, L"resources\\maps\\outcastle\\lv1.png", D3DCOLOR_XRGB(0, 0, 0));
	//textures->Add(ID_TEX_MAP_OUT_CASTLE, L"resources\\maps\\outcastle\\tilesetoutcastle.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(ID_TEX_MAP_OUT_CASTLE, L"resources\\maps\\outcastle\\outcastle.png", D3DCOLOR_XRGB(0, 0, 0));

}

void CastlevaniaRescoures::LoadSprites()
{
	LPDIRECT3DTEXTURE9 texCastlevania = textures->Get(ID_TEX_SIMON);

	//top left
	sprites->AddByWidthHeight(10000, 12, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10001, 74, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10002, 135, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10003, 192, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10004, 252, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10005, 312, 2, 48, 62, texCastlevania);
	sprites->AddByWidthHeight(10006, 373, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10007, 421, 2, 43, 62, texCastlevania, -11);

	//top right
	sprites->AddByWidthHeight(11000, 916, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11001, 854, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11002, 793, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11003, 736, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11004, 676, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11005, 600, 2, 48, 62, texCastlevania, -16);
	sprites->AddByWidthHeight(11006, 555, 2, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11007, 496, 2, 43, 62, texCastlevania);

	//medium left
	sprites->AddByWidthHeight(10010, 10, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(10011, 80, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(10012, 130, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(10013, 190, 66, 24, 64, texCastlevania);
	sprites->AddByWidthHeight(10014, 259, 66, 30, 64, texCastlevania);
	sprites->AddByWidthHeight(10015, 322, 66, 24, 64, texCastlevania);
	sprites->AddByWidthHeight(10016, 378, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(10017, 432, 66, 48, 64, texCastlevania);

	//medium right
	sprites->AddByWidthHeight(11010, 918, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(11011, 848, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(11012, 798, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(11013, 746, 66, 24, 64, texCastlevania);
	sprites->AddByWidthHeight(11014, 671, 66, 30, 64, texCastlevania);
	sprites->AddByWidthHeight(11015, 614, 66, 24, 64, texCastlevania);
	sprites->AddByWidthHeight(11016, 550, 66, 32, 64, texCastlevania);
	sprites->AddByWidthHeight(11017, 480, 66, 48, 64, texCastlevania, -16);

	//bottom left
	sprites->AddByWidthHeight(10020, 11, 134, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10021, 61, 134, 44, 62, texCastlevania, -12);
	sprites->AddByWidthHeight(10022, 130, 134, 48, 62, texCastlevania);
	sprites->AddByWidthHeight(10023, 190, 134, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10024, 241, 134, 41, 62, texCastlevania);
	sprites->AddByWidthHeight(10025, 319, 134, 41, 62, texCastlevania);
	sprites->AddByWidthHeight(10026, 379, 134, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(10027, 427, 134, 44, 62, texCastlevania);

	//bottom right
	sprites->AddByWidthHeight(11020, 917, 134, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11021, 855, 134, 44, 62, texCastlevania);
	sprites->AddByWidthHeight(11022, 782, 134, 48, 62, texCastlevania);
	sprites->AddByWidthHeight(11023, 738, 134, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11024, 678, 134, 41, 62, texCastlevania);
	sprites->AddByWidthHeight(11025, 600, 134, 41, 62, texCastlevania);
	sprites->AddByWidthHeight(11026, 549, 134, 32, 62, texCastlevania);
	sprites->AddByWidthHeight(11027, 489, 134, 44, 62, texCastlevania);

	//object map
	LPDIRECT3DTEXTURE9 texBrickOutCastle = textures->Get(ID_TEX_BRICK_OUT_CASTLE);
	sprites->AddByWidthHeight(20000, 0, 0, 32, 32, texBrickOutCastle);

	LPDIRECT3DTEXTURE9 texTorch = textures->Get(ID_TEX_TORCH);
	sprites->AddByWidthHeight(20010, 0, 0, 32, 64, texTorch);
	sprites->AddByWidthHeight(20011, 32, 0, 32, 64, texTorch);

	LPDIRECT3DTEXTURE9 texBrickSceneOne = textures->Get(ID_TEX_BRICK_SCENE_ONE);
	sprites->AddByWidthHeight(20020, 0, 0, 32, 32, texBrickSceneOne);

	LPDIRECT3DTEXTURE9 texCandle = textures->Get(ID_TEX_CANDLE);
	sprites->AddByWidthHeight(20030, 0, 0, 16, 32, texCandle);
	sprites->AddByWidthHeight(20031, 16, 0, 16, 32, texCandle);

	//weapons
	LPDIRECT3DTEXTURE9 texWhip = textures->Get(ID_TEX_WHIP);
	sprites->AddByWidthHeight(30000, 150, 16, 15, 50, texWhip, 45, 12);
	sprites->AddByWidthHeight(30001, 375, 10, 30, 40, texWhip, 32, 10);
	sprites->AddByWidthHeight(30002, 532, 14, 44, 17, texWhip, -56, 12);

	sprites->AddByWidthHeight(31000, 1275, 16, 15, 50, texWhip, -29, 12);
	sprites->AddByWidthHeight(31001, 1035, 10, 30, 40, texWhip, -20, 10);
	sprites->AddByWidthHeight(31002, 864, 14, 44, 17, texWhip, 43, 12);

	sprites->AddByWidthHeight(30010, 150, 82, 15, 50, texWhip, 45, 12);
	sprites->AddByWidthHeight(30011, 375, 76, 30, 40, texWhip, 32, 10);
	sprites->AddByWidthHeight(30012, 532, 84, 44, 13, texWhip, -56, 17);

	sprites->AddByWidthHeight(31010, 1275, 82, 15, 50, texWhip, -29, 12);
	sprites->AddByWidthHeight(31011, 1035, 76, 30, 40, texWhip, -20, 10);
	sprites->AddByWidthHeight(31012, 864, 84, 44, 13, texWhip, 43, 17);

	sprites->AddByWidthHeight(30020, 150, 148, 15, 50, texWhip, 45, 12);
	sprites->AddByWidthHeight(30021, 375, 148, 30, 40, texWhip, 32, 10);
	sprites->AddByWidthHeight(30022, 502, 154, 74, 14, texWhip, -86, 17);

	sprites->AddByWidthHeight(31020, 1275, 148, 15, 50, texWhip, -29, 12);
	sprites->AddByWidthHeight(31021, 1035, 148, 30, 40, texWhip, -20, 10);
	sprites->AddByWidthHeight(31022, 864, 154, 74, 14, texWhip, 43, 17);

	//effect
	LPDIRECT3DTEXTURE9 texCollisonEffect = textures->Get(ID_TEX_COLLISION_EFFECT);
	sprites->AddByWidthHeight(40000, 0, 0, 16, 20, texCollisonEffect, -8, -10);

	LPDIRECT3DTEXTURE9 texDeadEffect = textures->Get(ID_TEX_DEAD_EFFECT);
	sprites->AddByWidthHeight(40010, 18, 10, 6, 26, texDeadEffect, -3, 13);
	sprites->AddByWidthHeight(40011, 58, 12, 12, 24, texDeadEffect, -6, 12);
	sprites->AddByWidthHeight(40012, 98, 6, 16, 30, texDeadEffect, -8, 15);

	//boards
	LPDIRECT3DTEXTURE9 texHP = textures->Get(ID_TEX_HP);
	sprites->AddByWidthHeight(50000, 0, 0, 11, 18, texHP);
	sprites->AddByWidthHeight(50001, 11, 0, 11, 18, texHP);
	sprites->AddByWidthHeight(50002, 22, 0, 11, 18, texHP);

	LPDIRECT3DTEXTURE9 texSmallHeart = textures->Get(ID_TEX_ITEM_BOARD_HEART);
	sprites->AddByWidthHeight(50010, 0, 0, 16, 16, texSmallHeart);

	//Items
	LPDIRECT3DTEXTURE9 texItemWhip = textures->Get(ID_TEX_ITEM_WHIP);
	sprites->AddByWidthHeight(60000, 0, 0, 32, 32, texItemWhip);

	LPDIRECT3DTEXTURE9 texItemHeart = textures->Get(ID_TEX_ITEM_HEART);
	sprites->AddByWidthHeight(60001, 0, 0, 24, 20, texItemHeart);

	//map out castle
	LPDIRECT3DTEXTURE9 texMapOutCastle = textures->Get(ID_TEX_MAP_OUT_CASTLE);
	//sprites->AddByWidthHeight(ID_SPRITE_MAP_OUT_CASTLE, 0, 0, 256, 320, texMapOutCastle);
	//sprites->AddByWidthHeight(ID_SPRITE_MAP_OUT_CASTLE, 0, 0, 319, 159, texMapOutCastle);
	sprites->AddByWidthHeight(ID_SPRITE_MAP_OUT_CASTLE, 0, 0, 1536, 384, texMapOutCastle);
}

void CastlevaniaRescoures::LoadAnimations()
{
	LPANIMATION ani;

	//simon
	ani = new CAnimation(100);	// idle left
	ani->Add(10000);
	animations->Add(100, ani);

	ani = new CAnimation(100);// idle right
	ani->Add(11000);
	animations->Add(101, ani);

	ani = new CAnimation(100);	// walking left
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	ani->Add(10002);
	animations->Add(102, ani);

	ani = new CAnimation(100); // walking right
	ani->Add(11001);
	ani->Add(11002);
	ani->Add(11003);
	ani->Add(11002);
	animations->Add(103, ani);

	ani = new CAnimation(100);	// sitting down left
	ani->Add(10004);
	animations->Add(104, ani);

	ani = new CAnimation(100);// sitting down right
	ani->Add(11004);
	animations->Add(105, ani);

	ani = new CAnimation(150);	// fighting left
	ani->Add(10005);
	ani->Add(10006);
	ani->Add(10007);
	animations->Add(106, ani);

	ani = new CAnimation(150); // fighting right
	ani->Add(11005);
	ani->Add(11006);
	ani->Add(11007);
	animations->Add(107, ani);

	ani = new CAnimation(150);	// sit fighting left
	ani->Add(10017);
	ani->Add(10020);
	ani->Add(10021);
	animations->Add(108, ani);

	ani = new CAnimation(150); // sit fighting right
	ani->Add(11017);
	ani->Add(11020);
	ani->Add(11021);
	animations->Add(109, ani);

	ani = new CAnimation(100);	// jump fighting left
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	animations->Add(110, ani);

	ani = new CAnimation(100); // jump fighting right
	ani->Add(11022);
	ani->Add(11023);
	ani->Add(11024);
	animations->Add(111, ani);

	//object map
	ani = new CAnimation(100); //brick out castle
	ani->Add(20000);
	animations->Add(200, ani);

	ani = new CAnimation(100); //brick scene one
	ani->Add(20020);
	animations->Add(201, ani);

	ani = new CAnimation(100);//torch
	ani->Add(20010);
	ani->Add(20011);
	animations->Add(202, ani);

	ani = new CAnimation(100); //candle
	ani->Add(20030);
	ani->Add(20031);
	animations->Add(203, ani);

	//weapons
	//whip
	ani = new CAnimation(150); //whip level 1 prepare left
	ani->Add(30000);
	ani->Add(30001);
	animations->Add(300, ani);

	ani = new CAnimation(150); //whip level 1 left
	ani->Add(30002);
	animations->Add(301, ani);

	ani = new CAnimation(150); //whip level 1 prepare right
	ani->Add(31000);
	ani->Add(31001);
	animations->Add(302, ani);

	ani = new CAnimation(150); //whip level 1 right
	ani->Add(31002);
	animations->Add(303, ani);

	ani = new CAnimation(150); //whip level 2 prepare left
	ani->Add(30010);
	ani->Add(30011);
	animations->Add(304, ani);

	ani = new CAnimation(150); //whip level 2 left
	ani->Add(30012);
	animations->Add(305, ani);

	ani = new CAnimation(150); //whip level 2 prepare right
	ani->Add(31010);
	ani->Add(31011);
	animations->Add(306, ani);

	ani = new CAnimation(150); //whip level 2 right
	ani->Add(31012);
	animations->Add(307, ani);

	ani = new CAnimation(150); //whip level 3 prepare left
	ani->Add(30020);
	ani->Add(30021);
	animations->Add(308, ani);

	ani = new CAnimation(150); //whip level 3 left
	ani->Add(30022);
	animations->Add(309, ani);

	ani = new CAnimation(150); //whip level 3 prepare right
	ani->Add(31020);
	ani->Add(31021);
	animations->Add(310, ani);

	ani = new CAnimation(150); //whip level 3 right
	ani->Add(31022);
	animations->Add(311, ani);

	//effect
	ani = new CAnimation(100); //collision effect
	ani->Add(40000);
	animations->Add(400, ani);

	ani = new CAnimation(100); //dead effect
	ani->Add(40010);
	ani->Add(40011);
	ani->Add(40012);
	animations->Add(401, ani);

	//Items
	ani = new CAnimation(100); //Item Whip
	ani->Add(60000);
	animations->Add(600, ani);

	ani = new CAnimation(100); //Item Heart
	ani->Add(60001);
	animations->Add(601, ani);
}

void CastlevaniaRescoures::LoadTextures(string file)
{
	wifstream input;
	input.open(file, wifstream::in);
	wstring checkEnd;

	int id;
	wstring filePath;
	int colorR;
	int colorG;
	int colorB;
	LPCWSTR path;

	while (input >> checkEnd)
	{
		if (checkEnd == L"END")
		{
			return;
		}
		else
		{
			id = stoi(checkEnd.c_str());
			input >> filePath >> colorR >> colorG >> colorB;

			path = (LPCWSTR)filePath.c_str();
			textures->Add(id, path, D3DCOLOR_XRGB(colorR, colorG, colorB));
		}
	}
}

void CastlevaniaRescoures::LoadSprites(string file)
{
	ifstream input;
	input.open(file, ifstream::in);
	string checkEnd;

	int id;
	int left;
	int top;
	int right;
	int bottom;
	int textureId;
	int dx;
	int dy;

	while (input >> checkEnd)
	{
		if (checkEnd == "END")
		{
			return;
		}
		else
		{
			id = stoi(checkEnd.c_str());
			input >> left >> top >> right >> bottom >> textureId >> dx >> dy;
			sprites->AddByWidthHeight(id, left, top, right, bottom, textures->Get(textureId), dx, dy);
		}
	}
}

void CastlevaniaRescoures::LoadAnimations(string file)
{
	fstream pFile;
	pFile.open(file, fstream::in);
	string lineString;

	std::vector<std::string> listRow;
	int id;
	int time;
	LPANIMATION ani;
	while (pFile.good())
	{
		getline(pFile, lineString);
		if (lineString == "END")
		{
			return;
		}
		else
		{
			listRow = Helper::split(lineString, ' ');
			id = stoi(listRow[0].c_str());
			time = stoi(listRow[1].c_str());

			ani = new CAnimation(time);
			int spriteId;
			for (int i = 2; i < listRow.size(); i++)
			{
				spriteId = atoi(listRow[i].c_str());
				ani->Add(spriteId);
			}
			animations->Add(id, ani);
		}
	}
}

CastlevaniaRescoures::CastlevaniaRescoures()
{
	this->textures = CTextures::GetInstance();

	this->sprites = CSprites::GetInstance();

	this->animations = CAnimations::GetInstance();
}

void CastlevaniaRescoures::LoadResoucre()
{
	LoadTextures("resources\\files\\textures.txt");
	LoadSprites("resources\\files\\sprites.txt");
	LoadAnimations("resources\\files\\animations.txt");
}
