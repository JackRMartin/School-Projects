
#include "MiniBar.h"

//minibar.cpp

MiniBar::MiniBar() : sodaPrice(3.00), waterPrice(2.00), juicePrice(4.00) // intialize constants
{
	miniBarCharge = 0.0, sodaCharge = 0.0, waterCharge = 0.0, juiceCharge = 0.0; // initializing variables
}

void MiniBar::setTotal(CustomerBill &customer1)
{
	customer1.setTotalCharges(miniBarCharge);
}

void MiniBar::setMiniBarCharge(int sodaNum, int waterNum, int juiceNum)
{
	miniBarCharge = (sodaNum * sodaPrice) + (waterNum * waterPrice) + (juiceNum * juicePrice);
}

double MiniBar::getMiniBarCharge()
{
	return miniBarCharge;
}

void MiniBar::setSodaCharge(int sodaPurchased)
{
	sodaCharge = sodaPurchased * sodaPrice;
}

double MiniBar::getSodaCharge()
{
	return sodaCharge;
}

void MiniBar::setWaterCharge(int waterPurchased)
{
	waterCharge = waterPurchased * waterPrice;
}

double MiniBar::getWaterCharge()
{
	return waterCharge;
}

void MiniBar::setJuiceCharge(int juicePurchased)
{
	juiceCharge = juicePurchased * juicePrice;
}

double MiniBar::getJuiceCharge()
{
	return juiceCharge;
}

double MiniBar::getSodaPrice()
{
	return sodaPrice;
}

double MiniBar::getWaterPrice()
{
	return waterPrice;
}

double MiniBar::getJuicePrice()
{
	return juicePrice;
}

MiniBar::~MiniBar()
{
}