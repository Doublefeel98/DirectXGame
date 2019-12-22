#include "../Framework/Scene.h"
#include "SceneEndBoard.h"
#include "Define.h"

class SceneEnd : public CScene
{
	SceneEndBoard* sceneEndBoard;
public:
	SceneEnd();
	void Render();
	void Update(DWORD dt);
	void DestroyAll();
};