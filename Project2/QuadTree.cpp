#include"QuadTree.h"
QuadTree* QuadTree::instance;
// APPLE 0
/*
APPLE 0
BAT 1
GUARD 2
SKELETON 3 
STONE 4
FACE 5
VASE 6
TRAP 7
PENNY 8
HEART 9
*/
QuadTree::QuadTree() {
	BuildTree();
}
QuadTree::~QuadTree()
{
}

QuadTree* QuadTree::Instance()
{
	if (!instance)
		instance = new QuadTree();
	return instance;
}
void QuadTree::LoadObjects() {
	fstream f;
	f.open((char*)"C:\\Users\\ngoho\\Desktop\\objects.txt", ios::in);

	int nObjects, width, height;
	string data;
	getline(f, data);
	stringstream stream_data;
	stream_data << data;
	stream_data >> nObjects >> width >> height;
	int stt, id, x, y, direction; //stt=key
	for (int i = 0; i < nObjects; i++)
	{
		data = "";
		stream_data.clear();

		getline(f, data);
		stream_data << data;

		stream_data >> stt >> id >> x >> y >> direction;

		this->Objects[stt] = CreateObject(id, x, y, direction);
	}

	f.close();
}
void QuadTree::LoadNodes()
{
	//listNode = TXT::Instance()->LoadListNode((char*)"listnode.txt", this->listObject);

	fstream f;
	//map<int, Node*> list_node;
	string data;

	f.open((char*)"C:\\Users\\ngoho\\Desktop\\nodes.txt", ios::in);

	stringstream stream_data;
	int id, x, y, w, sttObject; //stt=key
	int number_of_object_in_node;
	while (getline(f, data))
	{
		stream_data << data;

		stream_data >> id >> x >> y >> w;
		Node* node = new Node(x, y, w, w);

		number_of_object_in_node = CountWords(data) - 4;
		for (int i = 0; i < number_of_object_in_node; i++)
		{
			stream_data >> sttObject;
			node->AddObject(sttObject, this->Objects[sttObject]);// new CTreeObject(obj->getId(), obj->getBound().getX(), obj->getBound().getY(), obj->getBound().getWidth(), obj->getBound().getHeight(), obj->getDirect()));
		}
		this->Nodes[id] = node;

		data = "";
		stream_data.clear();
	}
}
void QuadTree::BuildTree() {
	LoadObjects();
	LoadNodes();

	int id, parent_id, child_id;
	for (auto node : Nodes) {
		id = node.first;
		parent_id = id / 10;
		if (this->Nodes[parent_id]) {
			child_id = id % 10;
			this->Nodes[parent_id]->GetChildren()[child_id] = node.second;
		}
	}
}
Object* QuadTree::CreateObject(int id, int x, int y, int d) {
	Direction dir;
	if (d == 0) {
		dir = RIGHT;
	}
	else { dir = LEFT; }
	Object* o;

	y *= G_Scale.y;
	x *= G_Scale.x;
	switch (id) {
	case QAPPLE:
		o = new Apple(x, y, dir);
		break;
	case QBAT:
		o = new Bat(x, y, dir);
		break;
	case QGUARD:
		o = new Guard(x, y, dir);
		break;
	case QSKELETON:
		o = new Skeleton(x, y, dir);
		break;
	case QSTONE:
		o = new Stone(x, y, dir);
		break;

	case QFACE:
		o = new Face(x, y, dir);
		break;

	case QVASE:
		o = new Vase(x, y, dir);
		break;
	case QTRAP:
		o = new Trap(x, y, dir);
		break;
	case QPENNY:
		o = new Penny(x, y, dir);
		break;
	case QHEART:
		//o = new Heart(x, y, dir);
		//break;
	default:
		o = new Apple(x, y, dir);
		break;
	}
	return o;
}
int QuadTree::CountWords(string str) {
	stringstream s(str);
	string word;
	int count = 0;
	while (s >> word) {
		count++;
	}
	return count;
}
vector<Object*> QuadTree::GetObjects(Box cam)
{
	Box _cam;
	_cam.x = cam.x - cam.w / 4;
	_cam.y = cam.y - cam.h / 4;
	_cam.w = cam.w * 3 / 2;
	_cam.h = cam.h * 3 / 2;
	if(!this->Nodes[1])
	return vector<Object*>();

	vector<Object*> listObject;
	map<int, Object*> list = this->Nodes[1]->GetListObject(_cam);

	for (auto obj : list)
	{
		//Object* object = obj.second;
		listObject.push_back(obj.second);
	}

	return listObject;
}
