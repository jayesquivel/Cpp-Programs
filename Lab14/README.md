Given main(), complete the Artist class (in files Artist.h and Artist.cpp) with constructors to initialize an artist's
information, get member functions, and a PrintInfo() member function. 
The default constructor should initialize the artist's name to "unknown" and the years of birth and death to -1. PrintInfo() displays "Artist:", then a space, then
the artist's name, then another space, then the birth and death dates in one of three formats:
    
    1. (XXXX to YYYY) if both the birth and death years are nonnegative
    2. (XXXX to present) if the birth year is nonnegative and the death year is negative 
    3. (unknown) otherwise

Complete the Artwork class (in files Artwork.h and Artwork.cpp) with constructors to initialize an artwork's
information, get member functions, and a PrintInfo() member function. 
The default constructor should initialize the title to "unknown", the year created to -1. PrintInfo() displays an artist's information by calling the PrintInfo()
function in the Artist class, followed by the artwork's title and the year created. Declare a private field of type
Artist in the Artwork class.

Example 1, if input is:
```
Pablo Picasso
Three Musicians
1881
1973
1921
```
1881 and 1973 are the birth and death years respectively for Pablo Picasso, and 1921 is the year the artwork "Three Musicians" was created.
The output should be:
```
Artist: Pablo Picasso (1881 to 1973)
Title: Three Musicians, 1921
```

Example 2, if input is:
```
Brice Marden
Distant Muses
1938
-1
2000
```
The output should be:
```
Artist: Brice Marden (1938 to present)
Title: Distant Muses, 2000
```
Example 3, if input is:
```
Banksy
Balloon Girl
-1
-1
2002
```
The output should be:
```
Artist: Banksy (unknown)
Title: Balloon Girl, 2002
```
