#pragma once

#include <memory>
#include "Piece.hpp"
#include "iostream"
using namespace std;

class Player
{
public:
	Player() : pos_(nullptr) {}
	bool move();
	
	void setPos(Room* pos) { pos_ = pos; }
	Room* getPos() { return pos_; }
private:
	Room* pos_;
	void objectInteraction(string& playerMove);

};