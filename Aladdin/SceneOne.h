#include "../Framework/Scene.h"
#include "ScoreBoard.h"
#include "Define.h"
#include "AladdinObjects.h"
#include "Aladdin.h"

class SceneOne : public CScene
{
	Aladdin* aladdin;
	AladdinObjects* aladinObjects;
	ScoreBoard* scoreboard;
	vector<LPGAMEOBJECT> pilars;
	vector<LPGAMEOBJECT> exit;
	vector<LPGAMEOBJECT> fances;
public:
	SceneOne();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};