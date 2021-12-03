#pragma once

#include <memory>
#include <functional>
#include "Piece.hpp"
#include "Affichage.hpp"
#include "Player.hpp"


using namespace std;

class Map
{
public:
	Map();
	void changePiece(shared_ptr<Piece> piece);
	void addPiece(shared_ptr<Piece> piece);

	void startGame();
private:
	string titre_;
	vector<shared_ptr<Piece>> pieces_;
	Player player_;
};
