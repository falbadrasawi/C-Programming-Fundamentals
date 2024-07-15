/*
RECURSIVE SEARCH FUNCTION

A recursive function is a natural match for the recursive binary search algorithm. 
A function GuessNumber(lowVal, highVal) has parameters that indicate the low and high sides of 
the guessing range. 
The function guesses at the midpoint of the range. 
If the user says lower, the function calls GuessNumber(lowVal, midVal). If the user says higher, the function calls
GuessNumber(midVal + 1, highVal).

The recursive function has an if-statement. The if branch ends th erecursion, known as the BASE CASE.
The aelse branch has recursive calls. SUch an if-else pattern is common in recursive functions. 
*/

//A recursive function carrying out a binary search algorithm.
#include <stdio.h>

void GuessNumber(int lowVal, int highVal) {
    int midVal; //Midpoint of the low and high value
    char userAnswer; //User response

    midVal = (highVal + lowVal) / 2;

    //Prompt user for input
    printf("Is it %d? (l/h/y): ", midVal);
    scanf(" %c", &userAnswer);

    if ( (userAnswer != 'l') && (userAnswer != 'h') ) {
        //Base case: Found Number
    }
    else { //Recusive case: split into lower OR upper half
        if (userAnswer == 'l') { //Guess in lower half
            GuessNumber(lowVal, midVal); //Recursive call
        }
        else { //Guess in upper half
            GuessNumber(midVal + 1, highVal); //Recursive call
        }
    }
}

int main(void) {
    // Print game objective, user input commands
    printf("Choose a number from 0 to 100\n");
    printf("Answer with:\n");
    printf("   l (your number is lower)\n");
    printf("   h (your number is higher)\n");
    printf("   any other key (guess is right).\n");

    //Call recursive function to guess number
    GuessNumber(0, 100);

    return 0;
}

