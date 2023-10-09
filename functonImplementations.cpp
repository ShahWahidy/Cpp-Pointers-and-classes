#include <iostream>
#include "functionDeclarations.h"

using namespace std;

void addLocation(double*& longitude, double*& latitude, int& size, double newLong, double newLat) {
    double* newLongitude = new double[size + 1];
    double* newLatitude = new double[size + 1];

    for (int i = 0; i < size; i++) {
        newLongitude[i] = longitude[i];
        newLatitude[i] = latitude[i];
    }
    newLongitude[size] = newLong;
    newLatitude[size] = newLat;

    delete[] longitude;
    delete[] latitude;
    longitude = newLongitude;
    latitude = newLatitude;
    size++;
}

void deleteLocation(double* longitude, double* latitude, int& size) {
    int userDeleteChoice;
    if (size > 0) {
        cout <<"\nPlease select a location to remove"<<endl;
        for (int j = 0; j <= size; j++ ){
            cout<<"\n"<<"["<<j<<"]"<<" Long : "<<longitude[j]<<"  Lat : "<<latitude[j];
        }
        cin >> userDeleteChoice;
        if (userDeleteChoice >= 0 && userDeleteChoice < size) {
            for (int k = userDeleteChoice; k < size - 1; k++) {
                longitude[k] = longitude[k + 1];
                latitude[k] = latitude[k + 1];
            }
            size--;
            cout << "Location deleted successfully." << endl;
        } else {
            cout << "Invalid choice. No location deleted." << endl;
        }
    } else {
        cout <<"No locations found to remove"<<endl;
    }

}

void showAllLocations (double longArray[], double latArray[], int size){
    if (size > 0) {
        for (int j = 0; j < size; j++) {
            cout << "\n" << "[" << j << "] -- " << " Long : " << longArray[j] << "  Lat : " << latArray[j];
        }
    } else {
        cout << "No location found...";
    }
}
