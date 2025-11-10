#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Artist::Artist() {
    artistName = "unknown";
    birthYear = -1;
    deathYear = -1;
}

// Parameterized constructor
Artist::Artist(string artistName, int birthYear, int deathYear) {
    this -> artistName = artistName;
    this -> birthYear = birthYear;
    this -> deathYear = deathYear;
}

// Get functions
string Artist::GetName() const {
    return artistName;
}

int Artist::GetBirthYear() const {
    return birthYear;
}

int Artist::GetDeathYear() const {
    return deathYear;
}

// PrintInfo function
void Artist::PrintInfo() const {
    cout << "Artist: " << artistName << " ";

    // Check which format to use
    if (birthYear >= 0 && deathYear >= 0) {

        // Format: (XXXX to YYYY)
        cout << "(" << birthYear << " to " << deathYear << ")";
    } else if (birthYear >= 0 && deathYear < 0) {

        // Format: (XXXX to present)
        cout << "(" << birthYear << " to present)";
    } else {
        // Format: (unknown)
        cout << "(unknown)";
    }

    cout<< endl;
}