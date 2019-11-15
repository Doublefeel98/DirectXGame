/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102

	SAMPLE 04 - COLLISION

	This sample illustrates how to:

		1/ Implement SweptAABB algorithm between moving objects
		2/ Implement a simple (yet effective) collision frame work

	Key functions:
		CGame::SweptAABB
		CGameObject::SweptAABBEx
		CGameObject::CalcPotentialCollisions
		CGameObject::FilterCollision

		CGameObject::GetBoundingBox

================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "../Framework/debug.h"
#include "../Framework/Game.h"
#include "../Framework/GameObject.h"
#include "../Framework/Textures.h"

#include "Aladdin.h"
#include "Define.h"
#include "Brick.h"


CGame * game;

Aladdin* aladdin;

vector<LPGAMEOBJECT> objects;

class CSampleKeyHander : public CKeyEventHandler
{
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander* keyHandler;

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_X:
		aladdin->SetState(ALADDIN_STATE_STANDING_SLASH);
		break;
	case DIK_C:
		aladdin->SetState(ALADDIN_STATE_JUMP);
		break;
	case DIK_A: // reset
		aladdin->SetState(ALADDIN_STATE_IDLE);
		aladdin->SetPosition(50.0f, 0.0f);
		aladdin->SetSpeed(0, 0);
		break;
	}
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}

