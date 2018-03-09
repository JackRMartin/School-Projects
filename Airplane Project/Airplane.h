#pragma once
#include <iostream>

class Airplane
{

private:
	std::string model;
	int year;
	int speed;
	int seats;

public:
	Airplane(); // default values constrsuctor
	Airplane(std::string newModel, int newYear, int newSpeed, int newseats); // custom values constructor

	std::string getModel(); // function to retrieve the model variable from the class ( object must be created and variable must be already set )
	void setModel(std::string newModel); // allows custom user input for model variable( object must be created )
	int getYear(); // function to retrieve the year variable from the class ( object must be created and variable must be already set )
	void setYear(int newYear); // allows custom user input for year variable( object must be created )
	int getSpeed(); // function to retrieve the speed variable from the class ( object must be created and variable must be already set )
	void setSpeed(int newSpeed); // allows custom user input for speed variable ( object must be created )
	int getSeats(); // function to retrieve the seats variable from the class ( object must be created and variable must be already set )
	void setSeats(int newSeats); // allows custom user input for seats variable( object must be created )
	void accelerate(); // accelerates the plane by 100 mph
	void brake(); // decellerates the plane by 100 mph
	

	~Airplane(); // destrcutor

};