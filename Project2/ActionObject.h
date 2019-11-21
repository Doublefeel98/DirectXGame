#pragma once
#ifndef  ActionObject_H_
#define ActionObject_H_
#include"Object.h"
#include"Camera.h"

class ActionObject :public Object {
public:
	State state;
	Direction direction;

	int hitpoints;
	bool destroyed;

	bool actived;

public:
	ActionObject();
	ActionObject(int x, int y, int w, int h, Direction d);
	~ActionObject();

	virtual void Update(DWORD ddt, vector<Object*>* list) {};
	virtual void Render();
	virtual void LoadResource() {};

	virtual BoundingBox GetBoundingBox();
	virtual void SetState(State s);
	virtual void SetDirection(Direction d) {};
	virtual void SetBeingAttacked(int damage){this->hitpoints -= damage;}
	virtual bool IsDestroyed() { return destroyed;}
	virtual bool isActived() { return actived; }
	virtual void SetHitpoint() { this->hitpoints -= 1; }


	virtual State GetState();
	virtual Direction GetDirection();
	virtual int GetDamage() { return 1; }

	virtual void SetActived(bool active) { this->actived = active; }

};
#endif // ! ActionObject_H
