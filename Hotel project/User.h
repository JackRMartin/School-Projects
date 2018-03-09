#ifndef USER_H
#define USER_H

#pragma once
#include <string>
//user.h
class User
{

private:

	std::string name;
	std::string userName;
	std::string password;

public:

	User();
	void setUserName(std::string username);
	std::string getUserName();
	void setPassword(std::string password);
	std::string getPassword();
	void setname(std::string name);
	std::string getname();
	~User();

};




#endif // !USER_H
