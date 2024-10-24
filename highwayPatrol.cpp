#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void programInformation(){
    // Prints out program information.
    cout << "[Provide some useful information about AHP program]" << endl;
    cout << "including your name, version, and instructions, etc." << endl;
}

void displayResults(int& count, int& ticketsGiven, int& ticketsTotal){
    cout << "Tickets were given to " << ticketsGiven << " out of " << count << " vehicles." << endl;
    if (count != 0) {
        cout << "Percent of ticketed vehicles: " << (static_cast<float>(ticketsGiven) / count) * 100 << "%" << endl;
        cout << "Average ticket amount: $" << (static_cast<float>(ticketsTotal) / ticketsGiven) << endl;
    } else {
        cout << "No vehicles were processed." << endl;
    }
}

// Calculation
void calculation(int& speedLimit, int& vehicleSpeed, string& licensePlate, int& count, int& ticketsGiven, int& ticketsTotal){

    const int base = 120;
    int ticketCost;
    int fee;

    cout << "Vehicle's speed is " << vehicleSpeed << " mph" << endl;

    int speedLimitDifference = vehicleSpeed - speedLimit;

    // Check if the vehicle's speed is above or below the limit.
    if (speedLimitDifference <= 0){
        cout << "Vehicle travelled " << abs(speedLimitDifference) << " miles under the speed limit." << endl;
        cout << "No ticket is issued to " << licensePlate << endl;
        return;
    } else {
        cout << "Vehicle travelled " << speedLimitDifference << " miles over the speed limit." << endl;
    }

    if (speedLimitDifference >= 50){
        cout << "A ticket of $1000 is issued to " << licensePlate << endl;
        ticketsTotal += 1000;
        ticketsGiven++;
        return;
    } else if (speedLimitDifference < 50 && speedLimitDifference >= 20) {
        fee = 10;
    } else {
        fee = 5;
    }

    int ticketAmount = base + fee * speedLimitDifference;
    cout << "A ticket of $" << ticketAmount << " is issued to " << licensePlate << endl;
    ticketsTotal += ticketAmount;
    ticketsGiven++;
}

// Input Data
void inputData(int& speedLimit, int& vehicleSpeed, string& licensePlate, int& count, int& ticketsGiven, int& ticketsTotal){
    // Continues to ask for vehicle/street information.
    // Typing "QUIT" will result in the loop breaking and displayResults() being called.
    while (true) {
        cout << "Enter license plate: " << endl;
        cin >> licensePlate;

        if (licensePlate == "QUIT"){
            break;
        }

        cout << "Enter current vehicle's speed: " << endl;
        cin >> vehicleSpeed;

        cout << "Enter speed limit in zone: " << endl;
        cin >> speedLimit;

        count++;
        calculation(speedLimit, vehicleSpeed, licensePlate, count, ticketsGiven, ticketsTotal);
    }

    displayResults(count, ticketsGiven, ticketsTotal);
}

int main(){
    // Declare ticket variables
    int speedLimit;
    int vehicleSpeed;
    int ticketsTotal = 0;   // Initialize to 0
    string licensePlate;

    // Tracks how many tickets in total were processed
    int count = 0;          // Initialize to 0
    int ticketsGiven = 0;    // Initialize to 0

    // Functions
    programInformation();
    inputData(speedLimit, vehicleSpeed, licensePlate, count, ticketsGiven, ticketsTotal);

    return 0;
}
