#include "AladdinResoucres.h"
#include "Define.h"


void AladdinResoucres::LoadTextures()
{
	textures->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(ID_TEX_ALADDIN_GO_RIGHT, L"resources\\textures\\aladdinGoRight.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ALADDIN_GO_LEFT, L"resources\\textures\\aladdinGoLeft.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ALADDIN_FULL_RIGHT, L"resources\\textures\\aladdinStateFullRight.png", D3DCOLOR_XRGB(106, 148, 189));
	textures->Add(ID_TEX_ALADDIN_FULL_LEFT, L"resources\\textures\\aladdinStateFullLeft.png", D3DCOLOR_XRGB(106, 148, 189));

	//item
	textures->Add(ID_TEX_ITEM, L"resources\\textures\\Items.png", D3DCOLOR_XRGB(248, 0, 248));

	//map
	//textures->Add(ID_TEX_MAP_ONE, L"resources\\mapread\\lv1\\lv1.png", D3DCOLOR_XRGB(163, 73, 164));
	//textures->Add(ID_TEX_MAP_ONE, L"resources\\map\\lv1\\titlemaplv1.png", D3DCOLOR_XRGB(163, 73, 164));
	//textures->Add(ID_TEX_MAP_ONE, L"resources\\map\\lv1\\mapgamelv1.png", D3DCOLOR_XRGB(163, 73, 164));
	textures->Add(ID_TEX_MAP_ONE, L"resources\\map\\lv1\\maplv1.png", D3DCOLOR_XRGB(163, 73, 164));

	//textures->Add(ID_TEX_MAP_BOSS, L"resources\\map\\lv_boss\\tileset.png", D3DCOLOR_XRGB(249, 245, 248));
	textures->Add(ID_TEX_MAP_BOSS, L"resources\\map\\lv_boss\\lv_boss.png", D3DCOLOR_XRGB(250, 246, 249));

	//Obstacle
	textures->Add(ID_TEX_OBSTACLE, L"resources\\textures\\Aladdin_Sultan_ Dungeon.png", D3DCOLOR_XRGB(163, 73, 164));

	//bat
	textures->Add(ID_TEX_BAT, L"resources\\textures\\bat.png", D3DCOLOR_XRGB(255, 0, 255));

	//guard
	textures->Add(ID_TEX_GUARD, L"resources\\textures\\enemy.png", D3DCOLOR_XRGB(255, 0, 255));

	//skeleton
	textures->Add(ID_TEX_SKELETON, L"resources\\textures\\skeleton.png", D3DCOLOR_XRGB(255, 0, 255));

	//EnemyExplosions
	textures->Add(ID_TEX_ENEMY_EXPLOSIONS, L"resources\\textures\\EnemyExplosions.png", D3DCOLOR_XRGB(186, 254, 202));

	//jafar
	textures->Add(ID_TEX_JAFAR, L"resources\\textures\\boss.png", D3DCOLOR_XRGB(255, 0, 255));

	//iago
	textures->Add(ID_TEX_IAGO_RIGHT, L"resources\\textures\\iagoRight.png", D3DCOLOR_XRGB(84, 109, 142));
	textures->Add(ID_TEX_IAGO_LEFT, L"resources\\textures\\iagoLeft.png", D3DCOLOR_XRGB(84, 109, 142));

	//statue
	textures->Add(ID_TEX_IAGO_RIGHT, L"resources\\textures\\ShivaStatueRight.png", D3DCOLOR_XRGB(84, 109, 142));
	textures->Add(ID_TEX_IAGO_LEFT, L"resources\\textures\\ShivaStatueRight.png", D3DCOLOR_XRGB(84, 109, 142));

	//CutScene
	textures->Add(ID_TEX_MAP, L"resources\\textures\\Cutscenes.png", D3DCOLOR_XRGB(63, 72, 204));
}

