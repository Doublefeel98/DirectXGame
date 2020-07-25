/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102

	SAMPLE 05 - SCENCE MANAGER

	This sample illustrates how to:

		1/ Implement a scence manager
		2/ Load scene from "database", add/edit/remove scene without changing code
		3/ Dynamically move between scenes without hardcode logic

================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "../Framework/Utils.h"
#include "../Framework/Game.h"
#include "../Framework/GameObject.h"
#include "../Framework/Textures.h"
#include "../Framework/SceneManager.h"
#include "../Framework/Camera.h"
#include "PlayScence.h"
#include "Simon.h"
#include "Define.h"

#include "PlayScence.h"
#include "TitleScene.h"
#include "IntroScene.h"

CGame* game;
CSceneManager* sceneManager;

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}



/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	sceneManager->GetCurrentScene()->Update(dt);
	if (sceneManager->IsSwitchScene()) {
		sceneManager->SwitchScene();
	}
}

/*
	Render a frame
*/
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, game->GetBackgroundColor());

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		sceneManager->GetCurrentScene()->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();

			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

void handleSwitchScene(CSceneManager* manager)
{
	int current_scene_id = manager->GetCurrentSceneId();
	int next_scene_id = manager->GetNextSceneId();

	LPSCENE current_scene = manager->GetScene(current_scene_id);
	LPSCENE next_scene = manager->GetScene(next_scene_id);

	if (next_scene_id < 1) {
		CGame::GetInstance()->SetDeviationY(0);
	}
	else {
		CCamera::GetInstance()->SetFollowPlayer(true);
		CGame::GetInstance()->SetDeviationY(45);
		CPlayScene* s = dynamic_cast<CPlayScene*>(next_scene);
		if (current_scene_id > 0) {
			CPlayScene* oldScene = dynamic_cast<CPlayScene*>(current_scene);
			s->SetDefaultTime(oldScene->GetRemainTime());
		}
		s->position = -1;
	}
}

LPSCENE getSceneById(int id, LPCWSTR path)
{
	LPSCENE scene;
	if (id == -1) {
		scene = new TitleScene(id, path);
	}
	else if (id == 0) {
		scene = new IntroScene(id, path);
	}
	else {
		scene = new CPlayScene(id, path);
	}
	return scene;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = CGame::GetInstance();
	game->SetBackgroundColor(BACKGROUND_COLOR);
	game->Init(hWnd);
	game->InitKeyboard();

	sceneManager = CSceneManager::GetInstance();
	//require set getSceneById
	sceneManager->SetFunctionGetSceneByID(getSceneById);
	//require set handleSwitchScene
	sceneManager->SetFunctionHandleSwitchScene(handleSwitchScene);
	//require set player
	sceneManager->SetPlayer(Simon::GetInstance());
	sceneManager->Load(L"resources\\castlevania-sample.txt");

	CCamera::GetInstance()->SetSize(CAMERA_WIDTH, CAMERA_HEIGHT);

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}
