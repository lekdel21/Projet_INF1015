#pragma once

#include <string>
#include <memory>
#include <vector>
#include <iostream>

#include "Object.hpp"


using namespace std;

class Room
{
public:
	Room(string name, string description);
	~Room();
	void addCouloir(string direction, Room* room);
	Room* getCouloir(string direction);

	string getName() { return name_; }
	void addObjet(Object* objet) { objects_.push_back(objet); }
	bool isObject(const string& object);

	Object* getObject(const string& object);
	
	void afficher();

private:
	string name_;
	string description_;
	vector<Object*> objects_;
	vector<pair<string, Room*>> hallways_;
};