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
#include "Ground.h"
#include "AladdinResoucres.h"

CCamera* camera;

CGame * game;

Aladdin* aladdin;

AladdinResoucres *resources;
CSceneManager * sceneManager;

float dy;

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
	case DIK_Z:
		if (aladdin->GetState() != ALADDIN_STATE_THROW_APPLE)
		{
			if (aladdin->IsSit)
			{
				aladdin->SetState(ALADDIN_STATE_SITTING_THROW_APPLE);
			}
			else
			{
				aladdin->SetState(ALADDIN_STATE_THROW_APPLE);
			}
		}	
		break;
	case DIK_X:
		if (aladdin->GetState() != ALADDIN_STATE_STANDING_SLASH)
		{
			if (aladdin->IsSit)
			{
				aladdin->SetState(ALADDIN_STATE_SITTING_SLASH);
			}
			else if (aladdin->IsLookingUp)
			{
				aladdin->SetState(ALADDIN_STATE_LOOKING_UP_SLASH);
			}
			else
			{
				aladdin->SetState(ALADDIN_STATE_STANDING_SLASH);
			}			
		}
		break;
	case DIK_C:
		if (!aladdin->IsJump)
		{
			if (aladdin->IsSlash)
			{
				aladdin->SetState(ALADDIN_STATE_JUMPING_SLASH);
			}
			else if (aladdin->IsThrow)
			{
				aladdin->SetState(ALADDIN_STATE_JUMPING_THROW_APPLE);
			}
			else
			{
				aladdin->SetState(ALADDIN_STATE_JUMP);
			}
		}
		break;
	case DIK_RIGHT:
		aladdin->nx = 1;
		break;
	case DIK_LEFT:
		aladdin->nx = -1;
		break;
	}
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_DOWN:
		aladdin->SetState(ALADDIN_STATE_IDLE);
		break;
	case DIK_UP:
		break;
	}
}

void CSampleKeyHander::KeyState(BYTE* states)
{
	  //disable control key when Mario die 
	if (aladdin->GetState() == ALADDIN_STATE_DIE) return;
	if (game->IsKeyDown(DIK_RIGHT)) {
		if (!aladdin->IsSit)
			aladdin->SetState(ALADDIN_STATE_WALKING_RIGHT);
	}	
	else if (game->IsKeyDown(DIK_LEFT)) {
		if (!aladdin->IsSit)
			aladdin->SetState(ALADDIN_STATE_WALKING_LEFT);
	}
		
	else if (game->IsKeyDown(DIK_DOWN)) {
		if (!aladdin->IsJump) {
			aladdin->SetState(ALADDIN_STATE_SIT_DOWN);
		}
	}
	else if (game->IsKeyDown(DIK_UP))
	{
		aladdin->SetState(ALADDIN_STATE_LOOKING_UP);
	}
	else {
		if (aladdin->GetState() != ALADDIN_STATE_STANDING_SLASH)
		{
			aladdin->SetState(ALADDIN_STATE_IDLE);
		}
	}

	 //CCamera* camera = CCamera::GetInstance();
	 //if (game->IsKeyDown(DIK_RIGHT))
	 //	camera->SetCameraPosition(camera->GetCameraPosition().x + 10, camera->GetCameraPosition().y);
	 //else if (game->IsKeyDown(DIK_LEFT))
	 //	camera->SetCameraPosition(camera->GetCameraPosition().x - 10, camera->GetCameraPosition().y);
	 //else if (game->IsKeyDown(DIK_UP))
	 //	camera->SetCameraPosition(camera->GetCameraPosition().x, camera->GetCameraPosition().y - 10);
	 //else if (game->IsKeyDown(DIK_DOWN))
	 //	camera->SetCameraPosition(camera->GetCameraPosition().x, camera->GetCameraPosition().y + 10);
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

void LoadResources()
{
	aladdin = new Aladdin();
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

	// Update camera to follow aladdin
	D3DXVECTOR3 pos = camera->GetCameraPosition();
	float cx, cy, mapWidth, mapHeight, boundHeight;

	mapWidth = sceneManager->GetCurrentScene()->GetMapWidth();
	mapHeight = sceneManager->GetCurrentScene()->GetMapHeight();

	aladdin->GetPosition(cx, cy);

	boundHeight = mapHeight + 22;
	
	if (cx + aladdin->GetWidth() + 5 < SCREEN_WIDTH / 2) {
		cx = pos.x;
	}
	else if (cx + aladdin->GetWidth() + 5 + SCREEN_WIDTH / 2 > mapWidth - 1) {
		cx = mapWidth - SCREEN_WIDTH - 1;
	}
	else {
		cx = cx + aladdin->GetWidth() + 5 + SCREEN_WIDTH/2 - SCREEN_WIDTH;
	}

	if (cy + aladdin->GetHeight()/2 < mapHeight - SCREEN_HEIGHT / 2) {
		cy = cy + aladdin->GetHeight() / 2 - SCREEN_HEIGHT / 2;
	}
	else {
		cy = boundHeight - SCREEN_HEIGHT;
	}

	if (aladdin->IsMoveCameraWhenLookingUp())
	{
		cy = cy - 10;
	}

	camera->SetCameraPosition(cx, cy);
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

	camera = CCamera::GetInstance();

	resources = new AladdinResoucres();
	resources->LoadResoucre();

	LoadResources();
	sceneManager = CSceneManager::GetInstance();
	sceneManager->ChangeScene(new SceneOne(aladdin));

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH*2, SCREEN_HEIGHT*2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}