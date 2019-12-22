#include "../Framework/Scene.h"
#include "SceneStartBoard.h"
#include "Define.h"

class SceneStart : public CScene
{
	SceneStartBoard* sceneStartBoard;
public:
	SceneStart();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};