
//Jack Martin
//CPSC 121 Project #1
// 
//Psuedo code
//
//create function prototypes for the 8 functions
//these 8 functions include
//- display menu X
//- get user input X 
//- read data from file/store data in arrays X 
//- determine letter grade for each student based on their grades stored in arrays X
//- output results to screen X
//- calculate highest class score X
//- find duplicate records X
//- record class' grades and student names to a new text file X
//
//
//declare constant int scores = 6
//
//declare variables and arrays
//string names[], string scores[], char grades[], string inputname, string gradecalc[]
//
//open file to extract data
//read data into files ignoring commas.
//store the names into the name[] array
//store the scores into the scores array
//
//if file fails to open then display and error message and exit program
//
//calculate the scores each student got. (add all together to get a total score)
//then assign a letter grade to each of these scores and assign that letter to index of array
//
//do while loop to create a menu for the user.
//
//make the menu use the 'switch statement'
//user has 5 choices: h,a,s,g,q
//
//'h': diplay all student names, scores, and letter grades on the screen
//use a for loop to cycle through the index of each array and display on screen
//
//
//'a': Display the student name with highest overall score in the class
//compare the total scores with eachother until the highest one is found, then display the student who had that highest score.
//
//'s': search by student name to display only their respective scores
//allow user to type a student name
//then use an if statement to match the student name with their respective array index and output their scores.
//
//'g': create a text file (StudentGrades.txt) which outputs the student names and their letter grades to a .txt file
//use filestream to create a txt file and loop through the array indexes to write data to that file with student names and letter grades
//
//'q': allows the user to exit the loop with exit() function
//will make while loop false
//
//close program


#include <iostream>
#include <string>
#include <fstream>

const int SIZE = 30;
const int ROWS = 23;
const int COLUMNS = 6;

void storeData(std::string name[], int scores[][COLUMNS]);
void displayMenu();
char getInput();
void letterGrade(char grades[], int scores[][COLUMNS]);
void highestScore(int scores[][COLUMNS], std::string name[]);
void displayStudents(std::string name[], int scores[][COLUMNS], char grades[]);
void searchStudents(std::string name[], int scores[][COLUMNS]);
void saveData(std::string name[], char grades[]);
void findDuplicates(std::string name[]);

int main()
{

	char choice; // used for user menu (switch statement)
	std::string name[ROWS];
	int scores[ROWS][COLUMNS]; // parallel array with grades
	char grades[ROWS]; //parallel array with scores / gradeCalc
	
	storeData(name, scores);
	letterGrade(grades, scores);

	do // loop user menu
	{
		
		displayMenu();
		choice = getInput();

		switch (choice)
		{
		case 'A': // displays students' names, scores, and their grades
		{
			displayStudents(name, scores, grades);
			system("pause");
			break;
		}
		case 'H': // displays student name with overall highest score
		{
			highestScore(scores, name);

			system("pause");
			break;
		}
		case 'S': // search by student name to display all scores
		{
			searchStudents(name, scores);
			
			system("pause");

			break;
		}
		case 'G': // generate StudentGrades.txt and save students' names and letter grades
		{
			saveData(name, grades);
			system("pause");
			break;
		}
		case 'D':
		{
			findDuplicates(name);
			break;
		}
		case 'Q': // quit ( fine as is )
		{
			break;
		}

		} // end of switch statement

	} while (choice != 'Q');

	system("cls");
	std::cout << "Program ending!" << std::endl;

	system("pause");
	return 0;

}

void storeData(std::string name[], int scores[][COLUMNS])
{
	std::string garbage;
	char c; // used to store int data in array
	std::ifstream inputFile;
	inputFile.open("CPSC121dataUpdated.txt");

	if (inputFile.is_open())
	{

		for (int i = 0; i < ROWS; i++)
		{

			{
				if (i > 0)
				{
					getline(inputFile, garbage, '\n');
				}
				getline(inputFile, name[i], ',');	 // assign names to array

			}

			for (int k = 0; k < COLUMNS; k++)
			{
				inputFile >> scores[i][k];
				inputFile >> c;
			}
		}

	}
	else if (!inputFile.is_open())
	{
		std::cout << "Error! File not found!" << std::endl;
		system("pause");
		exit(0);
	}

	inputFile.close();
}

