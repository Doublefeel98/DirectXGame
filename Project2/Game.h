#pragma once

#ifndef Game_H
#define Game_H
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<windows.system.diagnostics.h>
#include<dinput.h>
#include"Global.h"

class Game {
protected:
	DWORD delta_time;
	BYTE _KeyStates[256];
	DIDEVICEOBJECTDATA _KeyEvents[KEY_BUFFER_SIZE];
	int cmd;

	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	int InitWindow(int cmd);
	int InitDirectX();
	void InitKeyboard();

	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	void ProcessKeyBoard();
	virtual void Update() {};

	void GameDraw(int deltaTime);
	void RenderFrame();

	virtual void OnKeyUp(int KeyCode);
	virtual void OnKeyDown(int KeyCode);
	int IsKeyDown(int KeyCode);

public:
	Game(){}
	Game(int cmd);
	~Game();

	void InitGame();
	void GameRun();
};
#endif // !Game_H
