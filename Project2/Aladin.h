#pragma once
#ifndef Aladin_H
#define Aladin_H
#include"ActionObject.h"
#include<d3dx9.h>
#include<list>

#define HEIGHT 60 
#define WIDTH 60
#define GRAVITY -0.01f

#define WALK_SPEED 0.1f
#define JUMP_SPEED 0.2f
#define CLIMB_SPEED 0.05f

#define HP 20

class Aladin :public ActionObject {
private:
	bool isAllowedClimb;
	double startJumping;
	static Aladin* instance;
	int yStartJump, yPrev;
	bool isGround;
	int pennies, apples, life;
	int _x, _y;

	Animation* lifebar;
	Animation* penny;
public:
	Aladin();
	~Aladin();


	static Aladin* Instance();

	void Update(DWORD dt, vector<Object*>* dynamicObject);
	//void ProcessBullet(list<Bullet*> list);
	void ProcessEnemy(vector<Object*> list);
	void ProcessStatic(vector<Object*> list);
	void Render();
	void LoadResource();

	BoundingBox GetBoundingBox();

	void SetState(State s);
	void SetDirection(Direction d);
	void SetClimb(bool allow) { this->isAllowedClimb = allow; }
	void SetStartJump() { this->yStartJump = this->y; }

	State GetState();
	State GetNewState(State currentState, EController controller);
	Direction GetDirection();
	float getDistanceJump;
	void GetPosition(float& x, float& y);
	bool IsGround() {
		return this->isGround;
	}
	bool isFreeFall() { return (this->y + 2 < yPrev); }
	bool isDie() { return (this->hitpoints <= 0); }
	void SetGround(bool ground) { this->isGround = ground; }
	bool IsFinshAction()
	{
		return this->animation->Sprites[state]->IsFinalFrame();
	}
	void ResetAnimation() { this->animation->Sprites[state]->Reset(); }
	bool IsGround(int dis = 0);
	bool IsChain();

};
#endif