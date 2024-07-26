//7.3 Structs and Arrays

/*
The power of structs become more  evident when used in 
conjunction with arrays.
Consider a TV watching time program where a user can 
enter a country name, and the program outputs the 
daily TV watching hours average for a person in that country
One approach uses the two same-sized arrays, one to hold names,
and the other to hold numbers corresponding to each name. 
Instead of those two arrays, a struct allows for declaration of 
just one array that stores items that each have name and number
data members. 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int MAX_COUNTRY_NAME_LENGTH = 50;

typedef struct CountryTvWatch_struct {
    char countryName[MAX_COUNTRY_NAME_LENGTH];
    int tvMinutes;
} CountryTvWatch;

int main(void) {
    const int NUM_COUNTRIES = 4;

    CountryTvWatch countryList[NUM_COUNTRIES];
    char countryToFind[MAX_COUNTRY_NAME_LENGTH];
    bool countryFound;
    int i;

    strcpy(countryList[0].countryName, "Brazil");
    countryList[0].tvMinutes = 222;
    strcpy(countryList[1].countryName, "India");
    countryList[1].tvMinutes = 119;
    strcpy(countryList[2].countryName, "United Kingdom");
    countryList[2].tvMinutes = 242;
    strcpy(countryList[3].countryName, "United States");
    countryList[3].tvMinutes = 283;

    printf("Enter country name: ");
    scanf("%s", countryToFind);

    countryFound = false;
    for (i = 0; i < NUM_COUNTRIES && !countryFound; ++i) {
        if (strcmp(countryList[i].countryName, countryToFind) == 0)
        {
            countryFound = true;
            printf("People in %s watch\n", countryToFind);
            printf("%d minutes of TV daily.\n", countryList[i].tvMinutes);
        } 
        if (!countryFound) {
            printf("Country not found, try again.\n");
        }
        return 0;
    }
}