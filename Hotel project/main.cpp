// Jack Martin
// Project #5
// main.cpp
// 

// This project simulates an interaction between a client at a hotel and an employee at the hotel.
// both the user and employee can create accounts for the hotel software
// then the employee can create a bill for the customer based on the services they used.
// both the employee and the customer have the option of viewing the bill, thereafter.
// demonstrates knowledge of objects, inheritance, conditional statements, and input validation.

#include <limits>
#include "RoomService.h"
#include "MiniBar.h"
#include "CustomerBill.h"
#include "Guest.h"
#include "Clerk.h"

#undef max

void displayMenu();
void accountRegistration(Guest& guest1, Clerk& clerk1, bool guestCheck, bool clerkCheck);
void checkUserType(bool& guestCheck, bool& clerkCheck);
void clerkLogIn(Clerk& clerkObject, bool clerkCheck);
void guestLogIn(Guest& guestObject, bool guestCheck);
void miniBarInput(MiniBar &minibar1);
void roomServiceInput(RoomService &roomservice1);
void displayBill(CustomerBill &customer1, MiniBar &minibar1, RoomService &roomservice1, Guest guest1);
int getInt(int value); // function used to validate user input
void createCustomerBill(CustomerBill& customer1, Guest& guest1, MiniBar& minibar1, RoomService& roomservice1, Clerk clerk1);

int main()
{
	std::string name; // customer name ( used for user input )
	int daysAtHotel = 0; // days at hotel ( used for user input )
	int choice;

	char clerkChoice;
	char guestChoice;
	char clerkBillchoice;

	/*char miniBarChoice;
	char roomserviceChoice;*/

	Clerk clerk1; // create clerk object
	Guest guest1; // create guest object
	CustomerBill customer1; //create customer object
	MiniBar minibar1; // create mini bar object
	RoomService roomservice1; // create roomservice object

	bool billExists = false;

	do
	{
		system("cls");
		bool guestCheck = false;
		bool clerkCheck = false;
		

		displayMenu();
		std::cin >> choice; // user chooses an option from display menu
		choice = getInt(choice); // validation

		if (choice == 1) // if choice is '1' user will be prompted to create an account for the hotel
		{
			// prompt user selection, and registration
			checkUserType(guestCheck, clerkCheck);

			if (guestCheck) // user wants to make a guest account
			{
				accountRegistration(guest1, clerk1, guestCheck, clerkCheck);
			}

			if (clerkCheck) // user wants to make a clerk account
			{
				accountRegistration(guest1, clerk1, guestCheck, clerkCheck);
			}
			
		}

		if (choice == 2)
		{
			// log in code

			checkUserType(guestCheck, clerkCheck);

			if (guestCheck) // guest log in was successful
			{
				std::cout << "What is your name ?" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				getline(std::cin, name);
				customer1.setCustomerName(name); // assign customer name to name variable in object

				std::cout << "Would you like to view your bill? ('Y' or 'N')";
				std::cin >> guestChoice;
				guestChoice = toupper(guestChoice);

				if (guestChoice == 'Y' && billExists == true)
				{
					displayBill(customer1, minibar1, roomservice1, guest1); // display the Receipt to the user!
				}
				
				if (guestChoice == 'Y' && billExists == false)
				{
					std::cout << "Sorry, your bill hasn't been created yet! \n\n Have a clerk log in to create your bill! \n";
					system("pause");
				}

				std::cout << "Logging out! " << std::endl;

				//code for guest abilities after log in
				// if user wants to display the bill ..... displayBill(customer1, minibar1, roomservice1);
			}
			if (clerkCheck) // clerk log in was successful
			{
				std::cout << "Hello " << clerk1.getname() << " Would you like to create the customer's bill? ('y' or 'n'):";
				std::cin >> clerkChoice;
				clerkChoice = toupper(clerkChoice);
					
				if (clerkChoice == 'Y') // this means the clerk wants to create a bill for the customer. 
				{
					createCustomerBill(customer1, guest1, minibar1, roomservice1, clerk1);
					billExists = true;
				}

				std::cout << "Would you like to display the bill? ('Y' or 'N')";
				std::cin >> clerkBillchoice;
				clerkBillchoice = toupper(clerkBillchoice);

				if (clerkBillchoice == 'Y' && billExists == true)
				{
					system("cls");
					displayBill(customer1, minibar1, roomservice1, guest1); // display the bill to the user!
				}
				
				if (clerkBillchoice == 'Y' && billExists == false)
				{
					system("cls");
					std::cout << "Sorry the bill hasn't been created yet! You have to make one in order to view it! \n\n";
					system("pause");
				}
				
			}

		}
	} while (choice != 3);
	
	//displayBill(customer1, minibar1, roomservice1); // display the Receipt to the user!

	system("pause");
	return 0;
}

