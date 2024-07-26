//7.1 Grouping Data: Struct

/*
Sometimes two data items are really aspects of the same data. 
For example, time might be recorded in hours and minutes,
as in 4 hours and 23 minutes.
Or a point on a plot might be recorded as x = 5, y = 7.
Storing such data in separate varibales, such as 
runTimeHours and runTimeMinutes,
is not as clear as grouping that data into a single variable,
like runTime, which might have subitems runTime.hourValue
and runTime.minuteValue.
 */

/*
The STRUCT construct defines a new type, 
which can be used to declare a variable with subitems.
*/

#include <stdio.h>

typedef struct TimeHrMin_struct {
    int hourValue;
    int minuteValue;
} TimeHrMin;


int main(){
  
    printf("struct example");
    TimeHrMin runTime1;
    TimeHrMin runTime2;
    TimeHrMin runTime3;

    runTime1.hourValue = 5;
    runTime1.minuteValue = 46;
    runTime3.hourValue = runTime1.hourValue;
}

//The struct construct just declares new type; no memory us allocated
//Variable definitions allocate memory for each object's member
//Accesses refer to an object member's memory location. 



