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
        itemPos = midVal;
    }
    else if (rangeSize == 1) { //Base Case 2: Not Found
        printf("%sPerson not found.\n", indentAmt);
        itemPos = -1;
    }
    else { //Recursive case: search lower or upper half
        if (strcmp(itemMatch, stringsList[midVal]) < 0) {
            //Search lower half, recursive call
            printf("%sSearching lower half.\n", indentAmt);
            itemPos = FindMatch(stringsList, itemMatch, lowVal, midVal, indentNext);
        }
        else { //Search upper half, recursive call
            printf("%sSearching upper half.\n", indentAmt);
            itemPos = FindMatch(stringsList, itemMatch, midVal + 1, highVal, indentNext);
        }
    }
    printf("%sReturning pos = %d.\n", indentAmt, itemPos);
    return itemPos;
}

int main(void) {
    char attendeesList[NUM_ATTENDEES][CHAR_LIMIT_PER_NAME]; //List of attendees
    char attendeeName[50]; //Name of attendee to match. 50 character limit
    int matchPos; //Matched position in attendee list
    char indentLevel[50]; //Stores indentation (3 Spaces)

    //Omitting part of program that adds attendees
    //Instead, insert some sample attendees in sorted order
    strcpy(attendeesList[0], "Apple, Fiona");
    strcpy(attendeesList[1], "Bottom, Jeans");
    strcpy(attendeesList[2], "Carlton, Weezy");
    strcpy(attendeesList[3], "Doom, MF");
    strcpy(attendeesList[4], "Edinburough, Duke");
    strcpy(attendeesList[5], "Fuller, Nothanksim");

    //prompt user to enter a name to find
    printf("Enter person's name: Last, First: ");
    fgets(attendeeName, CHAR_LIMIT_PER_NAME, stdin);
    attendeeName[strlen(attendeeName) - 1] = '\0'; //remove newline
    strcpy(indentLevel, "   ");

    //Call function to match name, output results
    matchPos = FindMatch(attendeesList, attendeeName, 0, NUM_ATTENDEES - 1, indentLevel);
    if (matchPos >= 0) {
        printf("Found at postion %d.\n", matchPos);
    }
    else {
        printf("Not found. \n");
    }
    return 0;
}