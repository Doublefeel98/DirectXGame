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
	void LoadTextures(string file);
	void LoadSprites(string file);
	void LoadAnimations(string file);
public:
	CastlevaniaRescoures();
	void LoadResoucre();
};
