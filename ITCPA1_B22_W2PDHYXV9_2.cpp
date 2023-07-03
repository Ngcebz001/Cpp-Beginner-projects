/*
Program: 	Payslip Calculator
Programmer:	Ngcebo Ngcobo
StudentNum: W2PDHYXV9
Date:		06/06/2022
*/

/* This program will receive an employees name, surname, hours worked and whether they've completed
their work in a week, then continue to output a payslip that will display the employee's name,
surname, hours worked, gross pay, bonus if there is one, PAYE tax and final net pay to the user*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function Prototypes
void displayMsg(string);
int inputData();
double calcPay(int);
double overtimePay(int);
double taxDeductions(double);
double bonusCalc(double);
double netPayCalc(double, double, double);
void displayPay(string, string, double, double, double, double, double);

//Declaring & initializing constant variables
const int WEEKLY_CONTRACTED_HOURS = 40;
const int BASE_PAY = 5000;
const int HOURLY_RATE = 600;

int main(){

//Declaring local variables
string employeeName;
string employeeSurname;
int hours;
char workCompleteInWeek;
double grossPay;
double bonus;
double tax;
double netPay;

//Prompting user to enter the employee details, hours worked and whether the work was done in the week
displayMsg("Please enter employee name: ");
cin >> employeeName;

displayMsg("Please enter employee surname: ");
cin >> employeeSurname;

displayMsg("Please enter total hours worked: ");
hours = inputData();

displayMsg("Work completed in the week?: (Y/N)");
cin >> workCompleteInWeek;


/*If the employee has worked over 40 hours, the overtimePay function will be called,
    otherwise the calcPay function will be called */
if (hours > WEEKLY_CONTRACTED_HOURS){
    grossPay = overtimePay(hours);
}

else{
    grossPay = calcPay(hours);
}

/*If the user indicated that the employee did complete their work in the one week, the bonusCalc
    function will be called, otherwise bonus will equal to zero */
if (workCompleteInWeek == 'Y')
{
    bonus = bonusCalc(grossPay);
}
else if(workCompleteInWeek == 'N'){
    bonus = 0;
}

//Calling the taxDeductions function to calculate the PAYE tax
tax = taxDeductions(grossPay);

//Calling the netPayCalc function to calculate the employee's Net Pay
netPay = netPayCalc(grossPay, tax, bonus);

//Calling the displayPay function to display the final results on the user's screen
displayPay(employeeName, employeeSurname, hours, grossPay, bonus, tax, netPay);

return 0;
}

//Function to display a string of text to the user
void displayMsg(string message){
cout << message << endl;
}

//Function to capture data inputted by the user
int inputData(){
    int data;
    cin >> data;
    return data;
}

//Function to calculate the gross pay when hours worked are equal to or below 40
double calcPay(int hours){

    double pay;

    pay = BASE_PAY + (HOURLY_RATE * hours);
    return pay;
}

//Function to calculate the gross pay when hours worked are above 40
double overtimePay(int hours){

    //Declaring local variables
    double overtimePay;
    double overtimeRate = HOURLY_RATE + (HOURLY_RATE * 0.3333);

    //Calculations
    overtimePay = BASE_PAY + (WEEKLY_CONTRACTED_HOURS * HOURLY_RATE) 
    + ((hours - WEEKLY_CONTRACTED_HOURS) * overtimeRate);

    return overtimePay;
}

//Function to calculate the tax deductions from the user's gross pay
double taxDeductions(double pay){
    
    double payeTax = 0.06;
    double taxDeduc;
    taxDeduc = pay * payeTax;
    return taxDeduc;
}

//Function to calculate the user's bonus pay when the condition is met
double bonusCalc(double pay){

    double bonusAmount = 0.08;
    double bonusPay;
    bonusPay = pay * bonusAmount;
    return bonusPay;
}

//Function to calculate the user's total net pay
double netPayCalc(double grossPay, double taxDeduc, double bonusAmount){
    double netPay;
    netPay = grossPay - taxDeduc + bonusAmount;
    return netPay;
}

//Function to display the calculated data on to the user's screen
void displayPay(string name, string surname, double hours, double grossPay, double bonusPay, double tax, double pay)
{

	//Displaying heading
    displayMsg("________________________________________");
    displayMsg("=============== Payslip ================");
    displayMsg("________________________________________");

    //Displaying the user inputted data
	cout << right << setw(20) << "Name: " << left << setw(20) << name << endl;
    cout << right << setw(20) << "Surname: " << left << setw(20) << surname << endl;
	cout << right << setw(20) << "Total Hours Worked: " << left << setw(20) << hours << endl;

    //Formatting the output
    cout << setprecision(2) << fixed;
	cout << right << setw(20) << "Gross Pay: " << left << setw(1) << "R"<< setw(20) << grossPay << endl;

    //Display the bonus amount only if it is above 0
    if (bonusPay > 0){
	cout << right << setw(20) << "Bonus Pay: " << left << setw(1) << "R" << setw(20) << bonusPay << endl;
    }

	cout << right << setw(20) << "PAYE tax: " << left << setw(1) << "R" << setw(20) << tax << endl;
	displayMsg("________________________________________");
	cout << right << setw(20) << "Total Pay: " << left << setw(1) << "R" << setw(20) << pay << endl;
    displayMsg("________________________________________");

}
