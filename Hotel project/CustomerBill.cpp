
#include "CustomerBill.h"

//customerbill.cpp

CustomerBill::CustomerBill() : resortFee(100.00)
{
	totalCharges = 0.0, daysAtHotel = 0;
}

void CustomerBill::setTotalCharges(double charge)
{
	totalCharges = totalCharges + charge;
}

void CustomerBill::setTotalWithDays()
{
	totalCharges += (daysAtHotel * resortFee);
}

double CustomerBill::getTotalCharges()
{
	return totalCharges;
}

void CustomerBill::setCustomerName(std::string newName)
{
	customername = newName;
}

std::string CustomerBill::getCustomerName()
{
	return customername;
}

void CustomerBill::setDaysAtHotel(int days)
{
	daysAtHotel = days;
}

int CustomerBill::getDaysAtHotel()
{
	return daysAtHotel;
}

double CustomerBill::getResortFee()
{
	return resortFee;
}

CustomerBill::~CustomerBill()
{

}

