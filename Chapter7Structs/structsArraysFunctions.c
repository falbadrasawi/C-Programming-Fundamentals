//7.4 Structs, arrays, functions: a seat reservation example
/*
A programmer commonly uses structs, arrays, and functions together.
Consider a program that allows a reservation agent to reserve seats for people.
userful for a theater, an airplane, etc.
The below program defines a Seat struct whose data members are a person's first name,
last name, and the amount paid for the seat. 
The program declares an array of 5 seats to represent the 
theater, airplane, etc. 
initializes all seats to being empty, 
(indicated by a first name of "empty")
and then allows a user to enter commands to print all seats, reserve a seat or quit
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Seat_struct {
    char firstName[50];
    char lastName[50];
    int amountPaid;
} Seat;

/* FUNCTIONS FOR SEAT */

void SeatMakeEmpty(Seat* seat) {
    strcpy((*seat).firstName, "empty");
    strcpy((*seat).lastName, "empty");
    (*seat).amountPaid = 0;
}

bool SeatIsEmpty(Seat seat) {
    return (strcmp(seat.firstName, "empty") == 0);
}

void SeatPrint(Seat seat) {
    printf("%s ", seat.firstName);
    printf("%s, ", seat.lastName);
    printf("Paid: %d\n", seat.amountPaid);
}

/* FUNCTIONS FOR ARRAY OF SEAT */

void SeatsMakeEmpty(Seat seats[], int numSeats) {
    int i;

    for (i = 0; i < numSeats; ++i) {
        printf("%d: ", i);
        SeatPrint(seats[i]);
    }
}

int main(void) {
    const int NUM_SEATS = 5;
    char userKey;
    int seatNum;
    Seat allSeats[NUM_SEATS];
    Seat currSeat;

    userKey = "-";

    SeatsMakeEmpty(allSeats, NUM_SEATS);

    while (userKey != 'q') {
        printf("Enter command (p/r/q): ");
        scanf("%c", &userKey);

        if (userKey == 'p') {
            SeatsPrint(allSeats, NUM_SEATS);
            printf("\n");
        }
        else if (userKey == 'r') {
            printf("Enter seat num: ");
            scanf("%d", &seatNum);

            if (!SeatIsEmpty(allSeats[seatNum])) {
                printf("Seat not empty.\n\n");
            }
            else {
                printf("Enter first name: ");
                scanf("%s", currSeat.firstName);
                printf("Enter last name: ");
                scanf("%s", currSeat.lastName);
                printf("Enter amount paid: ");
                scanf("%d", &currSeat.amountPaid);

                allSeats[seatNum] = currSeat;

                printf("Completed.\n\n");
            }
        }
        //FIXME: Add option to delete reservations
        else if (userKey == 'q') {
            printf("Quitting\n");
        }
        else {
            printf("Invalid command\n\n");
        }
    }
    return 0;
}



