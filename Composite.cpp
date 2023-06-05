#include "DanhMucHangHoa.h"

// constructor - destructor
Composite::Composite()
{
	components.resize(0);
}

Composite::~Composite()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
		components[i] = NULL;
	}
	components.resize(0);
}

// getter - setter for attribute "name"
void Composite::setName(string mName)
{
	this->name = mName;
}

string Composite::getName()
{
	return this->name;
}

// add a component in list components
void Composite::addComponent(Component* iComponent)
{
	components.push_back(iComponent);
}

// display component
void Composite::display(int depth)
{
	for (int i = 0; i < components.size(); i++)
	{
		for (int j = 0; j < depth; j++)
		{
			cout << " ";
		}
		cout << components[i]->getName()  << endl;
		components[i]->display(depth + 1);
	}
}

// input composite from console
void Composite::input(istream& is)
{
	bool flag = true;
	do
	{
		bool check = false;
		flag = true;
		string tmp;
		getline(is, tmp);
		if(tmp=="\0")
		{
			return;
		}
		/*else if(tmp=="-")
		{
			return;
		}*/
		Component* tmpD = new Composite;
		if (tmp[tmp.length() - 1] == ')')
		{
			tmp.erase(tmp.length() - 2, tmp.length() - 1);
			check = true;
		}
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] == ' ')
			{
				tmp.erase(tmp.begin() + i);
			}
			else
			{
				break;
			}
		}
		tmpD->setName(tmp);
		if (tmpD != NULL)
		{
			this->addComponent(tmpD);
			if (check==true)
			{
				
				tmpD->input(is);
			} else flag = false;
		}
	} while (true);
}