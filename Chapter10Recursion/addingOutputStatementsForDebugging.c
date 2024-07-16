/*
Recursive functions can be particularly challenging to debug. 
Adding output statements can be helpful. 
Furhtermore, an additional trick is to indent the print statements to show the current depth of recursion.
The following program adds a parameter indent to a FindMatch() function that searches a sorted list for an item.
All of FindMatch()'s print statements start with 
printf("% ...", indentAmt, ...);
Indent is typically some number of spaces. 
main() sets indent to three spaces. 
Each recusrive call adds three more spaces. 
Note how the output now clearly shows the recursion depth.
*/

//Output statemetns can help debug recursive functions. especially if indented based on recursion depth.
#include <stdio.h>
#include <string.h>

/*
Finds index of string in array of strings, else -1.
Searches only with index range low to high
Note: Upper/lower case characters matter
*/

const int NUM_ATTENDEES = 6; //Number of total attendees
const int CHAR_LIMIT_PER_NAME = 50; //Limit size of attendee name

int FindMatch(char stringsList[NUM_ATTENDEES][CHAR_LIMIT_PER_NAME], char itemMatch[], int lowVal, int highVal, char indentAmt[CHAR_LIMIT_PER_NAME]) //indentAmt used for print debug
{
    int midVal; //Midpoint of low and high values
    int itemPos; //Position where item found
    int rangeSize; //Remaining range of values to search for match
    char indentNext[50]; //Stores next recursion level indentation amount

    itemPos = -1;

    // Update indent amount for next level of recursion
    strcpy(indentNext, indentAmt);
    strcat(indentNext, "   ");

    printf("%sFind() range %d %d\n", indentAmt, lowVal, highVal);
    rangeSize = (highVal - lowVal) + 1;
    midVal = (highVal + lowVal) / 2;

    if (strcmp(stringsList[midVal], itemMatch) == 0) { //Base case 1: Found at mid
        printf("%sFound person.\n", indentAmt);

    }
}