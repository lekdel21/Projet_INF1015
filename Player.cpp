#pragma once

#include "Player.hpp"

bool Player::move()
{
	string move;

	do
	{
		cout << ">"; cin >> move; cout << endl;
		objectInteraction(move);

	} while (pos_->getCouloir(move) == nullptr && move != "quitter");
	
	if (move == "quitter")
		return false;
	
	cout << "Going to " << pos_->getCouloir(move)->getName() << endl;
	
	pos_ = pos_->getCouloir(move);

	return true;
}		

void Player::objectInteraction(string& playerMove)
{
	string object = playerMove;
	if (playerMove.find(" ") != -1)
	{
		object = playerMove.substr(playerMove.find(" "));
		playerMove.resize(playerMove.find(" "));
	}
	if (pos_->isObject(object))
	{
		if (playerMove == "look")
		{
			cout << pos_->getObject(object)->getDescription() << endl;
		}
		else if (playerMove == "use" && pos_->getObject(object)->isButton()== true)
		{
			//pos_->addCouloir("South", map_.getRoomVec()[5]);
			cout << pos_->getObject(object)->getAction() << endl;
			cout<<"yopu"<<endl;
		}
		else if (playerMove == "use")
		{
			
		}
		
	}
}