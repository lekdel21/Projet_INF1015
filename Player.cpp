#pragma once

#include "Player.hpp"

char Player::avancer()
{
	char direction;

	do
	{
		
		cout << ">"; cin >> direction; cout << endl;
 
	} while (pos_->getCouloir(direction) == nullptr && direction != 'Q');
	if (direction == 'Q')
		return direction;
	cout << "Going to " << pos_->getCouloir(direction)->getNom() << endl;
	pos_ = pos_->getCouloir(direction);

	return direction;
}		