void miniBarInput(MiniBar &minibar1)
{
	int sodaNum = 0;
	int waterNum = 0;
	int juiceNum = 0;

	std::cout << "How many sodas did you purchase: ";
	std::cin >> sodaNum;
	sodaNum = getInt(sodaNum);

	if (sodaNum > 0)	// determines if soda charge needs to be updated in minibar class
	{
		minibar1.setSodaCharge(sodaNum);
	}

	std::cout << "How many water bottles did you purchase: ";
	std::cin >> waterNum;
	waterNum = getInt(waterNum);

	if (waterNum > 0)	// determines if water charge needs to be updated in minibar class
	{
		minibar1.setWaterCharge(waterNum);
	}

	std::cout << "How many juice bottles did you purchase: ";
	std::cin >> juiceNum;
	juiceNum = getInt(juiceNum);

	if (juiceNum > 0)	// determines if juice charge needs to be updated in minibar class
	{
		minibar1.setJuiceCharge(juiceNum);
	}

	minibar1.setMiniBarCharge(sodaNum, waterNum, juiceNum);
	
}
void roomServiceInput(RoomService &roomservice1)
{
	int cleaningNum = 0;
	int pizzaNum = 0;
	int laundryNum = 0;

	std::cout << "How many pizzas did you order: ";
	std::cin >> pizzaNum;
	pizzaNum = getInt(pizzaNum);

	if (pizzaNum > 0) // determines if pizza charge needs to be updated in roomservice class
	{
		roomservice1.setPizzaCharge(pizzaNum);
	}

	std::cout << "How many times did you order room cleaning: ";
	std::cin >> cleaningNum;
	cleaningNum = getInt(cleaningNum);

	if (cleaningNum > 0) // determines if cleaning charge needs to be updated in roomservice class
	{
		roomservice1.setCleaningCharge(cleaningNum);
	}

	std::cout << "How many times did you order Laundry services: ";
	std::cin >> laundryNum;
	laundryNum = getInt(laundryNum);

	if (laundryNum > 0) // determines if laundry charge needs to be updated in roomservice class
	{
		roomservice1.setLaundryCharge(laundryNum);
	}

	roomservice1.setRoomServiceCharge(pizzaNum, cleaningNum, laundryNum);
}

