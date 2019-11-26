#include "Score.h"
#include "../Framework/Sprites.h"
#include "../Framework/debug.h"

void Score::Render()
{
	CSprites* sprites = CSprites::GetInstance();
	int text;
	for (int i = 0; i < score.size(); i++)
	{
		char temp = score[i];
		switch (temp)
		{
		case 'a':
		case 'A':
			text = 20200;
			break;
		case 'b':
		case 'B':
			text = 20201;
			break;
		case 'c':
		case 'C':
			text = 20202;
			break;
		case 'd':
		case 'D':
			text = 20203;
			break;
		case 'e':
		case 'E':
			text = 20204;
			break;
		case 'f':
		case 'F':
			text = 20205;
			break;
		case 'g':
		case 'G':
			text = 20206;
			break;
		case 'h':
		case 'H':
			text = 20207;
			break;
		case 'i':
		case 'I':
			text = 20208;
			break;
		case 'j':
		case 'J':
			text = 20209;
			break;
		case 'k':
		case 'K':
			text = 20210;
			break;
		case 'l':
		case 'L':
			text = 20211;
			break;
		case 'm':
		case 'M':
			text = 20212;
			break;
		case 'n':
		case 'N':
			text = 20213;
			break;
		case 'o':
		case 'O':
			text = 20214;
			break;
		case 'p':
		case 'P':
			text = 20215;
			break;
		case 'q':
		case 'Q':
			text = 20214;
			break;
		case 'r':
		case 'R':
			text = 20217;
			break;
		case 's':
		case 'S':
			text = 20218;
			break;
		case 't':
		case 'T':
			text = 20219;
			break;
		case 'u':
		case 'U':
			text = 20220;
			break;
		case 'v':
		case 'V':
			text = 20221;
			break;
		case 'w':
		case 'W':
			text = 20222;
			break;
		case 'x':
		case 'X':
			text = 20223;
			break;
		case 'y':
		case 'Y':
			text = 20224;
			break;
		case 'z':
		case 'Z':
			text = 20225;
			break;
		case '(':
			text = 20226;
			break;
		case ')':
			text = 20227;
			break;
		case '0':
			text = 20228;
			break;
		case '1':
			text = 20229;
			break;
		case '2':
			text = 20230;
			break;
		case '3':
			text = 20231;
			break;
		case '4':
			text = 20232;
			break;
		case '5':
			text = 20233;
			break;
		case '6':
			text = 20234;
			break;
		case '7':
			text = 20235;
			break;
		case '8':
			text = 20236;
			break;
		case '9':
			text = 20237;
			break;
		case '.':
			text = 20238;
			break;
		default:
			text = -1;
			break;
		}
		if (text != -1)
		{
			//DebugOut(L"[INFO] index: %d\n", i);
			sprites->Get(text)->DrawWithoutCamera(x + i * width, y);
		}
	}
}

void Score::Update(wstring score)
{
	this->score = score;
}

void Score::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

Score::Score()
{
	width = 8;
	height = 8;
}
