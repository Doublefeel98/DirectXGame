#include "../Framework/Scene.h";
#include "ScoreBoard.h";
#include "Define.h"
#include "AladdinObjects.h"
#include "Aladdin.h"

class SceneOne : public CScene
{
	Aladdin* aladdin;
	AladdinObjects * aladinObjects;
	ScoreBoard* scoreboard;
	char* fileResource;
public:
	SceneOne(Aladdin* aladdin);
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};