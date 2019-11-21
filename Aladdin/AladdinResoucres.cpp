#include "AladdinResoucres.h"
#include "Define.h"


void AladdinResoucres::LoadTextures()
{
	textures->Add(ID_TEX_BBOX, L"resources\\textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	textures->Add(ID_TEX_MISC, L"resources\\textures\\misc.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ALADDIN_GO_RIGHT, L"resources\\textures\\aladdinGoRight.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ALADDIN_GO_LEFT, L"resources\\textures\\aladdinGoLeft.png", D3DCOLOR_XRGB(255, 0, 255));

	//map
	textures->Add(ID_TEX_MAP_ONE, L"resources\\mapread\\lv1\\lv1.png", D3DCOLOR_XRGB(163, 73, 164));
}

void AladdinResoucres::LoadSprites()
{
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

	sprites->Add(10101, 14, 1215, 54, 1273, texAladdinGoRight);		// walk	right
	sprites->Add(10102, 66, 1215, 109, 1273, texAladdinGoRight);
	sprites->Add(10103, 120, 1215, 161, 1273, texAladdinGoRight);
	sprites->Add(10104, 171, 1215, 212, 1273, texAladdinGoRight);
	sprites->Add(10105, 220, 1215, 272, 1272, texAladdinGoRight);
	sprites->Add(10106, 279, 1215, 325, 1273, texAladdinGoRight);
	sprites->Add(10107, 334, 1215, 376, 1273, texAladdinGoRight);
	sprites->Add(10108, 386, 1215, 427, 1273, texAladdinGoRight);
	sprites->Add(10109, 440, 1215, 475, 1273, texAladdinGoRight);
	sprites->Add(10110, 488, 1215, 537, 1273, texAladdinGoRight);
	sprites->Add(10111, 547, 1215, 602, 1273, texAladdinGoRight);
	sprites->Add(10112, 611, 1215, 666, 1273, texAladdinGoRight);
	sprites->Add(10113, 679, 1215, 723, 1273, texAladdinGoRight);

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

	sprites->Add(10221, 10, 705, 51, 747, texAladdinGoRight);		// run jump	right
	sprites->Add(10222, 66, 683, 111, 759, texAladdinGoRight);
	sprites->Add(10223, 124, 686, 181, 743, texAladdinGoRight);
	sprites->Add(10224, 199, 698, 257, 740, texAladdinGoRight);
	sprites->Add(10225, 273, 696, 334, 744, texAladdinGoRight);
	sprites->Add(10226, 350, 692, 408, 745, texAladdinGoRight);
	sprites->Add(10227, 419, 688, 472, 746, texAladdinGoRight);
	sprites->Add(10228, 491, 680, 541, 765, texAladdinGoRight);
	sprites->Add(10229, 560, 719, 719, 763, texAladdinGoRight);

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

	sprites->Add(10341, 13, 1077, 65, 1131, texAladdinGoRight);		// jumping slash right right
	sprites->Add(10342, 75, 1075, 125, 1127, texAladdinGoRight);
	sprites->Add(10343, 140, 1067, 187, 1133, texAladdinGoRight);
	sprites->Add(10344, 199, 1078, 151, 1134, texAladdinGoRight);
	sprites->Add(10345, 266, 1079, 349, 1130, texAladdinGoRight);
	sprites->Add(10346, 361, 1087, 408, 1142, texAladdinGoRight);

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

	sprites->Add(10501, 11, 1362, 40, 1448, texAladdinGoRight);		// climbing
	sprites->Add(10502, 53, 1361, 81, 1450, texAladdinGoRight);
	sprites->Add(10503, 94, 1374, 122, 1448, texAladdinGoRight);
	sprites->Add(10504, 133, 1377, 175, 239, texAladdinGoRight);
	sprites->Add(10505, 186, 1363, 217, 1439, texAladdinGoRight);
	sprites->Add(10506, 231, 1358, 260, 1444, texAladdinGoRight);
	sprites->Add(10507, 274, 1367, 302, 1446, texAladdinGoRight);
	sprites->Add(10508, 314, 1377, 346, 1440, texAladdinGoRight);
	sprites->Add(10509, 356, 1377, 398, 1439, texAladdinGoRight);
	sprites->Add(10510, 406, 1362, 434, 1443, texAladdinGoRight);

	sprites->Add(10521, 10, 1870, 44, 1943, texAladdinGoRight);	// falling after climbing
	sprites->Add(10522, 65, 1873, 90, 1950, texAladdinGoRight);
	sprites->Add(10523, 100, 1874, 136, 1945, texAladdinGoRight);
	sprites->Add(10524, 144, 1874, 192, 1938, texAladdinGoRight);
	sprites->Add(10525, 204, 1875, 263, 1929, texAladdinGoRight);
	sprites->Add(10526, 281, 1876, 340, 1917, texAladdinGoRight);
	sprites->Add(10527, 354, 1869, 406, 1923, texAladdinGoRight);
	sprites->Add(10528, 422, 1871, 469, 1938, texAladdinGoRight);
	sprites->Add(10529, 482, 1866, 527, 1941, texAladdinGoRight);

	sprites->Add(10531, 1058, 1769, 1106, 1856, texAladdinGoLeft);	// climbing slash right
	sprites->Add(10532, 988, 1769, 1040, 1858, texAladdinGoLeft);
	sprites->Add(10533, 914, 1769, 975, 1862, texAladdinGoLeft);
	sprites->Add(10534, 821, 1773, 874, 1863, texAladdinGoLeft);
	sprites->Add(10535, 739, 1773, 794, 1862, texAladdinGoLeft);
	sprites->Add(10536, 646, 1775, 718, 1864, texAladdinGoLeft);
	sprites->Add(10537, 574, 1775, 622, 1862, texAladdinGoLeft);

	sprites->Add(10541, 1071, 1666, 1108, 1753, texAladdinGoLeft);	// climbing throw apple right
	sprites->Add(10542, 1015, 1666, 1056, 1753, texAladdinGoLeft);
	sprites->Add(10543, 945, 1665, 996, 1753, texAladdinGoLeft);
	sprites->Add(10544, 898, 1664, 929, 1753, texAladdinGoLeft);
	sprites->Add(10545, 828, 1664, 885, 1753, texAladdinGoLeft);

	sprites->Add(10601, 9, 2111, 61, 2149, texAladdinGoRight);	// ride the carpet right
	sprites->Add(10602, 68, 2110, 120, 2149, texAladdinGoRight);
	sprites->Add(10603, 129, 2110, 181, 2149, texAladdinGoRight);
	sprites->Add(10604, 190, 2111, 242, 2149, texAladdinGoRight);
	sprites->Add(10605, 259, 2126, 63, 2146, texAladdinGoRight);
	sprites->Add(10606, 333, 2107, 388, 2149, texAladdinGoRight);


	//left

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

	sprites->Add(11221, 1070, 705, 1111, 747, texAladdinGoLeft);		// run jump	left
	sprites->Add(11222, 1010, 683, 1055, 759, texAladdinGoLeft);
	sprites->Add(11223, 940, 686, 957, 743, texAladdinGoLeft);
	sprites->Add(11224, 864, 698, 922, 740, texAladdinGoLeft);
	sprites->Add(11225, 787, 696, 848, 744, texAladdinGoLeft);
	sprites->Add(11226, 713, 692, 771, 745, texAladdinGoLeft);
	sprites->Add(11227, 649, 688, 702, 746, texAladdinGoLeft);
	sprites->Add(11228, 580, 680, 630, 765, texAladdinGoLeft);
	sprites->Add(11229, 502, 719, 561, 763, texAladdinGoLeft);

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

	sprites->Add(11341, 1056, 1077, 1108, 1131, texAladdinGoLeft);		// jumping slash left
	sprites->Add(11342, 996, 1075, 1046, 1127, texAladdinGoLeft);
	sprites->Add(11343, 934, 1067, 981, 1133, texAladdinGoLeft);
	sprites->Add(11344, 870, 1078, 922, 1134, texAladdinGoLeft);
	sprites->Add(11345, 772, 1079, 855, 1130, texAladdinGoLeft);
	sprites->Add(11346, 713, 1087, 760, 1142, texAladdinGoLeft);

	sprites->Add(11401, 1071, 235, 1114, 291, texAladdinGoLeft);		// throw apple left
	sprites->Add(11402, 1023, 232, 1064, 291, texAladdinGoLeft);
	sprites->Add(11403, 974, 233, 1012, 291, texAladdinGoLeft);
	sprites->Add(11404, 912, 231, 958, 291, texAladdinGoLeft);
	sprites->Add(114015, 863, 233, 900, 291, texAladdinGoLeft);
	sprites->Add(11406, 814, 239, 853, 291, texAladdinGoLeft);

	sprites->Add(11411, 1075, 571, 112, 615, texAladdinGoLeft);		// sitting throw apple left
	sprites->Add(11412, 1026, 567, 1063, 615, texAladdinGoLeft);
	sprites->Add(11413, 964, 571, 1014, 619, texAladdinGoLeft);
	sprites->Add(11414, 875, 578, 957, 615, texAladdinGoLeft);
	sprites->Add(11415, 808, 579, 865, 616, texAladdinGoLeft);

	sprites->Add(11421, 1053, 1005, 1102, 1060, texAladdinGoLeft);		// jumping throw apple left
	sprites->Add(11422, 1001, 1007, 1044, 1059, texAladdinGoLeft);
	sprites->Add(11423, 950, 1008, 989, 1061, texAladdinGoLeft);
	sprites->Add(11424, 884, 1008, 936, 1061, texAladdinGoLeft);
	sprites->Add(11425, 828, 1012, 868, 1064, texAladdinGoLeft);

	sprites->Add(11531, 15, 1769, 63, 1856, texAladdinGoRight);	// climbing slash left
	sprites->Add(11532, 81, 1769, 133, 1858, texAladdinGoRight);
	sprites->Add(11533, 146, 1769, 207, 1862, texAladdinGoRight);
	sprites->Add(11534, 247, 1773, 300, 1863, texAladdinGoRight);
	sprites->Add(11535, 327, 1773, 382, 1862, texAladdinGoRight);
	sprites->Add(11536, 403, 1775, 475, 1864, texAladdinGoRight);
	sprites->Add(11537, 499, 1775, 547, 1862, texAladdinGoRight);

	sprites->Add(11541, 13, 1666, 50, 1753, texAladdinGoRight);	// climbing throw apple left
	sprites->Add(11542, 65, 1666, 106, 1753, texAladdinGoRight);
	sprites->Add(11543, 125, 1665, 176, 1753, texAladdinGoRight);
	sprites->Add(11544, 192, 1664, 223, 1753, texAladdinGoRight);
	sprites->Add(11545, 236, 1664, 293, 1753, texAladdinGoRight);

	sprites->Add(11601, 1060, 2111, 1112, 2149, texAladdinGoRight);	// ride the carpet left
	sprites->Add(11602, 1001, 2110, 1053, 2149, texAladdinGoRight);
	sprites->Add(11603, 940, 2110, 992, 2149, texAladdinGoRight);
	sprites->Add(11604, 879, 2111, 931, 2149, texAladdinGoRight);
	sprites->Add(11605, 799, 2126, 862, 2146, texAladdinGoRight);
	sprites->Add(11606, 733, 2107, 788, 2149, texAladdinGoRight);

	LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 408, 225, 424, 241, texMisc);

	LPDIRECT3DTEXTURE9 textMapOne = textures->Get(ID_TEX_MAP_ONE);
	sprites->Add(ID_SPRITE_MAP_ONE, 0, 0, 2144, 1024, textMapOne);
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
	animations->Add(103, ani);

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

	ani = new CAnimation(100);	// run jump right
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

	ani = new CAnimation(100);	// climbing
	ani->Add(10501);
	ani->Add(10502);
	ani->Add(10503);
	ani->Add(10504);
	ani->Add(10505);
	ani->Add(10506);
	ani->Add(10507);
	ani->Add(10508);
	ani->Add(10509);
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

	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);
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
