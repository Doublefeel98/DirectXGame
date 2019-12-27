#include "../Framework/Scene.h"
#include "../Framework/SceneManager.h"
#include "ScoreBoard.h"
#include "Define.h"
#include "AladdinObjects.h"
#include "Aladdin.h"
#include "Exit.h"

class SceneOne : public CScene
{
	Aladdin* aladdin;
	AladdinObjects* aladinObjects;
	ScoreBoard* scoreboard;
	vector<LPGAMEOBJECT> pilars;
	Exit* exit;
	vector<LPGAMEOBJECT> fances;
public:
	SceneOne();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};