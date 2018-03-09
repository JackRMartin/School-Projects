#ifndef GUEST_H
#define GUEST_H

#include "User.h"

#pragma once

//guest.h
class Guest : public User
{

private:

	std::string checkIn, checkOut;

public:

	Guest();

	void setCheckIn(std::string checkIn);
	std::string getCheckIn();
	void setCheckOut(std::string checkOut);
	std::string getCheckOut();

	~Guest();

};





#endif // !GUEST_H

