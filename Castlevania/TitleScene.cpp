#include "TitleScene.h"
#include "Define.h"
#include <iostream>
#include <fstream>
#include "../Framework/Utils.h"
#include "../Framework/SceneManager.h"

void TitleSceneKeyHandler::KeyState(BYTE* states)
{
}

void TitleSceneKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	TitleScene* s = dynamic_cast<TitleScene*>(scence);
	s->SwitchScene();
}

void TitleSceneKeyHandler::OnKeyUp(int KeyCode)
{
}

void TitleScene::_ParseSection_SETTINGS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 2) return;
	if (tokens[0] == "background")
		background = CSprites::GetInstance()->Get(atoi(tokens[1].c_str()));
	else if (tokens[0] == "bat_ani_set_id")
		batStartGame->SetAnimationSet(atoi(tokens[1].c_str()));
	else if (tokens[0] == "text_ani_set_id")
		textTitle->SetAnimationSet(atoi(tokens[1].c_str()));
}


TitleScene::TitleScene(int id, LPCWSTR filePath) : CScene(id, filePath)
{
	key_handler = new TitleSceneKeyHandler(this);
}

void TitleScene::SwitchScene()
{
	is_switch_scene = true;
	time_switch_scene = GetTickCount();
	batStartGame->SetPauseAni(true);
	textTitle->StartFlashingEffect();
}

void TitleScene::Load()
{
	is_switch_scene = false;
	batStartGame = new BatStartGame();
	textTitle = new TextTitleScreen();
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

	DebugOut(L"[INFO] Done loading title screen resources %s\n", sceneFilePath);
}

void TitleScene::Update(DWORD dt)
{
	textTitle->Update(dt);
	batStartGame->Update(dt);
	if (is_switch_scene) {
		if (GetTickCount() - time_switch_scene > 2000) {
			Simon::GetInstance()->Position = 0;
			CSceneManager::GetInstance()->BeforeSwitchScene(0);
		}
	}
}

void TitleScene::Render()
{
	background->DrawWithoutCamera(0, 0);
	textTitle->Render();
	batStartGame->Render();
}

void TitleScene::Unload()
{
	SAFE_DELETE(textTitle);
	SAFE_DELETE(batStartGame);

	CScene::Unload();
}
