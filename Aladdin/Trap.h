#pragma once
#include "../Framework/GameObject.h"
#include "Define.h"

class Trap :public CGameObject {
private:
	bool enabled;
public:
	Trap();
	~Trap();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	bool IsEnabled() { return enabled; }
	void SetEnabled(bool en) { enabled = en; }
};