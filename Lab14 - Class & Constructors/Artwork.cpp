#include "Artwork.h"
#include <iostream>
using namespace std;

// Default constructor
Artwork::Artwork() {
    title = "unknown";
    yearCreated = -1;

    // Artist will be initialized with Artist's default constructor
}

// Parameterized constructor
Artwork::Artwork(string title, int yearCreated, Artist artist) {
    this->title = title;
    this->yearCreated = yearCreated;
    this->artist = artist;
}

// Get functions
string Artwork::GetTitle()  {
    return title;
}

int Artwork::GetYearCreated() {
    return yearCreated;
}

// PrintInfo Function
void Artwork::PrintInfo() {
    // First, print the artist's info by calling the Artist's PrintInfo()
    artist.PrintInfo();

    // Then print the artwork's title and year created
    cout << "Title: " << title << ", " << yearCreated << endl;
}