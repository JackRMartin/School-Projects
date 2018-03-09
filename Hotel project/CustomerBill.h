#ifndef CUSTOMERBILL
#define CUSTOMERBILL

#pragma once

#include <iostream>	
#include <string>
//customerbill.h
class CustomerBill
{

private:
	double totalCharges;
	std::string customername;
	int daysAtHotel;
	const double resortFee;

public:

	CustomerBill();
	void CustomerBill::setTotalWithDays();
	void setTotalCharges(double charge);
	double getTotalCharges();
	void setCustomerName(std::string name);
	std::string getCustomerName();
	void setDaysAtHotel(int days);
	int getDaysAtHotel();
	double getResortFee();

	~CustomerBill();

};

#endif // !customerbill