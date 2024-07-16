/*
CREATING A RECURSIVE FUNCTION

Creating a recursive function can be accomplished in two steps.

Write the base case -- Every recursive function must have a case that returns a value without performing a recursive call. 
THat case is called tghe base case.
A programmer may write that part of the function first, and then test.
THere may be multiple base cases.

Write the recursive case -- THe programmer then adds the recursive 
case to the function. 
*/

/*
The following illustrates a simple function that computes the factorial of N
(i.e N!). THe base case is N = 1 or 1! which evaluates to 1. 
The base case is written as 
if (N <= 1) { fact = 1; }. 
The recursive case is used for N > 1, and written as 
else {fact = N * NFact (N - 1);}
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int NFACT(int N) {
    int factResult;

    if (N <= 1) { //BASE CASE
        factResult = 1;
    }
    else { //RECURSIVE CASE
        factResult = N * NFact(N - 1);
    }
    return factResult;
}
// main(): Get N, print NFact (N)

/*
A common error is to not cover all possible base cases in a recursive function. 
Another common error is tp write a recursive function that doesn't always reach a base case. 
Both errors may lead to infinite recursion, causing the program to fail. 

Typically, programmers will use two functions for recursion. 
An "outer" function is intended to be called from other parts of the program, like the function
int CalcFactorial(int inVal). The outer function m,ay check for a valid input value
eg. ensuring inVal is not negative, and then
calling the inner function
Commonly,the inner function has parameters that are mainly
of use as part of the recursion, and need not be part of the outer function, 
thus keeping the outer function more intuitive.
*/

