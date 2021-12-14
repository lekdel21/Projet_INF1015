#pragma once


#include "Map.hpp"
#include "Piece.hpp"

using namespace std;

Map::Map()
{
	titre_ = "The Abandoned House";
	auto piece1 = make_shared<Piece>("Kitchen", "This room is very dark");
	auto piece2 = make_shared<Piece>("Living Room", "This room is very clear");
	auto piece3 = make_shared<Piece>("Storage", "This room is comforting");
	auto piece4 = make_shared<Piece>("Bedroom", "You don't feel wlcomed in this room");
	auto piece5 = make_shared<Piece>("Dining Room", "This room is weird");

	pieces_ = { piece1, piece2, piece3, piece4, piece5 };
	player_.setPos(piece1);

	piece1->addCouloir("East", piece2);

	piece2->addCouloir("East", piece3);
	piece2->addCouloir("South", piece4);
	piece2->addCouloir("West", piece1);

	piece3->addCouloir("South", piece5);
	piece3->addCouloir("West", piece2);

	piece4->addCouloir("East", piece5);
	piece4->addCouloir("North", piece2);

	piece5->addCouloir("North", piece3);
	piece5->addCouloir("West", piece4);
}

void Map::changePiece(shared_ptr<Piece> piece)
{

}

void Map::addPiece(shared_ptr<Piece> piece)
{

}

void Map::startGame()
{
	char quitter = 'r';
	cout << ">>>>>>>>>> ";
	cout << titre_;
	cout << " <<<<<<<<<<"<<endl;
	cout << "Commands: " << endl;
	cout << "(L) to show the room that you are in" << endl;
	cout << "(N),(E),(S),(W) to change rooms" << endl;
	do
	{
		player_.getPos()->afficher();
		quitter = player_.avancer();
	} while (quitter != 'Q');
}