#ifndef CLERK_H
#define CLERK_H

#include "User.h"
#include "CustomerBill.h"
#include "MiniBar.h"
#include"RoomService.h"

#pragma once
//clerk.h
class Clerk: public User
{
private:

public:

	Clerk();
	void updateMiniBarCharge(MiniBar minibar1, CustomerBill customer1);
	double getMiniBarCharge(MiniBar minibar1); 
	void updateRoomServiceCharge(RoomService roomservice1, CustomerBill customer1);
	double getRoomServiceCharge(RoomService roomservice1);
	void setBillTotal(CustomerBill& customer1, MiniBar minibar1, RoomService roomservice1);
	double getBillTotal(CustomerBill customer1);
	void setDaysAtHotel(CustomerBill customer1);
	double getDaysAtHotel(CustomerBill customer1);
	/*void setBillTotalWithDays(CustomerBill& customer1, MiniBar minibar1, RoomService roomservice1);*/

	~Clerk();
};

#endif // !CLERK_H