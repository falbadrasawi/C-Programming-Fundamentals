#include <stdio.h>
#include <string.h>

void FindNumber(int number, int lowVal, int highVal) {
   int midVal;

   midVal = (highVal + lowVal) / 2;
   printf("%d %d", number, midVal);

   if (number == midVal) {
      printf(" a\n");
   }
   else {
      if (number < midVal) {
         printf(" b\n");
         FindNumber(number, lowVal, midVal);
      }
      else {
         printf(" c\n");
         FindNumber(number, midVal + 1, highVal);
      }
   }
}

int main() {
   int number;

   scanf("%d", &number);
   FindNumber(number, 0, 12);
   
   return 0;
}