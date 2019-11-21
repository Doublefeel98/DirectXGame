#pragma once
#ifndef Penny_H
#define Penny_H
#include"ActionObject.h"
#include"Aladin.h"
#include"Smoke.h"
#define WIDTH 15
#define HEIGHT 15
#define VY 0.2f
#define VX 0.2f
#define MAX_HP 3

class Penny :public ActionObject
{
private:
	int center_region_y;
	float time_active;
	bool attack;
	bool active;

public:
	Penny();
	Penny(int x, int y, Direction);
	~Penny();

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

#pragma once
