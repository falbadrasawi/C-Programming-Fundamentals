//7.2 Structs and functions

/*
The struct construct's power is evident when used with functions.
A struct can be used to return multiple values. Although ConvHrMin() 
has two output values, the struct type allows the function to return a single item, 
avoiding a less-clear approach using two pass by reference parameters.
*/

#include <stdio.h>

typedef struct TimeHrMin_struct {
    int hourValue;
    int minuteValue;
} TimeHrMin;

TimeHrMin ConvHrMin(int totalTime) {
    TimeHrMin timeStruct;

    timeStruct.hourValue = totalTime / 60;
    timeStruct.minuteValue = totalTime % 60;

    return timeStruct;
}

int main(void) {
    int inTime; 
    TimeHrMin travelTime;

    printf("Enter total minutes: ");
    scanf("%d", &inTime);

    travelTime = ConvHrMin(inTime);

    printf("Equals: ");
    printf("%d hrs ", travelTime.hourValue);
    printf("%d mins\n", travelTime.minuteValue);

    return 0;
}

//The program prompts the user to enter travel time in minutes,
//then calls the ConvHrMin function to convert travel time to hours and minutes
//Upon return, timeStruct's data members are copied to main's travelTime variable.
//Returning a struct type allows the ConvHrMin function to return a single item 
//instead of using two pass-by-reference parameters.