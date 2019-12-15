#include "Sprites.h"
#include "Game.h"
#include "debug.h"

CSprite::CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex, int dx, int dy)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
	this->dx = dx;
	this->dy = dy;
}



CSprites* CSprites::__instance = NULL;

CSprites* CSprites::GetInstance()
{
	if (__instance == NULL) __instance = new CSprites();
	return __instance;
}

void CSprite::Draw(float x, float y, int alpha)
{
	CGame* game = CGame::GetInstance();
	game->Draw(x + dx, y + dy, texture, left, top, right, bottom, alpha);
}

void CSprite::Draw(D3DXVECTOR3& pos, RECT& rect, int alpha)
{
	pos.x += dx;
	pos.y += dy;
	CGame* game = CGame::GetInstance();
	game->Draw(texture, pos, rect, alpha);
}


void CSprite::Draw(D3DXVECTOR3& pos, int alpha)
{
	pos.x += dx;
	pos.y += dy;
	CGame* game = CGame::GetInstance();
	game->Draw(texture, pos, alpha);
}

void CSprite::DrawFlipOx(float x, float y, int alpha)
{
	CGame* game = CGame::GetInstance();
	game->DrawFlipOx(x + dx, y + dy, texture, left, top, right, bottom, alpha);
}

void CSprite::DrawWithoutCamera(float x, float y, int alpha)
{
	CGame* game = CGame::GetInstance();
	game->DrawWithoutCamera(x + dx, y + dy, texture, left, top, right, bottom, alpha);
}

void CSprite::DrawWithoutCamera(D3DXVECTOR3& pos, RECT& rect, int alpha)
{
	pos.x += dx;
	pos.y += dy;
	CGame* game = CGame::GetInstance();
	game->DrawWithoutCamera(texture, pos, rect, alpha);
}

void CSprite::DrawWithoutCamera(D3DXVECTOR3& pos, int alpha)
{
	pos.x += dx;
	pos.y += dy;
	CGame* game = CGame::GetInstance();
	game->DrawWithoutCamera(texture, pos, alpha);
}

//
//void CSprite::Draw(float x ,float y, int alpha)
//{
//	CGame * game = CGame::GetInstance();
//	game->Draw(x,y, texture, left, top, right, bottom, alpha);
//}




void CSprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex, int dx, int dy)
{
	LPSPRITE s = new CSprite(id, left, top, right, bottom, tex, dx, dy);
	sprites[id] = s;
}

void CSprites::AddByWidthHeight(int id, int left, int top, int width, int height, LPDIRECT3DTEXTURE9 tex, int dx, int dy)
{
	LPSPRITE s = new CSprite(id, left, top, left + width, top + height, tex, dx, dy);
	sprites[id] = s;
}

LPSPRITE CSprites::Get(int id)
{
	return sprites[id];
}

void CAnimation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t = this->defaultTime;

	LPSPRITE sprite = CSprites::GetInstance()->Get(spriteId);
	LPANIMATION_FRAME frame = new CAnimationFrame(sprite, t);
	frames.push_back(frame);
}

//void CAnimation::Render(float x, float y, int alpha)
//{
//	DWORD now = GetTickCount();
//	if (currentFrame == -1) 
//	{
//		currentFrame = 0; 
//		lastFrameTime = now;
//	}
//	else
//	{
//		DWORD t = frames[currentFrame]->GetTime();
//		if (now - lastFrameTime > t)
//		{
//			currentFrame++;
//			lastFrameTime = now;
//			if (currentFrame == frames.size()) currentFrame = 0;
//		}
//		
//	}
//
//	frames[currentFrame]->GetSprite()->Draw(x, y, alpha);
//}

void CAnimation::Render(float x, float y, int alpha, bool isFollow)
{
	DWORD now = GetTickCount();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		if (!paused)
		{
			DWORD t = frames[currentFrame]->GetTime();
			if (now - lastFrameTime > t)
			{
				if (IsLastFrame && !IsLoop) {}
				else {
					currentFrame++;
				}
				lastFrameTime = now;
				if (currentFrame == frames.size())
				{
					if (IsLoop) {
						currentFrame = 0;
					}
					else
					{
						currentFrame = frames.size() - 1;
						IsLastFrame = true;
					}
				}
			}
		}
	}
	if (isFollow)
	{
		frames[currentFrame]->GetSprite()->Draw(x, y, alpha);
	}
	else {
		frames[currentFrame]->GetSprite()->DrawWithoutCamera(x, y, alpha);
	}
}

void CAnimation::RenderFlipOx(float x, float y, int alpha)
{
	DWORD now = GetTickCount();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
		}

	}

	frames[currentFrame]->GetSprite()->DrawFlipOx(x, y, alpha);
}


CAnimations* CAnimations::__instance = NULL;

CAnimations* CAnimations::GetInstance()
{
	if (__instance == NULL) __instance = new CAnimations();
	return __instance;
}

void CAnimations::Add(int id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION CAnimations::Get(int id)
{
	return animations[id];
}