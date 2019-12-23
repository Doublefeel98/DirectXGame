#include "../Framework/Scene.h"
#include "SceneEndBoard.h"
#include "Define.h"

class SceneEnd : public CScene
{
	CSprite* complete;
	CSprite* endBackground;
	CSprites* sprites;
	int x, y;
	DWORD timeDelay;
	bool isDelay;
public:
	SceneEnd();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};