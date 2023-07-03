/*
Program: Train data processor
Programer: N. Ngcobo
Date: 11/11/2022

*/

#include <iostream>
#include <fstream>

using namespace std;


//Constant variable declaration
const string FILE_NAME = "Gautraindata.txt";
const int NUM_ROWS = 7;
const int NUM_COL = 5;


//
ifstream inputFile;



//Function to read data from the file and stores it in a 2-dimensional array
void readData(int passengersPer[7][5]){


/*Two for-loops that will read each number from the file*/
for (int arrRow = 0; arrRow < NUM_ROWS; arrRow++){
    for (int arrCol = 0; arrCol < NUM_COL; arrCol++){
        inputFile >> passengersPer[arrRow][arrCol];
    }
}

}


//Function to display the information received from the read file on to the user's screen
void displayInfo(int passengersPer[7][5]){

    for (int arrRow = 0; arrRow < NUM_ROWS; arrRow++){
    for (int arrCol = 0; arrCol < NUM_COL; arrCol++){
        cout << passengersPer[arrRow][arrCol] << " ";
        }
    cout << endl;
    }
    cout << "\n\n";
}

//Function to calculate the average numvber of people per station
void calAverage(int passengersPer[7][5]){
    
    //Declaring the array averages where all the average values will be stored
    double averages[NUM_ROWS];

    //Initializing the variables to be used in the calculations for the average
    double stationTotals[NUM_COL];
    int accSum[NUM_COL];
    int count = 0;

/*Two for loops to pull the values stored in the 2 dimensional array, and calculate their average values*/
for (int arrCol = 0; arrCol < NUM_COL; arrCol++){

    accSum[arrCol] = 0;

    for (int arrRow = 0; arrRow < NUM_ROWS; arrRow++){

        accSum[arrCol] = accSum[arrCol] + passengersPer[arrRow][arrCol];
        count++;

        }
        averages[arrCol] = accSum[arrCol]/NUM_ROWS;
        
    }   

    //Outputting the average values per station on to the user's screen
    cout << "Station Averages: " << endl;
    for (int count = 0; count < NUM_COL; count++){
        cout << "Station " << (count +1) << " = " << averages[count] << endl;
    }
    cout << "\n\n";
}

//Function to find the maximum value of passengers per train
void findHighest(int passengersPer[7][5]){

    //All the maximum values will be stored in an array called max, that accepts 7 values
    int max[NUM_ROWS];

    //Two for-loops to process each row and column to find the maximum value per train
    for (int arrRow = 0; arrRow < NUM_ROWS; arrRow++){
        max[arrRow] = 0;
        for (int arrCol = 0; arrCol < NUM_COL; arrCol++){
            if (passengersPer[arrRow][arrCol] > max[arrRow]){
                max[arrRow] = passengersPer[arrRow][arrCol];
            }
        }
    }

    //Outputting the maximum value per train on to the user's display
    cout << "Highest per Train: " << endl;
    for (int count = 0; count < NUM_ROWS; count++){
        cout << "Train " << (count +1) << " = " << max[count] << endl;
    }

}





//Main function
int main(){


//Variable declarations
int count;
int numPeoplePerTrain[7][5];
double averagePerStation[5];
int max[7];

//Opening the file to extract the data
inputFile.open(FILE_NAME);

//Error checking to see whether the file was found, if not the program will exit
if (!inputFile){
    cout << "File not found" << endl;
    return -1;
}

/*While loop that will read the data from the file until it reaches the 
    end of file. It will do this by calling the readData function */
while (!inputFile.eof()){
readData(numPeoplePerTrain);

}

//Calling the function to display all the acquired data to the user
displayInfo(numPeoplePerTrain);

//Calling the function to calculate the average number of people per station
calAverage(numPeoplePerTrain);

//Calling the function to find the highest number of people per train
findHighest(numPeoplePerTrain);



return 0;
}

