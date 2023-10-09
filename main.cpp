#include <iostream>
#include "functionDeclarations.h"
using namespace std;

 

int main() {
    int size = 0;
    double *longitude = new double [size];
    double *latitude = new double [size];
    char userProgramChoice;
    int userMenuChoice;

    do {
        cout << "=======Main menu please select an option======"<<endl;
        cout << "1) Store  a new location\n2) Delete a location\n3) Show all locations"<<endl;

        cin >>  userMenuChoice;

        if (userMenuChoice == 1){
            double newLong, newLat;
            cout << "Enter the Long: ";
            cin >> newLong;
            cout << "Enter the Lat: ";
            cin >> newLat;

            addLocation(longitude, latitude, size, newLong, newLat);

        } else if (userMenuChoice == 2){
            deleteLocation(longitude, latitude,size);
        } else if (userMenuChoice == 3) {
            showAllLocations(longitude, latitude, size);
        } else {
            cout << "Please select a valid number...\n";
        }

        cout <<"\nRun the program again? (y/n)"<<endl;
        cin >> userProgramChoice;
    } while (userProgramChoice == 'y' || userProgramChoice == 'Y');

    delete[] longitude;
    delete[] latitude;
    return 0;
}

