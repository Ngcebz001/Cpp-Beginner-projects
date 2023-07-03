/*
Program: 	Hotel Calculator
Programmer:	Ngcebo Ngcobo
StudentNum: W2PDHYXV9
Date:		06/06/2022
*/

/* This program will receive the cost of renting a room, number of rooms, number of days booked,
and the sales tax then finally output a bill to the user that has the room cost, discount, quantity
of rooms, number of days booked, total cost, sales tax and the final billing amount to the user */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;


//Function Prototypes
void displayMsg(string);
int inputData();
double roomDiscountCalc(double, int, int);
double totalBillingCalc(double, double);
void displayBilling(double, int, int, double, double, double);

//Declaring & initializing constants
const double TEN_ROOM_DISCOUNT = 0.1;
const double TWENTY_ROOM_DISCOUNT = 0.2;
const double THIRTY_ROOM_DISCOUNT = 0.3;
const double THREE_DAY_BOOKING = 0.05;

//Declaring global variables
int discountPercentage;

int main()
{
    //Declaring local variables
    double oneNightCost;
    int numRooms;
    int daysBooked;
    double salesTax;
    double totalCost;
    double totalBilling;

//Prompting the user to enter data about the rooms and costs
    displayMsg("Please enter the cost of renting one room: ");
    cin >> oneNightCost;

    displayMsg("Please enter the number of rooms booked: ");
    numRooms = inputData();

    displayMsg("Please enter the number of days the rooms are booked for: ");
    daysBooked = inputData();

    displayMsg("Please enter the sales tax amount: ");
    cin >> salesTax;
    //converting the sales tax into a decimal value
    salesTax = salesTax / 100;

//Assigning the value returned from the roomDiscountCalc function into the totalCost variable
    totalCost = roomDiscountCalc(oneNightCost, numRooms, daysBooked);

//Assigning the value returning from the totalBillingCalc variable into the totalBilling variable
    totalBilling = totalBillingCalc(totalCost, salesTax);

//Calling the displayBilling 
    displayBilling(oneNightCost, numRooms, daysBooked, totalCost, salesTax, totalBilling);

    return 0;
}

//Function to output a message on the user's screen
void displayMsg(string message)
{
    cout << message << endl;
}

//Function to receive input data from the user
int inputData()
{
    int data;
    cin >> data;
    return data;
}

/*Function that receives the daily room cost, number of roomms and days booked, then calculates
the total cost with discounts factored in*/
double roomDiscountCalc(double dailyCost, int numRooms, int daysBooked)
{
    double stayCost = (dailyCost * numRooms) * daysBooked;
    double costWithDiscount;

    //If statement to determine wthether a discount will be applied to the total cost, and how much discount
    if (numRooms >= 10 && numRooms < 20)
    {
        discountPercentage = 10;
        costWithDiscount = stayCost - (stayCost * TEN_ROOM_DISCOUNT);
    }

    else if (numRooms >= 20 && numRooms < 30)
    {
        discountPercentage = 20;
        costWithDiscount = stayCost - (stayCost * TWENTY_ROOM_DISCOUNT);
    }

    else if (numRooms >= 30)
    {
        discountPercentage = 30;
        costWithDiscount = stayCost - (stayCost * THIRTY_ROOM_DISCOUNT);
    }
    else
    {
        discountPercentage = 0;
        costWithDiscount = stayCost;
    }

    if (daysBooked >= 3)
    {
        return (costWithDiscount - (costWithDiscount * THREE_DAY_BOOKING));
    }

    else
    {
        return costWithDiscount;
    }
}

//Function that calculate the total billing amount from the total cost and the tax value
double totalBillingCalc(double cost, double tax)
{
    double totalBill;
    totalBill = cost + (cost * tax);
    return totalBill;
}

//Function that displays the captured and calculated data on the user's screen
void displayBilling(double roomCost, int rooms, int days, double cost, double tax, double bill)
{

    // Displaying heading

    displayMsg("=============== Final Costs ================");
    displayMsg("____________________________________________");

    // Displaying the user inputted data
    cout << right << setw(25) << "Room Cost per Night: " << left << setw(1) << "R" << setw(20) << roomCost << endl;

    if (days >= 3){
        cout << right << setw(25) << "Discount Percentage: " << left << setw(20) << to_string(discountPercentage) + "% + 5%" << endl;
    }
    else{
        cout << right << setw(25) << "Discount Percentage: " << left << setw(20) << to_string(discountPercentage) + "%" << endl;

    }
    cout << right << setw(25) << "Number of rooms booked: " << left << setw(20) << rooms << endl;
    cout << right << setw(25) << "Number of days booked: " << left << setw(20) << days << endl;

    // Formatting the output
    cout << setprecision(2) << fixed;
    cout << right << setw(25) << "Total amount: " << left << setw(1) << "R" << setw(20) << cost << endl;
    cout << right << setw(25) << "Sales tax: " << left << setw(5) << (tax * 100) << "%" << endl;
    cout << right << setw(25) << "Total Billing: " << left << setw(1) << "R" << setw(20) << bill << endl;
    displayMsg("________________________________________");
}