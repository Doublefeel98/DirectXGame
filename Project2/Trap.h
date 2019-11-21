#pragma once
#ifndef Trap_H
#define Trap_H
#include"ActionObject.h"
#include"Aladin.h"

#define MAX_HP 3

#define WIDTH 40
#define HEIGHT 15
#define WIDTH_MIN 20
class Trap :public ActionObject {
private:
	int center_region_y;
public:
	Trap();
	Trap(int x, int y, Direction d);
	~Trap();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();
	void SetState(State s);
	void SetDirection(Direction d);
	void Reset(int x, int y, Direction d);
};

#endif // !Trap