void AladdinResoucres::LoadSprites()
{
	LPDIRECT3DTEXTURE9 texAladdinGoRight = textures->Get(ID_TEX_ALADDIN_GO_RIGHT);
	LPDIRECT3DTEXTURE9 texAladdinGoLeft = textures->Get(ID_TEX_ALADDIN_GO_LEFT);
	LPDIRECT3DTEXTURE9 texAladdinFullRight = textures->Get(ID_TEX_ALADDIN_FULL_RIGHT);
	LPDIRECT3DTEXTURE9 texAladdinFullLeft = textures->Get(ID_TEX_ALADDIN_FULL_LEFT);
	LPDIRECT3DTEXTURE9 texEnemyExplosions = textures->Get(ID_TEX_ENEMY_EXPLOSIONS);

	LPDIRECT3DTEXTURE9 texItem = textures->Get(ID_TEX_ITEM);

	LPDIRECT3DTEXTURE9 texGuard = textures->Get(ID_TEX_GUARD);

	LPDIRECT3DTEXTURE9 texBat = textures->Get(ID_TEX_BAT);

	LPDIRECT3DTEXTURE9 texSkeleton = textures->Get(ID_TEX_SKELETON);

	LPDIRECT3DTEXTURE9 texJafar = textures->Get(ID_TEX_JAFAR);

	LPDIRECT3DTEXTURE9 texIagoRight = textures->Get(ID_TEX_IAGO_RIGHT);
	LPDIRECT3DTEXTURE9 texIagoLeft = textures->Get(ID_TEX_IAGO_LEFT);

	LPDIRECT3DTEXTURE9 texStatueRight = textures->Get(ID_TEX_STATUE_RIGHT);
	LPDIRECT3DTEXTURE9 texStatueLeft = textures->Get(ID_TEX_STATUE_LEFT);

	LPDIRECT3DTEXTURE9 texObstacle = textures->Get(ID_TEX_OBSTACLE);


	LPDIRECT3DTEXTURE9 texMapOne = textures->Get(ID_TEX_MAP_ONE);
	//sprites->Add(ID_SPRITE_MAP_ONE, 0, 0, 2144, 1024, textMapOne);
	//sprites->Add(ID_SPRITE_MAP_ONE, 0, 0, 256, 8304, textMapOne);
	sprites->Add(ID_SPRITE_MAP_ONE, 0, 0, 2272, 1152, texMapOne);

	LPDIRECT3DTEXTURE9 textMapBoss = textures->Get(ID_TEX_MAP_BOSS);
	/*sprites->Add(ID_SPRITE_MAP_BOSS, 0, 0, 512, 800, textMapBoss);*/
	sprites->Add(ID_SPRITE_MAP_BOSS, 0, 0, 960, 416, textMapBoss);


	LPDIRECT3DTEXTURE9 texMap = textures->Get(ID_TEX_MAP);
	sprites->AddByWidthHeight(90000, 651, 193, 320, 256, texMap); // map start


	sprites->AddByWidthHeight(90100, 9, 12, 243, 90, texAladdinFullRight); // intro

	sprites->AddByWidthHeight(91000, 1, 454, 320, 224, texMap); // map end
	sprites->AddByWidthHeight(91100, 513, 2851, 232, 149, texAladdinFullRight); // complete


	sprites->Add(10001, 3, 9, 41, 59, texAladdinGoRight);		// idle right

	sprites->Add(11001, 1081, 9, 1118, 59, texAladdinGoLeft);	// idle left	

	sprites->Add(10034, 47, 3, 88, 58, texAladdinGoRight, -2);		// look around right
	sprites->Add(10035, 95, 3, 135, 58, texAladdinGoRight);
	sprites->Add(10036, 143, 3, 187, 58, texAladdinGoRight);
	sprites->Add(10037, 197, 3, 238, 58, texAladdinGoRight);
	sprites->Add(10038, 250, 3, 292, 58, texAladdinGoRight, -2);
	sprites->Add(10039, 303, 3, 347, 58, texAladdinGoRight, -4);

	sprites->Add(11034, 1033, 3, 1074, 58, texAladdinGoLeft);		//look around left	
	sprites->Add(11035, 986, 3, 1026, 58, texAladdinGoLeft, -2);
	sprites->Add(11036, 934, 3, 978, 58, texAladdinGoLeft, -2);
	sprites->Add(11037, 883, 3, 924, 58, texAladdinGoLeft, -6);
	sprites->Add(11038, 829, 3, 871, 58, texAladdinGoLeft);
	sprites->Add(11039, 774, 3, 818, 58, texAladdinGoLeft);

	sprites->Add(10002, 6, 58, 46, 134, texAladdinGoRight);			// standing idle right
	sprites->Add(10003, 51, 58, 112, 134, texAladdinGoRight, -12);
	sprites->Add(10004, 116, 58, 178, 134, texAladdinGoRight, 9);
	sprites->Add(10005, 180, 58, 221, 134, texAladdinGoRight, 9);
	sprites->Add(10006, 228, 58, 267, 134, texAladdinGoRight, 9);
	sprites->Add(10007, 275, 58, 311, 134, texAladdinGoRight, 9);
	sprites->Add(10008, 319, 58, 359, 134, texAladdinGoRight, 9);
	sprites->Add(10009, 366, 58, 407, 134, texAladdinGoRight, 9);
	sprites->Add(10010, 417, 58, 454, 134, texAladdinGoRight, 9);
	sprites->Add(10011, 465, 58, 503, 134, texAladdinGoRight, 9);
	sprites->Add(10012, 516, 58, 554, 134, texAladdinGoRight, 9);
	sprites->Add(10013, 568, 58, 608, 134, texAladdinGoRight, 9);
	sprites->Add(10014, 619, 58, 660, 134, texAladdinGoRight, 9);
	sprites->Add(10015, 668, 58, 708, 134, texAladdinGoRight, 9);
	sprites->Add(10016, 715, 58, 754, 134, texAladdinGoRight, 9);
	sprites->Add(10017, 3, 141, 39, 218, texAladdinGoRight, 9);
	sprites->Add(10018, 46, 141, 86, 218, texAladdinGoRight, 9);
	sprites->Add(10019, 91, 141, 132, 218, texAladdinGoRight, 9);
	sprites->Add(10020, 140, 141, 178, 215, texAladdinGoRight, 9);
	sprites->Add(10021, 188, 141, 229, 218, texAladdinGoRight, 9);
	sprites->Add(10022, 238, 141, 280, 215, texAladdinGoRight, 9);
	sprites->Add(10023, 287, 141, 325, 218, texAladdinGoRight, 9);
	sprites->Add(10024, 334, 141, 373, 218, texAladdinGoRight, 9);
	sprites->Add(10025, 378, 141, 417, 218, texAladdinGoRight, 9);
	sprites->Add(10026, 425, 141, 463, 218, texAladdinGoRight, 9);
	sprites->Add(10027, 472, 141, 510, 218, texAladdinGoRight, 9);
	sprites->Add(10028, 519, 141, 555, 218, texAladdinGoRight, 9);
	sprites->Add(10029, 568, 141, 607, 218, texAladdinGoRight, 9);
	sprites->Add(10030, 615, 141, 657, 215, texAladdinGoRight, 9);
	sprites->Add(10031, 666, 141, 707, 218, texAladdinGoRight, 9);
	sprites->Add(10032, 715, 141, 754, 218, texAladdinGoRight, 9);
	sprites->Add(10033, 762, 141, 801, 218, texAladdinGoRight, 9);

	sprites->Add(11002, 1075, 58, 1115, 134, texAladdinGoLeft);		// standing left
	sprites->Add(11003, 1009, 58, 1070, 134, texAladdinGoLeft);
	sprites->Add(11004, 943, 58, 1005, 134, texAladdinGoLeft);
	sprites->Add(11005, 900, 58, 941, 134, texAladdinGoLeft);
	sprites->Add(11006, 854, 58, 893, 134, texAladdinGoLeft);
	sprites->Add(11007, 810, 58, 846, 134, texAladdinGoLeft);
	sprites->Add(11008, 762, 58, 802, 134, texAladdinGoLeft);
	sprites->Add(11009, 720, 58, 755, 134, texAladdinGoLeft);
	sprites->Add(11010, 667, 58, 704, 134, texAladdinGoLeft);
	sprites->Add(11011, 618, 58, 656, 134, texAladdinGoLeft);
	sprites->Add(11012, 567, 58, 605, 134, texAladdinGoLeft);
	sprites->Add(11013, 513, 58, 553, 134, texAladdinGoLeft);
	sprites->Add(11014, 461, 58, 502, 134, texAladdinGoLeft);
	sprites->Add(11015, 413, 58, 453, 134, texAladdinGoLeft);
	sprites->Add(11016, 367, 58, 406, 134, texAladdinGoLeft);
	sprites->Add(11017, 1082, 141, 1118, 218, texAladdinGoLeft);
	sprites->Add(11018, 1035, 141, 1075, 218, texAladdinGoLeft);
	sprites->Add(11019, 989, 141, 1030, 218, texAladdinGoLeft);
	sprites->Add(11020, 943, 141, 981, 218, texAladdinGoLeft);
	sprites->Add(11021, 892, 141, 933, 218, texAladdinGoLeft);
	sprites->Add(11022, 841, 141, 883, 218, texAladdinGoLeft);
	sprites->Add(11023, 796, 141, 834, 218, texAladdinGoLeft);
	sprites->Add(11024, 748, 141, 787, 218, texAladdinGoLeft);
	sprites->Add(11025, 704, 141, 743, 218, texAladdinGoLeft);
	sprites->Add(11026, 658, 141, 696, 218, texAladdinGoLeft);
	sprites->Add(11027, 611, 141, 649, 218, texAladdinGoLeft);
	sprites->Add(11028, 566, 141, 602, 218, texAladdinGoLeft);
	sprites->Add(11029, 514, 138, 553, 218, texAladdinGoLeft);
	sprites->Add(11030, 464, 141, 508, 218, texAladdinGoLeft);
	sprites->Add(11031, 414, 141, 455, 218, texAladdinGoLeft);
	sprites->Add(11032, 366, 141, 406, 218, texAladdinGoLeft);
	sprites->Add(11033, 320, 141, 359, 218, texAladdinGoLeft);

	sprites->Add(10041, 205, 500, 247, 551, texAladdinGoRight, -6);		// sitting down right
	sprites->Add(10042, 258, 500, 306, 551, texAladdinGoRight, -11);
	sprites->Add(10043, 315, 500, 369, 551, texAladdinGoRight, -8);
	sprites->Add(10044, 378, 500, 431, 551, texAladdinGoRight, -3);

	sprites->Add(11041, 874, 500, 916, 551, texAladdinGoLeft);			// sitting down left
	sprites->Add(11042, 815, 500, 863, 551, texAladdinGoLeft, -3);
	sprites->Add(11043, 752, 500, 806, 551, texAladdinGoLeft, -9);
	sprites->Add(11044, 690, 500, 743, 551, texAladdinGoLeft, -13);

	sprites->Add(10051, 11, 490, 50, 549, texAladdinGoRight);			// looking up right
	sprites->Add(10052, 59, 490, 104, 549, texAladdinGoRight, -4);
	sprites->Add(10053, 111, 490, 160, 549, texAladdinGoRight, -7);

	sprites->Add(11051, 1071, 490, 1110, 549, texAladdinGoLeft);		// looking up left
	sprites->Add(11052, 1017, 490, 1062, 549, texAladdinGoLeft, -3);
	sprites->Add(11053, 961, 490, 1010, 549, texAladdinGoLeft, -4);

	sprites->Add(10101, 14, 1215, 54, 1273, texAladdinGoRight);		// walk	right
	sprites->Add(10102, 66, 1215, 109, 1273, texAladdinGoRight);
	sprites->Add(10103, 120, 1215, 161, 1273, texAladdinGoRight);
	sprites->Add(10104, 171, 1215, 212, 1273, texAladdinGoRight);
	sprites->Add(10105, 220, 1215, 272, 1273, texAladdinGoRight);
	sprites->Add(10106, 279, 1215, 325, 1273, texAladdinGoRight);
	sprites->Add(10107, 334, 1215, 376, 1273, texAladdinGoRight);
	sprites->Add(10108, 386, 1215, 427, 1273, texAladdinGoRight);
	sprites->Add(10109, 440, 1215, 475, 1273, texAladdinGoRight);
	sprites->Add(10110, 488, 1215, 537, 1273, texAladdinGoRight);
	sprites->Add(10111, 547, 1215, 602, 1273, texAladdinGoRight);
	sprites->Add(10112, 611, 1215, 666, 1273, texAladdinGoRight);
	sprites->Add(10113, 679, 1215, 723, 1273, texAladdinGoRight);

	sprites->Add(11101, 1067, 1215, 1107, 1273, texAladdinGoLeft);		// walk	left
	sprites->Add(11102, 1012, 1215, 1055, 1273, texAladdinGoLeft);
	sprites->Add(11103, 960, 1215, 1001, 1273, texAladdinGoLeft);
	sprites->Add(11104, 909, 1215, 950, 1273, texAladdinGoLeft);
	sprites->Add(11105, 849, 1215, 901, 1273, texAladdinGoLeft);
	sprites->Add(11106, 796, 1215, 842, 1273, texAladdinGoLeft);
	sprites->Add(11107, 745, 1215, 787, 1273, texAladdinGoLeft);
	sprites->Add(11108, 694, 1215, 735, 1273, texAladdinGoLeft);
	sprites->Add(11109, 646, 1215, 681, 1273, texAladdinGoLeft);
	sprites->Add(11110, 584, 1215, 633, 1273, texAladdinGoLeft);
	sprites->Add(11111, 519, 1215, 574, 1273, texAladdinGoLeft);
	sprites->Add(11112, 455, 1215, 510, 1273, texAladdinGoLeft);
	sprites->Add(11113, 398, 1215, 442, 1273, texAladdinGoLeft);

	sprites->Add(10121, 11, 1283, 68, 1352, texAladdinGoRight);		// stop	right
	sprites->Add(10122, 83, 1283, 127, 1352, texAladdinGoRight);
	sprites->Add(10123, 134, 1283, 185, 1352, texAladdinGoRight);
	sprites->Add(10124, 200, 1283, 246, 1352, texAladdinGoRight);
	sprites->Add(10125, 256, 1283, 298, 1352, texAladdinGoRight);
	sprites->Add(10126, 309, 1283, 364, 1352, texAladdinGoRight);
	sprites->Add(10127, 376, 1283, 428, 1352, texAladdinGoRight);
	sprites->Add(10128, 437, 1283, 483, 1352, texAladdinGoRight);
	sprites->Add(10129, 498, 1283, 549, 1352, texAladdinGoRight);

	sprites->Add(11121, 1053, 1283, 1110, 1352, texAladdinGoLeft);		// stop	left
	sprites->Add(11122, 994, 1283, 1038, 1352, texAladdinGoLeft);
	sprites->Add(11123, 936, 1283, 987, 1352, texAladdinGoLeft);
	sprites->Add(11124, 875, 1283, 921, 1352, texAladdinGoLeft);
	sprites->Add(11125, 823, 1283, 865, 1352, texAladdinGoLeft);
	sprites->Add(11126, 757, 1283, 812, 1352, texAladdinGoLeft);
	sprites->Add(11127, 693, 1283, 745, 1352, texAladdinGoLeft);
	sprites->Add(11128, 638, 1283, 684, 1352, texAladdinGoLeft);
	sprites->Add(11129, 572, 1283, 623, 1352, texAladdinGoLeft);

	sprites->Add(10201, 8, 808, 67, 905, texAladdinGoRight, -14);		// jump	right
	sprites->Add(10202, 75, 808, 127, 905, texAladdinGoRight, -16);
	sprites->Add(10203, 137, 808, 191, 905, texAladdinGoRight, -14);
	sprites->Add(10204, 203, 808, 257, 905, texAladdinGoRight, -27);
	sprites->Add(10205, 269, 808, 320, 905, texAladdinGoRight, -19);
	sprites->Add(10206, 336, 808, 374, 905, texAladdinGoRight, -9);
	sprites->Add(10207, 390, 808, 425, 905, texAladdinGoRight, -9);
	sprites->Add(10208, 448, 808, 482, 905, texAladdinGoRight, -2);
	sprites->Add(10209, 504, 808, 538, 905, texAladdinGoRight, -2);
	sprites->Add(10210, 564, 808, 598, 905, texAladdinGoRight, -2);

	sprites->Add(11201, 1054, 808, 1113, 905, texAladdinGoLeft, -10);		// jump	left
	sprites->Add(11202, 994, 808, 1046, 905, texAladdinGoLeft, -9);
	sprites->Add(11203, 930, 808, 984, 905, texAladdinGoLeft, -18);
	sprites->Add(11204, 864, 808, 918, 905, texAladdinGoLeft, -23);
	sprites->Add(11205, 801, 808, 852, 905, texAladdinGoLeft, -23);
	sprites->Add(11206, 747, 808, 785, 905, texAladdinGoLeft, -13);
	sprites->Add(11207, 696, 808, 731, 905, texAladdinGoLeft, -6);
	sprites->Add(11208, 639, 808, 673, 905, texAladdinGoLeft, -11);
	sprites->Add(11209, 583, 808, 617, 905, texAladdinGoLeft, -11);
	sprites->Add(11210, 523, 808, 557, 905, texAladdinGoLeft, -11);

	sprites->Add(10221, 10, 680, 51, 765, texAladdinGoRight);		// run jump	right
	sprites->Add(10222, 66, 680, 111, 765, texAladdinGoRight);
	sprites->Add(10223, 124, 680, 181, 765, texAladdinGoRight);
	sprites->Add(10224, 199, 680, 257, 765, texAladdinGoRight);
	sprites->Add(10225, 273, 680, 334, 765, texAladdinGoRight);
	sprites->Add(10226, 350, 680, 408, 765, texAladdinGoRight);
	sprites->Add(10227, 419, 680, 472, 765, texAladdinGoRight);
	sprites->Add(10228, 491, 680, 541, 765, texAladdinGoRight);
	sprites->Add(10229, 560, 680, 719, 765, texAladdinGoRight);

	sprites->Add(11221, 1070, 680, 1111, 765, texAladdinGoLeft);		// run jump	left
	sprites->Add(11222, 1010, 680, 1055, 765, texAladdinGoLeft);
	sprites->Add(11223, 940, 680, 997, 765, texAladdinGoLeft);
	sprites->Add(11224, 864, 680, 922, 765, texAladdinGoLeft);
	sprites->Add(11225, 787, 680, 848, 765, texAladdinGoLeft);
	sprites->Add(11226, 713, 680, 771, 765, texAladdinGoLeft);
	sprites->Add(11227, 649, 680, 702, 765, texAladdinGoLeft);
	sprites->Add(11228, 580, 680, 630, 765, texAladdinGoLeft);
	sprites->Add(11229, 502, 680, 561, 765, texAladdinGoLeft);

	sprites->AddByWidthHeight(10231, 8, 1285, 35, 60, texAladdinFullRight);		// run slash right
	sprites->AddByWidthHeight(10232, 53, 1285, 51, 60, texAladdinFullRight);
	sprites->AddByWidthHeight(10233, 114, 1285, 50, 60, texAladdinFullRight);
	sprites->AddByWidthHeight(10234, 174, 1285, 48, 60, texAladdinFullRight);
	sprites->AddByWidthHeight(10235, 232, 1285, 75, 60, texAladdinFullRight);
	sprites->AddByWidthHeight(10236, 315, 1285, 60, 60, texAladdinFullRight);

	sprites->AddByWidthHeight(11231, 974, 1285, 35, 60, texAladdinFullLeft);	// run slash left
	sprites->AddByWidthHeight(11232, 913, 1285, 51, 60, texAladdinFullLeft);
	sprites->AddByWidthHeight(11233, 853, 1285, 50, 60, texAladdinFullLeft);
	sprites->AddByWidthHeight(11234, 795, 1285, 48, 60, texAladdinFullLeft);
	sprites->AddByWidthHeight(11235, 712, 1285, 75, 60, texAladdinFullLeft);
	sprites->AddByWidthHeight(11236, 642, 1285, 60, 60, texAladdinFullLeft);

	sprites->AddByWidthHeight(10241, 511, 1291, 37, 62, texAladdinFullRight);		// run throw right
	sprites->AddByWidthHeight(10242, 572, 1291, 49, 62, texAladdinFullRight);
	sprites->AddByWidthHeight(10243, 664, 1291, 49, 62, texAladdinFullRight);
	sprites->AddByWidthHeight(10244, 761, 1291, 53, 62, texAladdinFullRight);
	sprites->AddByWidthHeight(10245, 849, 1291, 44, 62, texAladdinFullRight);
	sprites->AddByWidthHeight(10246, 961, 1291, 35, 62, texAladdinFullRight);

	sprites->AddByWidthHeight(11241, 469, 1291, 37, 62, texAladdinFullLeft);		// run throw left
	sprites->AddByWidthHeight(11242, 396, 1291, 49, 62, texAladdinFullLeft);
	sprites->AddByWidthHeight(11243, 304, 1291, 49, 62, texAladdinFullLeft);
	sprites->AddByWidthHeight(11244, 203, 1291, 53, 62, texAladdinFullLeft);
	sprites->AddByWidthHeight(11245, 124, 1291, 44, 62, texAladdinFullLeft);
	sprites->AddByWidthHeight(11246, 21, 1291, 35, 62, texAladdinFullLeft);

	sprites->Add(10301, 5, 314, 50, 388, texAladdinGoRight, -9);		// standing slash right
	sprites->Add(10302, 54, 314, 105, 388, texAladdinGoRight, -10);
	sprites->Add(10303, 115, 314, 160, 388, texAladdinGoRight, -4);
	sprites->Add(10304, 171, 314, 253, 388, texAladdinGoRight);
	sprites->Add(10305, 260, 314, 311, 388, texAladdinGoRight, -7);

	sprites->Add(11301, 1071, 314, 1116, 388, texAladdinGoLeft);		// standing slash left
	sprites->Add(11302, 1016, 314, 1067, 388, texAladdinGoLeft, -3);
	sprites->Add(11303, 961, 314, 1006, 388, texAladdinGoLeft, -3);
	sprites->Add(11304, 868, 314, 950, 388, texAladdinGoLeft, -43);
	sprites->Add(11305, 810, 314, 861, 388, texAladdinGoLeft, -6);

	sprites->Add(10311, 9, 639, 56, 673, texAladdinGoRight);		// sitting slash right
	sprites->Add(10312, 64, 639, 109, 673, texAladdinGoRight);
	sprites->Add(10313, 115, 639, 186, 673, texAladdinGoRight);
	sprites->Add(10314, 193, 639, 285, 673, texAladdinGoRight);
	sprites->Add(10315, 298, 639, 382, 673, texAladdinGoRight);
	sprites->Add(10316, 392, 639, 463, 673, texAladdinGoRight);
	sprites->Add(10317, 475, 639, 520, 673, texAladdinGoRight);

	sprites->Add(11311, 1065, 639, 1112, 673, texAladdinGoLeft, -10);		// sitting slash left
	sprites->Add(11312, 1012, 639, 1057, 673, texAladdinGoLeft, -8);
	sprites->Add(11313, 935, 639, 1006, 673, texAladdinGoLeft, -34);
	sprites->Add(11314, 836, 639, 928, 673, texAladdinGoLeft, -54);
	sprites->Add(11315, 739, 639, 823, 673, texAladdinGoLeft, -47);
	sprites->Add(11316, 658, 639, 729, 673, texAladdinGoLeft, -30);
	sprites->Add(11317, 601, 639, 646, 673, texAladdinGoLeft, -34);

	sprites->Add(10321, 11, 389, 53, 473, texAladdinGoRight);		// looking up slash right
	sprites->Add(10322, 66, 389, 104, 473, texAladdinGoRight);
	sprites->Add(10323, 111, 389, 176, 473, texAladdinGoRight, -24);
	sprites->Add(10324, 193, 389, 240, 473, texAladdinGoRight, -7);
	sprites->Add(10325, 249, 389, 296, 473, texAladdinGoRight, -7);
	sprites->Add(10326, 298, 389, 352, 473, texAladdinGoRight, -14);
	sprites->Add(10327, 363, 389, 437, 473, texAladdinGoRight);
	sprites->Add(10328, 452, 389, 506, 473, texAladdinGoRight);
	sprites->Add(10329, 520, 389, 569, 473, texAladdinGoRight);
	sprites->Add(10330, 584, 389, 635, 473, texAladdinGoRight);
	sprites->Add(10331, 644, 389, 697, 473, texAladdinGoRight, -11);
	sprites->Add(10332, 704, 389, 750, 473, texAladdinGoRight, -5);

	sprites->Add(11321, 1068, 389, 1110, 473, texAladdinGoLeft);		// looking up slash left
	sprites->Add(11322, 1017, 389, 1045, 473, texAladdinGoLeft);
	sprites->Add(11323, 945, 389, 1010, 473, texAladdinGoLeft);
	sprites->Add(11324, 881, 389, 928, 473, texAladdinGoLeft);
	sprites->Add(11325, 825, 389, 872, 473, texAladdinGoLeft);
	sprites->Add(11326, 769, 389, 823, 473, texAladdinGoLeft);
	sprites->Add(11327, 684, 389, 758, 473, texAladdinGoLeft, -32);
	sprites->Add(11328, 615, 389, 669, 473, texAladdinGoLeft, -11);
	sprites->Add(11329, 552, 389, 601, 473, texAladdinGoLeft, -11);
	sprites->Add(11330, 486, 389, 537, 473, texAladdinGoLeft, -11);
	sprites->Add(11331, 424, 389, 477, 473, texAladdinGoLeft);
	sprites->Add(11332, 371, 389, 417, 473, texAladdinGoLeft);

	sprites->Add(10341, 13, 1067, 65, 1142, texAladdinGoRight);		// jumping slash right
	sprites->Add(10342, 75, 1067, 125, 1142, texAladdinGoRight);
	sprites->Add(10343, 140, 1067, 187, 1142, texAladdinGoRight);
	sprites->Add(10344, 199, 1067, 251, 1142, texAladdinGoRight);
	sprites->Add(10345, 266, 1067, 349, 1142, texAladdinGoRight);
	sprites->Add(10346, 361, 1067, 408, 1142, texAladdinGoRight);

	sprites->Add(11341, 1056, 1067, 1108, 1142, texAladdinGoLeft);		// jumping slash left
	sprites->Add(11342, 996, 1067, 1046, 1142, texAladdinGoLeft);
	sprites->Add(11343, 934, 1067, 981, 1142, texAladdinGoLeft);
	sprites->Add(11344, 870, 1067, 922, 1142, texAladdinGoLeft);
	sprites->Add(11345, 772, 1067, 855, 1142, texAladdinGoLeft);
	sprites->Add(11346, 713, 1067, 760, 1142, texAladdinGoLeft);

	sprites->Add(10401, 7, 231, 50, 291, texAladdinGoRight);		// throw apple right
	sprites->Add(10402, 57, 231, 98, 291, texAladdinGoRight);
	sprites->Add(10403, 109, 231, 147, 291, texAladdinGoRight);
	sprites->Add(10404, 163, 231, 209, 291, texAladdinGoRight, -1);
	sprites->Add(10405, 221, 231, 258, 291, texAladdinGoRight);
	sprites->Add(10406, 268, 231, 320, 291, texAladdinGoRight, -2);

	sprites->Add(11401, 1071, 231, 1114, 291, texAladdinGoLeft, -6);		// throw apple left
	sprites->Add(11402, 1023, 231, 1064, 291, texAladdinGoLeft, -2);
	sprites->Add(11403, 974, 231, 1012, 291, texAladdinGoLeft);
	sprites->Add(11404, 912, 231, 958, 291, texAladdinGoLeft, -7);
	sprites->Add(11405, 863, 231, 900, 291, texAladdinGoLeft);
	sprites->Add(11406, 814, 231, 853, 291, texAladdinGoLeft);

	sprites->Add(10411, 9, 567, 46, 619, texAladdinGoRight);		// sitting throw apple right
	sprites->Add(10412, 58, 567, 95, 619, texAladdinGoRight);
	sprites->Add(10413, 107, 567, 157, 619, texAladdinGoRight);
	sprites->Add(10414, 164, 567, 246, 619, texAladdinGoRight, -11);
	sprites->Add(10415, 256, 567, 313, 619, texAladdinGoRight, -7);

	sprites->Add(11411, 1075, 567, 1112, 619, texAladdinGoLeft);		// sitting throw apple left
	sprites->Add(11412, 1026, 567, 1063, 619, texAladdinGoLeft);
	sprites->Add(11413, 964, 567, 1014, 619, texAladdinGoLeft, -13);
	sprites->Add(11414, 875, 567, 957, 619, texAladdinGoLeft, -34);
	sprites->Add(11415, 808, 567, 865, 619, texAladdinGoLeft, -13);

	sprites->Add(10421, 19, 1005, 68, 1064, texAladdinGoRight);		// jumping throw apple right
	sprites->Add(10422, 77, 1005, 120, 1064, texAladdinGoRight);
	sprites->Add(10423, 132, 1005, 171, 1064, texAladdinGoRight);
	sprites->Add(10424, 185, 1005, 237, 1064, texAladdinGoRight);
	sprites->Add(10425, 253, 1005, 293, 1064, texAladdinGoRight);

	sprites->Add(11421, 1053, 1005, 1102, 1064, texAladdinGoLeft);	// jumping throw apple left
	sprites->Add(11422, 1001, 1005, 1044, 1064, texAladdinGoLeft);
	sprites->Add(11423, 950, 1005, 989, 1064, texAladdinGoLeft);
	sprites->Add(11424, 884, 1005, 936, 1064, texAladdinGoLeft);
	sprites->Add(11425, 828, 1005, 868, 1064, texAladdinGoLeft);

	//sprites->Add(10501, 11, 1358, 40, 1450, texAladdinGoRight, -5, -35);		// climbing
	//sprites->Add(10502, 53, 1358, 81, 1450, texAladdinGoRight, -6, -38);
	//sprites->Add(10503, 94, 1358, 122, 1450, texAladdinGoRight, -4, -23);
	//sprites->Add(10504, 133, 1358, 175, 1450, texAladdinGoRight, -18, -11);
	//sprites->Add(10505, 186, 1358, 217, 1450, texAladdinGoRight, -7, -25);
	//sprites->Add(10506, 231, 1358, 260, 1450, texAladdinGoRight, -8, -35);
	//sprites->Add(10507, 274, 1358, 302, 1450, texAladdinGoRight, -7, -28);
	//sprites->Add(10508, 314, 1358, 346, 1450, texAladdinGoRight, -6, -12);
	//sprites->Add(10509, 356, 1358, 398, 1450, texAladdinGoRight, -7, -11);
	//sprites->Add(10510, 406, 1358, 434, 1450, texAladdinGoRight, -5, -30);

	sprites->Add(10501, 11, 1358, 40, 1450, texAladdinGoRight, 0, -35);		// climbing
	sprites->Add(10502, 53, 1358, 81, 1450, texAladdinGoRight, 0, -38);
	sprites->Add(10503, 94, 1358, 122, 1450, texAladdinGoRight, 0, -23);
	sprites->Add(10504, 133, 1358, 175, 1450, texAladdinGoRight, 0, -11);
	sprites->Add(10505, 186, 1358, 217, 1450, texAladdinGoRight, 0, -25);
	sprites->Add(10506, 231, 1358, 260, 1450, texAladdinGoRight, 0, -35);
	sprites->Add(10507, 274, 1358, 302, 1450, texAladdinGoRight, 0, -28);
	sprites->Add(10508, 314, 1358, 346, 1450, texAladdinGoRight, 0, -12);
	sprites->Add(10509, 356, 1358, 398, 1450, texAladdinGoRight, 0, -11);
	sprites->Add(10510, 406, 1358, 434, 1450, texAladdinGoRight, 0, -30);

	sprites->Add(10521, 10, 1866, 44, 1950, texAladdinGoRight);		// falling after climbing
	sprites->Add(10522, 65, 1866, 90, 1950, texAladdinGoRight);
	sprites->Add(10523, 100, 1866, 136, 1950, texAladdinGoRight);
	sprites->Add(10524, 144, 1866, 192, 1950, texAladdinGoRight);
	sprites->Add(10525, 204, 1866, 263, 1950, texAladdinGoRight);
	sprites->Add(10526, 281, 1866, 340, 1950, texAladdinGoRight);
	sprites->Add(10527, 354, 1866, 406, 1950, texAladdinGoRight);
	sprites->Add(10528, 422, 1866, 469, 1950, texAladdinGoRight);
	sprites->Add(10529, 482, 1866, 527, 1950, texAladdinGoRight);

	sprites->Add(10531, 1058, 1769, 1106, 1864, texAladdinGoLeft, -35);	// climbing slash right
	sprites->Add(10532, 988, 1769, 1040, 1864, texAladdinGoLeft, -38);
	sprites->Add(10533, 914, 1769, 975, 1864, texAladdinGoLeft, -12, -3);
	sprites->Add(10534, 821, 1769, 874, 1864, texAladdinGoLeft, -33);
	sprites->Add(10535, 739, 1769, 794, 1864, texAladdinGoLeft, -35);
	sprites->Add(10536, 646, 1769, 718, 1864, texAladdinGoLeft, -34);
	sprites->Add(10537, 574, 1769, 622, 1864, texAladdinGoLeft, -35);

	sprites->Add(11531, 15, 1769, 63, 1864, texAladdinGoRight, -6);		// climbing slash left
	sprites->Add(11532, 81, 1769, 133, 1864, texAladdinGoRight, -7);
	sprites->Add(11533, 146, 1769, 207, 1864, texAladdinGoRight, -42, -3);
	sprites->Add(11534, 247, 1769, 300, 1864, texAladdinGoRight, -11);
	sprites->Add(11535, 327, 1769, 382, 1864, texAladdinGoRight, -13);
	sprites->Add(11536, 403, 1769, 475, 1864, texAladdinGoRight, -31);
	sprites->Add(11537, 499, 1769, 547, 1864, texAladdinGoRight, -6);

	sprites->Add(10541, 1071, 1664, 1108, 1753, texAladdinGoLeft, -23);	// climbing throw apple right
	sprites->Add(10542, 1015, 1664, 1056, 1753, texAladdinGoLeft, -26);
	sprites->Add(10543, 945, 1664, 996, 1753, texAladdinGoLeft, -37);
	sprites->Add(10544, 898, 1664, 929, 1753, texAladdinGoLeft, -17);
	sprites->Add(10545, 828, 1664, 885, 1753, texAladdinGoLeft, -23);

	sprites->Add(11541, 13, 1664, 50, 1753, texAladdinGoRight, -7);		// climbing throw apple left
	sprites->Add(11542, 65, 1664, 106, 1753, texAladdinGoRight, -8);
	sprites->Add(11543, 125, 1664, 176, 1753, texAladdinGoRight, -7);
	sprites->Add(11544, 192, 1664, 223, 1753, texAladdinGoRight, -7);
	sprites->Add(11545, 236, 1664, 293, 1753, texAladdinGoRight, -28);

	sprites->Add(10601, 9, 2107, 61, 2149, texAladdinGoRight, -10);	// ride the carpet right
	sprites->Add(10602, 68, 2107, 120, 2149, texAladdinGoRight, -10);
	sprites->Add(10603, 129, 2107, 181, 2149, texAladdinGoRight, -10);
	sprites->Add(10604, 190, 2107, 242, 2149, texAladdinGoRight, -10);
	sprites->Add(10605, 259, 2107, 63, 2149, texAladdinGoRight, -16);
	sprites->Add(10606, 333, 2107, 388, 2149, texAladdinGoRight, -13);

	sprites->Add(11601, 1060, 2107, 1112, 2149, texAladdinGoRight, -5);	// ride the carpet left
	sprites->Add(11602, 1001, 2107, 1053, 2149, texAladdinGoRight, -6);
	sprites->Add(11603, 940, 2107, 992, 2149, texAladdinGoRight, -5);
	sprites->Add(11604, 879, 2107, 931, 2149, texAladdinGoRight, -6);
	sprites->Add(11605, 799, 2107, 862, 2149, texAladdinGoRight, -15);
	sprites->Add(11606, 733, 2107, 788, 2149, texAladdinGoRight, -7);

	sprites->AddByWidthHeight(10701, 9, 2160, 42, 52, texAladdinGoRight);		// be attacked right
	sprites->AddByWidthHeight(10702, 58, 2160, 55, 52, texAladdinGoRight);
	sprites->AddByWidthHeight(10703, 122, 2160, 59, 52, texAladdinGoRight);
	sprites->AddByWidthHeight(10704, 189, 2160, 80, 52, texAladdinGoRight);
	sprites->AddByWidthHeight(10705, 282, 2160, 62, 52, texAladdinGoRight);
	sprites->AddByWidthHeight(10706, 351, 2160, 59, 52, texAladdinGoRight);

	sprites->AddByWidthHeight(11701, 1070, 2160, 42, 52, texAladdinGoLeft);		// be attacked left
	sprites->AddByWidthHeight(11702, 1008, 2160, 55, 52, texAladdinGoLeft);
	sprites->AddByWidthHeight(11703, 940, 2160, 59, 52, texAladdinGoLeft);
	sprites->AddByWidthHeight(11704, 852, 2160, 80, 52, texAladdinGoLeft);
	sprites->AddByWidthHeight(11705, 778, 2160, 62, 52, texAladdinGoLeft);
	sprites->AddByWidthHeight(11706, 711, 2160, 59, 52, texAladdinGoLeft);

	// item hp
	sprites->AddByWidthHeight(20000, 17, 3007, 120, 32, texAladdinFullRight); //hp aladdin 1
	sprites->AddByWidthHeight(20001, 147, 3007, 120, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20002, 277, 3007, 119, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20003, 406, 3007, 119, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20010, 17, 3054, 112, 32, texAladdinFullRight); //hp aladdin 2
	sprites->AddByWidthHeight(20011, 139, 3054, 112, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20012, 261, 3054, 111, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20013, 382, 3054, 111, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20020, 17, 3101, 104, 32, texAladdinFullRight); //hp aladdin 3
	sprites->AddByWidthHeight(20021, 131, 3101, 104, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20022, 245, 3101, 103, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20023, 358, 3101, 103, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20030, 17, 3148, 96, 32, texAladdinFullRight); //hp aladdin 4
	sprites->AddByWidthHeight(20031, 123, 3148, 96, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20032, 229, 3148, 95, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20033, 334, 3148, 95, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20040, 17, 3195, 88, 32, texAladdinFullRight); //hp aladdin 5
	sprites->AddByWidthHeight(20041, 116, 3195, 88, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20042, 214, 3195, 87, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20043, 311, 3195, 87, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20050, 17, 3242, 80, 32, texAladdinFullRight); //hp aladdin 6
	sprites->AddByWidthHeight(20051, 107, 3242, 80, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20052, 197, 3242, 79, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20053, 286, 3242, 79, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20060, 17, 3289, 71, 32, texAladdinFullRight); //hp aladdin 7
	sprites->AddByWidthHeight(20061, 98, 3289, 71, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20062, 179, 3289, 72, 32, texAladdinFullRight);
	sprites->AddByWidthHeight(20063, 261, 3289, 72, 32, texAladdinFullRight);

	sprites->AddByWidthHeight(20070, 17, 3336, 63, 29, texAladdinFullRight); //hp aladdin 8
	sprites->AddByWidthHeight(20071, 90, 3336, 63, 29, texAladdinFullRight);
	sprites->AddByWidthHeight(20072, 163, 3336, 64, 29, texAladdinFullRight);
	sprites->AddByWidthHeight(20073, 237, 3335, 64, 30, texAladdinFullRight);

	sprites->AddByWidthHeight(20080, 17, 3380, 48, 24, texAladdinFullRight); //hp aladdin 9

	//item life				  
	sprites->AddByWidthHeight(20100, 13, 3568, 22, 25, texAladdinFullRight);
	sprites->AddByWidthHeight(20101, 45, 3567, 24, 26, texAladdinFullRight);
	sprites->AddByWidthHeight(20102, 79, 3567, 24, 26, texAladdinFullRight);
	sprites->AddByWidthHeight(20103, 113, 3565, 27, 28, texAladdinFullRight);
	sprites->AddByWidthHeight(20104, 150, 3560, 36, 33, texAladdinFullRight);
	sprites->AddByWidthHeight(20105, 196, 3562, 33, 31, texAladdinFullRight);
	sprites->AddByWidthHeight(20106, 239, 3568, 23, 25, texAladdinFullRight);
	sprites->AddByWidthHeight(20107, 272, 3568, 22, 25, texAladdinFullRight);
	sprites->AddByWidthHeight(20108, 304, 3568, 22, 25, texAladdinFullRight);

	sprites->AddByWidthHeight(20109, 13, 3616, 22, 25, texAladdinFullRight);
	sprites->AddByWidthHeight(20110, 45, 3615, 24, 26, texAladdinFullRight);
	sprites->AddByWidthHeight(20111, 79, 3615, 24, 26, texAladdinFullRight);
	sprites->AddByWidthHeight(20112, 113, 3612, 37, 39, texAladdinFullRight);
	sprites->AddByWidthHeight(20113, 160, 3609, 37, 41, texAladdinFullRight);
	sprites->AddByWidthHeight(20114, 207, 3608, 37, 42, texAladdinFullRight);
	sprites->AddByWidthHeight(20115, 254, 3609, 37, 42, texAladdinFullRight);
	sprites->AddByWidthHeight(20116, 301, 3609, 37, 41, texAladdinFullRight);
	sprites->AddByWidthHeight(20117, 349, 3608, 37, 39, texAladdinFullRight);
	sprites->AddByWidthHeight(20118, 396, 3609, 32, 36, texAladdinFullRight);
	sprites->AddByWidthHeight(20119, 438, 3614, 32, 36, texAladdinFullRight);
	sprites->AddByWidthHeight(20120, 484, 3616, 22, 25, texAladdinFullRight);

	//text A->Z ()			  
	sprites->AddByWidthHeight(20200, 359, 3566, 7, 8, texAladdinFullRight); //A
	sprites->AddByWidthHeight(20201, 371, 3566, 7, 8, texAladdinFullRight); //B
	sprites->AddByWidthHeight(20202, 383, 3566, 7, 8, texAladdinFullRight); //C
	sprites->AddByWidthHeight(20203, 395, 3566, 7, 8, texAladdinFullRight); //D
	sprites->AddByWidthHeight(20204, 407, 3566, 7, 8, texAladdinFullRight); //E
	sprites->AddByWidthHeight(20205, 419, 3566, 7, 8, texAladdinFullRight); //F
	sprites->AddByWidthHeight(20206, 431, 3566, 7, 8, texAladdinFullRight); //G
	sprites->AddByWidthHeight(20207, 443, 3566, 7, 8, texAladdinFullRight); //H
	sprites->AddByWidthHeight(20208, 455, 3566, 7, 8, texAladdinFullRight); //I
	sprites->AddByWidthHeight(20209, 463, 3566, 7, 8, texAladdinFullRight); //J
	sprites->AddByWidthHeight(20210, 472, 3566, 7, 8, texAladdinFullRight); //K
	sprites->AddByWidthHeight(20211, 484, 3566, 7, 8, texAladdinFullRight); //L
	sprites->AddByWidthHeight(20212, 496, 3566, 7, 8, texAladdinFullRight); //M

	sprites->AddByWidthHeight(20213, 360, 3581, 7, 8, texAladdinFullRight); //N
	sprites->AddByWidthHeight(20214, 372, 3581, 7, 8, texAladdinFullRight); //O
	sprites->AddByWidthHeight(20215, 384, 3581, 7, 8, texAladdinFullRight); //P
	sprites->AddByWidthHeight(20216, 396, 3581, 7, 8, texAladdinFullRight); //Q
	sprites->AddByWidthHeight(20217, 408, 3581, 7, 8, texAladdinFullRight); //R
	sprites->AddByWidthHeight(20218, 420, 3581, 7, 8, texAladdinFullRight); //S
	sprites->AddByWidthHeight(20219, 431, 3581, 7, 8, texAladdinFullRight); //T
	sprites->AddByWidthHeight(20220, 442, 3581, 7, 8, texAladdinFullRight); //U
	sprites->AddByWidthHeight(20221, 454, 3581, 7, 8, texAladdinFullRight); //V
	sprites->AddByWidthHeight(20222, 466, 3581, 7, 8, texAladdinFullRight); //W
	sprites->AddByWidthHeight(20223, 478, 3581, 7, 8, texAladdinFullRight); //X
	sprites->AddByWidthHeight(20224, 490, 3581, 7, 8, texAladdinFullRight); //Y
	sprites->AddByWidthHeight(20225, 502, 3581, 7, 8, texAladdinFullRight); //Z

	sprites->AddByWidthHeight(20226, 514, 3581, 4, 8, texAladdinFullRight); //(
	sprites->AddByWidthHeight(20227, 520, 3581, 4, 8, texAladdinFullRight); //)

	//number 0-9			  
	sprites->AddByWidthHeight(20228, 359, 3594, 7, 8, texAladdinFullRight); //0
	sprites->AddByWidthHeight(20229, 371, 3594, 7, 8, texAladdinFullRight); //1
	sprites->AddByWidthHeight(20230, 379, 3594, 7, 8, texAladdinFullRight); //2
	sprites->AddByWidthHeight(20231, 389, 3594, 7, 8, texAladdinFullRight); //3
	sprites->AddByWidthHeight(20232, 398, 3594, 7, 8, texAladdinFullRight); //4
	sprites->AddByWidthHeight(20233, 409, 3594, 7, 8, texAladdinFullRight); //5
	sprites->AddByWidthHeight(20234, 419, 3594, 7, 8, texAladdinFullRight); //6
	sprites->AddByWidthHeight(20235, 430, 3594, 7, 8, texAladdinFullRight); //7
	sprites->AddByWidthHeight(20236, 439, 3594, 7, 8, texAladdinFullRight); //8
	sprites->AddByWidthHeight(20237, 449, 3594, 7, 8, texAladdinFullRight); //9
	sprites->AddByWidthHeight(20238, 459, 3594, 7, 8, texAladdinFullRight); //.

	//						  
	sprites->AddByWidthHeight(20300, 17, 3435, 11, 16, texAladdinFullRight); //tao
	sprites->AddByWidthHeight(20301, 285, 3435, 17, 16, texAladdinFullRight); //trung


	sprites->Add(20400, 1, 1770, 31, 1793, texObstacle);		//Stone
	sprites->Add(20401, 37, 1770, 67, 1793, texObstacle);
	sprites->Add(20402, 73, 1770, 107, 1793, texObstacle);
	sprites->Add(20403, 112, 1770, 149, 1793, texObstacle);
	sprites->Add(20404, 155, 1770, 194, 1793, texObstacle);

	sprites->Add(20420, 1, 1798, 23, 1833, texObstacle);		//trap
	sprites->Add(20421, 29, 1798, 51, 1833, texObstacle);
	sprites->Add(20422, 57, 1798, 82, 1833, texObstacle);
	sprites->Add(20423, 88, 1798, 120, 1833, texObstacle);
	sprites->Add(20424, 126, 1798, 167, 1833, texObstacle);
	sprites->Add(20425, 173, 1798, 221, 1833, texObstacle);

	sprites->Add(20430, 227, 1770, 240, 1837, texObstacle);			//ball
	sprites->Add(20431, 246, 1770, 260, 1837, texObstacle);
	sprites->Add(20432, 266, 1770, 280, 1837, texObstacle);
	sprites->Add(20433, 286, 1770, 300, 1837, texObstacle);
	sprites->Add(20434, 306, 1770, 321, 1837, texObstacle);
	sprites->Add(20435, 327, 1770, 342, 1837, texObstacle);
	sprites->Add(20436, 349, 1770, 365, 1837, texObstacle);
	sprites->Add(20437, 371, 1770, 391, 1837, texObstacle);
	sprites->Add(20438, 397, 1770, 422, 1837, texObstacle);
	sprites->Add(20439, 428, 1770, 456, 1837, texObstacle);
	sprites->Add(20440, 461, 1770, 490, 1837, texObstacle);
	sprites->Add(20441, 496, 1770, 526, 1837, texObstacle);
	sprites->Add(20442, 532, 1770, 564, 1837, texObstacle);
	sprites->Add(20443, 569, 1770, 601, 1837, texObstacle);
	sprites->Add(20444, 607, 1770, 639, 1837, texObstacle);
	sprites->Add(20445, 569, 1770, 601, 1837, texObstacle);
	sprites->Add(20446, 532, 1770, 564, 1837, texObstacle);
	sprites->Add(20447, 496, 1770, 526, 1837, texObstacle);
	sprites->Add(20448, 461, 1770, 490, 1837, texObstacle);
	sprites->Add(20449, 428, 1770, 456, 1837, texObstacle);
	sprites->Add(20450, 397, 1770, 422, 1837, texObstacle);
	sprites->Add(20451, 371, 1770, 391, 1837, texObstacle);
	sprites->Add(20452, 349, 1770, 365, 1837, texObstacle);
	sprites->Add(20453, 327, 1770, 342, 1837, texObstacle);
	sprites->Add(20454, 306, 1770, 321, 1837, texObstacle);
	sprites->Add(20455, 286, 1770, 300, 1837, texObstacle);
	sprites->Add(20456, 266, 1770, 280, 1837, texObstacle);
	sprites->Add(20457, 246, 1770, 260, 1837, texObstacle);


	sprites->AddByWidthHeight(20500, 177, 1144, 40, 344, texObstacle); // pilar 1
	sprites->AddByWidthHeight(20501, 497, 1144, 32, 160, texObstacle); // pilar 2
	sprites->AddByWidthHeight(20502, 817, 1144, 32, 744, texObstacle); // pilar 3
	sprites->AddByWidthHeight(20503, 1169, 1144, 32, 192, texObstacle); // pilar 4

	sprites->AddByWidthHeight(20600, 2192, 1144, 78, 208, texObstacle); // exit

	sprites->AddByWidthHeight(20700, 1, 1493, 512, 256, texObstacle); // fance


	//item

	sprites->Add(21100, 340, 107, 357, 128, texItem);		//penny
	sprites->Add(21101, 363, 107, 380, 128, texItem);
	sprites->Add(21102, 386, 107, 403, 128, texItem);
	sprites->Add(21103, 409, 107, 426, 128, texItem);
	sprites->Add(21104, 432, 107, 449, 128, texItem);
	sprites->Add(21105, 454, 107, 487, 128, texItem);
	sprites->Add(21106, 492, 107, 515, 128, texItem);
	sprites->Add(21107, 522, 107, 539, 128, texItem);
	sprites->Add(21108, 545, 107, 562, 128, texItem);

	sprites->Add(21110, 335, 45, 372, 97, texItem);		//genie face
	sprites->Add(21111, 389, 45, 431, 97, texItem);
	sprites->Add(21112, 443, 45, 486, 97, texItem);
	sprites->Add(21113, 497, 45, 541, 97, texItem);

	sprites->Add(21120, 335, 45, 372, 97, texItem);

	sprites->Add(21130, 19, 424, 38, 461, texItem);		//vase
	sprites->Add(21131, 49, 424, 72, 461, texItem);
	sprites->Add(21132, 78, 424, 111, 461, texItem);
	sprites->Add(21133, 119, 424, 138, 461, texItem);
	sprites->Add(21134, 145, 424, 167, 461, texItem);
	sprites->Add(21135, 174, 424, 199, 461, texItem);
	sprites->Add(21136, 207, 424, 230, 461, texItem);
	sprites->Add(21137, 239, 424, 258, 461, texItem);
	sprites->Add(21138, 270, 424, 293, 461, texItem);
	sprites->Add(21139, 302, 424, 324, 461, texItem);

	sprites->Add(21140, 19, 424, 38, 461, texItem);

	sprites->Add(21141, 302, 424, 324, 461, texItem);	// vase stop


	sprites->Add(21150, 341, 17, 353, 29, texItem);		//apple

	sprites->AddByWidthHeight(21161, 80, 31, 38, 21, texEnemyExplosions, -14, -10);	//item effect
	sprites->AddByWidthHeight(21162, 128, 39, 17, 13, texEnemyExplosions, -8, -6);
	sprites->AddByWidthHeight(21163, 152, 28, 39, 24, texEnemyExplosions, -19, -12);
	sprites->AddByWidthHeight(21164, 200, 36, 30, 16, texEnemyExplosions, -15, -8);
	sprites->AddByWidthHeight(21165, 240, 49, 3, 3, texEnemyExplosions, -1, -1);

	sprites->AddByWidthHeight(21181, 296, 9, 6, 43, texEnemyExplosions);	//genie effect
	sprites->AddByWidthHeight(21182, 312, 9, 19, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21183, 344, 9, 26, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21184, 384, 9, 30, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21185, 424, 9, 43, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21186, 480, 9, 37, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21187, 528, 9, 42, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21188, 584, 9, 41, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21189, 8, 67, 43, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21190, 64, 67, 42, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21191, 120, 67, 43, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21192, 176, 67, 43, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21193, 232, 67, 42, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21194, 288, 67, 43, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21195, 344, 67, 41, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21196, 392, 67, 36, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21197, 440, 67, 39, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21198, 488, 67, 26, 43, texEnemyExplosions);
	sprites->AddByWidthHeight(21199, 528, 67, 20, 43, texEnemyExplosions);

	sprites->Add(21170, 343, 171, 361, 196, texItem);		//heart
	sprites->Add(21171, 366, 171, 382, 196, texItem);
	sprites->Add(21172, 386, 171, 403, 196, texItem);
	sprites->Add(21173, 406, 171, 423, 196, texItem);
	sprites->Add(21174, 426, 171, 445, 196, texItem);
	sprites->Add(21175, 448, 171, 465, 196, texItem);
	sprites->Add(21176, 467, 171, 483, 196, texItem);
	sprites->Add(21177, 486, 171, 502, 196, texItem);

	sprites->AddByWidthHeight(21200, 340, 140, 22, 24, texItem);		//life


	sprites->AddByWidthHeight(22000, 373, 24, 7, 7, texAladdinGoRight);		// throw apple

	sprites->AddByWidthHeight(22001, 394, 23, 7, 10, texAladdinGoRight, -3, -5);	// throw apple break
	sprites->AddByWidthHeight(22002, 414, 18, 20, 18, texAladdinGoRight, -10, -9);
	sprites->AddByWidthHeight(22003, 444, 16, 29, 22, texAladdinGoRight, -14, -11);
	sprites->AddByWidthHeight(22004, 485, 14, 31, 25, texAladdinGoRight, -15, -12);
	sprites->AddByWidthHeight(22005, 532, 13, 30, 27, texAladdinGoRight, -15, -13);

	//thin guard

	sprites->AddByWidthHeight(30000, 940, 160, 44, 73, texGuard);	// idle right

	sprites->AddByWidthHeight(31000, 8, 160, 44, 73, texGuard);	// idle left

	sprites->AddByWidthHeight(30001, 945, 9, 45, 67, texGuard);	// walk right
	sprites->AddByWidthHeight(30002, 894, 9, 45, 67, texGuard);
	sprites->AddByWidthHeight(30003, 837, 9, 46, 67, texGuard);
	sprites->AddByWidthHeight(30004, 783, 9, 45, 67, texGuard);
	sprites->AddByWidthHeight(30005, 741, 9, 37, 67, texGuard);
	sprites->AddByWidthHeight(30006, 690, 9, 43, 67, texGuard);
	sprites->AddByWidthHeight(30007, 634, 9, 50, 67, texGuard);
	sprites->AddByWidthHeight(30008, 593, 9, 36, 67, texGuard);

	sprites->AddByWidthHeight(31001, 2, 9, 45, 67, texGuard);	// walk left
	sprites->AddByWidthHeight(31002, 53, 9, 45, 67, texGuard);
	sprites->AddByWidthHeight(31003, 109, 9, 46, 67, texGuard);
	sprites->AddByWidthHeight(31004, 164, 9, 45, 67, texGuard);
	sprites->AddByWidthHeight(31005, 214, 9, 37, 67, texGuard);
	sprites->AddByWidthHeight(31006, 259, 9, 43, 67, texGuard);
	sprites->AddByWidthHeight(31007, 308, 9, 50, 67, texGuard);
	sprites->AddByWidthHeight(31008, 363, 9, 36, 67, texGuard);

	sprites->AddByWidthHeight(30011, 946, 82, 37, 74, texGuard);	// attack right
	sprites->AddByWidthHeight(30012, 890, 82, 49, 74, texGuard, -10);
	sprites->AddByWidthHeight(30013, 791, 82, 92, 74, texGuard);
	sprites->AddByWidthHeight(30014, 703, 82, 86, 74, texGuard);
	sprites->AddByWidthHeight(30015, 623, 82, 77, 74, texGuard);
	sprites->AddByWidthHeight(30016, 569, 82, 96, 74, texGuard);

	sprites->AddByWidthHeight(31011, 9, 82, 37, 74, texGuard);		// attack left
	sprites->AddByWidthHeight(31012, 53, 82, 49, 74, texGuard, -8);
	sprites->AddByWidthHeight(31013, 109, 82, 92, 74, texGuard, -60);
	sprites->AddByWidthHeight(31014, 203, 82, 86, 74, texGuard, -55);
	sprites->AddByWidthHeight(31015, 292, 82, 77, 74, texGuard, -44);
	sprites->AddByWidthHeight(31016, 382, 82, 96, 74, texGuard, -6);

	sprites->AddByWidthHeight(30021, 940, 160, 44, 73, texGuard, -3);	// surprise right
	sprites->AddByWidthHeight(30022, 893, 160, 40, 73, texGuard);
	sprites->AddByWidthHeight(30023, 839, 160, 39, 73, texGuard);
	sprites->AddByWidthHeight(30024, 790, 160, 41, 73, texGuard);
	sprites->AddByWidthHeight(30025, 736, 160, 46, 73, texGuard);
	sprites->AddByWidthHeight(30026, 682, 160, 42, 73, texGuard);
	sprites->AddByWidthHeight(30027, 627, 160, 47, 73, texGuard);
	sprites->AddByWidthHeight(30028, 574, 160, 40, 73, texGuard);
	sprites->AddByWidthHeight(30029, 514, 160, 45, 73, texGuard, -8);

	sprites->AddByWidthHeight(31021, 8, 160, 44, 73, texGuard, -7);		// surprise left
	sprites->AddByWidthHeight(31022, 59, 160, 40, 73, texGuard, -3);
	sprites->AddByWidthHeight(31023, 114, 160, 39, 73, texGuard);
	sprites->AddByWidthHeight(31024, 161, 160, 41, 73, texGuard, -4);
	sprites->AddByWidthHeight(31025, 210, 160, 46, 73, texGuard, -7);
	sprites->AddByWidthHeight(31026, 268, 160, 42, 73, texGuard, -8);
	sprites->AddByWidthHeight(31027, 318, 160, 47, 73, texGuard, -7);
	sprites->AddByWidthHeight(31028, 378, 160, 40, 73, texGuard, -3);
	sprites->AddByWidthHeight(31029, 433, 160, 45, 73, texGuard);

	// normal guard

	sprites->AddByWidthHeight(30100, 943, 388, 44, 53, texGuard);	// idle right

	sprites->AddByWidthHeight(31100, 5, 388, 44, 53, texGuard, -20);	// idle left

	sprites->AddByWidthHeight(30101, 943, 316, 47, 56, texGuard);	// walk right
	sprites->AddByWidthHeight(30102, 885, 316, 52, 56, texGuard);
	sprites->AddByWidthHeight(30103, 825, 316, 56, 56, texGuard);
	sprites->AddByWidthHeight(30104, 768, 316, 51, 56, texGuard);
	sprites->AddByWidthHeight(30105, 713, 316, 49, 56, texGuard);
	sprites->AddByWidthHeight(30106, 666, 316, 42, 56, texGuard);
	sprites->AddByWidthHeight(30107, 614, 316, 44, 56, texGuard);
	sprites->AddByWidthHeight(30108, 563, 316, 47, 56, texGuard);

	sprites->AddByWidthHeight(31101, 2, 316, 47, 56, texGuard);	// walk left
	sprites->AddByWidthHeight(31102, 55, 316, 52, 56, texGuard);
	sprites->AddByWidthHeight(31103, 111, 316, 56, 56, texGuard);
	sprites->AddByWidthHeight(31104, 173, 316, 51, 56, texGuard);
	sprites->AddByWidthHeight(31105, 230, 316, 49, 56, texGuard);
	sprites->AddByWidthHeight(31106, 284, 316, 42, 56, texGuard);
	sprites->AddByWidthHeight(31107, 334, 316, 44, 56, texGuard);
	sprites->AddByWidthHeight(31108, 382, 316, 47, 56, texGuard);

	sprites->AddByWidthHeight(30111, 943, 448, 44, 54, texGuard);	// wait right
	sprites->AddByWidthHeight(30112, 899, 448, 37, 54, texGuard);
	sprites->AddByWidthHeight(30113, 840, 448, 54, 54, texGuard);
	sprites->AddByWidthHeight(30114, 777, 448, 58, 54, texGuard);
	sprites->AddByWidthHeight(30115, 722, 448, 49, 54, texGuard);
	sprites->AddByWidthHeight(30116, 670, 448, 44, 54, texGuard);

	sprites->AddByWidthHeight(31111, 5, 448, 44, 54, texGuard, -19);	// wait left
	sprites->AddByWidthHeight(31112, 56, 448, 37, 54, texGuard, -12);
	sprites->AddByWidthHeight(31113, 98, 448, 54, 54, texGuard, -29);
	sprites->AddByWidthHeight(31114, 157, 448, 58, 54, texGuard, -33);
	sprites->AddByWidthHeight(31115, 221, 448, 49, 54, texGuard, -24);
	sprites->AddByWidthHeight(31116, 278, 448, 44, 54, texGuard, -19);

	sprites->AddByWidthHeight(30121, 931, 552, 55, 73, texGuard, -4);		//attack stab right
	sprites->AddByWidthHeight(30122, 860, 552, 67, 73, texGuard, -5);
	sprites->AddByWidthHeight(30123, 782, 552, 70, 73, texGuard, -6);
	sprites->AddByWidthHeight(30124, 701, 552, 75, 73, texGuard, -7);
	sprites->AddByWidthHeight(30125, 607, 552, 88, 73, texGuard, -7);
	sprites->AddByWidthHeight(30126, 502, 552, 95, 73, texGuard, -7);

	sprites->AddByWidthHeight(31121, 6, 552, 55, 73, texGuard, -25);		//attack stab left
	sprites->AddByWidthHeight(31122, 65, 552, 67, 73, texGuard, -36);
	sprites->AddByWidthHeight(31123, 140, 552, 70, 73, texGuard, -38);
	sprites->AddByWidthHeight(31124, 216, 552, 75, 73, texGuard, -42);
	sprites->AddByWidthHeight(31125, 297, 552, 88, 73, texGuard, -55);
	sprites->AddByWidthHeight(31126, 395, 552, 95, 73, texGuard, -61);

	sprites->AddByWidthHeight(30127, 943, 629, 43, 73, texGuard, -15);	//attack slash right
	sprites->AddByWidthHeight(30128, 888, 629, 43, 73, texGuard, -18);
	sprites->AddByWidthHeight(30129, 824, 629, 52, 73, texGuard, -24);
	sprites->AddByWidthHeight(30130, 700, 629, 114, 73, texGuard, -19);
	sprites->AddByWidthHeight(30131, 601, 629, 91, 73, texGuard, -15);

	sprites->AddByWidthHeight(31127, 6, 629, 43, 73, texGuard, -4);		//attack slash left
	sprites->AddByWidthHeight(31128, 61, 629, 43, 73, texGuard, -1);
	sprites->AddByWidthHeight(31129, 116, 629, 52, 73, texGuard, -4);
	sprites->AddByWidthHeight(31130, 178, 629, 114, 73, texGuard, -71);
	sprites->AddByWidthHeight(31131, 300, 629, 91, 73, texGuard, -52);

	sprites->AddByWidthHeight(30141, 932, 789, 54, 71, texGuard);		// suprise right
	sprites->AddByWidthHeight(30142, 858, 789, 63, 71, texGuard, -18);
	sprites->AddByWidthHeight(30143, 789, 789, 65, 71, texGuard, -23);
	sprites->AddByWidthHeight(30144, 711, 789, 71, 71, texGuard, -26);
	sprites->AddByWidthHeight(30145, 628, 789, 74, 71, texGuard, -26);
	sprites->AddByWidthHeight(30146, 544, 789, 66, 71, texGuard, -13);

	sprites->AddByWidthHeight(31141, 6, 789, 54, 71, texGuard, -21);	// surprise left
	sprites->AddByWidthHeight(31142, 71, 789, 63, 71, texGuard, -18);
	sprites->AddByWidthHeight(31143, 138, 789, 65, 71, texGuard, -18);
	sprites->AddByWidthHeight(31144, 210, 789, 71, 71, texGuard, -20);
	sprites->AddByWidthHeight(31145, 290, 789, 74, 71, texGuard, -24);
	sprites->AddByWidthHeight(31146, 382, 789, 66, 71, texGuard, -19);

	// fat guard
	sprites->AddByWidthHeight(30200, 940, 943, 43, 50, texGuard);	// idle right

	sprites->AddByWidthHeight(31200, 9, 943, 43, 50, texGuard);	// idle left

	sprites->AddByWidthHeight(30201, 948, 1056, 37, 60, texGuard);	// walk right
	sprites->AddByWidthHeight(30202, 905, 1056, 35, 60, texGuard);
	sprites->AddByWidthHeight(30203, 862, 1056, 37, 60, texGuard);
	sprites->AddByWidthHeight(30204, 820, 1056, 39, 60, texGuard);
	sprites->AddByWidthHeight(30205, 771, 1056, 43, 60, texGuard);
	sprites->AddByWidthHeight(30206, 720, 1056, 39, 60, texGuard);
	sprites->AddByWidthHeight(30207, 674, 1056, 37, 60, texGuard);
	sprites->AddByWidthHeight(30208, 635, 1056, 34, 60, texGuard);

	sprites->AddByWidthHeight(31201, 7, 1056, 37, 60, texGuard);		// walk left
	sprites->AddByWidthHeight(31202, 52, 1056, 35, 60, texGuard);
	sprites->AddByWidthHeight(31203, 93, 1056, 37, 60, texGuard);
	sprites->AddByWidthHeight(31204, 133, 1056, 39, 60, texGuard);
	sprites->AddByWidthHeight(31205, 178, 1056, 43, 60, texGuard);
	sprites->AddByWidthHeight(31206, 233, 1056, 39, 60, texGuard);
	sprites->AddByWidthHeight(31207, 281, 1056, 37, 60, texGuard);
	sprites->AddByWidthHeight(31208, 323, 1056, 34, 60, texGuard);

	sprites->AddByWidthHeight(30211, 935, 1183, 55, 58, texGuard);	// attack right
	sprites->AddByWidthHeight(30212, 888, 1183, 36, 58, texGuard);
	sprites->AddByWidthHeight(30213, 816, 1183, 61, 58, texGuard);
	sprites->AddByWidthHeight(30214, 764, 1183, 46, 58, texGuard);
	sprites->AddByWidthHeight(30215, 723, 1183, 33, 58, texGuard);

	sprites->AddByWidthHeight(31211, 2, 1183, 55, 58, texGuard);		// attack right
	sprites->AddByWidthHeight(31212, 68, 1183, 36, 58, texGuard);
	sprites->AddByWidthHeight(31213, 61, 1183, 61, 58, texGuard);
	sprites->AddByWidthHeight(31214, 182, 1183, 46, 58, texGuard);
	sprites->AddByWidthHeight(31215, 236, 1183, 33, 58, texGuard);

	sprites->AddByWidthHeight(30221, 2, 999, 37, 52, texGuard);		// surprise right
	sprites->AddByWidthHeight(30222, 45, 999, 37, 52, texGuard);
	sprites->AddByWidthHeight(30223, 94, 999, 34, 52, texGuard);
	sprites->AddByWidthHeight(30224, 143, 999, 38, 52, texGuard);
	sprites->AddByWidthHeight(30225, 187, 999, 54, 52, texGuard);
	sprites->AddByWidthHeight(30226, 247, 999, 52, 52, texGuard);
	sprites->AddByWidthHeight(30227, 308, 999, 49, 52, texGuard);

	sprites->AddByWidthHeight(31221, 953, 999, 37, 52, texGuard);		// surprise left
	sprites->AddByWidthHeight(31222, 910, 999, 37, 52, texGuard);
	sprites->AddByWidthHeight(31223, 864, 999, 34, 52, texGuard);
	sprites->AddByWidthHeight(31224, 811, 999, 38, 52, texGuard);
	sprites->AddByWidthHeight(31225, 751, 999, 54, 52, texGuard);
	sprites->AddByWidthHeight(31226, 693, 999, 52, 52, texGuard);
	sprites->AddByWidthHeight(31227, 644, 999, 49, 52, texGuard);

	// bat
	sprites->AddByWidthHeight(30301, 9, 10, 7, 26, texBat);					// wait

	sprites->AddByWidthHeight(30302, 20, 10, 21, 26, texBat);				// swing
	sprites->AddByWidthHeight(30303, 48, 10, 19, 26, texBat);
	sprites->AddByWidthHeight(30304, 76, 10, 21, 26, texBat);

	sprites->AddByWidthHeight(30311, 10, 52, 24, 40, texBat);				// fly
	sprites->AddByWidthHeight(30312, 39, 52, 13, 40, texBat);
	sprites->AddByWidthHeight(30313, 56, 52, 30, 40, texBat);
	sprites->AddByWidthHeight(30314, 89, 52, 32, 40, texBat);
	sprites->AddByWidthHeight(30315, 128, 52, 8, 40, texBat);
	sprites->AddByWidthHeight(30316, 143, 52, 20, 40, texBat);
	sprites->AddByWidthHeight(30317, 165, 52, 34, 40, texBat);

	sprites->Add(30320, 10, 100, 23, 159, texBat);							//die
	sprites->Add(30321, 38, 100, 89, 159, texBat);
	sprites->Add(30322, 93, 100, 115, 159, texBat);
	sprites->Add(30323, 128, 100, 146, 159, texBat);
	sprites->Add(30324, 160, 100, 189, 159, texBat);
	sprites->Add(30325, 199, 100, 228, 159, texBat);
	sprites->Add(30326, 233, 100, 266, 159, texBat);
	sprites->Add(30327, 275, 100, 298, 159, texBat);
	sprites->Add(30328, 306, 100, 335, 159, texBat);

	//skeleton
	sprites->AddByWidthHeight(30400, 876, 8, 86, 91, texSkeleton);			// wait right

	sprites->AddByWidthHeight(31400, 774, 8, 86, 91, texSkeleton);			// wait left

	sprites->AddByWidthHeight(30401, 876, 8, 86, 91, texSkeleton);			// stand up right
	sprites->AddByWidthHeight(30402, 969, 8, 80, 91, texSkeleton);
	sprites->AddByWidthHeight(30403, 1056, 8, 75, 91, texSkeleton);
	sprites->AddByWidthHeight(30404, 1151, 8, 62, 91, texSkeleton);
	sprites->AddByWidthHeight(30405, 1233, 8, 50, 91, texSkeleton);
	sprites->AddByWidthHeight(30406, 1295, 8, 48, 91, texSkeleton);
	sprites->AddByWidthHeight(30407, 1354, 8, 48, 91, texSkeleton);
	sprites->AddByWidthHeight(30408, 1412, 8, 51, 91, texSkeleton);
	sprites->AddByWidthHeight(30409, 1469, 8, 51, 91, texSkeleton);
	sprites->AddByWidthHeight(30410, 1530, 8, 52, 91, texSkeleton);
	sprites->AddByWidthHeight(30411, 1594, 8, 68, 91, texSkeleton);
	sprites->AddByWidthHeight(30412, 1667, 8, 65, 91, texSkeleton);
	sprites->AddByWidthHeight(30413, 881, 115, 50, 91, texSkeleton);
	sprites->AddByWidthHeight(30414, 943, 115, 49, 91, texSkeleton);
	sprites->AddByWidthHeight(30415, 1000, 115, 61, 91, texSkeleton);
	sprites->AddByWidthHeight(30416, 1071, 115, 64, 91, texSkeleton);
	sprites->AddByWidthHeight(30417, 1147, 115, 74, 91, texSkeleton);
	sprites->AddByWidthHeight(30418, 1244, 115, 81, 91, texSkeleton);
	sprites->AddByWidthHeight(30419, 1347, 115, 95, 91, texSkeleton);
	sprites->AddByWidthHeight(30420, 1461, 115, 60, 91, texSkeleton);

	sprites->AddByWidthHeight(31401, 774, 8, 86, 91, texSkeleton);			// stand up left
	sprites->AddByWidthHeight(31402, 687, 8, 80, 91, texSkeleton);
	sprites->AddByWidthHeight(31403, 605, 8, 75, 91, texSkeleton);
	sprites->AddByWidthHeight(31404, 523, 8, 62, 91, texSkeleton);
	sprites->AddByWidthHeight(31405, 453, 8, 50, 91, texSkeleton);
	sprites->AddByWidthHeight(31406, 393, 8, 48, 91, texSkeleton);
	sprites->AddByWidthHeight(31407, 334, 8, 48, 91, texSkeleton);
	sprites->AddByWidthHeight(31408, 273, 8, 51, 91, texSkeleton);
	sprites->AddByWidthHeight(31409, 216, 8, 51, 91, texSkeleton);
	sprites->AddByWidthHeight(31410, 154, 8, 52, 91, texSkeleton);
	sprites->AddByWidthHeight(31411, 74, 8, 68, 91, texSkeleton);
	sprites->AddByWidthHeight(31412, 4, 8, 65, 91, texSkeleton);
	sprites->AddByWidthHeight(31413, 805, 115, 50, 91, texSkeleton);
	sprites->AddByWidthHeight(31414, 744, 115, 49, 91, texSkeleton);
	sprites->AddByWidthHeight(31415, 675, 115, 61, 91, texSkeleton);
	sprites->AddByWidthHeight(31416, 601, 115, 64, 91, texSkeleton);
	sprites->AddByWidthHeight(31417, 515, 115, 74, 91, texSkeleton);
	sprites->AddByWidthHeight(31418, 411, 115, 81, 91, texSkeleton);
	sprites->AddByWidthHeight(31419, 294, 115, 95, 91, texSkeleton);
	sprites->AddByWidthHeight(31420, 215, 115, 60, 91, texSkeleton);

	sprites->AddByWidthHeight(31433, 1533, 129, 16, 5, texSkeleton);	// bond 1
	sprites->AddByWidthHeight(31432, 1556, 122, 6, 15, texSkeleton);		// bond 2
	sprites->AddByWidthHeight(31431, 1568, 122, 12, 13, texSkeleton);	// bond 3
	sprites->AddByWidthHeight(31430, 1586, 126, 6, 8, texSkeleton);		// bond 4




	// jafar
	sprites->AddByWidthHeight(40000, 870, 9, 64, 71, texJafar);		//idle right

	sprites->AddByWidthHeight(41000, 791, 9, 64, 71, texJafar, -19);		//idle left

	sprites->AddByWidthHeight(40001, 942, 9, 57, 71, texJafar);		//attack right
	sprites->AddByWidthHeight(40002, 1006, 9, 55, 71, texJafar);
	sprites->AddByWidthHeight(40003, 1070, 9, 51, 71, texJafar);
	sprites->AddByWidthHeight(40004, 1134, 9, 64, 71, texJafar);
	sprites->AddByWidthHeight(40005, 1206, 9, 82, 71, texJafar);
	sprites->AddByWidthHeight(40006, 1302, 9, 85, 71, texJafar);
	sprites->AddByWidthHeight(40007, 1398, 9, 69, 71, texJafar);

	sprites->AddByWidthHeight(41001, 726, 9, 57, 71, texJafar, -13);		//attack left
	sprites->AddByWidthHeight(41002, 664, 9, 55, 71, texJafar, -11);
	sprites->AddByWidthHeight(41003, 604, 9, 51, 71, texJafar, -7);
	sprites->AddByWidthHeight(41004, 527, 9, 64, 71, texJafar, -21);
	sprites->AddByWidthHeight(41005, 437, 9, 82, 71, texJafar, -59);
	sprites->AddByWidthHeight(41006, 338, 9, 85, 71, texJafar, -42);
	sprites->AddByWidthHeight(41007, 259, 9, 69, 71, texJafar, -25);

	// star
	sprites->AddByWidthHeight(40010, 1060, 423, 28, 16, texJafar);		// right
	sprites->AddByWidthHeight(40011, 1100, 423, 24, 16, texJafar);
	sprites->AddByWidthHeight(40012, 1132, 423, 26, 16, texJafar);

	sprites->AddByWidthHeight(41010, 637, 423, 28, 16, texJafar);		// left
	sprites->AddByWidthHeight(41011, 601, 423, 24, 16, texJafar);
	sprites->AddByWidthHeight(41012, 567, 423, 26, 16, texJafar);

	// star effect
	sprites->AddByWidthHeight(40020, 543, 429, 7, 10, texJafar);		// right
	sprites->AddByWidthHeight(40021, 511, 432, 15, 7, texJafar);
	sprites->AddByWidthHeight(40022, 466, 418, 15, 21, texJafar);

	// snake
	sprites->AddByWidthHeight(40101, 870, 291, 70, 84, texJafar, -13);		//snake right
	sprites->AddByWidthHeight(40102, 950, 291, 64, 84, texJafar, -25);
	sprites->AddByWidthHeight(40103, 1022, 291, 67, 84, texJafar, -38);
	sprites->AddByWidthHeight(40104, 1102, 291, 71, 84, texJafar, -42);
	sprites->AddByWidthHeight(40105, 1182, 291, 69, 84, texJafar, -37);
	sprites->AddByWidthHeight(40106, 1262, 291, 69, 84, texJafar, -37);
	sprites->AddByWidthHeight(40107, 1342, 291, 70, 84, texJafar, -38);
	sprites->AddByWidthHeight(40108, 1422, 291, 70, 84, texJafar, -38);
	sprites->AddByWidthHeight(40109, 1506, 291, 64, 84, texJafar, -36);
	sprites->AddByWidthHeight(40110, 1578, 291, 64, 84, texJafar, -18);
	sprites->AddByWidthHeight(40111, 1650, 291, 71, 84, texJafar, -7);

	sprites->AddByWidthHeight(41101, 785, 291, 70, 84, texJafar, -35);		//snake left
	sprites->AddByWidthHeight(41102, 711, 291, 64, 84, texJafar, -16);
	sprites->AddByWidthHeight(41103, 636, 291, 67, 84, texJafar, -6);
	sprites->AddByWidthHeight(41104, 552, 291, 71, 84, texJafar, -4);
	sprites->AddByWidthHeight(41105, 474, 291, 69, 84, texJafar);
	sprites->AddByWidthHeight(41106, 394, 291, 69, 84, texJafar);
	sprites->AddByWidthHeight(41107, 313, 291, 70, 84, texJafar, -1);
	sprites->AddByWidthHeight(41108, 233, 291, 70, 84, texJafar, -1);
	sprites->AddByWidthHeight(41109, 155, 291, 64, 84, texJafar, -2);
	sprites->AddByWidthHeight(41110, 83, 291, 64, 84, texJafar, -19);
	sprites->AddByWidthHeight(41111, 4, 291, 71, 84, texJafar, -37);

	sprites->AddByWidthHeight(40121, 870, 484, 75, 51, texJafar);		//snake fire right
	sprites->AddByWidthHeight(40122, 958, 484, 79, 51, texJafar);
	sprites->AddByWidthHeight(40123, 1051, 484, 94, 51, texJafar);
	sprites->AddByWidthHeight(40124, 1158, 484, 90, 51, texJafar);
	sprites->AddByWidthHeight(40125, 1262, 484, 77, 51, texJafar);
	sprites->AddByWidthHeight(40126, 1350, 484, 73, 51, texJafar);
	sprites->AddByWidthHeight(40127, 1430, 484, 64, 51, texJafar);
	sprites->AddByWidthHeight(40128, 1507, 484, 64, 51, texJafar);

	sprites->AddByWidthHeight(41121, 780, 484, 75, 51, texJafar);		//snake fire left
	sprites->AddByWidthHeight(41122, 958, 484, 79, 51, texJafar);
	sprites->AddByWidthHeight(41123, 580, 484, 94, 51, texJafar);
	sprites->AddByWidthHeight(41124, 477, 484, 90, 51, texJafar);
	sprites->AddByWidthHeight(41125, 386, 484, 77, 51, texJafar);
	sprites->AddByWidthHeight(41126, 302, 484, 73, 51, texJafar);
	sprites->AddByWidthHeight(41127, 231, 484, 64, 51, texJafar);
	sprites->AddByWidthHeight(41128, 154, 484, 64, 51, texJafar);

	//fire
	sprites->AddByWidthHeight(40201, 876, 386, 24, 53, texJafar);
	sprites->AddByWidthHeight(40202, 908, 386, 22, 53, texJafar);
	sprites->AddByWidthHeight(40203, 940, 386, 24, 53, texJafar);
	sprites->AddByWidthHeight(40204, 972, 386, 27, 53, texJafar);
	sprites->AddByWidthHeight(40205, 1012, 386, 35, 53, texJafar);



	// efect
	sprites->AddByWidthHeight(50001, 8, 67, 43, 41, texEnemyExplosions, -21, -20);
	sprites->AddByWidthHeight(50002, 64, 67, 42, 41, texEnemyExplosions, -21, -20);
	sprites->AddByWidthHeight(50003, 120, 69, 43, 39, texEnemyExplosions, -21, -19);
	sprites->AddByWidthHeight(50004, 176, 71, 43, 37, texEnemyExplosions, -21, -18);
	sprites->AddByWidthHeight(50005, 232, 71, 42, 37, texEnemyExplosions, -21, -18);
	sprites->AddByWidthHeight(50006, 288, 64, 43, 44, texEnemyExplosions, -21, -22);
	sprites->AddByWidthHeight(50007, 344, 73, 41, 35, texEnemyExplosions, -20, -17);
	sprites->AddByWidthHeight(50008, 392, 84, 41, 24, texEnemyExplosions, -20, -12);
	sprites->AddByWidthHeight(50009, 440, 84, 34, 24, texEnemyExplosions, -17, -12);
	sprites->AddByWidthHeight(50010, 488, 88, 26, 20, texEnemyExplosions, -13, -10);
	sprites->AddByWidthHeight(50011, 528, 89, 20, 19, texEnemyExplosions, -10, -9);
	sprites->AddByWidthHeight(50012, 566, 84, 10, 23, texEnemyExplosions, -5, -11);

	sprites->AddByWidthHeight(50101, 8, 180, 26, 24, texEnemyExplosions, -13, -12);
	sprites->AddByWidthHeight(50102, 48, 155, 60, 49, texEnemyExplosions, -30, -24);
	sprites->AddByWidthHeight(50103, 120, 118, 81, 86, texEnemyExplosions, -40, -43);
	sprites->AddByWidthHeight(50104, 208, 123, 83, 81, texEnemyExplosions, -41, -40);
	sprites->AddByWidthHeight(50105, 304, 124, 82, 80, texEnemyExplosions, -41, -40);
	sprites->AddByWidthHeight(50106, 400, 128, 83, 76, texEnemyExplosions, -41, -33);
	sprites->AddByWidthHeight(50107, 496, 131, 83, 73, texEnemyExplosions, -41, -36);

	//iago

	//sprites->AddByWidthHeight(40101, 10, 10, 43, 59, texIagoRight);		//fly right
	//sprites->AddByWidthHeight(40102, 71, 10, 62, 59, texIagoRight);
	//sprites->AddByWidthHeight(40103, 144, 10, 61, 59, texIagoRight);
	//sprites->AddByWidthHeight(40104, 217, 10, 61, 59, texIagoRight);
	//sprites->AddByWidthHeight(40105, 291, 10, 60, 59, texIagoRight);
	//sprites->AddByWidthHeight(40106, 375, 10, 60, 59, texIagoRight);
	//sprites->AddByWidthHeight(40107, 439, 10, 61, 59, texIagoRight);
	//sprites->AddByWidthHeight(40108, 512, 10, 61, 59, texIagoRight);

	//sprites->AddByWidthHeight(41101, 581, 10, 43, 59, texIagoLeft);		//fly left
	//sprites->AddByWidthHeight(41102, 501, 10, 62, 59, texIagoLeft);
	//sprites->AddByWidthHeight(41103, 429, 10, 61, 59, texIagoLeft);
	//sprites->AddByWidthHeight(41104, 356, 10, 61, 59, texIagoLeft);
	//sprites->AddByWidthHeight(41105, 283, 10, 60, 59, texIagoLeft);
	//sprites->AddByWidthHeight(41106, 209, 10, 60, 59, texIagoLeft);
	//sprites->AddByWidthHeight(41107, 134, 10, 61, 59, texIagoLeft);
	//sprites->AddByWidthHeight(41108, 61, 10, 61, 59, texIagoLeft);

	//sprites->AddByWidthHeight(40111, 13, 78, 51, 70, texIagoRight);		//die right
	//sprites->AddByWidthHeight(40112, 77, 78, 48, 70, texIagoRight);
	//sprites->AddByWidthHeight(40113, 139, 78, 81, 70, texIagoRight);
	//sprites->AddByWidthHeight(40114, 236, 78, 47, 70, texIagoRight);

	//sprites->AddByWidthHeight(41111, 570, 78, 51, 70, texIagoLeft);		//die left
	//sprites->AddByWidthHeight(41112, 509, 78, 48, 70, texIagoLeft);
	//sprites->AddByWidthHeight(41113, 414, 78, 81, 70, texIagoLeft);
	//sprites->AddByWidthHeight(41114, 351, 78, 47, 70, texIagoLeft);

	//statue

	//sprites->AddByWidthHeight(40200, 10, 7, 51, 76, texStatueRight);		//idle right

	//sprites->AddByWidthHeight(41200, 599, 7, 51, 76, texStatueLeft, -16);		//idle left

	//sprites->AddByWidthHeight(40201, 75, 7, 44, 76, texStatueRight);		//attack right
	//sprites->AddByWidthHeight(40202, 135, 7, 43, 76, texStatueRight);
	//sprites->AddByWidthHeight(40203, 190, 7, 42, 76, texStatueRight);
	//sprites->AddByWidthHeight(40204, 245, 7, 45, 76, texStatueRight);
	//sprites->AddByWidthHeight(40205, 307, 7, 71, 76, texStatueRight);
	//sprites->AddByWidthHeight(40206, 392, 7, 59, 76, texStatueRight);
	//sprites->AddByWidthHeight(40207, 465, 7, 49, 76, texStatueRight);

	//sprites->AddByWidthHeight(41201, 541, 7, 44, 76, texStatueLeft, -6);		//attack left
	//sprites->AddByWidthHeight(41202, 482, 7, 43, 76, texStatueLeft, -3);
	//sprites->AddByWidthHeight(41203, 428, 7, 42, 76, texStatueLeft);
	//sprites->AddByWidthHeight(41204, 370, 7, 45, 76, texStatueLeft, -7);
	//sprites->AddByWidthHeight(41205, 282, 7, 71, 76, texStatueLeft, -35);
	//sprites->AddByWidthHeight(41206, 209, 7, 59, 76, texStatueLeft, -23);
	//sprites->AddByWidthHeight(41207, 146, 7, 49, 76, texStatueLeft, -12);
}

