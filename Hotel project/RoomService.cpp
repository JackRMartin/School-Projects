
#include "RoomService.h"

//roomservice.cpp

RoomService::RoomService() : laundryPrice(10.00), pizzaPrice(8.00), cleanRoomPrice(15.00) // initializing the constants
{
	roomServiceCharge = 0.0, pizzaCharge = 0.0, cleaningCharge = 0.0, laundryCharge = 0.0; // intializing the normal variabes
}

void RoomService::setRoomServiceCharge(int pizzNum, int cleaningNum, int laundryNum)
{
	roomServiceCharge = (pizzaPrice * pizzNum) + (cleaningNum * cleanRoomPrice) + (laundryNum * laundryPrice);
}

void RoomService::setTotal(CustomerBill &customer1)
{

	customer1.setTotalCharges(roomServiceCharge);
}

double RoomService::getRoomServiceCharge()
{
	return roomServiceCharge;
}

void RoomService::setPizzaCharge(int pizzaNum)
{
	pizzaCharge = pizzaNum * pizzaPrice;
}

double RoomService::getPizzaCharge()
{
	return pizzaCharge;
}

void RoomService::setCleaningCharge(int cleaningNum)
{
	cleaningCharge = cleaningNum * cleanRoomPrice;
}

double RoomService::getCleaningCharge()
{
	return cleaningCharge;
}

double RoomService::getPizzaPrice()
{
	return pizzaPrice;
}

double RoomService::getCleanRoomPrice()
{
	return cleanRoomPrice;
}

void RoomService::setLaundryCharge(int laundryNum)
{
	laundryCharge = laundryNum * laundryPrice;
}

double RoomService::getLaundryCharge()
{
	return laundryCharge;
}

double RoomService::getLaundryPrice()
{
	return laundryPrice;
}

RoomService::~RoomService()
{

}