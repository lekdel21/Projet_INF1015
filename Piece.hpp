#pragma once

#include <string>
#include <memory>
#include <map>
#include <iostream>
//#include "Affichage.hpp"

using namespace std;

class Piece
{
public:
	Piece(string nom, string description);
	void addCouloir(string direction, shared_ptr<Piece> piece);
	shared_ptr<Piece> getCouloir(char direction);

	string getNom() { return nom_; }
	map<string, shared_ptr<Piece>> couloirs_;
	void afficher();
private:
	string nom_;
	string description_;
	
};
