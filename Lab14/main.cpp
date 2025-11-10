#include "Artist.h"
#include "Artwork.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string userTitle, userArtistName;
    int yearCreated, userBirthYear, userDeathYear;

    // Get Artist Name
    cout << "Welcome to Lab14!" << endl;
    cout << "Please enter the artist's name: ";
    getline(cin, userArtistName);

    // Get Artwork Title
    cout << "Enter the artwork's title: ";
    getline(cin, userTitle);

    // Get Birth Year, Death Year, and Year Created
    cout << "Enter the artist's birth year: ";
    cin >> userBirthYear;

    cout << "Enter the artist's death year: ";
    cin >> userDeathYear;

    cout << "Enter the year the artwork was created: ";
    cin >> yearCreated;

    Artist userArtist =  Artist(userArtistName, userBirthYear, userDeathYear);

    Artwork newArtwork = Artwork(userTitle, yearCreated, userArtist);

    newArtwork.PrintInfo();
}