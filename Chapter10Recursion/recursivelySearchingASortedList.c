/*
Search is commonly performed to quickly find an item in a sorted list stored in an array or vector.
Consider a list of attendees at a conference, whose names have been stored in alphabetical order in an array or vector.
The following quickly determines whether a particular person is in attendance.

FIndMatch() restricts its search to elements within the range lowVal to highVal. main() initially passes a range of the entire list: 
0 to (list size - 1). FindMatch() compares to the middle element, returning the element's position if matching. If not matching,
FindMatch() checks if the window's size is just one element, returning -1 in that case to indicate the item was not found.
If neither of those two base cases are satisfied, then FindMatch() recursively searches either the lower or upper half of the range as appropriate
*/

//RECURSIVELY SEARCHING A SORTED LIST
#include <stdio.h>
#include <string.h>

/*
Finds index of string in array of strings, else -1.
Searches only with index range low to high
Note: Upper/lower case characters matter
*/

const int NUM_ATTENDEES = 6; //Number of total attendees
const int CHAR_LIMIT_PER_NAME = 50; //Limit size of attendee name

int FindMatch (char stringsList[NUM_ATTENDEES][CHAR_LIMIT_PER_NAME], char itemMatch[], int lowVal, int highVal) {

    int midVal; //Midpoint of low and high values
    int itemPos; //Position where item found
    int rangeSize; //Remaining range of values to search for match

    itemPos = -1; //-1 if not found
    rangeSize = (highVal - lowVal) + 1;
    midVal = (highVal + lowVal) / 2;

    if (strcmp(stringsList[midVal], itemMatch) == 0) { //Base case 1: item found at midVal position
        itemPos = midVal;
    }
    else if (rangeSize == 1) { //Base Case 2: match not found
        itemPos = -1;
    }
    else {                  //Recursive case: search lower or upper half
        if (strcmp(itemMatch, stringsList[midVal]) < 0) { //Search lower half
            itemPos = FindMatch(stringsList, itemMatch, midVal + 1, highVal);
        }
        else {          //Search upper half
            itemPos = FindMatch(stringsList, itemMatch, midVal + 1, highVal);
        }
    }
    return itemPos;
}

int main(void) {
    char attendeesList[NUM_ATTENDEES][CHAR_LIMIT_PER_NAME]; //List of attendees
    char attendeeName[50]; //Name of attendee to match. 50 is CHAR_LIMIT_PER_NAME
    int matchPos; //Matched position in attendee list

    //Omitting part of program that adds attendees
    //Instead, we insert some sample attendees in sorted order
    strcpy(attendeesList[0], "Adams, Mary");
    strcpy(attendeesList[1], "Borwn, Liberty");
    strcpy(attendeesList[2], "Cat, Kitty");
    strcpy(attendeesList[3], "Dawg, Hot");
    strcpy(attendeesList[4], "Elephant, Smellaphant");
    strcpy(attendeesList[5], "Fadi, Albadrasawi");

    //Prompt user to enter a name to find
    printf("Enter a person's name: Last, First: ");
    fgets(attendeeName, CHAR_LIMIT_PER_NAME, stdin);
    attendeeName[strlen(attendeeName) - 1] = '\0'; //remove newline

    // Call function to match name, output results
    matchPos = FindMatch(attendeesList, attendeeName, 0, NUM_ATTENDEES - 1);
    if (matchPos >= 0) {
        printf("Found at position %d.\n", matchPos);
    }
    else {
        printf("Not found. \n");
    }
    return 0;
}