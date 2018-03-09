#include "User.h"
//user.cpp
User::User()
{
}

void User::setUserName(std::string username)
{
	this->userName = username;
}

std::string User::getUserName()
{
	return userName;
}

void User::setPassword(std::string password)
{
	this->password = password;
}

std::string User::getPassword()
{
	return password;
}

void User::setname(std::string name)
{
	this->name = name;
}

std::string User::getname()
{
	return name;
}

User::~User()
{
}