void AladdinResoucres::LoadAnimations()
{
	LPANIMATION ani;

	ani = new CAnimation(100);	// idle right
	ani->Add(10001);
	animations->Add(100, ani);

	ani = new CAnimation(100);
	ani->Add(11001);
	animations->Add(101, ani);	//idle left

	ani = new CAnimation(100);	// standing right
	ani->Add(10002);
	ani->Add(10003);
	ani->Add(10004);
	ani->Add(10005);
	ani->Add(10006);
	ani->Add(10007);
	ani->Add(10008);
	ani->Add(10009);
	ani->Add(10010);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	ani->Add(10014);
	ani->Add(10015);
	ani->Add(10016);
	ani->Add(10017);
	ani->Add(10018);
	ani->Add(10019);
	ani->Add(10020);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	ani->Add(10025);
	ani->Add(10026);
	ani->Add(10027);
	ani->Add(10028);
	ani->Add(10029);
	ani->Add(10030);
	ani->Add(10031);
	ani->Add(10032);
	ani->Add(10033);
	animations->Add(102, ani);

	ani = new CAnimation(100);	// standing left
	ani->Add(11002);
	ani->Add(11003);
	ani->Add(11004);
	ani->Add(11005);
	ani->Add(11006);
	ani->Add(11007);
	ani->Add(11008);
	ani->Add(11009);
	ani->Add(11010);
	ani->Add(11011);
	ani->Add(11012);
	ani->Add(11013);
	ani->Add(11014);
	ani->Add(11015);
	ani->Add(11016);
	ani->Add(11017);
	ani->Add(11018);
	ani->Add(11019);
	ani->Add(11020);
	ani->Add(11021);
	ani->Add(11022);
	ani->Add(11023);
	ani->Add(11024);
	ani->Add(11025);
	ani->Add(11026);
	ani->Add(11027);
	ani->Add(11028);
	ani->Add(11029);
	ani->Add(11030);
	ani->Add(11031);
	ani->Add(11032);
	ani->Add(11033);
	animations->Add(103, ani);

	ani = new CAnimation(100, false);	// sitting down right
	ani->Add(10041);
	ani->Add(10042);
	ani->Add(10043);
	ani->Add(10044);
	animations->Add(104, ani);

	ani = new CAnimation(100, false);	// sitting down left
	ani->Add(11041);
	ani->Add(11042);
	ani->Add(11043);
	ani->Add(11044);
	animations->Add(105, ani);

	ani = new CAnimation(100, false);	// looking up right
	ani->Add(10051);
	ani->Add(10052);
	ani->Add(10053);
	animations->Add(106, ani);

	ani = new CAnimation(100, false);	// looking up left
	ani->Add(11051);
	ani->Add(11052);
	ani->Add(11053);
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

	ani = new CAnimation(60);	// jump right
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

	ani = new CAnimation(85);	// jump left
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

	ani = new CAnimation(85);	// run jump right
	ani->Add(10221);
	ani->Add(10222);
	ani->Add(10223);
	ani->Add(10224);
	ani->Add(10225);
	ani->Add(10226);
	ani->Add(10227);
	ani->Add(10228);
	ani->Add(10229);
	animations->Add(122, ani);

	ani = new CAnimation(100);	// run jump left
	ani->Add(11221);
	ani->Add(11222);
	ani->Add(11223);
	ani->Add(11224);
	ani->Add(11225);
	ani->Add(11226);
	ani->Add(11227);
	ani->Add(11228);
	ani->Add(11229);
	animations->Add(123, ani);

	ani = new CAnimation(85);	// run slash right
	ani->Add(10231);
	ani->Add(10232);
	ani->Add(10233);
	ani->Add(10234);
	ani->Add(10235);
	ani->Add(10236);
	animations->Add(124, ani);

	ani = new CAnimation(85);	// run slash left
	ani->Add(11231);
	ani->Add(11232);
	ani->Add(11233);
	ani->Add(11234);
	ani->Add(11235);
	ani->Add(11236);
	animations->Add(125, ani);

	ani = new CAnimation(85);	// run throw right
	ani->Add(10241);
	ani->Add(10242);
	ani->Add(10243);
	ani->Add(10244);
	ani->Add(10245);
	ani->Add(10246);
	animations->Add(126, ani);

	ani = new CAnimation(85);	// run throw left
	ani->Add(11241);
	ani->Add(11242);
	ani->Add(11243);
	ani->Add(11244);
	ani->Add(11245);
	ani->Add(11246);
	animations->Add(127, ani);

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

	ani = new CAnimation(100);	// jumping slash right
	ani->Add(10341);
	ani->Add(10342);
	ani->Add(10343);
	ani->Add(10344);
	ani->Add(10345);
	ani->Add(10346);
	animations->Add(137, ani);

	ani = new CAnimation(100);	// jumping slash left
	ani->Add(11341);
	ani->Add(11342);
	ani->Add(11343);
	ani->Add(11344);
	ani->Add(11345);
	ani->Add(11346);
	animations->Add(138, ani);

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

	ani = new CAnimation(100);	// jumping throw apple right
	ani->Add(10421);
	ani->Add(10422);
	ani->Add(10423);
	ani->Add(10424);
	ani->Add(10425);
	animations->Add(144, ani);

	ani = new CAnimation(100);	// jumping throw apple left
	ani->Add(11421);
	ani->Add(11422);
	ani->Add(11423);
	ani->Add(11424);
	ani->Add(11425);
	animations->Add(145, ani);

	ani = new CAnimation(80);	// climbing
	ani->Add(10501);
	ani->Add(10502);
	ani->Add(10503);
	//ani->Add(10504, 50);
	ani->Add(10505);
	ani->Add(10506);
	ani->Add(10507);
	ani->Add(10508);
	//ani->Add(10509, 50);
	ani->Add(10510);
	animations->Add(150, ani);

	ani = new CAnimation(100);	// falling after climbing
	ani->Add(10521);
	ani->Add(10522);
	ani->Add(10523);
	ani->Add(10524);
	ani->Add(10525);
	ani->Add(10526);
	ani->Add(10527);
	ani->Add(10528);
	ani->Add(10529);
	animations->Add(151, ani);

	ani = new CAnimation(100);	// climbing slash right
	ani->Add(10531);
	ani->Add(10532);
	ani->Add(10533);
	ani->Add(10534);
	ani->Add(10535);
	ani->Add(10536);
	ani->Add(10537);
	animations->Add(152, ani);

	ani = new CAnimation(100);	// climbing slash left
	ani->Add(11531);
	ani->Add(11532);
	ani->Add(11533);
	ani->Add(11534);
	ani->Add(11535);
	ani->Add(11536);
	ani->Add(11537);
	animations->Add(153, ani);

	ani = new CAnimation(100);	// climbing throw apple right
	ani->Add(10541);
	ani->Add(10542);
	ani->Add(10543);
	ani->Add(10544);
	ani->Add(10545);
	animations->Add(154, ani);

	ani = new CAnimation(100);	// climbing throw apple left
	ani->Add(11541);
	ani->Add(11542);
	ani->Add(11543);
	ani->Add(11544);
	ani->Add(11545);
	animations->Add(155, ani);

	ani = new CAnimation(100);	// ride the carpet right
	ani->Add(10601);
	ani->Add(10602);
	ani->Add(10603);
	ani->Add(10604);
	ani->Add(10605);
	ani->Add(10606);
	animations->Add(161, ani);

	ani = new CAnimation(100);	// ride the carpet left
	ani->Add(11601);
	ani->Add(11602);
	ani->Add(11603);
	ani->Add(11604);
	ani->Add(11605);
	ani->Add(11606);
	animations->Add(162, ani);

	ani = new CAnimation(200);	// look around right
	ani->Add(10034);
	ani->Add(10035);
	ani->Add(10036);
	ani->Add(10037);
	ani->Add(10038);
	ani->Add(10039);
	animations->Add(163, ani);

	ani = new CAnimation(200);	// look around left
	ani->Add(11034);
	ani->Add(11035);
	ani->Add(11036);
	ani->Add(11037);
	ani->Add(11038);
	ani->Add(11039);
	animations->Add(164, ani);

	ani = new CAnimation(100);	// be attacked right
	ani->Add(10701);
	ani->Add(10702);
	ani->Add(10703);
	ani->Add(10704);
	ani->Add(10705);
	ani->Add(10706);
	animations->Add(165, ani);

	ani = new CAnimation(100);	// be attacked left
	ani->Add(11701);
	ani->Add(11702);
	ani->Add(11703);
	ani->Add(11704);
	ani->Add(11705);
	ani->Add(11706);
	animations->Add(166, ani);

	// enemy
	// thin guard
	ani = new CAnimation(100);		// idle right
	ani->Add(30000);
	animations->Add(201, ani);

	ani = new CAnimation(100);		// idle left
	ani->Add(31000);
	animations->Add(202, ani);

	ani = new CAnimation(100);		// walk right
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30003);
	ani->Add(30004);
	ani->Add(30005);
	ani->Add(30006);
	ani->Add(30007);
	ani->Add(30008);
	animations->Add(203, ani);

	ani = new CAnimation(100);		// walk left
	ani->Add(31001);
	ani->Add(31002);
	ani->Add(31003);
	ani->Add(31004);
	ani->Add(31005);
	ani->Add(31006);
	ani->Add(31007);
	ani->Add(31008);
	animations->Add(204, ani);

	ani = new CAnimation(100);		// attack right
	ani->Add(30011);
	ani->Add(30012);
	ani->Add(30013);
	ani->Add(30014);
	ani->Add(30015);
	ani->Add(30016);
	animations->Add(205, ani);

	ani = new CAnimation(100);		// attack left
	ani->Add(31011);
	ani->Add(31012);
	ani->Add(31013);
	ani->Add(31014);
	ani->Add(31015);
	ani->Add(31016);
	animations->Add(206, ani);

	ani = new CAnimation(100);		// surprise right
	ani->Add(30021);
	ani->Add(30022);
	ani->Add(30023);
	ani->Add(30024);
	ani->Add(30025);
	ani->Add(30026);
	ani->Add(30027);
	ani->Add(30028);
	ani->Add(30029);
	animations->Add(207, ani);

	ani = new CAnimation(100);		// surprise left
	ani->Add(31021);
	ani->Add(31022);
	ani->Add(31023);
	ani->Add(31024);
	ani->Add(31025);
	ani->Add(31026);
	ani->Add(31027);
	ani->Add(31028);
	ani->Add(31029);
	animations->Add(208, ani);

	// nomal guard

	ani = new CAnimation(100);		// idle right
	ani->Add(30100);
	animations->Add(300, ani);

	ani = new CAnimation(100);		// idle left
	ani->Add(31100);
	animations->Add(301, ani);

	ani = new CAnimation(100);		// walk right
	ani->Add(30101);
	ani->Add(30102);
	ani->Add(30103);
	ani->Add(30104);
	ani->Add(30105);
	ani->Add(30106);
	ani->Add(30107);
	ani->Add(30108);
	animations->Add(302, ani);

	ani = new CAnimation(100);		// walk left
	ani->Add(31101);
	ani->Add(31102);
	ani->Add(31103);
	ani->Add(31104);
	ani->Add(31105);
	ani->Add(31106);
	ani->Add(31107);
	ani->Add(31108);
	animations->Add(303, ani);

	ani = new CAnimation(100);		// wait right
	ani->Add(30111);
	ani->Add(30112);
	ani->Add(30113);
	ani->Add(30114);
	ani->Add(30115);
	ani->Add(30116);
	animations->Add(304, ani);

	ani = new CAnimation(100);		// wait left
	ani->Add(31111);
	ani->Add(31112);
	ani->Add(31113);
	ani->Add(31114);
	ani->Add(31115);
	ani->Add(31116);
	animations->Add(305, ani);

	ani = new CAnimation(100);		// attack stab right
	ani->Add(31121);
	ani->Add(31122);
	ani->Add(31123);
	ani->Add(31124);
	ani->Add(31125);
	ani->Add(31126);
	animations->Add(306, ani);

	ani = new CAnimation(100);		// attack stab left
	ani->Add(31121);
	ani->Add(31122);
	ani->Add(31123);
	ani->Add(31124);
	ani->Add(31125);
	ani->Add(31126);
	animations->Add(307, ani);

	ani = new CAnimation(100);		// attack slash right
	ani->Add(30127);
	ani->Add(30128);
	ani->Add(30129);
	ani->Add(30130);
	ani->Add(30131);
	animations->Add(308, ani);

	ani = new CAnimation(100);		//attack slash left
	ani->Add(31127);
	ani->Add(31128);
	ani->Add(31129);
	ani->Add(31130);
	ani->Add(31131);
	animations->Add(309, ani);

	ani = new CAnimation(100);		// surprise right
	ani->Add(30141);
	ani->Add(30142);
	ani->Add(30143);
	ani->Add(30144);
	ani->Add(30145);
	ani->Add(30146);
	animations->Add(310, ani);

	ani = new CAnimation(100);		// surprise left
	ani->Add(31141);
	ani->Add(31142);
	ani->Add(31143);
	ani->Add(31144);
	ani->Add(31145);
	ani->Add(31146);
	animations->Add(311, ani);

	// fat guard

	ani = new CAnimation(100);		// idle right
	ani->Add(30200);
	animations->Add(400, ani);

	ani = new CAnimation(100);		// idle left
	ani->Add(31200);
	animations->Add(401, ani);

	ani = new CAnimation(100);		// walk right
	ani->Add(30201);
	ani->Add(30202);
	ani->Add(30203);
	ani->Add(30204);
	ani->Add(30205);
	ani->Add(30206);
	ani->Add(30207);
	ani->Add(30208);
	animations->Add(402, ani);

	ani = new CAnimation(100);		// walk left
	ani->Add(31201);
	ani->Add(31202);
	ani->Add(31203);
	ani->Add(31204);
	ani->Add(31205);
	ani->Add(31206);
	ani->Add(31207);
	ani->Add(31208);
	animations->Add(403, ani);

	ani = new CAnimation(100);		// attack right
	ani->Add(30211);
	ani->Add(30212);
	ani->Add(30213);
	ani->Add(30214);
	ani->Add(30215);
	animations->Add(404, ani);

	ani = new CAnimation(100);		// attack left
	ani->Add(31211);
	ani->Add(31212);
	ani->Add(31213);
	ani->Add(31214);
	ani->Add(31215);
	animations->Add(405, ani);

	ani = new CAnimation(100);		// surprise right
	ani->Add(30221);
	ani->Add(30222);
	ani->Add(30223);
	ani->Add(30224);
	ani->Add(30225);
	ani->Add(30226);
	ani->Add(30227);
	animations->Add(406, ani);

	ani = new CAnimation(100);		// surprise left
	ani->Add(31221);
	ani->Add(31222);
	ani->Add(31223);
	ani->Add(31224);
	ani->Add(31225);
	ani->Add(31226);
	ani->Add(31227);
	animations->Add(407, ani);

	// bat
	ani = new CAnimation(100);		// wait
	ani->Add(30301);
	animations->Add(500, ani);

	ani = new CAnimation(100);		// swing
	ani->Add(30302);
	ani->Add(30303);
	ani->Add(30304);
	animations->Add(501, ani);

	ani = new CAnimation(100);		// fly
	ani->Add(30311);
	ani->Add(30312);
	ani->Add(30313);
	ani->Add(30314);
	ani->Add(30315);
	ani->Add(30316);
	ani->Add(30317);
	animations->Add(502, ani);

	ani = new CAnimation(100);		// die
	ani->Add(30320);
	ani->Add(30321);
	ani->Add(30322);
	ani->Add(30323);
	ani->Add(30324);
	ani->Add(30325);
	ani->Add(30326);
	animations->Add(503, ani);

	// skeleton
	ani = new CAnimation(100);		// wait right
	ani->Add(30400);
	animations->Add(600, ani);

	ani = new CAnimation(100);		// wait left
	ani->Add(31400);
	animations->Add(601, ani);

	ani = new CAnimation(100, false);		// stand up right
	ani->Add(30401);
	ani->Add(30402);
	ani->Add(30403);
	ani->Add(30404);
	ani->Add(30405);
	ani->Add(30406);
	ani->Add(30407);
	ani->Add(30408);
	ani->Add(30409);
	ani->Add(30410);
	ani->Add(30411);
	ani->Add(30412);
	ani->Add(30413);
	ani->Add(30414);
	ani->Add(30415);
	ani->Add(30416);
	ani->Add(30417);
	ani->Add(30418);
	ani->Add(30419);
	ani->Add(30420);
	animations->Add(602, ani);

	ani = new CAnimation(100, false);		// stand up left
	ani->Add(31401);
	ani->Add(31402);
	ani->Add(31403);
	ani->Add(31404);
	ani->Add(31405);
	ani->Add(31406);
	ani->Add(31407);
	ani->Add(31408);
	ani->Add(31409);
	ani->Add(31410);
	ani->Add(31411);
	ani->Add(31412);
	ani->Add(31413);
	ani->Add(31414);
	ani->Add(31415);
	ani->Add(31416);
	ani->Add(31417);
	ani->Add(31418);
	ani->Add(31419);
	ani->Add(31420);
	animations->Add(603, ani);

	ani = new CAnimation(100);		// bond
	ani->Add(31430);
	ani->Add(31431);
	ani->Add(31432);
	ani->Add(31433);
	animations->Add(604, ani);

	// jafar
	ani = new CAnimation(100);		// idle right
	ani->Add(40000);
	animations->Add(700, ani);

	ani = new CAnimation(100);		// idle left
	ani->Add(41000);
	animations->Add(701, ani);

	ani = new CAnimation(150);		// attack right
	ani->Add(40001);
	ani->Add(40002);
	ani->Add(40003);
	ani->Add(40004);
	ani->Add(40005);
	ani->Add(40006, 2000);
	ani->Add(40007);
	animations->Add(702, ani);

	ani = new CAnimation(150);		// attack left
	ani->Add(41001);
	ani->Add(41002);
	ani->Add(41003);
	ani->Add(41004);
	ani->Add(41005);
	ani->Add(41006, 2000);
	ani->Add(41007);
	animations->Add(703, ani);

	//snake
	ani = new CAnimation(150);		// snake right
	ani->Add(40101);
	ani->Add(40102);
	ani->Add(40103);
	ani->Add(40104);
	ani->Add(40105);
	ani->Add(40106);
	ani->Add(40107);
	ani->Add(40108);
	ani->Add(40109);
	ani->Add(40110);
	ani->Add(40111);
	animations->Add(800, ani);

	ani = new CAnimation(150);		// snake left
	ani->Add(41101);
	ani->Add(41102);
	ani->Add(41103);
	ani->Add(41104);
	ani->Add(41105);
	ani->Add(41106);
	ani->Add(41107);
	ani->Add(41108);
	ani->Add(41109);
	ani->Add(41110);
	ani->Add(41111);
	animations->Add(801, ani);


	//weapon jafar
	//star
	ani = new CAnimation(100);		// attack right
	ani->Add(40010);
	ani->Add(40011);
	ani->Add(40012);
	animations->Add(704, ani);

	//star effect
	ani = new CAnimation(100, false);		
	ani->Add(40020);
	ani->Add(40021);
	ani->Add(40022);
	animations->Add(705, ani);

	ani = new CAnimation(100);		// snake fire right
	ani->Add(40121);
	ani->Add(40122);
	ani->Add(40123);
	ani->Add(40124);
	ani->Add(40125);
	ani->Add(40126);
	ani->Add(40127);
	ani->Add(40128);
	animations->Add(802, ani);

	ani = new CAnimation(100);		// snake fire left
	ani->Add(41121);
	ani->Add(41122);
	ani->Add(41123);
	ani->Add(41124);
	ani->Add(41125);
	ani->Add(41126);
	ani->Add(41127);
	ani->Add(41128);
	animations->Add(803, ani);

	//fire
	ani = new CAnimation(100, false);		// fire
	ani->Add(40201);
	ani->Add(40202);
	ani->Add(40203);
	ani->Add(40204);
	ani->Add(40205);
	animations->Add(900, ani);


	//item
	ani = new CAnimation(100);		// HP 1
	ani->Add(20000);
	ani->Add(20001);
	ani->Add(20002);
	ani->Add(20003);
	animations->Add(-100, ani);

	ani = new CAnimation(100);		// HP 2
	ani->Add(20010);
	ani->Add(20011);
	ani->Add(20012);
	ani->Add(20013);
	animations->Add(-101, ani);

	ani = new CAnimation(100);		// HP 3
	ani->Add(20020);
	ani->Add(20021);
	ani->Add(20022);
	ani->Add(20023);
	animations->Add(-102, ani);

	ani = new CAnimation(100);		// HP 4
	ani->Add(20030);
	ani->Add(20031);
	ani->Add(20032);
	ani->Add(20033);
	animations->Add(-103, ani);

	ani = new CAnimation(100);		// HP 5
	ani->Add(20040);
	ani->Add(20041);
	ani->Add(20042);
	ani->Add(20043);
	animations->Add(-104, ani);

	ani = new CAnimation(100);		// HP 6
	ani->Add(20050);
	ani->Add(20051);
	ani->Add(20052);
	ani->Add(20053);
	animations->Add(-105, ani);

	ani = new CAnimation(100);		// HP 7
	ani->Add(20060);
	ani->Add(20061);
	ani->Add(20062);
	ani->Add(20063);
	animations->Add(-106, ani);

	ani = new CAnimation(100);		// HP 8
	ani->Add(20070);
	ani->Add(20071);
	ani->Add(20072);
	ani->Add(20073);
	animations->Add(-107, ani);

	ani = new CAnimation(100);		// HP 9
	ani->Add(20080);
	animations->Add(-108, ani);


	ani = new CAnimation(100);		// Pilar 1
	ani->Add(20500);
	animations->Add(2050, ani);

	ani = new CAnimation(100);		// Pilar 2
	ani->Add(20501);
	animations->Add(2051, ani);

	ani = new CAnimation(100);		// Pilar 3
	ani->Add(20502);
	animations->Add(2052, ani);

	ani = new CAnimation(100);		// Pilar 4
	ani->Add(20503);
	animations->Add(2053, ani);

	ani = new CAnimation(100);		// Exit
	ani->Add(20600);
	animations->Add(2060, ani);

	ani = new CAnimation(100);		// Fance
	ani->Add(20700);
	animations->Add(2070, ani);

	ani = new CAnimation(200);		// Stone
	ani->Add(20400);
	ani->Add(20401);
	ani->Add(20402);
	ani->Add(20403);
	ani->Add(20404, 2000);
	ani->Add(20403);
	ani->Add(20402);
	ani->Add(20401);
	//delay
	ani->Add(20400, 1400);
	animations->Add(2040, ani);

	ani = new CAnimation(200);		// Trap
	ani->Add(20420);
	ani->Add(20421);
	ani->Add(20422);
	ani->Add(20423);
	ani->Add(20424);
	ani->Add(20425);
	ani->Add(20424);
	ani->Add(20423);
	ani->Add(20422);
	ani->Add(20421);
	//delay
	ani->Add(20420, 1800);
	animations->Add(2042, ani);

	ani = new CAnimation(100);		// Ball
	ani->Add(20430);
	ani->Add(20431);
	ani->Add(20432);
	ani->Add(20433);
	ani->Add(20434);
	ani->Add(20435);
	ani->Add(20436);
	ani->Add(20437);
	ani->Add(20438);
	ani->Add(20439);
	ani->Add(20440);
	ani->Add(20441);
	ani->Add(20442);
	ani->Add(20443);
	ani->Add(20444);
	ani->Add(20445);
	ani->Add(20446);
	ani->Add(20447);
	ani->Add(20448);
	ani->Add(20449);
	ani->Add(20450);
	ani->Add(20451);
	ani->Add(20452);
	ani->Add(20453);
	ani->Add(20454);
	ani->Add(20455);
	ani->Add(20456);
	ani->Add(20457);
	//delay
	ani->Add(20430, 0);
	animations->Add(2043, ani);

	ani = new CAnimation(100);		//penny
	ani->Add(21100);
	ani->Add(21101);
	ani->Add(21102);
	ani->Add(21103);
	ani->Add(21104);
	ani->Add(21105);
	ani->Add(21106);
	ani->Add(21107);
	ani->Add(21108);
	animations->Add(2110, ani);

	ani = new CAnimation(100);		//face
	ani->Add(21110);
	ani->Add(21111);
	ani->Add(21112);
	ani->Add(21113);
	animations->Add(2111, ani);

	ani = new CAnimation(100);
	ani->Add(21120);
	animations->Add(2112, ani);

	ani = new CAnimation(100, false);		//vase
	ani->Add(21130);
	ani->Add(21131);
	ani->Add(21132);
	ani->Add(21133);
	ani->Add(21134);
	ani->Add(21135);
	ani->Add(21136);
	ani->Add(21137);
	ani->Add(21138);
	ani->Add(21139);
	animations->Add(2113, ani);

	ani = new CAnimation(100);		// vase idle
	ani->Add(21140);
	animations->Add(2114, ani);

	ani = new CAnimation(100);		// vase stop
	ani->Add(21141);
	animations->Add(2119, ani);

	ani = new CAnimation(100);		//apple
	ani->Add(21150);
	animations->Add(2115, ani);

	ani = new CAnimation(100, false);		//item effect
	ani->Add(21161);
	ani->Add(21162);
	ani->Add(21163);
	ani->Add(21164);
	ani->Add(21165);
	animations->Add(2116, ani);

	ani = new CAnimation(100, false);		//genie effect
	ani->Add(21181);
	ani->Add(21182);
	ani->Add(21183);
	ani->Add(21184);
	ani->Add(21185);
	ani->Add(21186);
	ani->Add(21187);
	ani->Add(21188);
	ani->Add(21189);
	ani->Add(21190);
	ani->Add(21191);
	ani->Add(21192);
	ani->Add(21193);
	ani->Add(21194);
	ani->Add(21195);
	ani->Add(21196);
	ani->Add(21197);
	ani->Add(21198);
	ani->Add(21199);
	animations->Add(2117, ani);

	ani = new CAnimation(100);		//heart
	ani->Add(21170);
	ani->Add(21171);
	ani->Add(21172);
	ani->Add(21173);
	ani->Add(21174);
	ani->Add(21175);
	ani->Add(21176);
	ani->Add(21177);
	animations->Add(2118, ani);

	ani = new CAnimation(100);		//penny count
	ani->Add(21100);
	animations->Add(2120, ani);

	ani = new CAnimation(100);		//life
	ani->Add(21200);
	animations->Add(2130, ani);

	ani = new CAnimation(100);		// throw apple
	ani->Add(22000);
	animations->Add(2200, ani);

	ani = new CAnimation(100, false);		// throw apple break
	ani->Add(22001);
	ani->Add(22002);
	ani->Add(22003);
	ani->Add(22004);
	ani->Add(22005);
	animations->Add(2201, ani);

	ani = new CAnimation(100, false);		// throw apple break boss
	ani->Add(50001);
	ani->Add(50002);
	ani->Add(50003);
	ani->Add(50004);
	ani->Add(50005);
	ani->Add(50006);
	ani->Add(50007);
	ani->Add(50008);
	ani->Add(50009);
	ani->Add(50010);
	ani->Add(50011);
	ani->Add(50012);
	animations->Add(5000, ani);

	ani = new CAnimation(100, false);		// Jafar Explosions
	ani->Add(50101);
	ani->Add(50102);
	ani->Add(50103);
	ani->Add(50104);
	ani->Add(50105);
	ani->Add(50106);
	ani->Add(50107);
	animations->Add(5001, ani);

	//ani = new CAnimation(100, false);		// map start
	//ani->Add(90000);
	//animations->Add(9000, ani);

	//ani = new CAnimation(100);		// intro
	//ani->Add(90100);
	//animations->Add(9010, ani);

	//ani = new CAnimation(100);		// map end
	//ani->Add(91000);
	//animations->Add(9100, ani);

	//ani = new CAnimation(100);		// complete
	//ani->Add(91100);
	//animations->Add(9110, ani);
}

AladdinResoucres::AladdinResoucres()
{
	this->textures = CTextures::GetInstance();

	this->sprites = CSprites::GetInstance();

	this->animations = CAnimations::GetInstance();
}

void AladdinResoucres::LoadResoucre()
{
	LoadTextures();
	LoadSprites();
	LoadAnimations();
}
