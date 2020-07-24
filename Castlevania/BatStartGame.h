#pragma once
#include "../Framework/Effect.h"

class BatStartGame : public Effect
{
	DWORD time_start;
	int ani;
	bool is_pause_ani;
public:
	void Update(DWORD dt);
	void Render();
	BatStartGame();
	~BatStartGame();
	void SetPauseAni(bool is_pause_ani) { this->is_pause_ani = is_pause_ani; }
	bool IsPauseAni() { return is_pause_ani; }
	void ReStart();
};
