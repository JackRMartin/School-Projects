#include "Clerk.h"
//clerk.cpp
Clerk::Clerk()
{

}

void Clerk::updateMiniBarCharge(MiniBar minibar1, CustomerBill customer1)
{
	minibar1.setTotal(customer1);
}

double Clerk::getMiniBarCharge(MiniBar minibar1)
{
	return minibar1.getMiniBarCharge();
}

void Clerk::updateRoomServiceCharge(RoomService roomservice1, CustomerBill customer1)
{
	roomservice1.setTotal(customer1);
}

double Clerk::getRoomServiceCharge(RoomService roomservice1)
{
	return roomservice1.getRoomServiceCharge();
}

void Clerk::setBillTotal(CustomerBill& customer1, MiniBar minibar1, RoomService roomservice1)
{
	double charge = 0;
	charge = (customer1.getResortFee() * customer1.getDaysAtHotel()) + minibar1.getMiniBarCharge() + roomservice1.getRoomServiceCharge();
	customer1.setTotalCharges(charge);
}

double Clerk::getBillTotal(CustomerBill customer1)
{
	return customer1.getTotalCharges();
}

void Clerk::setDaysAtHotel(CustomerBill customer1)
{
	
}

double Clerk::getDaysAtHotel(CustomerBill customer1)
{
	return 0.0;
}

//void Clerk::setBillTotalWithDays(CustomerBill customer1, MiniBar minibar1, RoomService roomservice1)
//{
//}

Clerk::~Clerk()
{

}

