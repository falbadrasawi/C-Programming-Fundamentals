/*
A program's memory usage typically includes four different regions

Code - the region where the program instructions are stored

Static Memory - the region where global variables (variables declafed outside any function) 
as well as static local variables
(variables declared inside functions starting with the keyword "static") are allocated.
Static variables are allocated once and stay in the same memory location for the duration of a program's execution.

The stack - The region where a function's local variables are
 allocated during a function call. 
 A function call adds local variables to the stack,
  and a return removes them, 
  like adding and removing dishes from a pile;
   hence the term "stack" Because this memory is automatically
    allocated and deallocated, 
    it is also called
    Automatic memory

The heap - The region where the malloc function allocates memory
and where the free function deallocates memory. The region is also
called "free store"
*/

#include <stdio.h>
#include <stdlib.h>

//Program is stored in CODE memory

int myGlobal = 33; //Global variables in STATIC memory

void myFunction() {
    int myLocal; //On STACK because its a local variable
    myLocal = 999;
    printf(" %d", myLocal);
}

int main(void) {
    int myInt; //On STACK because its a local variable
    int* myPtr = NULL; //On STACK because it is a local variable
    myInt = 555;

    myPtr = (int *)malloc(sizeof(int)); //In HEAP
    *myPtr = 222;
    printf("%d %d", *myPtr, myInt);
    free(myPtr); //Deallocated from heap

    myFunction(); //Stack grows, then shrinks

    return 0;
}

