#pragma once
#ifndef Bat_H
#define Bat_H
#include"ActionObject.h"
#include"Aladin.h"
#include"Smoke.h"
#define WIDTH 20
#define HEIGHT 20
#define VY 0.2f
#define VX 0.2f
#define MAX_HP 3

class Bat :public ActionObject
{
private: 
	int center_region_y;
	float time_active;
	bool attack;
	bool active;

public:
	Bat();
	Bat(int x, int y, Direction);
	~Bat();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();

	void SetState(State s);
	void SetDirection(Direction d);
	void SetAttack(bool allow) { this->attack = allow; };
	void Reset(int x, int y, Direction d, float vx, float vy);
};
#endif // 

