#include <iostream>
#include <fstream>

#include "IntroScene.h"
#include "Define.h"
#include "../Framework/Utils.h"
#include "Define.h"
#include "../Framework/SceneManager.h"
#include "../Framework/Ground.h"

void IntroScene::_ParseSection_SETTINGS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 2) return;
	if (tokens[0] == "background") {
		background = CSprites::GetInstance()->Get(atoi(tokens[1].c_str()));
		background_x = atof(tokens[2].c_str());
		background_y = atof(tokens[3].c_str());
	}
	else if (tokens[0] == "bat_ani_set_id")
	{
		batIntro1 = new BatIntro();
		batIntro1->SetPosition(atof(tokens[2].c_str()), atof(tokens[3].c_str()));
		batIntro1->SetState(atoi(tokens[4].c_str()));
		batIntro2 = new BatIntro();
		batIntro2->SetPosition(atof(tokens[5].c_str()), atof(tokens[6].c_str()));
		batIntro2->SetState(atoi(tokens[7].c_str()));

		batIntro1->SetAnimationSet(atoi(tokens[1].c_str()));
		batIntro2->SetAnimationSet(atoi(tokens[1].c_str()));
	}
	else if (tokens[0] == "helicopter_ani_set_id")
	{
		helicopter = new Helicopter();
		helicopter->SetPosition(atof(tokens[2].c_str()), atof(tokens[3].c_str()));
		helicopter->SetAnimationSet(atoi(tokens[1].c_str()));
	}
	else if (tokens[0] == "ground")
	{
		Ground* ground = new Ground();
		ground->SetPosition(atof(tokens[1].c_str()), atof(tokens[2].c_str()));
		ground->SetWidth(atoi(tokens[3].c_str()));
		ground->SetHeight(atoi(tokens[4].c_str()));
		objects.push_back(ground);
	}
	else if (tokens[0] == "player")
	{
		player = Simon::GetInstance();
		player->SetPosition(atof(tokens[1].c_str()), atof(tokens[2].c_str()));
	}
}

IntroScene::IntroScene(int id, LPCWSTR filePath) : CScene(id, filePath)
{
	key_handler = new IntroSceneKeyHandler(this);
}

void IntroScene::Load()
{
	DebugOut(L"[INFO] Start loading scene resources from : %s \n", sceneFilePath);

	ifstream f;
	f.open(sceneFilePath);

	// current resource section flag
	int section = SCENE_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines
		if (line[0] == '/' && line[1] == '/') continue;	// skip comment lines

		if (line == "[SETTINGS]") {
			section = SCENE_SECTION_SETTINGS; continue;
		}
		if (line == "[TEXTURES]") { section = SCENE_SECTION_TEXTURES; continue; }
		if (line == "[SPRITES]") {
			section = SCENE_SECTION_SPRITES; continue;
		}
		if (line == "[ANIMATIONS]") {
			section = SCENE_SECTION_ANIMATIONS; continue;
		}
		if (line == "[ANIMATION_SETS]") {
			section = SCENE_SECTION_ANIMATION_SETS; continue;
		}
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case SCENE_SECTION_SETTINGS: _ParseSection_SETTINGS(line); break;
		case SCENE_SECTION_TEXTURES: _ParseSection_TEXTURES(line); break;
		case SCENE_SECTION_SPRITES: _ParseSection_SPRITES(line); break;
		case SCENE_SECTION_ANIMATIONS: _ParseSection_ANIMATIONS(line); break;
		case SCENE_SECTION_ANIMATION_SETS: _ParseSection_ANIMATION_SETS(line); break;
		}
	}

	f.close();

	//CTextures::GetInstance()->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	scoreBoard = new ScoreBoard(player, 16);

	DebugOut(L"[INFO] Done loading scene resources %s\n", sceneFilePath);
}

void IntroScene::Update(DWORD dt)
{
	batIntro1->Update(dt);
	batIntro2->Update(dt);
	helicopter->Update(dt);
	scoreBoard->Update(16, 1000, 0);

	if (player->x > CAMERA_WIDTH / 2 - SIMON_BBOX_WIDTH / 2)
	{
		player->SetState(SIMON_STATE_WALK_LEFT);
	}
	player->Update(dt, &objects);
	DebugOut(L"player position: %f, %f\n", player->x, player->y);
	if (player->x < CAMERA_WIDTH / 2 - SIMON_BBOX_WIDTH)
	{
		player->SetPosition(player->x, player->y);
		player->SetState(SIMON_STATE_INTRO);
		timeDelay += dt;
		if (timeDelay >= SCENE_INTRO_LIVE_TIME)
		{
			CSceneManager::GetInstance()->BeforeSwitchScene(1);
		}
	}
}

void IntroScene::Render()
{
	background->DrawWithoutCamera(background_x, background_y);
	batIntro1->Render();
	batIntro2->Render();
	helicopter->Render();
	objects[0]->Render();
	player->Render();

	scoreBoard->Render();
}

void IntroScene::Unload()
{

	CScene::Unload();
}

void IntroSceneKeyHandler::KeyState(BYTE* states)
{
}

void IntroSceneKeyHandler::OnKeyDown(int KeyCode)
{
}

void IntroSceneKeyHandler::OnKeyUp(int KeyCode)
{
}
