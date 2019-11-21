#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<dinput.h>

#include"Camera.h"
#include"Game.h"
#include"Aladin.h"
#include"Map.h"
#include"Object.h"
#include"QuadTree.h"

class MyGame : public Game {
private:
	Aladin* aladin;
	Map* map;
	vector<Object*> Objects;
	float x, y;

	vector<Object*> Enemies;
	vector<Object*> DynamicObjects;
	vector<Object*> StaticObjects;
	vector<Object*> Items;
public:
	MyGame();
	MyGame(int cmd);
	~MyGame();

	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	void Update();

	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);

};
