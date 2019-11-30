#include "AladdinObjects.h"
#include "Ground.h"

AladdinObjects::AladdinObjects()
{
}

AladdinObjects::~AladdinObjects()
{
}

void AladdinObjects::Load(string file, vector<LPGAMEOBJECT>* listObject)
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
void AladdinObjects::LoadListObject(string file, vector<LPGAMEOBJECT>* listObject) {
	fstream f;
	f.open(file, ios::in);

	int nObjects, width, height;

	string data;
	getline(f, data);
	stringstream stream_data;
	stream_data << data;
	stream_data >> nObjects;
	int stt, type, x, y;
	for (int i = 0; i < nObjects; i++)
	{
		data = "";
		stream_data.clear();

		getline(f, data);
		stream_data << data;

		stream_data >> stt >> type >> x >> y;

		LoadObject(stt, type, x, y, listObject);
	}

	f.close();
}
void AladdinObjects::LoadObject(int id, int type, float _x, float _y, vector<LPGAMEOBJECT>* listObject) {
	float x = _x - 64, y = _y - 96;
	switch (type) {
	case OBJECT_STONE: 
	{
		Stone* object = new Stone();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y);
		listObject->push_back(object);
		break;
	}
	
	case OBJECT_TRAP: 
	{
		Trap* object = new Trap();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y);
		listObject->push_back(object);
		break;
	}
		
	case OBJECT_BALL:
	{
		Ball* object = new Ball();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y);
		listObject->push_back(object);
		break;
	}
		
	case OBJECT_BAT :
	{
		Bat* object = new Bat();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y);
		listObject->push_back(object);
		break;
	}
	case OBJECT_FACE:
	{
		GenieBonusLevel* object = new GenieBonusLevel();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y-50);
		listObject->push_back(object);
		break;	
	}
	case OBJECT_GUARD :
	{
		MusclePalaceGuard* object = new MusclePalaceGuard();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x - 75, y - 65);
		listObject->push_back(object);
		break;
	}
	case OBJECT_SKELETON:
	{
		ExplodingSkeleton* object = new ExplodingSkeleton();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y - 100);
		listObject->push_back(object);
		break;
	}
	case OBJECT_THIN_GUARD :
	{
		ThinPalaceGuard* object = new ThinPalaceGuard();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y - 75);
		listObject->push_back(object);
		break;
	}
	case OBJECT_VASE :
	{
		Vase* object = new Vase();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y - 35);
		listObject->push_back(object);
		break;
	}
	case OBJECT_PENNY :
	{
		Penny* object = new Penny();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y - 20);
		listObject->push_back(object);
		break;
	}
	case OBJECT_APPLE :
	{
		ThrowApples* object = new ThrowApples();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(x, y - 15);
		listObject->push_back(object);
		break;

	}
	case OBJECT_HEART :
	{

	}
	default: {
		Heart* object = new Heart();
		object->SetId(id);
		object->SetType(type);
		object->SetPosition(10, 975);
		listObject->push_back(object);
		break;
	}
	}

}
void AladdinObjects::LoadObject(int id, int type, float x, float y, int width, int height, vector<LPGAMEOBJECT>* listObject)
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
