#include "../Framework/Scene.h";
#include "ScoreBoard.h";
#include "Define.h"
#include "AladdinObjects.h"

class SceneOne : public CScene
{
	AladdinObjects *objects;
	ScoreBoard* scoreboard;
public:
	SceneOne();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};