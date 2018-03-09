#ifndef ROOMSERVICE
#define ROOMSERVICE

#pragma once

#include <iostream>
#include <string>

#include "CustomerBill.h"
//roomservice.h
class RoomService
{

private:

	double roomServiceCharge;
	double pizzaCharge;
	double cleaningCharge;
	double laundryCharge;
	const double laundryPrice;
	const double pizzaPrice;
	const double cleanRoomPrice;

public:

	RoomService(); // constructor 

	void setRoomServiceCharge(int pizzaNum, int cleaningNum, int laundryNum);
	void setTotal(CustomerBill &customer1);
	double getRoomServiceCharge();
	void setPizzaCharge(int pizzaNum);
	double getPizzaCharge();
	void setCleaningCharge(int cleaningNum);
	double getCleaningCharge();
	double getPizzaPrice();
	double getCleanRoomPrice();
	void setLaundryCharge(int laundryNum);
	double getLaundryCharge();
	double getLaundryPrice();

	~RoomService(); // destructor
};

#endif // !ROOMSERVICE