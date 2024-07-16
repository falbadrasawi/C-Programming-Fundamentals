// Write the preprocessor command to include the stdio.h header file
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//A3 2.a add the one preprocessor command
#include <string.h>

//define the following macros using the #define directive
#define ONE 1
#define TWO 2
#define NAME 20
#define ZERO 0
#define SIX 6
#define ROLLS 3
//2.a-f defining more macros according to spec
#define THREE 3
#define FOUR 4
#define FIVE 5
#define DICE 5
#define FALSE 0
#define TRUE 1

// function declarations
void welcomeScreen();
void playGame();
void displayEmptyCard();
void displayDice();
void displayRandomDice();
int rollDie();
//more function prototypes for assignment 3
//A3 4.a-f
void initDice();
void rollDice();
int selectDice();
void displayRoll();
int isValid();
void trimTrailing();

enum scores
{
    one,
    two,
    three,
    four,
    fice,
    six,
    theekind,
    fourkind,
    fivekind,
    fullhouse,
    smstr,
    lgstr,
    yahtzee,
    chance
};

// int main, return type int, empty parameter, calls the functions and returns 0;
int main()
{
    welcomeScreen();
    srand((unsigned)time(NULL));
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
//updating function playGame for assignment 3
{
    // declare variables playerOne, playerTwo using macro NAME
    char playerOne[NAME];
    char playerTwo[NAME];
    int currentPlayer = ONE;
    int loop = ZERO;
    int dice[DICE]; //A3 5.a.a-b create one dimensional arrays
    int keep[DICE]; //A3 5.a.a-b create one dimensional arrays

    printf("\nPlayer One, enter your name\n");
    scanf("%s", playerOne);

    printf("\nPlayer Two, enter your name\n");
    scanf("%s", playerTwo);

    printf("%s and %s, let's play Yahtzee\n\n", playerOne, playerTwo);

    // while loop
    while (loop < 2)
    {
        if (currentPlayer == ONE)
        {
            printf("\n%s it is your turn\n", playerOne);
            displayEmptyCard();
            initDice(dice); //A3 5.b.b
            initDice(keep); //A3 5.b.c
            //A3 5.b.a comment out displayRandomDice();
            fflush(stdin); //A3 5.b.d
            rollDice(dice, keep); //A3 5.b.e
            currentPlayer = TWO;
        }

        else if (currentPlayer == TWO)
        {
            printf("\n%s it is your turn\n", playerTwo);
            displayEmptyCard();
            initDice(dice); //A3 5.b.b
            initDice(keep); //A3 5.b.c
            //A3 5.b.a comment out displayRandomDice();
            fflush(stdin); //A3 5.b.d
            rollDice(dice, keep); //A3 5.b.e
            currentPlayer = ONE;
        }
        // increment loop control variable
        loop++;
    }
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
    getchar();
}

void displayRandomDice()
{
    int roll;
    int die1;
    int die2;
    int die3;
    int die4;
    int die5;

    for (roll = ZERO; roll < ROLLS; roll++)
    {
        die1 = rollDie();
        die2 = rollDie();
        die3 = rollDie();
        die4 = rollDie();
        die5 = rollDie();

        // 5 Dice prepared to be programmed accordingly
        printf("+---+ +---+ +---+ +---+ +---+\n");
        printf("| %d | | %d | | %d | | %d | | %d |\n", die1, die2, die3, die4, die5);
        printf("+---+ +---+ +---+ +---+ +---+\n\n");
    }
}

int rollDie()
{
    int dieValue = rand() % 6 + 1;
    return dieValue;
}

//A3 6.a-c
void initDice(int dice[DICE]) {
    for (int i = 0; i < DICE; ++i) {
        dice[i] = ZERO;
    }
}

//A3 7.a-d
void rollDice(int dice[DICE], int keep[DICE]){
    int roll = ZERO;
    while (roll < ROLLS) {
        printf("This is Roll %d\n", roll + 1);
        for(int i = 0; i < DICE; ++i){
            if (keep[i] == FALSE){
                dice[i] = rollDie();
            }
        }
        displayRoll(dice);
        if (selectDice(dice, keep) == FALSE){
            printf("Your selected dice were invalid\n");
        }
        else {
            ++roll;
        }
    }
}

int selectDice(int dice[DICE], int keep[DICE]){
    char input[NAME];
    char data[NAME];
    char * value;
    int valid = FALSE;
    printf("Select the dice you would like to keep\n");
    fgets(input, NAME, stdin);
    trimTrailing(input);
    strcpy(data, input);
    valid = isValid(data);
    if (valid == FALSE) {
        return FALSE;
    }
    initDice(keep);
    value = strtok(input, " ");
    while (value != NULL) {//FIXME logic may be incorrect {
        int number = atoi(value); //It says atio in the spec but this may be an error 8.n
        switch (number){
            case 1:
                keep[0] = TRUE;
                valid = TRUE;
                break;
            case 2:
                keep[1] = TRUE;
                valid = TRUE;
                break;
            case 3:
                keep[2] = TRUE;
                valid = TRUE;
                break;
            case 4:
                keep[3] = TRUE;
                valid = TRUE;
                break;
            case 5:
                keep[4] = TRUE;
                valid = TRUE;
                break;
            default:
                valid = FALSE;
                break;
        }
        value = strtok(NULL," ");
    }
    return valid;
}

//A3 9.a-e
void displayRoll(int dice[DICE]){
    printf("+-----+ +-----+ +-----+ +-----+ +-----+\n");
    for (int i = 0; i < DICE; i++)
    {
        printf("|  %d  | ", dice[i]);
    }
    printf("\n+-----+ +-----+ +-----+ +-----+ +-----+\n");
}

//A3 10.a-f? I closed the spec but I think it was to f.
int isValid(char data[NAME]) {
    char * value;
    int valid = TRUE;
    value = strtok(data," ");
    while (value != NULL) {
        int number = atoi(value);
        if (number >= 1 && number <= 5) {
            valid = TRUE;
        }
        else {
            valid = FALSE;
            break;
        }
     value = strtok(NULL, " ");
    }
    return valid;
}

//A3 11
void trimTrailing(char * str)
{
// Set default index to invalid number
int index = -1;
// loop control variable
int i = 0;
// Find last index of non-white space character
while(str[i] != '\0')
{
if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
{
index = i;
}
i++;
}
// Mark next character to last non-white space character as NULL
str[index + 1] = '\0';
}
