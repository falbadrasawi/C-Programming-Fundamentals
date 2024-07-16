// Write the preprocessor command to include the stdio.h header file
#include <stdio.h>

// define the following macros using the #define directive
#define ONE 1
#define TWO 2
#define NAME 20

// function declarations
void welcomeScreen();
void playGame();
void displayEmptyCard();
void displayDice();

// int main, return type int, empty paramter, calls the functions and returns 0;
int main()
{
    welcomeScreen();
    playGame();
    return 0;
}

// welcomeScreen return type void, empty parameter list, printf YAHTZEE and the game instructions
void welcomeScreen()
{
    printf(" Y     Y   A    H   H TTTTT ZZZZZ  EEEEE  EEEEE\n");
    printf("  Y   Y   A A   H   H   T       Z  E      E\n");
    printf("   Y Y   AAAAA  HHHHH   T     Z    EEEE   EEEE\n");
    printf("    Y   A     A H   H   T   Z      E      E\n");
    printf("    Y   A     A H   H   T  ZZZZZ   EEEEE  EEEEE\n");

    printf("\n\tYAHTZEE GAME RULES\n");
    printf("1. Five six-sided dice.\n");
    printf("2. Players roll all five dice.\n");
    printf("3. Players can roll the seleced dice three times per turn.\n");
    printf("4. Player must score one of the 12 categories per turn.\n");
    printf("5. Players alternate turns.\n");
    printf("6. Game ends when all players score 13 categories.\n");
    printf("7. Player with the highest score wins!\n");
}

// playGame function, return type void, empty parameter list
void playGame()
{
    // declare variables playerOne, playerTwo using macro NAME
    char playerOne[NAME];
    char playerTwo[NAME];
    int currentPlayer = ONE;
    printf("\nPlayer One, enter your name\n");
    scanf("%s", playerOne);

    currentPlayer = TWO;
    printf("\nPlayer Two, enter your name\n");
    scanf("%s", playerTwo);

    printf("%s and %s, let's play Yahtzee\n\n", playerOne, playerTwo);

    currentPlayer = ONE;
    printf("\n%s it is your turn\n", playerOne);
    displayEmptyCard();
    displayDice();

    currentPlayer = TWO;
    printf("\n%s it is your turn\n", playerTwo);
    displayEmptyCard();
    displayDice();
}

// return type void, empty parameter, output pretty scorecard
void displayEmptyCard()
{
    // Followed the scorecard with the figure
    printf(" ___________________________ \n");
    printf("|___________________________|\n");
    printf("|UPPER SECTION|LOWER SECTION|\n");
    printf("|---------------------------|\n");
    printf("|---------------------------|\n");
    printf("| Aces   |     | 3 Kind  |  |\n");
    printf("|---------------------------|\n");
    printf("| Twos   |     | 4 Kind  |  |\n");
    printf("|---------------------------|\n");
    printf("| Threes |     | Full Hs |  |\n");
    printf("|---------------------------|\n");
    printf("| Fours  |     | Sm Str  |  |\n");
    printf("|---------------------------|\n");
    printf("| Fives  |     | Lg Str  |  |\n");
    printf("|---------------------------|\n");
    printf("| Sixes  |     | Yahtzee |  |\n");
    printf("|---------------------------|\n");
    printf("| Total  |     | Chance  |  |\n");
    printf("|---------------------------|\n");
    printf("| Bonues |     | Total   |  |\n");
    printf("|---------------------------|\n");
    printf("| Game Total   |            |\n");
    printf("|___________________________|\n");
}

void displayDice()
{
    // 5 Dice prepared to be programmed accordingly
    printf("+---+ +---+ +---+ +---+ +---+\n");
    printf("| 5 | | 4 | | 3 | | 2 | | 1 |\n");
    printf("+---+ +---+ +---+ +---+ +---+\n\n");
}
