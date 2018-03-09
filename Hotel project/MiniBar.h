#ifndef MINIBAR
#define MINIBAR

#pragma once

#include <iostream>
#include <string>

#include "CustomerBill.h"
//minibar.h
class MiniBar
{

private:
	double miniBarCharge;
	double sodaCharge;
	double waterCharge;
	double juiceCharge;
	const double sodaPrice;
	const double waterPrice;
	const double juicePrice;

public:
	MiniBar(); // constructor

	void setTotal(CustomerBill &customer1);
	void setMiniBarCharge(int sodaNum, int waterNum, int juiceNum);
	double getMiniBarCharge();
	void setSodaCharge(int sodaPurchased);
	double getSodaCharge();
	void setWaterCharge(int waterPurchased);
	double getWaterCharge();
	void setJuiceCharge(int juicePurchased);
	double getJuiceCharge();
	double getSodaPrice();
	double getWaterPrice();
	double getJuicePrice();

	~MiniBar(); // destructor
};

#endif // !MINIBAR