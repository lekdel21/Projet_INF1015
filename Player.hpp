#pragma once

#include <memory>
#include "Piece.hpp"
#include "iostream"
using namespace std;

class Player
{
public:
	Player() : pos_(nullptr) {}
	char avancer();
	

	void setPos(shared_ptr<Piece> pos) { pos_ = pos; }
	shared_ptr<Piece> getPos() { return pos_; }
private:
	shared_ptr<Piece> pos_;
};