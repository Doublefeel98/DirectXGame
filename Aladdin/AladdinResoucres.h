#pragma once
#include "../Framework/GameObject.h"
#include "../Framework/Textures.h"
#include "../Framework/Sprites.h"
class AladdinResoucres
{
	CTextures* textures;
	CSprites* sprites;
	CAnimations* animations;
	void LoadTextures();
	void LoadSprites();
	void LoadAnimations();
public:
	AladdinResoucres();
	void LoadResoucre();
};

