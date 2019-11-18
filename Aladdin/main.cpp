/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102

	SAMPLE 04 - COLLISION

	This sample illustrates how to:

		1/ Implement SweptAABB algorithm between moving objects
		2/ Implement a simple (yet effective) collision frame work

	Key functions:
		CGame::SweptAABB
		CGameObject::SweptAABBEx
		CGameObject::CalcPotentialCollisions
		CGameObject::FilterCollision

		CGameObject::GetBoundingBox

================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "../Framework/debug.h"
#include "../Framework/Game.h"
#include "../Framework/GameObject.h"
#include "../Framework/Textures.h"

#include "Aladdin.h"
#include "Define.h"
#include "Brick.h"
#include "../Framework/SceneManager.h"
#include "SceneOne.h"


CGame * game;

Aladdin* aladdin;

vector<LPGAMEOBJECT> objects;

class CSampleKeyHander : public CKeyEventHandler
{
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander* keyHandler;

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		aladdin->SetState(ALADDIN_STATE_JUMP);
		break;
	case DIK_A: // reset
		aladdin->SetState(ALADDIN_STATE_IDLE);
		aladdin->SetPosition(50.0f, 0.0f);
		aladdin->SetSpeed(0, 0);
		break;
	}
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}

void CSampleKeyHander::KeyState(BYTE* states)
{
	// disable control key when Mario die 
	/*if (aladdin->GetState() == ALADDIN_STATE_DIE) return;
	if (game->IsKeyDown(DIK_RIGHT))
		aladdin->SetState(ALADDIN_STATE_WALKING_RIGHT);
	else if (game->IsKeyDown(DIK_LEFT))
		aladdin->SetState(ALADDIN_STATE_WALKING_LEFT);
	else
		aladdin->SetState(ALADDIN_STATE_IDLE);*/
	CCamera* camera = CCamera::GetInstance();
	if (game->IsKeyDown(DIK_RIGHT))
		camera->SetCameraPosition(camera->GetCameraPosition().x + 10, camera->GetCameraPosition().y);
	else if (game->IsKeyDown(DIK_LEFT))
		camera->SetCameraPosition(camera->GetCameraPosition().x - 10, camera->GetCameraPosition().y);
	else if (game->IsKeyDown(DIK_UP))
		camera->SetCameraPosition(camera->GetCameraPosition().x, camera->GetCameraPosition().y - 10);
	else if (game->IsKeyDown(DIK_DOWN))
		camera->SetCameraPosition(camera->GetCameraPosition().x, camera->GetCameraPosition().y + 10);
}

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
	Load all game resources
	In this example: load textures, sprites, animations and aladdin object

	TO-DO: Improve this function by loading texture,sprite,animation,object from file
*/

void LoadTextures()
{
	CTextures* textures = CTextures::GetInstance();

	//textures->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(ID_TEX_MISC, L"resources\\textures\\misc.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ALADDIN, L"resources\\textures\\aladdin.png", D3DCOLOR_XRGB(255, 0, 255));

	//map
	textures->Add(ID_TEX_MAP_ONE, L"resources\\mapread\\lv1\\lv1.png", D3DCOLOR_XRGB(163, 73, 164));

}

void LoadSprites()
{
	CTextures* textures = CTextures::GetInstance();

	CSprites* sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_ALADDIN);

	LPDIRECT3DTEXTURE9 texAladdin = textures->Get(ID_TEX_ALADDIN);

	sprites->Add(10001, 3, 9, 41, 57, texAladdin);		// idle right

	sprites->Add(10101, 14, 1225, 53, 1222, texAladdin);		// walk	right
	sprites->Add(10102, 66, 1222, 108, 1272, texAladdin);
	sprites->Add(10103, 120, 1220, 160, 1272, texAladdin);
	sprites->Add(10104, 171, 1216, 211, 1272, texAladdin);
	sprites->Add(10105, 220, 1216, 271, 1272, texAladdin);
	sprites->Add(10106, 279, 1219, 324, 1273, texAladdin);
	sprites->Add(10107, 334, 1215, 375, 1273, texAladdin);
	sprites->Add(10108, 386, 1221, 426, 1273, texAladdin);
	sprites->Add(10109, 440, 1219, 474, 1273, texAladdin);
	sprites->Add(10110, 488, 1216, 536, 1273, texAladdin);
	sprites->Add(10111, 547, 1215, 601, 1273, texAladdin);
	sprites->Add(10112, 611, 1219, 665, 1273, texAladdin);
	sprites->Add(10113, 679, 1218, 722, 1273, texAladdin);


	/*LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 408, 225, 424, 241, texMisc);*/

	LPDIRECT3DTEXTURE9 textMapOne = textures->Get(ID_TEX_MAP_ONE);
	sprites->Add(ID_SPRITE_MAP_ONE, 0, 0, 2144, 1024, textMapOne);
}

void LoadAnimations()
{
	CTextures* textures = CTextures::GetInstance();

	CSprites* sprites = CSprites::GetInstance();

	CAnimations* animations = CAnimations::GetInstance();

	LPANIMATION ani;

	ani = new CAnimation(100);	// idle big right
	ani->Add(10001);
	animations->Add(100, ani);

	ani = new CAnimation(100);	// walk right big
	ani->Add(10101);
	ani->Add(10102);
	ani->Add(10103);
	ani->Add(10104);
	ani->Add(10105);
	ani->Add(10106);
	ani->Add(10107);
	ani->Add(10108);
	ani->Add(10109);
	ani->Add(10110);
	ani->Add(10111);
	ani->Add(10112);
	ani->Add(10113);
	animations->Add(110, ani);

	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);
}
void LoadResources()
{
	LoadTextures();
	LoadSprites();
	LoadAnimations();

	aladdin = new Aladdin();
	aladdin->AddAnimation(100);		// idle
	aladdin->AddAnimation(110);		// walking

	aladdin->SetPosition(50.0f, 0);
	objects.push_back(aladdin);

	//for (int i = 0; i < 30; i++)
	//{
	//	CBrick* brick = new CBrick();
	//	brick->AddAnimation(601);
	//	brick->SetPosition(0 + i * 16.0f, 150);
	//	objects.push_back(brick);
	//}
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	/* We know that Mario is the first object in the list hence we won't add him into the colliable object list
	 TO-DO: This is a "dirty" way, need a more organized way */

	CSceneManager::GetInstance()->GetCurrentScene()->Update(dt);

	vector<LPGAMEOBJECT> coObjects;
	for (int i = 1; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}


	//// Update camera to follow aladdin
	//float cx, cy;
	//aladdin->GetPosition(cx, cy);

	//cx -= SCREEN_WIDTH / 2;
	//cy -= SCREEN_HEIGHT / 2;

	//CGame::GetInstance()->SetCamPos(cx, 0.0f /*cy*/);
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
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		CSceneManager::GetInstance()->GetCurrentScene()->Render();

		for (int i = 0; i < objects.size(); i++)
			objects[i]->Render();

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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = CGame::GetInstance();
	game->Init(hWnd);

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);

	LoadResources();
	CSceneManager::GetInstance()->ChangeScene(new SceneOne());

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}