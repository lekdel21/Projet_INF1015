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
	switch (direction) 
	{
		case 'N': ptr = couloirs_["North"];
			break;
		case 'E': ptr = couloirs_["East"];
			break;
		case 'S': ptr = couloirs_["South"];
			break;
		case 'W': ptr = couloirs_["West"];
			break;
	}
	return ptr;
}

void Piece::afficher()
{
	cout << nom_ << endl;
	cout << description_ << endl;
	for (auto&& [dir, piece] : couloirs_)
	{
		cout << piece->getNom() << " is to the " << dir << " (" << dir[0] << ")" << endl;
	}
}