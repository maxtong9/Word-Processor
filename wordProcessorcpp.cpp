/*This is the SPRING 2017 TERM PROJECT
created by:*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
//Function Prototypes
void menu1();
void menu2();
void openFileExist();
void openFileNew();
void quitProgram();
void substitute();
void copy();
void locate();
void delet();
void move();
void type();
void paste();
void insert();
void replace();
void goToLine();
void save();

//Global variables which can be used throughout all functions
const int SIZE = 100;
string lineData[SIZE] = { "" }; //Array indexes are 0-99
int currentLine = 0; //Current line 0-99 to correspond with the array

int main ()
{
	char fileName[SIZE];
	for (int i = 0; i < SIZE; i++)//Purpose is to define all array values to test to see the output.
	{
		lineData[i] = "";
	}
	//Here is where the program actually starts
	int men1choice,
		men2status = 1,
		men1status = 1;

	char men2choice;//menu choice/status variables
	cout << "Welcome to the word editor. " <<endl << endl; //Beginning welcome message

	while (men1status != 0)
	{
		menu1();//call to menu1

		cin >> men1choice; //user input menu choice
		while (men1choice != 1 && men1choice != 2 && men1choice != 3) //Makes sure menu choice is within range.
		{
			static int flag = 0;
			cout << "\aERROR: Please enter a valid option. ";
			cin >> men1choice;
			flag++;
			if (flag > 10)
			{
				cout << endl << "\a\a\aERROR:Program failiure. Please restart the program. "; //Bug fix to prevent infinite loop when character is entered
				exit(0);
			}
		}
		//Initiates appropriate call to function based upon menu 1 choice
		if (men1choice == 1)
		{
		

		}
 
		else if (men1choice == 2)
		{
			

		}
		else if (men1choice == 3)
		{
				quitProgram();
				men2choice = 0;
		}


		//Assuming user did not quit program with choice 3
		do
		{
			menu2(); //displays menu 2
			cin >> men2choice;
			//Range check *ADD*
			switch (men2choice)
			{
				case 's':
				case 'S': substitute();
					break;
				case 'c':
				case 'C': copy();
					break;
				case 'l':
				case 'L': locate();
					break;
				case 'D':
				case 'd': delet();
				break;
				case 'm':
				case 'M': move();
					break;
				case 't':
				case 'T': type();
					break;
				case 'p':
				case 'P': paste();
					break;
				case 'i': 
				case 'I': insert();
					break;
				case 'r':
				case 'R': replace();
					break;
				case 'q':
				case 'Q': quitProgram();
				case 'g':
				case 'G': goToLine();
					break;
				case 'V': 
				case 'v': save();
					break;
					men2status = 0;		  
					break;
				default: cout << "Please Enter a valid Character. ";
			}
		}while (men2status != 0);
	}
}

void substitute ()
{
	cout <<"substitute function\n";
}
void copy ()
{
	cout << "copy function\n";
}
void locate ()
{
	cout << "Locate function\n";
}
void delet ()
{
	cout << "Delete function \n";
}
void move()
{
	//Prompt the user to enter the number of lines they would like to move down.
	int lineChoice;
	cout << "How many lines would you like to move down? ";
	cin >> lineChoice;

	while (lineChoice <= 0)
	{
		cout << "\aERROR. Please input a positive number of lines to print. ";
		cin >> lineChoice;
	}
	cout << "-----------------------------"<< endl;
	for (int i = currentLine, r = 0; (i < SIZE && r < lineChoice && lineData[i] != ""); i++, r++)
	{
		cout << i + 1 << ". " << lineData[i];
		cout << endl;
		currentLine = i;
		if (lineData[i+1] == "")
			cout << "Next Line does not exist. Use the insert function to create new lines. ";
	}
	cout <<  "-----------------------------" << endl;
	cout << "The current line is now line " << (currentLine + 1) << endl;
}
void type()
{
	cout << "\nTYPE:\n";
	char var; //holds small menu variable
	int numLines; //holds how many lines to edit
	cout << "The current line is line " << (currentLine + 1) << ". How many lines would you like to see? ";
	cin >> numLines;
	while (numLines <= 0)
	{
		cout <<"Please enter a positive number of lines. ";
		cin >>numLines;
	}
	for (int i = currentLine, r = 0; (i < SIZE && r < numLines); i++, r++)
	{
		cout << i + 1 << ". ";
		cout << lineData[i] << endl;
		currentLine = i;
		

	}

	
}
void paste ()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << i+1 << ". " <<  lineData[i]<< endl;
	}
}
void insert ()
{
	char letter; //holds choice for next prompt
	cout << "INSERT:\n\n";
	cout << "You are currently on line " << (currentLine + 1) << ". Inserting lines over existing lines will overwrite existing lines. Would you like to change the current line? Y: Yes\tN: No";
	cin >> letter;
	switch (letter)
	{
		case 'y': 
		case 'Y': goToLine();
			break;
	}
	int var; //holds how many lines will be "added" to the array/eventually file
	cout << "How many lines would you like to insert? ";
	cin >> var;
	while (var <=0)
	{
		cout << "Please enter a positive number for the number of lines. ";
		cin >> var;
	}
	cin.ignore(100, '\n');
	for (int i = (currentLine), r = 0; (r < var && i < SIZE); i++, r++)
	{
		cout << (i+1) << ". ";
		getline (cin, lineData[i]);
		currentLine = i;
	}
	

}
void replace()
{
	cout << "Replace function\n";
}
void goToLine()
{
	int line; //holds user input of line variable before conversion to array
	cout << "Which Line would you like to go to? ";
	cin >> line;
	while (!(line >= 1 && line <= 100))
	{
		cout << "Please enter a line between 1-100 ";
		cin >> line;
	}

	currentLine = (line-1);
}
void save()
{

}





void openFileExist()
{
	cout << "open existing File function\n";
}
void openFileNew()
{
	cout << "open new file function\n";
}
void quitProgram()
{
	cout << "Quit Program function. will be loaded function.\n ";
	exit(1);
}
void menu1 ()
{
	cout << "Please Choose an option by entering a number: \n";
	cout << "1. Create a New Document" << endl;
	cout << "2. Process an Existing Document" << endl;
	cout << "3. Quit" << endl;
}

void menu2()
{
	cout << endl << "What would you like to do? \nPlease enter a";
	cout << " character for your choice: " << endl << endl;
	cout << setw(40) << left << "S: Substitute/oldstring/newstring" << "C: Copy" << endl;
	cout << setw(40) << "L: Locate/String" << "D: Delete" << endl;
	cout << setw(40) << "M: Move" << "T: Type" << endl;
	cout << setw(40) << "P: Paste" << "I: Insert" << endl;
	cout << setw(40) << "R: Replace" << "G: Go to Line #" << endl;
	cout << setw(40) << "V: Save" << "Q: Quit" << endl;
}


		