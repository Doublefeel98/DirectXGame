#pragma once
#include "../Framework/GameObject.h"
#include "../Framework/Textures.h"
#include "../Framework/Sprites.h"
class CastlevaniaRescoures
{
	CTextures* textures;
	CSprites* sprites;
	CAnimations* animations;
	void LoadTextures();
	void LoadSprites();
	void LoadAnimations();
public:
	CastlevaniaRescoures();
	void LoadResoucre();
};