void CSampleKeyHander::KeyState(BYTE* states)
{
	// disable control key when Mario die 
	if (aladdin->GetState() == ALADDIN_STATE_DIE) return;
	if (game->IsKeyDown(DIK_RIGHT))
		aladdin->SetState(ALADDIN_STATE_WALKING_RIGHT);
	else if (game->IsKeyDown(DIK_LEFT))
		aladdin->SetState(ALADDIN_STATE_WALKING_LEFT);
	else {
		aladdin->SetState(ALADDIN_STATE_IDLE);
	}	
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

/*
	Load all game resources
	In this example: load textures, sprites, animations and aladdin object

	TO-DO: Improve this function by loading texture,sprite,animation,object from file
*/
void LoadResources()
{
	CTextures* textures = CTextures::GetInstance();

	//textures->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(ID_TEX_MISC, L"resources\\textures\\misc.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ALADDIN_GO_RIGHT, L"resources\\textures\\aladdinGoRight.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ALADDIN_GO_LEFT, L"resources\\textures\\aladdinGoLeft.png", D3DCOLOR_XRGB(255, 0, 255));


	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPDIRECT3DTEXTURE9 texAladdinGoRight = textures->Get(ID_TEX_ALADDIN_GO_RIGHT);
	LPDIRECT3DTEXTURE9 texAladdinGoLeft = textures->Get(ID_TEX_ALADDIN_GO_LEFT);

	sprites->Add(10001, 3, 9, 41, 59, texAladdinGoRight);		// idle right

	sprites->Add(10002, 6, 83, 46, 135, texAladdinGoRight);		// standing idle right
	sprites->Add(10003, 51, 81, 112, 134, texAladdinGoRight);
	sprites->Add(10004, 116, 80, 178, 134, texAladdinGoRight);
	sprites->Add(10005, 180, 81, 221, 134, texAladdinGoRight);
	sprites->Add(10006, 228, 81, 267, 134, texAladdinGoRight);
	sprites->Add(10007, 275, 81, 311, 134, texAladdinGoRight);
	sprites->Add(10008, 319, 81, 359, 134, texAladdinGoRight);
	sprites->Add(10009, 366, 79, 407, 134, texAladdinGoRight);
	sprites->Add(10010, 417, 78, 454, 134, texAladdinGoRight);
	sprites->Add(10011, 465, 78, 503, 134, texAladdinGoRight);
	sprites->Add(10012, 516, 78, 554, 134, texAladdinGoRight);
	sprites->Add(10013, 568, 79, 608, 134, texAladdinGoRight);
	sprites->Add(10014, 619, 80, 660, 134, texAladdinGoRight);
	sprites->Add(10015, 668, 80, 708, 134, texAladdinGoRight);
	sprites->Add(10016, 715, 81, 754, 134, texAladdinGoRight);

	sprites->Add(10021, 205, 500, 247, 549, texAladdinGoRight);		// sitting down right
	sprites->Add(10022, 258, 509, 306, 549, texAladdinGoRight);
	sprites->Add(10023, 315, 519, 369, 549, texAladdinGoRight);
	sprites->Add(10024, 378, 516, 431, 551, texAladdinGoRight);

	sprites->Add(10031, 11, 496, 50, 546, texAladdinGoRight);		// looking up right
	sprites->Add(10032, 59, 490, 104, 549, texAladdinGoRight);
	sprites->Add(10033, 111, 491, 160, 549, texAladdinGoRight);

	sprites->Add(10101, 14, 1225, 53, 1273, texAladdinGoRight);		// walk	right
	sprites->Add(10102, 66, 1222, 108, 1273, texAladdinGoRight);
	sprites->Add(10103, 120, 1220, 160, 1273, texAladdinGoRight);
	sprites->Add(10104, 171, 1216, 211, 1273, texAladdinGoRight);
	sprites->Add(10105, 220, 1216, 271, 1272, texAladdinGoRight);
	sprites->Add(10106, 279, 1219, 324, 1273, texAladdinGoRight);
	sprites->Add(10107, 334, 1215, 375, 1273, texAladdinGoRight);
	sprites->Add(10108, 386, 1221, 426, 1273, texAladdinGoRight);
	sprites->Add(10109, 440, 1219, 474, 1273, texAladdinGoRight);
	sprites->Add(10110, 488, 1216, 536, 1273, texAladdinGoRight);
	sprites->Add(10111, 547, 1215, 601, 1273, texAladdinGoRight);
	sprites->Add(10112, 611, 1219, 665, 1273, texAladdinGoRight);
	sprites->Add(10113, 679, 1218, 722, 1273, texAladdinGoRight);

	sprites->Add(10121, 11, 1293, 68, 1350, texAladdinGoRight);		// stop	right
	sprites->Add(10122, 83, 1294, 127, 1350, texAladdinGoRight);
	sprites->Add(10123, 134, 1284, 185, 1350, texAladdinGoRight);
	sprites->Add(10124, 200, 1283, 246, 1348, texAladdinGoRight);
	sprites->Add(10125, 256, 1285, 298, 1349, texAladdinGoRight);
	sprites->Add(10126, 309, 1306, 364, 1352, texAladdinGoRight);
	sprites->Add(10127, 376, 1308, 428, 1352, texAladdinGoRight);
	sprites->Add(10128, 437, 1300, 483, 1352, texAladdinGoRight);
	sprites->Add(10129, 498, 1294, 549, 1346, texAladdinGoRight);

	sprites->Add(10201, 8, 846, 67, 889, texAladdinGoRight);		// jump	right
	sprites->Add(10202, 75, 828, 127, 890, texAladdinGoRight);
	sprites->Add(10203, 137, 829, 191, 890, texAladdinGoRight);
	sprites->Add(10204, 203, 824, 257, 893, texAladdinGoRight);
	sprites->Add(10205, 269, 820, 320, 894, texAladdinGoRight);
	sprites->Add(10206, 336, 829, 374, 895, texAladdinGoRight);
	sprites->Add(10207, 390, 818, 425, 897, texAladdinGoRight);
	sprites->Add(10208, 448, 808, 482, 901, texAladdinGoRight);
	sprites->Add(10209, 504, 810, 538, 903, texAladdinGoRight);
	sprites->Add(10210, 564, 812, 598, 905, texAladdinGoRight);

	sprites->Add(10301, 5, 337, 50, 388, texAladdinGoRight);		// standing slash right
	sprites->Add(10302, 54, 326, 105, 388, texAladdinGoRight);
	sprites->Add(10303, 115, 314, 160, 388, texAladdinGoRight);
	sprites->Add(10304, 171, 319, 253, 388, texAladdinGoRight);
	sprites->Add(10305, 260, 335, 311, 388, texAladdinGoRight);

	sprites->Add(10311, 9, 640, 56, 673, texAladdinGoRight);		// sitting slash right
	sprites->Add(10312, 64, 642, 109, 673, texAladdinGoRight);
	sprites->Add(10313, 115, 640, 186, 673, texAladdinGoRight);
	sprites->Add(10314, 193, 639, 285, 673, texAladdinGoRight);
	sprites->Add(10315, 298, 640, 382, 673, texAladdinGoRight);
	sprites->Add(10316, 392, 640, 463, 673, texAladdinGoRight);
	sprites->Add(10317, 475, 642, 520, 673, texAladdinGoRight);

	sprites->Add(10321, 11, 420, 53, 473, texAladdinGoRight);		// looking up slash right
	sprites->Add(10322, 66, 413, 104, 473, texAladdinGoRight);
	sprites->Add(10323, 111, 412, 176, 473, texAladdinGoRight);
	sprites->Add(10324, 193, 415, 240, 473, texAladdinGoRight);
	sprites->Add(10325, 249, 418, 296, 472, texAladdinGoRight);
	sprites->Add(10326, 298, 424, 352, 472, texAladdinGoRight);
	sprites->Add(10327, 363, 401, 437, 472, texAladdinGoRight);
	sprites->Add(10328, 452, 386, 506, 472, texAladdinGoRight);
	sprites->Add(10329, 520, 401, 569, 472, texAladdinGoRight);
	sprites->Add(10330, 584, 405, 635, 472, texAladdinGoRight);
	sprites->Add(10331, 644, 415, 697, 472, texAladdinGoRight);
	sprites->Add(10332, 704, 418, 750, 472, texAladdinGoRight);

	sprites->Add(10401, 7, 235, 50, 291, texAladdinGoRight);		// throw apple right
	sprites->Add(10402, 57, 232, 98, 291, texAladdinGoRight);
	sprites->Add(10403, 109, 233, 147, 291, texAladdinGoRight);
	sprites->Add(10404, 163, 231, 209, 291, texAladdinGoRight);
	sprites->Add(10405, 221, 233, 258, 291, texAladdinGoRight);
	sprites->Add(10406, 268, 239, 320, 291, texAladdinGoRight);

	sprites->Add(10411, 9, 571, 484, 615, texAladdinGoRight);		// sitting throw apple right
	sprites->Add(10412, 58, 567, 95, 615, texAladdinGoRight);
	sprites->Add(10413, 107, 571, 157, 619, texAladdinGoRight);
	sprites->Add(10414, 164, 578, 246, 615, texAladdinGoRight);
	sprites->Add(10415, 256, 579, 313, 616, texAladdinGoRight);

	sprites->Add(10421, 19, 1005, 68, 1060, texAladdinGoRight);		// jumping throw apple right
	sprites->Add(10422, 77, 1007, 120, 1059, texAladdinGoRight);
	sprites->Add(10423, 132, 1008, 171, 1061, texAladdinGoRight);
	sprites->Add(10424, 185, 1008, 237, 1061, texAladdinGoRight);
	sprites->Add(10425, 253, 1012, 293, 1064, texAladdinGoRight);

	sprites->Add(11001, 1081, 9, 1118, 59, texAladdinGoLeft);	// idle left	
	
	sprites->Add(11002, 1075, 81, 1115, 134, texAladdinGoLeft);		// standing left
	sprites->Add(11003, 1009, 81, 1070, 134, texAladdinGoLeft);
	sprites->Add(11004, 943, 80, 1005, 134, texAladdinGoLeft);
	sprites->Add(11005, 900, 81, 941, 134, texAladdinGoLeft);
	sprites->Add(11006, 854, 81, 893, 134, texAladdinGoLeft);
	sprites->Add(11007, 810, 81, 846, 134, texAladdinGoLeft);
	sprites->Add(11008, 762, 81, 802, 134, texAladdinGoLeft);
	sprites->Add(11009, 720, 79, 755, 134, texAladdinGoLeft);
	sprites->Add(11010, 667, 78, 704, 134, texAladdinGoLeft);
	sprites->Add(11011, 618, 78, 656, 134, texAladdinGoLeft);
	sprites->Add(10012, 567, 78, 605, 134, texAladdinGoLeft);
	sprites->Add(11013, 513, 79, 553, 134, texAladdinGoLeft);
	sprites->Add(11014, 461, 80, 502, 134, texAladdinGoLeft);
	sprites->Add(11015, 413, 80, 453, 134, texAladdinGoLeft);
	sprites->Add(11016, 367, 81, 406, 134, texAladdinGoLeft);

	sprites->Add(11021, 874, 500, 916, 549, texAladdinGoLeft);		// sitting down left
	sprites->Add(11022, 815, 509, 863, 549, texAladdinGoLeft);
	sprites->Add(11023, 752, 519, 806, 549, texAladdinGoLeft);
	sprites->Add(11024, 690, 516, 743, 551, texAladdinGoLeft);

	sprites->Add(11031, 1071, 496, 1110, 546, texAladdinGoLeft);		// looking up left
	sprites->Add(11032, 1017, 490, 1062, 549, texAladdinGoLeft);
	sprites->Add(11033, 961, 491, 1010, 549, texAladdinGoLeft);

	sprites->Add(11101, 1067, 1225, 1107, 1273, texAladdinGoLeft);		// walk	left
	sprites->Add(11102, 1012, 1222, 1055, 1273, texAladdinGoLeft);
	sprites->Add(11103, 960, 1220, 1001, 1273, texAladdinGoLeft);
	sprites->Add(11104, 909, 1216, 950, 1273, texAladdinGoLeft);
	sprites->Add(11105, 849, 1216, 901, 1272, texAladdinGoLeft);
	sprites->Add(11106, 796, 1219, 842, 1273, texAladdinGoLeft);
	sprites->Add(11107, 745, 1215, 787, 1273, texAladdinGoLeft);
	sprites->Add(11108, 694, 1221, 735, 1273, texAladdinGoLeft);
	sprites->Add(11109, 646, 1219, 681, 1273, texAladdinGoLeft);
	sprites->Add(11110, 584, 1216, 633, 1273, texAladdinGoLeft);
	sprites->Add(11111, 519, 1215, 574, 1273, texAladdinGoLeft);
	sprites->Add(11112, 455, 1219, 510, 1273, texAladdinGoLeft);
	sprites->Add(11113, 398, 1218, 442, 1273, texAladdinGoLeft);

	sprites->Add(11121, 1053, 1293, 1110, 1350, texAladdinGoLeft);		// stop	left
	sprites->Add(11122, 994, 1294, 1038, 1350, texAladdinGoLeft);
	sprites->Add(11123, 936, 1284, 987, 1350, texAladdinGoLeft);
	sprites->Add(11124, 875, 1283, 921, 1348, texAladdinGoLeft);
	sprites->Add(11125, 823, 1285, 865, 1349, texAladdinGoLeft);
	sprites->Add(11126, 757, 1306, 812, 1352, texAladdinGoLeft);
	sprites->Add(11127, 693, 1308, 745, 1352, texAladdinGoLeft);
	sprites->Add(11128, 638, 1300, 684, 1352, texAladdinGoLeft);
	sprites->Add(11129, 572, 1294, 623, 1346, texAladdinGoLeft);

	sprites->Add(11201, 1054, 846, 1113, 889, texAladdinGoLeft);		// jump	left
	sprites->Add(11202, 994, 828, 1046, 890, texAladdinGoLeft);
	sprites->Add(11203, 930, 829, 984, 890, texAladdinGoLeft);
	sprites->Add(11204, 864, 824, 918, 893, texAladdinGoLeft);
	sprites->Add(11205, 801, 820, 852, 894, texAladdinGoLeft);
	sprites->Add(11206, 747, 829, 785, 895, texAladdinGoLeft);
	sprites->Add(11207, 696, 818, 731, 897, texAladdinGoLeft);
	sprites->Add(11208, 639, 808, 673, 901, texAladdinGoLeft);
	sprites->Add(11209, 583, 810, 617, 903, texAladdinGoLeft);
	sprites->Add(11210, 523, 812, 557, 905, texAladdinGoLeft);

	sprites->Add(11301, 1071, 337, 1116, 388, texAladdinGoLeft);		// standing slash left
	sprites->Add(11302, 1016, 326, 1067, 388, texAladdinGoLeft);
	sprites->Add(11303, 961, 314, 1006, 388, texAladdinGoLeft);
	sprites->Add(11304, 868, 319, 950, 388, texAladdinGoLeft);
	sprites->Add(11305, 810, 335, 861, 388, texAladdinGoLeft);

	sprites->Add(11311, 1065, 640, 1112, 673, texAladdinGoLeft);		// sitting slash left
	sprites->Add(11312, 1012, 642, 1057, 673, texAladdinGoLeft);
	sprites->Add(11313, 935, 640, 1006, 673, texAladdinGoLeft);
	sprites->Add(11314, 836, 639, 928, 673, texAladdinGoLeft);
	sprites->Add(11315, 739, 640, 823, 673, texAladdinGoLeft);
	sprites->Add(11316, 658, 640, 729, 673, texAladdinGoLeft);
	sprites->Add(11317, 601, 642, 646, 673, texAladdinGoLeft);

	sprites->Add(11321, 1068, 420, 1110, 473, texAladdinGoLeft);		// looking up slash left
	sprites->Add(11322, 1017, 413, 104, 1055, texAladdinGoLeft);
	sprites->Add(11323, 945, 412, 1010, 473, texAladdinGoLeft);
	sprites->Add(11324, 881, 415, 928, 473, texAladdinGoLeft);
	sprites->Add(11325, 825, 418, 872, 472, texAladdinGoLeft);
	sprites->Add(11326, 769, 424, 823, 472, texAladdinGoLeft);
	sprites->Add(11327, 684, 401, 758, 472, texAladdinGoLeft);
	sprites->Add(11328, 615, 386, 669, 472, texAladdinGoLeft);
	sprites->Add(11329, 552, 401, 601, 472, texAladdinGoLeft);
	sprites->Add(11330, 486, 405, 537, 472, texAladdinGoLeft);
	sprites->Add(11331, 424, 415, 477, 472, texAladdinGoLeft);
	sprites->Add(11332, 371, 418, 417, 472, texAladdinGoLeft);

	sprites->Add(11401, 1071, 235, 1114, 291, texAladdinGoLeft);		// throw apple left
	sprites->Add(11402, 1023, 232, 1064, 291, texAladdinGoLeft);
	sprites->Add(11403, 974, 233, 1012, 291, texAladdinGoLeft);
	sprites->Add(11404, 912, 231, 958, 291, texAladdinGoLeft);
	sprites->Add(114015, 863, 233, 900, 291, texAladdinGoLeft);
	sprites->Add(11406, 814, 239, 853, 291, texAladdinGoLeft);

	sprites->Add(10411, 1075, 571, 112, 615, texAladdinGoLeft);		// sitting throw apple left
	sprites->Add(10412, 1026, 567, 1063, 615, texAladdinGoLeft);
	sprites->Add(10413, 964, 571, 1014, 619, texAladdinGoLeft);
	sprites->Add(10414, 875, 578, 957, 615, texAladdinGoLeft);
	sprites->Add(10415, 808, 579, 865, 616, texAladdinGoLeft);

	LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 408, 225, 424, 241, texMisc);

	LPANIMATION ani;

	ani = new CAnimation(100);	// idle right
	ani->Add(10001);
	animations->Add(100, ani);

	ani = new CAnimation(100);
	ani->Add(11001);
	animations->Add(101, ani);	//idle left

	//ani = new CAnimation(100);	// standing right
	//ani->Add(10002);
	//ani->Add(10003);
	//ani->Add(10004);
	//ani->Add(10005);
	//ani->Add(10006);
	//ani->Add(10007);
	//ani->Add(10008);
	//ani->Add(10009);
	//ani->Add(10010);
	//ani->Add(10011);
	//ani->Add(10012);
	//ani->Add(10013);
	//ani->Add(10014);
	//ani->Add(10015);
	//ani->Add(10016);
	//animations->Add(102, ani);

	//ani = new CAnimation(100);	// standing left
	//ani->Add(11002);
	//ani->Add(11003);
	//ani->Add(11004);
	//ani->Add(11005);
	//ani->Add(11006);
	//ani->Add(11007);
	//ani->Add(11008);
	//ani->Add(11009);
	//ani->Add(11010);
	//ani->Add(11011);
	//ani->Add(11012);
	//ani->Add(11013);
	//ani->Add(11014);
	//ani->Add(11015);
	//ani->Add(11016);
	//animations->Add(103, ani);

	ani = new CAnimation(100);	// sitting down right
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	animations->Add(104, ani);

	ani = new CAnimation(100);	// sitting down left
	ani->Add(11021);
	ani->Add(11022);
	ani->Add(11023);
	ani->Add(11024);
	animations->Add(105, ani);

	ani = new CAnimation(100);	// looking up right
	ani->Add(10031);
	ani->Add(10032);
	ani->Add(10033);
	animations->Add(106, ani);

	ani = new CAnimation(100);	// looking up left
	ani->Add(11031);
	ani->Add(11032);
	ani->Add(11033);
	animations->Add(107, ani);

	ani = new CAnimation(100);	// walk right
	ani->Add(10101);
	ani->Add(10102);
	ani->Add(10103);
	ani->Add(10104);
	ani->Add(10105);
	ani->Add(10106);
	ani->Add(10107);
	ani->Add(10108);
	ani->Add(10109);
	ani->Add(10110);
	ani->Add(10111);
	ani->Add(10112);
	ani->Add(10113);
	animations->Add(110, ani);

	ani = new CAnimation(100);	// walk left
	ani->Add(11101);
	ani->Add(11102);
	ani->Add(11103);
	ani->Add(11104);
	ani->Add(11105);
	ani->Add(11106);
	ani->Add(11107);
	ani->Add(11108);
	ani->Add(11109);
	ani->Add(11110);
	ani->Add(11111);
	ani->Add(11112);
	ani->Add(11113);
	animations->Add(111, ani);

	ani = new CAnimation(100);	// stop right
	ani->Add(10121);
	ani->Add(10122);
	ani->Add(10123);
	ani->Add(10124);
	ani->Add(10125);
	ani->Add(10126);
	ani->Add(10127);
	ani->Add(10128);
	ani->Add(10129);
	animations->Add(112, ani);

	ani = new CAnimation(100);	// stop left
	ani->Add(11121);
	ani->Add(11122);
	ani->Add(11123);
	ani->Add(11124);
	ani->Add(11125);
	ani->Add(11126);
	ani->Add(11127);
	ani->Add(11128);
	ani->Add(11129);
	animations->Add(113, ani);

	ani = new CAnimation(100);	// jump right
	ani->Add(10201);
	ani->Add(10202);
	ani->Add(10203);
	ani->Add(10204);
	ani->Add(10205);
	ani->Add(10206);
	ani->Add(10207);
	ani->Add(10208);
	ani->Add(10209);
	ani->Add(10210);
	animations->Add(120, ani);

	ani = new CAnimation(100);	// jump left
	ani->Add(11201);
	ani->Add(11202);
	ani->Add(11203);
	ani->Add(11204);
	ani->Add(11205);
	ani->Add(11206);
	ani->Add(11207);
	ani->Add(11208);
	ani->Add(11209);
	ani->Add(11210);
	animations->Add(121, ani);

	ani = new CAnimation(100);	// standing slash right
	ani->Add(10301);
	ani->Add(10302);
	ani->Add(10303);
	ani->Add(10304);
	ani->Add(10305);
	animations->Add(131, ani);

	ani = new CAnimation(100);	// standing slash left
	ani->Add(11301);
	ani->Add(11302);
	ani->Add(11303);
	ani->Add(11304);
	ani->Add(11305);
	animations->Add(132, ani);

	ani = new CAnimation(100);	// sitting slash right
	ani->Add(10311);
	ani->Add(10312);
	ani->Add(10313);
	ani->Add(10314);
	ani->Add(10315);
	ani->Add(10316);
	ani->Add(10317);
	animations->Add(133, ani);

	ani = new CAnimation(100);	// sitting slash left
	ani->Add(11311);
	ani->Add(11312);
	ani->Add(11313);
	ani->Add(11314);
	ani->Add(11315);
	ani->Add(11316);
	ani->Add(11317);
	animations->Add(134, ani);

	ani = new CAnimation(100);	// looking up slash right
	ani->Add(10321);
	ani->Add(10322);
	for (int i = 1; i <= 5; i++) {
		ani->Add(10323);
		ani->Add(10324);
		ani->Add(10325);
		ani->Add(10326);
		ani->Add(10327);
		ani->Add(10328);
		ani->Add(10329);
		ani->Add(10330);
	}
	ani->Add(10331);
	ani->Add(10332);
	animations->Add(135, ani);

	ani = new CAnimation(100);	// looking up slash left
	ani->Add(11321);
	ani->Add(11322);
	for (int i = 1; i <= 5; i++) {
		ani->Add(11323);
		ani->Add(11324);
		ani->Add(11325);
		ani->Add(11326);
		ani->Add(11327);
		ani->Add(11328);
		ani->Add(11329);
		ani->Add(11330);
	}
	ani->Add(11331);
	ani->Add(11332);
	animations->Add(136, ani);

	ani = new CAnimation(100);	// throw apple right
	ani->Add(10401);
	ani->Add(10402);
	ani->Add(10403);
	ani->Add(10404);
	ani->Add(10405);
	ani->Add(10406);
	animations->Add(140, ani);

	ani = new CAnimation(100);	// throw apple left
	ani->Add(11401);
	ani->Add(11402);
	ani->Add(11403);
	ani->Add(11404);
	ani->Add(11405);
	ani->Add(11406);
	animations->Add(141, ani);

	ani = new CAnimation(100);	// sitting throw apple right
	ani->Add(10411);
	ani->Add(10412);
	ani->Add(10413);
	ani->Add(10414);
	ani->Add(10415);
	animations->Add(142, ani);

	ani = new CAnimation(100);	// sitting throw apple left
	ani->Add(11411);
	ani->Add(11412);
	ani->Add(11413);
	ani->Add(11414);
	ani->Add(11415);
	animations->Add(143, ani);

	aladdin = new Aladdin();
	aladdin->AddAnimation(100);		// idle right
	aladdin->AddAnimation(101);		//idle left

	//aladdin->AddAnimation(102);		// standing right
	//aladdin->AddAnimation(103);		// standing left

	aladdin->AddAnimation(104);		// sitting down right
	aladdin->AddAnimation(105);		// sitting down left

	aladdin->AddAnimation(106);		// looking up right
	aladdin->AddAnimation(107);		// looking up right
	
	aladdin->AddAnimation(110);		// walking right
	aladdin->AddAnimation(111);		// walking left
	aladdin->AddAnimation(112);		// stop right
	aladdin->AddAnimation(113);		// stop left

	aladdin->AddAnimation(120);		// jump right
	aladdin->AddAnimation(121);		//jump left

	aladdin->AddAnimation(131);		// standing slash right
	aladdin->AddAnimation(132);		// standing slash left
	aladdin->AddAnimation(133);		// sitting slash right
	aladdin->AddAnimation(134);		// sitting slash left
	aladdin->AddAnimation(135);		// looking up slash right
	aladdin->AddAnimation(136);		// looking up slash left

	aladdin->AddAnimation(140);		//throw apple right
	aladdin->AddAnimation(141);		//throw apple left
	aladdin->AddAnimation(142);		//sitting throw apple right
	aladdin->AddAnimation(143);		//sitting throw apple left

	aladdin->SetPosition(50.0f, 0);
	objects.push_back(aladdin);

	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);

	for (int i = 0; i < 30; i++)
	{
		CBrick* brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(0 + i * 16.0f, 150);
		objects.push_back(brick);
	}
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	// We know that Mario is the first object in the list hence we won't add him into the colliable object list
	// TO-DO: This is a "dirty" way, need a more organized way 

	vector<LPGAMEOBJECT> coObjects;
	for (int i = 1; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}


	// Update camera to follow aladdin
	float cx, cy;
	aladdin->GetPosition(cx, cy);

	cx -= SCREEN_WIDTH / 2;
	cy -= SCREEN_HEIGHT / 2;

	CGame::GetInstance()->SetCamPos(cx, 0.0f /*cy*/);
}

/*
	Render a frame
*/
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		for (int i = 0; i < objects.size(); i++)
			objects[i]->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();

			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = CGame::GetInstance();
	game->Init(hWnd);

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);


	LoadResources();

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}