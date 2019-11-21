#include"MyGame.h"

MyGame::MyGame() {

}

MyGame::MyGame(int cmd) : Game(cmd) {

}
MyGame::~MyGame() {

}
void MyGame::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t) {
	OutputDebugString("Render Frame \n");
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	this->map->Render();
	//this->textStartGame->Render();
	//if (!Aladin::Instance()->isDie());
	for (auto o : Objects) {
		o->Render();
	}

	//WeaponSystem::Instance()->Render();
	this->aladin->Render();
	//this->launchers->Render();

	G_SpriteHandler->End();
}
void MyGame::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta) {
	float aladin_x, aladin_y;
	Aladin::Instance()->GetPosition(aladin_x, aladin_y);

	EController controller = NoneControl;
	if (IsKeyDown(DIK_LEFT)) {
		this->aladin->SetDirection(LEFT);
		controller = LeftControl;
	}
	if (IsKeyDown(DIK_RIGHT)) {
		this->aladin->SetDirection(RIGHT);
		controller = RightControl;
	}
	if (IsKeyDown(DIK_DOWN)) {
		controller = KneelControl;
	}
	if (IsKeyDown(DIK_S)) {
		controller = ThrowControl;
	}
	if (IsKeyDown(DIK_A)) {
		controller = SliceControl;
	}
	if (IsKeyDown(DIK_SPACE)) {
		controller = JumpControl;
	}
	
	State s = this->aladin->GetNewState(aladin->GetState(), controller);
	this->aladin->SetState(s);

}
void MyGame::Update() {
	aladin->GetPosition(x, y);
	Camera::Instance()->Update(x, y);

	this->Objects.clear();
	this->Objects = QuadTree::Instance()->GetObjects(Camera::Instance()->GetBound());

	this->Enemies.clear();
	this->Items.clear();
	this->DynamicObjects.clear();
	this->StaticObjects.clear();


	vector<Object*> temps;
	for (auto o : Objects) {
		switch (o->GetNameObject()) {
		case BAT:
		case GUARD:
		case SKELETON:
		case BIRD:
			Enemies.push_back(o);
			break;
		case APPLE:
		case HEART:
		case FACE:
		case VASE:
		case PENNY:
			Items.push_back(o);
			break;
		case TRAP:
		case BALL:
			DynamicObjects.push_back(o);
			break;
		default:
			break;
		}
	}
	for (auto o : Enemies) {
		o->Update(delta_time, &Enemies);
	}
	//for (auto o : DynamicObjects) {
	//	o->Update(delta_time, aladin);
	//}
	//DynamicObjects.push_back(this->launchers);

	aladin->Update(delta_time, &DynamicObjects);
	aladin->Update(delta_time, &Enemies);
	aladin->Update(delta_time, &Items);

}
void MyGame::LoadResources(LPDIRECT3DDEVICE9 d3ddv) {
	OutputDebugString("Load Aladin \n");
	this->aladin = Aladin::Instance();
	this->aladin->SetDirection(RIGHT);
	OutputDebugString("MAp \n");
	map = new Map();
}
void MyGame::OnKeyDown(int KeyCode) {

}
void MyGame::OnKeyUp(int KeyCode) {
	if (KeyCode == DIK_A) {
		
	}
	if (KeyCode == DIK_X) {
		aladin->SetState(KNEEL);
	}
	if (KeyCode == DIK_Z) {
		aladin->SetState(JUMPLAND);
	}
}