void displayBill(CustomerBill &customer1, MiniBar &minibar1, RoomService &roomservice1, Guest guest1)
{

	// formats and displays the receipt

	std::cout << "-Cal State Fullerton Resort-" << std::endl << std::endl;
	std::cout << "Receipt for " << customer1.getCustomerName() << std::endl;	// Displays the customer's name
	std::cout << "Days stayed at CSUF Resort: " << customer1.getDaysAtHotel() << std::endl << std::endl; // dispalys days stayed at the hotel 
	std::cout << "Check in date: " << guest1.getCheckIn() << "\nCheck out date: " << guest1.getCheckOut() << "\n";

	if (minibar1.getMiniBarCharge() > 0) // check if mini bar was used at all
	{
		std::cout << "-MiniBar Charges-" << std::endl << std::endl;
		if (minibar1.getSodaCharge() > 0)
		{
			std::cout << "Sodas Charge: $" << minibar1.getSodaCharge() << std::endl; // displays the charge for sodas
		}
		if (minibar1.getWaterCharge() > 0)
		{
			std::cout << "Water Charge: $" << minibar1.getWaterCharge() << std::endl; // displays the charge for waters
		}
		if (minibar1.getJuiceCharge() > 0)
		{
			std::cout << "Juice Charge: $" << minibar1.getJuiceCharge() << std::endl << std::endl; // displays the charge for juice
		}
		if (minibar1.getMiniBarCharge() > 0)
		{
			std::cout << "Total Mini Bar Charge: $" << minibar1.getMiniBarCharge() << std::endl << std::endl; // displays the total charge for minibar
		}
	}

	if (roomservice1.getRoomServiceCharge() > 0) // check if room service was used at all
	{
		std::cout << "-Room Service Charges-" << std::endl << std::endl;
		if (roomservice1.getCleaningCharge() > 0)
		{
			std::cout << "Room Cleaning Requests: $" << roomservice1.getCleaningCharge() << std::endl; // displays the charge for room cleanings
		}
		if (roomservice1.getPizzaCharge() > 0)
		{
			std::cout << "Pizza Requests: $" << roomservice1.getPizzaCharge() << std::endl; // displays the charge for pizza orders
		}
		if (roomservice1.getLaundryCharge() > 0)
		{
			std::cout << "Laundry Requests: $" << roomservice1.getLaundryCharge() << std::endl << std::endl; // displays the charge for laundry services
		}
		if (roomservice1.getRoomServiceCharge() > 0)
		{
			std::cout << "Total Room Service Charges: $" << roomservice1.getRoomServiceCharge() << std::endl << std::endl; // displays the charge for room service
		}
	}

	std::cout << "-Total-" << std::endl << std::endl;
	std::cout << "Days at Hotel: " << customer1.getDaysAtHotel() << std::endl << std::endl; //  displays the days spent at the hotel
	std::cout << "Total Bill Charge: $" << customer1.getTotalCharges() << std::endl << std::endl; // displays the total charges for the customer's bill
	system("pause");
}

int getInt(int value) // user input validation
{
	while (!std::cin)
	{
		std::cout << "You entered an invalid value! \nPlease Enter an integer value:";
		std::cin.clear(); // clear error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // cleans the stream
		std::cin >> value; // attempts a new value
	}
	return value;
}


void displayMenu()
{
	std::cout << "--CSUF Resort--\n";
	std::cout << "Please choose an option below \n\n";
	std::cout << "1) Create account\n";
	std::cout << "2) Log in\n";
	std::cout << "3) Exit\n";
}

void accountRegistration(Guest& guest1, Clerk& clerk1, bool guestCheck, bool clerkCheck)
{
	
	std::string username;
	std::string password;
	

	if (guestCheck)
	{
		system("cls"); // clear screen
		std::cout << "--Account Registration--\n\n";
		std::cout << "Please create a username:";
		std::cin >> username; // allow guest to create a username
		getline(std::cin, username); // store it in username variable, of guest object
		std::cout << "Your name has been stored!\n";
		guest1.setUserName(username);
		std::cout << "Please create a password:";
		getline(std::cin, password);
		guest1.setPassword(password);
		std::cout << "Your password has been saved!\n";
		system("pause");
		system("cls");
		
	}

	if (clerkCheck)
	{
		system("cls");
		std::cout << "--Account Registration--\n\n";
		std::cout << "Please create a username:";
		getline(std::cin, username); // stores username for the clerk
		std::cout << "Your name has been stored!\n";
		clerk1.setUserName(username);
		std::cout << "Please create a password:";
		getline(std::cin, password);
		clerk1.setPassword(password);
		std::cout << "Your password has been saved!\n";
		system("pause");
		system("cls");
	}
}

