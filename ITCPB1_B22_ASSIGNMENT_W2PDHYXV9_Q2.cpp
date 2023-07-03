/*
Program: Bonus Calculator
Programer: N. Ngcobo
Date: 11/11/2022

*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


//Constants Declaration
const int NUM_CONS = 10;
const int NUM_MONTHS = 3;

//Function to format and display the acquired data
void displayInfo(double rate, double totalPay, int salesTotal[NUM_CONS], double bonus[NUM_CONS]){

    cout << setprecision(2) << fixed;

    // Displaying the user inputted data
    cout << "Bonus rate in Decimal form: " << rate << endl;


    // Formatting and displaying the data to the user
    cout <<  "Number " << right << setw(15) << "Sales (R)" << setw(15) << "Bonus (R)" << endl;

    // For loop to process data stored in arrays to display to the user
    for (int index = 0; index < NUM_CONS; index++){
        cout <<  (index+1) << right << setw(18) << salesTotal[index] << setw(17) << bonus[index] << endl;
    }

    //Displaying the total bonuses paid
    cout << "\ntotal Bonus Paid: R" << totalPay << endl;


}

//Function to calculate the total sales, bonus and total bonus paid
void bonusCalc(double rate, double &totalPay, int salesNum[NUM_CONS][NUM_MONTHS], int salesTotal[NUM_CONS], double bonus[NUM_CONS]){


    // For loop to initialize all the elemnents in certain arrays to 0
    for (int count = 0; count < NUM_CONS; count ++){
        salesTotal[count] = 0;
        bonus[count] = 0;
        totalPay = 0;

    }

    // Accumulatively adding up the sales totals by accessing each column per row in the array
    // Looping through the rows
    for (int row = 0; row < NUM_CONS; row++ ){

        // Looping through the columns to add
        for (int col = 0; col < NUM_MONTHS; col++){

            // Adding the sales total in the array
            salesTotal[row] = salesTotal[row] + salesNum[row][col];
        }
    }



    /*For loop to calculate the bonus amount to be paid to each consultant
        Also calculates the total bonuses paid by accumulatively adding the
        bonus to the totalPay variable*/
    for (int index = 0; index < NUM_CONS; index++){

        //Bonus calculation
        bonus[index] = salesTotal[index] * rate;

        //Total bonus paid calculation
        totalPay += bonus[index];
    }

}


int main(){

// Initializing and Storing the array data
int salesNum[NUM_CONS][NUM_MONTHS] = {240000, 350000, 88000,
                                        150000, 70000, 97000,
                                        60000, 45000, 120000,
                                        79000, 240000, 50000,
                                        100000, 100000, 10000,
                                        63000, 70000, 80000,
                                        130000, 45000, 70000,
                                        270000, 55000, 60000,
                                        47000, 48000, 49000,
                                        120000, 130000, 40000};


//Declaring variables
int salesTotals[NUM_CONS];
double rate;
double bonus[NUM_CONS];
double totalPay;


//Receiving the rate from a user input
cout << "Please enter the bonus rate: ";
cin >> rate;

// Calling the function to calculate all values
bonusCalc(rate, totalPay, salesNum, salesTotals, bonus);


// Calling the function to format and display the acquired data
displayInfo(rate, totalPay, salesTotals, bonus);


    return 0;
}



