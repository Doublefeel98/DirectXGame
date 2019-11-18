#include "../Framework/Scene.h";
#include "ScoreBoard.h";
#include "Define.h"
#include "AladdinResources.h"

class SceneOne : public CScene
{
	AladdinResources *resoucres;
	ScoreBoard* scoreboard;
public:
	SceneOne();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};