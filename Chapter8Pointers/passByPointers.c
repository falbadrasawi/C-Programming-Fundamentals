//8.1 Why pointers: Pass by pointer example

/*
A challenging but powerful programming construct is called 
a pointer
This sections illustrates one example's beneficial usage of pointers
Namely, pass by pointer function parameters.

A function can only return one value. 
But consider a desired function that converts total inches 
into feet and inches, e.g 95 inches would be converted to 7 feet and 11 inches
To effectively rreturn two values, the function can be defined with two 
pass by pointer parameters,
by putting a * before a parameter name, and & before the corresponding argument variable

The & passes the variable's memory address, known as a pointer, rather than the variable's value
The * before the parameter name indicates the parameter is a pointer.
The function's statements can update each argument variable's memory location,
effectively "returning" a value.
The technique is also known as pass by reference, but the term pass by pointer avoids confusion
with pass by reference parameters in C++ (which are different), and to more accurately describe this technique


*/

//Pass by pointer example. 
#include <stdio.h>
#include <stdlib.h>

//The * before the parameter name indicates the parameter is a pointer. 
void ConvFeetInches (int totDist, int* inFeet, int* inInches) 
{
    *inFeet = totDist / 12;
    *inInches = totDist % 12;
}

int main(void) {
    int initMeasure;
    int resFeet;
    int resIn;

    initMeasure = 45;
    resFeet = 0;
    resIn = 0;

//The & before the argument inidcates that a variable's 
//memory addresses, known as a pointer, 
//is passed to a pass-by-pointer parameter.
    ConvFeetInches(initMeasure, &resFeet, &resIn);
    printf("%d feet %d inches\n", resFeet, resIn);

    return 0;
//Upon return from ConvFeetINches, 
//resFeet and resIn retain their updated values, 
//effectively returning two values
}

/*
Passing to pointers should be used only if two outputs are tightly related, 
like coordinates, calculating change, complimentary colors etc.
*/


