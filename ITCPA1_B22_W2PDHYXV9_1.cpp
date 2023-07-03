/*
Program: 	Grade Calculator
Programmer:	Ngcebo Ngcobo
StudentNum:     W2PDHYXV9
Date:		07/06/2022
*/

/* This program receives the student's name, surname and testscore from the user and
        outputs the students info alongside the grade corresponding with their testscore.
        The grade is determined by the use of a switch statement */
        
#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes
void displayInfo(string, string, char);

int main(){

//Declaring local variables
string studName, studSurname;
int testscore;
char grade;

//Prompting the user to enter the student's name, surname and testscore
cout << "Please enter the student name: " << endl;
cin >> studName;

cout << "Please enter the student surname: " << endl;
cin >> studSurname;

cout << "Please enter the student's test score: " << endl;
cin >> testscore;

// If statement for when the testscore value can be shared among two grades. 
if (testscore>= 50 && testscore <=64){
    testscore = 50;
}
else if (testscore >= 65 && testscore <= 79){
    testscore = 60;
}

//Switch statement that to assign the student's testscore to the corresponding Grade
switch (testscore/10){

        //In case 0-2 the program will assign the 'F' value to the student's grade.
    case 0:
    case 1:
    case 2:
            grade = 'F';
            break;

    case 3: grade = 'E';
            break;

    case 4: grade = 'D';
            break;
    
    case 5: grade = 'C';
            break;
    
    case 6: 
    case 7:
        grade = 'B';
        break;
    case 8:
    case 9:
    case 10:
        grade = 'A';
        break;
        //The default value statement will be displayed should the user enter a value outside the switch statement
    default: cout << "Invalid selection made" << endl;
}

//Calling the function to display the final results to the user's screen
displayInfo(studName, studSurname, grade);

return 0;
}

/*This function will receive the student's name, surname and grade, then output it in a formatted
manner on the user's screen*/
void displayInfo(string name, string surname, char grade){

        //Output statements
        cout << right << setw(20) << "Student Name: " << left << setw(20) << name << endl;
        cout << right << setw(20) << "Student Surname: " << left << setw(20) << surname << endl;
	cout << right << setw(20) << "Student Grade: " << left << setw(20) << grade << endl;
}