#include "Guest.h"

//guest.cpp
Guest::Guest()
{
}

void Guest::setCheckIn(std::string checkIn)
{
	this->checkIn = checkIn;
}

std::string Guest::getCheckIn()
{
	return checkIn;
}

void Guest::setCheckOut(std::string checkOut)
{
	this->checkOut = checkOut;
}

std::string Guest::getCheckOut()
{
	return checkOut;
}


Guest::~Guest()
{
}
