#include "TextTitleScreen.h"

TextTitleScreen::TextTitleScreen()
{
	ani = 0;
	time_start = GetTickCount();
}

TextTitleScreen::~TextTitleScreen()
{
}

void TextTitleScreen::Update(DWORD dt)
{
}

void TextTitleScreen::Render()
{
	animation_set->at(ani)->RenderWithoutCamera(72, 136, false);
}

void TextTitleScreen::StartFlashingEffect()
{
	ani = 1;
}

void TextTitleScreen::ReStart()
{
	ani = 0;
}