void displayMenu()
{
	system("cls");

	std::cout << "Display all students' names, scores, and their grades: Enter 'A'" << std::endl;
	std::cout << "Display Student name with overall highest score (overall total points in the class): Enter H" << std::endl;
	std::cout << "Search by the student name to display all scores for a particular student: S" << std::endl;
	std::cout << "Generate StudentGrades.txt and save students' names and letter grades : Enter G" << std::endl;
	std::cout << "Search records to find if there are any duplicates : Enter D" << std::endl;
	std::cout << "Quit: Q" << std::endl;

}

char getInput()
{
	char myChoice;
	std::cin >> myChoice;
	myChoice = toupper(myChoice);
	return myChoice; 
}

void letterGrade(char grades[], int scores[][COLUMNS])
{
	// calculate student scores / letter grade and assign letter grade to grades array.

	for (int i = 0; i < ROWS; i++)
	{
		int totalScore = 0; // used to temporarily store the students individual score

		for (int k = 0; k < COLUMNS; k++)

		{
			totalScore = totalScore + scores[i][k]; // sum of the scores for each individual student ( by rows )
		}

		if (totalScore >= 90 && totalScore <= 100)		// the following 'if' statements will assign each indivual student a letter grade based on their total score
		{
			grades[i] = 'A';
		}

		if (totalScore >= 80 && totalScore <= 89)
		{
			grades[i] = 'B';
		}

		if (totalScore >= 70 && totalScore <= 79)
		{
			grades[i] = 'C';
		}

		if (totalScore >= 60 && totalScore <= 69)
		{
			grades[i] = 'D';
		}

		if (totalScore <= 59)								// letter grade assignment ends at this 'if' statement
		{
			grades[i] = 'F';
		}
	}
}

void highestScore(int scores[][COLUMNS],  std::string name[])
{
	std::string highestScore;

	int tempMax = 0;

	for (int i = 0; i < ROWS; i++)
	{
		int sum = 0;

		for (int k = 0; k < COLUMNS; k++)
		{
			sum = sum + scores[i][k];

		}

		if (sum > tempMax)
		{
			tempMax = sum;
			highestScore = name[i];
		}
	}
	std::cout << highestScore << std::endl;
}

void displayStudents(std::string name[], int scores[][COLUMNS], char grades[])
{
	for (int i = 0; i < ROWS; i++)
	{
		std::cout << name[i];
		for (int k = 0; k < COLUMNS; k++)
		{
			std::cout << " " << scores[i][k];
		}
		std::cout << " " << grades[i];
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void searchStudents(std::string name[], int scores[][COLUMNS])
{
	std::string inputName;
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Please enter the name of a student to see their scores:" << std::endl;
	getline(std::cin, inputName);

	for (int i = 0; i < ROWS; i++)
	{
		if (inputName == name[i])
		{
			std::cout << name[i] << "'s scores ";
			for (int k = 0; k < COLUMNS; k++)
			{
				std::cout << scores[i][k] << " ";
			}
		}
	}
	std::cout << std::endl << std::endl;
}

void saveData(std::string name[], char grades[])
{
	std::ofstream outputFile;
	outputFile.open("StudentGrades.txt");

	for (int i = 0; i < ROWS; i++)
	{
		outputFile << name[i] << " " << grades[i] << std::endl;
	}

	std::cout << std::endl << "Data has been saved!" << std::endl;
	outputFile.close();

}

void findDuplicates(std::string name[])
{
	int duplicate = 0; // keep track of the location of a duplicate that is found, ( used to ignore that element when encountering its duplicate)
	int counter; // keeps track times an tempname matches a name in names array
	std::string tempName; // used to compare name in array to elements in another array

	for (int i = 0; i < ROWS; i++)
	{
		counter = 0;
		tempName = name[i];

		for (int k = 0; k < ROWS; k++)
		{
			if (tempName == name[k])
			{
				if (k != duplicate)
				{
					counter++;
				}
			}
		}
		if (counter >= 2)
		{
			duplicate = i; // marks the location in array where the duplicate name is found
			std::cout << "A duplicate name has been found! The student \"" << name[i] << "\" appears in our records " << counter << " times!" << std::endl;
			system("pause");
		}
		
	}
}