#pragma once
#include "../Framework/Effect.h"
class TextTitleScreen : public Effect
{
	int ani;
	DWORD time_start;
public:
	TextTitleScreen();
	~TextTitleScreen();
	void Update(DWORD dt);
	void Render();
	void StartFlashingEffect();
	void ReStart();
};
