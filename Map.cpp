#pragma once


#include "Map.hpp"
#include "Piece.hpp"

using namespace std;

Map::~Map()
{
	for (auto&& room : rooms_)
	{
		room->~Room();
		delete room;
	}
}

Map::Map()
{
	titre_ = "The Abandoned House";

	rooms_.push_back(new Room("Kitchen", "This room is very dark"));
	rooms_.push_back(new Room("Living Room", "This room is very clear"));
	rooms_.push_back(new Room("Storage", "This room is comforting"));
	rooms_.push_back(new Room("Bedroom", "You don't feel wlcomed in this room"));
	rooms_.push_back(new Room("Dining Room", "This room is weird"));

	player_.setPos(rooms_[0]);

	rooms_[0]->addCouloir("East", rooms_[1]);

	rooms_[1]->addCouloir("East", rooms_[2]);
	rooms_[1]->addCouloir("South", rooms_[3]);
	rooms_[1]->addCouloir("West", rooms_[0]);

	rooms_[2]->addCouloir("South", rooms_[4]);
	rooms_[2]->addCouloir("West", rooms_[1]);

	rooms_[3]->addCouloir("East", rooms_[4]);
	rooms_[3]->addCouloir("North", rooms_[1]);

	rooms_[4]->addCouloir("North", rooms_[2]);
	rooms_[4]->addCouloir("West", rooms_[3]);
}

void Map::addPiece(Room* piece)
{

}

void Map::startGame()
{
	bool playing = true;
	showMenu();
	do
	{
		player_.getPos()->afficher();
		playing = player_.move();
	} while (playing);
}

void Map::showMenu()
{
	cout << ">>>>>>>>>> " << titre_ << " <<<<<<<<<<" << endl;
	cout << "Commands: " << endl;
	cout << "(L) to show the room that you are in" << endl;
	cout << "(N),(E),(S),(W) to change rooms" << endl;
}