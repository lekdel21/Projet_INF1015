#pragma once

#include "Piece.hpp"

using namespace std;

Piece::Piece(string nom, string description) : nom_(nom), description_(description)
{}

void Piece::addCouloir(string direction, shared_ptr<Piece> piece)
{
	couloirs_[direction] = piece;
}

shared_ptr<Piece> Piece::getCouloir(char direction)
{
	shared_ptr<Piece> ptr = nullptr;
	if (direction == 'N' && couloirs_.find("North") != couloirs_.end())
		ptr = couloirs_["North"];
	else if (direction == 'E' && couloirs_.find("East") != couloirs_.end())
		ptr = couloirs_["East"];
	else if (direction == 'W' && couloirs_.find("West") != couloirs_.end())
		ptr = couloirs_["West"];
	else if (direction == 'S' && couloirs_.find("South") != couloirs_.end())
		ptr = couloirs_["South"];
	else if (direction == 'E' && couloirs_.find("East") == couloirs_.end())
		cout << "Cannot go there" << endl;
	else if (direction == 'W' && couloirs_.find("West") == couloirs_.end())
		cout << "Cannot go there" << endl;
	else if (direction == 'S' && couloirs_.find("South") == couloirs_.end())
		cout << "Cannot go there" << endl;
	else if (direction == 'N' && couloirs_.find("South") == couloirs_.end())
		cout << "Cannot go there" << endl;
	else if (direction == 'L')
		afficher();
	else
		cout << "I do not know that" << endl;
	return ptr;
}

void Piece::afficher()
{
	cout << endl << endl << endl;

	cout <<"----"<< nom_ <<"----"<< endl;
	cout << description_ << endl;
	
	for (auto&& [dir, piece] : couloirs_)
	{
		cout << piece->getNom() << " is to the " << dir << " (" << dir[0] << ")" << endl;
	}
	

}