void checkUserType(bool& guestCheck, bool& clerkCheck)
{
	int logInChoice;
	bool loop = true;

	while (loop)
	{

		std::cout << "Are you a guest or an Employee? ('1' for guest '2' for Clerk):" << std::endl;
		std::cin >> logInChoice;
		logInChoice = getInt(logInChoice);

		if (logInChoice == 1)
		{
			guestCheck = true;
			loop = false;
		}
		if (logInChoice == 2)
		{
			clerkCheck = true;
			loop = false;
		}
	}

}

void guestLogIn(Guest& guestObject, bool guestCheck)
{
	bool userLoop = true;
	bool passLoop = true;
	std::string username;
	std::string password;

	do // loops until guest chooses the correct username
	{

	std::cout << "Enter Username:";
	getline(std::cin, username);

		if (guestObject.getUserName() == username)
		{
			userLoop = false;
		}
		else
		{
			std::cout << "Incorrect Username! Try again:";
		}
	} while (userLoop);		

	do // loops until guest chooses the correct password
	{
		std::cout << "\nEnter Password:";
		getline(std::cin, password);

		if (guestObject.getPassword() == password)
		{
			std::cout << "Log In Successful!\n";
			passLoop = false;
		}

	} while (passLoop);
}

void clerkLogIn(Clerk& clerkObject, bool clerkCheck)
{
	bool userLoop = true;
	bool passLoop = true;
	std::string username;
	std::string password;
	
	do // loops until guest chooses the correct username
	{

		std::cout << "Enter Username:";
		getline(std::cin, username);

		if (clerkObject.getUserName() == username)
		{
			userLoop = false;
		}
		else
		{
			std::cout << "Incorrect Username! Try again:";
		}
	} while (userLoop);

	do // loops until guest chooses the correct password
	{
		std::cout << "\nEnter Password:";
		getline(std::cin, password);

		if (clerkObject.getPassword() == password)
		{
			std::cout << "Log In Successful!\n";
			passLoop = false;
		}

	} while (passLoop);
}

void createCustomerBill(CustomerBill& customer1, Guest& guest1, MiniBar& minibar1, RoomService& roomservice1, Clerk clerk1)
{
	std::string name;
	int daysAtHotel;
	std::string checkIn;
	std::string checkOut;
	char miniBarChoice;
	char roomServiceChoice;

	std::cin.clear();
	std::cin.ignore();
	std::cout << "What is the customer's name ?" << std::endl;
	getline(std::cin, name);
	customer1.setCustomerName(name); // assign customer name to name variable in object

	std::cout << "How many days did the customer stay at the hotel?" << std::endl; // ask user how many days they stayed at the hotel
	std::cin >> daysAtHotel;
	daysAtHotel = getInt(daysAtHotel); // validate user input ( make sure it is an integer )

	std::cin.clear();
	std::cin.ignore();
	customer1.setDaysAtHotel(daysAtHotel); // assign days at hotel to corresponding variable in object
	std::cout << "Enter the date you checked in:";
	getline(std::cin, checkIn);

	guest1.setCheckIn(checkIn);

	std::cout << "Enter the date you checked out:";
	getline(std::cin, checkOut);

	guest1.setCheckOut(checkOut);

	std::cout << "Did the customer use the minibar? ('y' or 'n'): "; // ask user if they used the minibar, if yes create a minibar object
	std::cin >> miniBarChoice;
	std::cout << std::endl;
	miniBarChoice = toupper(miniBarChoice);

	if (miniBarChoice == 'Y')
	{
		miniBarInput(minibar1);
		clerk1.updateMiniBarCharge(minibar1, customer1);
	}

	std::cout << std::endl;
	std::cout << "Did you order any roomService? ('y' or 'n'): "; // check if the user ordered room service at all , if yes create a room service object
	std::cin >> roomServiceChoice;
	roomServiceChoice = toupper(roomServiceChoice);

	if (roomServiceChoice == 'Y')
	{
		roomServiceInput(roomservice1);
		clerk1.updateRoomServiceCharge(roomservice1, customer1);
	}

	clerk1.setBillTotal(customer1, minibar1, roomservice1);
	system("cls"); // clears screen after all input has been taken from user
}