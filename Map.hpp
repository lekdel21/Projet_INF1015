#pragma once

#include <memory>
#include <functional>
#include "Piece.hpp"
#include "Player.hpp"


using namespace std;

class Map
{
public:
	Map();
	~Map();
	void addPiece(Room* room);

	void startGame();
private:
	string titre_;
	vector <Room*> rooms_;
	Player player_;

	void showMenu();
};
