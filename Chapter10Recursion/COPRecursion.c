//Endless recursion until broken
#include <stdio.h>

void recurse ( int count ) //Each call gets its own copy of count
{
    printf( " %d\n", count );
    //It is not necessary to increment count since each function's
    //variables are separate 
    //so each count will be initialized one greater
    recurse(count + 1);
}

int main()
{
    recurse (1); //First function call, 
    return 0;
}

//Goes about 1000 recursions until it's like nah bro.