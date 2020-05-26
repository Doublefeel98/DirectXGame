#pragma once

#include <unordered_map>

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>


#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include "Scence.h"
#include "Camera.h"

using namespace std;

#define KEYBOARD_BUFFER_SIZE 1024

class CGame
{
	static CGame* __instance;
	HWND hWnd;									// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data

	LPKEYEVENTHANDLER keyHandler;

	int screen_width;
	int screen_height;

	CCamera* camera;

	int deviation_y;

	D3DCOLOR backgroundColor;
public:
	void InitKeyboard();
	void SetKeyHandler(LPKEYEVENTHANDLER handler) { keyHandler = handler; }
	void Init(HWND hWnd);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255, int r = 255, int g = 255, int b = 255);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT rect, int alpha = 255, int r = 255, int g = 255, int b = 255);
	void DrawWithoutCamera(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom, int alpha = 255, int r = 255, int g = 255, int b = 255);
	void DrawWithoutCamera(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT rect, int alpha = 255, int r = 255, int g = 255, int b = 255);

	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();

	int GetScreenWidth() { return screen_width; }
	int GetScreenHeight() { return screen_height; }

	static void SweptAABB(
		float ml,			// move left 
		float mt,			// move top
		float mr,			// move right 
		float mb,			// move bottom
		float dx,			// 
		float dy,			// 
		float sl,			// static left
		float st,
		float sr,
		float sb,
		float& t,
		float& nx,
		float& ny);

	static bool IsColliding(float ml, float mt, float mr, float mb, float sl, float st, float sr, float sb);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	static CGame* GetInstance();

	void SetBackgroundColor(D3DCOLOR color) { backgroundColor = color; }
	D3DCOLOR GetBackgroundColor() { return backgroundColor; }

	HWND GetHWND() { return hWnd; }

	void SetDeviationY(int _deviation_y) { deviation_y = _deviation_y; }

	~CGame();
};
