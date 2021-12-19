#pragma once

#include <memory>
#include <functional>
#include <iostream>

using namespace std;

class Object
{
public:
	Object(string name, string description, string action, bool isbutton) : name_(name), description_(description), action_(action), isButton_(isbutton) {};
	string getName() const { return name_; }
	string getDescription() const {return description_;}
	string getAction() const { return action_; };

private:
	string name_, description_, action_;
	bool isButton_;
};
