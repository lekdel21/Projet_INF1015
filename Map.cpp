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
	rooms_.push_back(new Room("Bedroom", "You don't feel welcomed in this room"));
	rooms_.push_back(new Room("Dining Room", "This room is weird"));
	rooms_.push_back(new Room("Secret Library", "The exit is here!"));

	player_.setPos(rooms_[0]);

	rooms_[0]->addCouloir("East", rooms_[1]);
	rooms_[0]->addObjet(new Object("Piano", "An old piano, probably from the 1800's", "You play the piano, nothing happens it just sounds terrible", false));

	rooms_[1]->addCouloir("East", rooms_[2]);
	rooms_[1]->addCouloir("South", rooms_[3]);
	rooms_[1]->addCouloir("West", rooms_[0]);
	rooms_[1]->addObjet(new Object("Notes", "Notes written by hand, seems like a language you cannot understand", "You try to read the notes but you don't speak german", false));

	rooms_[2]->addCouloir("South", rooms_[4]);
	rooms_[2]->addCouloir("West", rooms_[1]);
	rooms_[2]->addObjet(new Object("A bottle of water", "A bottle of water is on the table, you don't know how long its been there", "You drink the water, it's refreshing", false));

	rooms_[3]->addCouloir("East", rooms_[4]);
	rooms_[3]->addCouloir("North", rooms_[1]);
	rooms_[3]->addObjet(new Object("An old picture", "An old picture from the 1800's of the family that used to live here, the Richardsons", "You look at the picture and notice they are standing in a room that you have not seen in this house anymore, there must be a secret room somehwere...", false));

	rooms_[4]->addCouloir("North", rooms_[2]);
	rooms_[4]->addCouloir("West", rooms_[3]);
	rooms_[4]->addObjet(new Object("A button", "A big red button covered in dust", "You press the button and a door open to a new room", true));
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