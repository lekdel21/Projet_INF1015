#pragma once


#include "Map.hpp"
#include "Piece.hpp"

using namespace std;

Map::Map()
{
	titre_ = "the maze";
	auto piece1 = make_shared<Piece>("piece 1", "cette piece est obscure.");
	auto piece2 = make_shared<Piece>("piece 2", "cette piece est clair.");
	auto piece3 = make_shared<Piece>("piece 3", "cette piece est reconfortante.");
	auto piece4 = make_shared<Piece>("piece 4", "vous ne vous sentez pas la bienvenue dans cette piece.");
	auto piece5 = make_shared<Piece>("piece 5", "cette piece est etrange.");

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
	cout << titre_ << endl;
	do
	{
		player_.getPos()->afficher();
		quitter = player_.avancer();
	} while (quitter != 'Q');
}