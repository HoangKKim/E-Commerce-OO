#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use composite pattern

class Component
{
protected:
	string name;
public:
	virtual string getName() = 0;
	virtual void setName(string mName) = 0;
	virtual void display(int depth) = 0;
	virtual void input(istream& is) = 0;
};

class Composite : public Component
{
private:
	vector <Component*> components;
public:
	Composite();
	~Composite();
	string getName();
	void setName(string mName);
	void display(int depth);
	void addComponent(Component* iComponent);
	void input(istream& is);
};