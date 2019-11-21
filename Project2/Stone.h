#pragma once
#ifndef Stone_H
#define Stone_H
#include"ActionObject.h"
#include"Aladin.h"

#define MAX_HP 3

#define WIDTH 35
#define HEIGHT 15

class Stone :public ActionObject {
private:
	int center_region_y;
public:
	Stone();
	Stone(int x, int y, Direction d);
	~Stone();

	void Update(DWORD dt, vector<Object*>* list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();
	void SetState(State s);
	void SetDirection(Direction d);
	void Reset(int x, int y, Direction d);
};

#endif // !Stone
