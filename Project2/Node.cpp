#include"Node.h"

Node::Node()
{
	for (int i = 0; i < 4; i++)
		Children[i] = NULL;
}

Node::Node(Box b)
{
	this->bound = b;

	for (int i = 0; i < 4; i++)
		Children[i] = NULL;
}

Node::Node(int x, int y, int w, int h)
{
	bound.SetingBox(x, y, w, h);

	for (int i = 0; i < 4; i++)
		Children[i] = NULL;
}

Node::~Node()
{
}

void Node::AddObject(int key, Object* value)
{
	this->Objects[key] = value;
}
map<int, Object*> Node::GetListObject(Box cam)
{
	map<int, Object*> list_object;
	list_object.clear();

	if (!this->Children[0])
		return this->Objects;
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->Children[i]->GetBound().IsOverlap(cam))
			{
				map<int, Object*> list_object_in_childs = Children[i]->GetListObject(cam);
				for (auto o : list_object_in_childs) {
					list_object[o.first] = o.second;
				}
			}
		}
	}

	return list_object;
}


map<int, Object*> Node::GetListObject()
{
	return (this->Objects);
}
Box Node::GetBound()
{
	return this->bound;
}

Node** Node::GetChildren()
{
	return Children;
}