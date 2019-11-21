#pragma once
#ifndef Guard_H
#define Guard_H
#include"ActionObject.h"
#include"Aladin.h"
#include"Smoke.h"
#define MAX_HP 3

#define WIDTH 40
#define HEIGHT 40
#define WIDTH_ATTACK 110
class Guard :public ActionObject {
private:
	int center_region_y;
public:
	Guard();
	Guard(int x, int y, Direction d);
	~Guard();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();
	void SetState(State s);
	void SetDirection(Direction d);
	void Reset(int x, int y, Direction d);
};

#endif // !Guard_H
