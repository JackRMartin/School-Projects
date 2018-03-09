//Jack Martin
//Project #3
//
// This project demonstrates basic knowledge of objects
// I created an airplane class, that can create an airplane object with either a default constructor or a parameter constructor
// the airplane object also has various getter and setter methods that will allow you to intialize and return the member variables of the object


#include "Airplane.h"
#include <string>


int main()
{
	std::string model;
	int year;
	int seats;
	int speed;
	int loop = 0;

	do
	{

	Airplane airplane;

	std::cout << "Enter the airplane model an model number:";
	getline(std::cin, model);
	std::cout << "Enter the airplane's year:";
	std::cin >> year;
	std::cout << "Enter the amount of seats in the airplane:";
	std::cin >> seats;
	airplane.setModel(model);
	airplane.setYear(year);
	airplane.setSeats(seats);
	airplane.getModel();
	airplane.getYear();
	airplane.getSeats();

	std::cout << "Your airplane is a " << airplane.getModel() << " year " << airplane.getYear() << " with " << airplane.getSeats() << " seats!";
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Lets Accelerate!" << std::endl;
		airplane.accelerate();
		std::cout << "The airplane's current speed is " << airplane.getSpeed() << "MPH!" << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << "OH NO! Lets slow down!" << std::endl;
		airplane.brake();
		std::cout << "The airplane's current speed is " << airplane.getSpeed() << "MPH!" << std::endl;
	}

	loop += loop;

	} while (loop != 0);

	system("pause");

	return 0;

}