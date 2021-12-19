#pragma once

#include "Piece.hpp"

using namespace std;

Room::Room(string name, string description) : name_(name), description_(description) {}

Room::~Room()
{
	for (auto&& o : objects_)
		delete o;
}

void Room::addCouloir(string direction, Room* room)
{
	hallways_.push_back(pair(direction, room));
}

Room* Room::getCouloir(string direction)
{

	for (auto&& hallway : hallways_)
	{

		if (hallway.first[0] == direction[0])
			return hallway.second;
	}

	if (direction[0] == 'N' || direction[0] == 'E' || direction[0] == 'W' || direction[0] == 'S')
		cout << "You cannot go there." << endl;
	else if (direction[0] == 'L')
		afficher();
	else if (direction != "quitter")
		cout << "I do not know that." << endl;

	return nullptr;
}

void Room::afficher()
{
	cout << endl << endl << endl;

	cout <<"----"<< name_ <<"----"<< endl;
	cout << description_ << endl;
	
	for (auto&& hallway : hallways_)
	{
		cout << hallway.second->getName() << " is to the " << hallway.first << " (" << hallway.first[0] << ")" << endl;
	}
	
}

bool Room::isObject(const string& object)
{
	if (objects_.size() != 0)
	{
		for (auto&& o : objects_)
		{
			if (o->getName() == object)
				return true;
		}
	}
	return false;
}

Object* Room::getObject(const string& object)
{
	for (int i = 0; i < objects_.size(); i++)
	{
		if (objects_[i]->getDescription() == object)
			return objects_[i];
	}
}