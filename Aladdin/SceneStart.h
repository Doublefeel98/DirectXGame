#include "../Framework/Scene.h"
#include "SceneStartBoard.h"
#include "Define.h"

class SceneStart : public CScene
{
	CSprite* background;
	CSprite* intro;
	CSprites* sprites;
	int x, y;
	DWORD timeDelay;
	bool isDelay, sound;
public:
	SceneStart();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};