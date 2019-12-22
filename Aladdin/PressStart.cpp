#include "PressStart.h"

void PressStart::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	//int text;
	//for (int i = 0; i < pressStart.size(); i++)
	//{
	//	char temp = pressStart[i];
	//	switch (temp)
	//	{
	//	case 'a':
	//	case 'A':
	//		text = 20200;
	//		break;
	//	case 'b':
	//	case 'B':
	//		text = 20201;
	//		break;
	//	case 'c':
	//	case 'C':
	//		text = 20202;
	//		break;
	//	case 'd':
	//	case 'D':
	//		text = 20203;
	//		break;
	//	case 'e':
	//	case 'E':
	//		text = 20204;
	//		break;
	//	case 'f':
	//	case 'F':
	//		text = 20205;
	//		break;
	//	case 'g':
	//	case 'G':
	//		text = 20206;
	//		break;
	//	case 'h':
	//	case 'H':
	//		text = 20207;
	//		break;
	//	case 'i':
	//	case 'I':
	//		text = 20208;
	//		break;
	//	case 'j':
	//	case 'J':
	//		text = 20209;
	//		break;
	//	case 'k':
	//	case 'K':
	//		text = 20210;
	//		break;
	//	case 'l':
	//	case 'L':
	//		text = 20211;
	//		break;
	//	case 'm':
	//	case 'M':
	//		text = 20212;
	//		break;
	//	case 'n':
	//	case 'N':
	//		text = 20213;
	//		break;
	//	case 'o':
	//	case 'O':
	//		text = 20214;
	//		break;
	//	case 'p':
	//	case 'P':
	//		text = 20215;
	//		break;
	//	case 'q':
	//	case 'Q':
	//		text = 20214;
	//		break;
	//	case 'r':
	//	case 'R':
	//		text = 20217;
	//		break;
	//	case 's':
	//	case 'S':
	//		text = 20218;
	//		break;
	//	case 't':
	//	case 'T':
	//		text = 20219;
	//		break;
	//	case 'u':
	//	case 'U':
	//		text = 20220;
	//		break;
	//	case 'v':
	//	case 'V':
	//		text = 20221;
	//		break;
	//	case 'w':
	//	case 'W':
	//		text = 20222;
	//		break;
	//	case 'x':
	//	case 'X':
	//		text = 20223;
	//		break;
	//	case 'y':
	//	case 'Y':
	//		text = 20224;
	//		break;
	//	case 'z':
	//	case 'Z':
	//		text = 20225;
	//		break;
	//	default:
	//		text = -1;
	//		break;
	//	}
	//	if (text != -1)
	//	{
	//		//DebugOut(L"[INFO] index: %d\n", i);
	//		sprites->Get(text)->DrawWithoutCamera(x + i * width, y);
	//	}
	//}

	sprites->Get(20215)->DrawWithoutCamera(x + 10, y);
	sprites->Get(20217)->DrawWithoutCamera(x + 20, y);
	sprites->Get(20204)->DrawWithoutCamera(x + 30, y);
	sprites->Get(20218)->DrawWithoutCamera(x + 40, y);
	sprites->Get(20218)->DrawWithoutCamera(x + 50, y);

	sprites->Get(20200)->DrawWithoutCamera(x + 70, y);
	sprites->Get(20213)->DrawWithoutCamera(x + 80, y);
	sprites->Get(20224)->DrawWithoutCamera(x + 90, y);

	sprites->Get(20201)->DrawWithoutCamera(x + 110, y);
	sprites->Get(20220)->DrawWithoutCamera(x + 120, y);
	sprites->Get(20219)->DrawWithoutCamera(x + 130, y);
	sprites->Get(20219)->DrawWithoutCamera(x + 140, y);
	sprites->Get(20214)->DrawWithoutCamera(x + 150, y);
	sprites->Get(20213)->DrawWithoutCamera(x + 160, y);
}


void PressStart::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

PressStart::PressStart()
{
	width = 8;
	height = 8;
}