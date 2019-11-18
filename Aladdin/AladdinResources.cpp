#include "AladdinResources.h"
#include "Ground.h"

AladdinResources::AladdinResources()
{
}

AladdinResources::~AladdinResources()
{
}

void AladdinResources::Load(string file, vector<LPGAMEOBJECT>* listObject)
{
	ifstream input;
	input.open(file, ifstream::in);

	string checkEnd;
	int id;
	int type;
	float x;
	float y;
	int width;
	int height;

	int count = 0;

	while (input >> checkEnd)
	{
		if (checkEnd == "END")
		{
			count++;
			continue;
		}
		if (count == 0)
		{
			id = atoi(checkEnd.c_str());
			input >> type >> x >> y >> width >> height;
			LoadObject(id, type, x, y, width, height, listObject);
		}
	}
}

void AladdinResources::LoadObject(int id, int type, float x, float y, int width, int height, vector<LPGAMEOBJECT>* listObject)
{
	
	if (type == OBJECT_GROUND)
	{
		Ground* object = new Ground();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y);
		object->SetWidth(width);
		object->SetHeight(height);
		listObject->push_back(object);
	}
}
