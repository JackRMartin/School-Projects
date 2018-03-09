#include "Airplane.h"

//class member function definitions

Airplane::Airplane()
{
	speed = 0;
}

Airplane::Airplane(std::string newModel, int newYear, int newSpeed, int newseats)
{
	model = newModel;
	year = newYear;
	speed = newSpeed;
	seats = newseats;
}
int Airplane::getYear()
{
	return year;
}
void Airplane::setYear(int newYear)
{
	year = newYear;
}
std::string Airplane::getModel()
{
	return model;
}
void Airplane::setModel(std::string newModel)
{
	model = newModel;
}
int Airplane::getSpeed()
{
	return speed;
}
void Airplane::setSpeed(int newSpeed)
{
	speed = newSpeed;
}
int Airplane::getSeats()
{
	return seats;
}
void Airplane::setSeats(int newSeats)
{
	seats = newSeats;
}
Airplane::~Airplane() // default
{
	std::cout << "Thank you for flying!" << std::endl << std::endl;
}
void Airplane::accelerate()
{
	speed += 100;
}

void Airplane::brake()
{
	speed -= 100;
}