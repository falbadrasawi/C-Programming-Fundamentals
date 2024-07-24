// include C libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// macros / global constants
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define	NAME 20
#define ROLLS 3
#define DICE 5
#define FALSE 0
#define TRUE 1
#define CATEGORY 13 //2a 
#define COLS 2      //2b

//3a-b
//Declare the structure
struct Player 
{
    int playerNum;
    char playerName[NAME];
    int scoreCard[CATEGORY][COLS];
};


// we will use the enums as indexes to the array that will store the scores
enum scores{one, two, three, four, five, six,
            threekind, fourkind, fullhouse, smstr,
            lgstr, yahtzee, chance};

// function prototypes
void welcomeScreen();
void playGame();
void displayEmptyCard();
void displayDice();
void displayRandomDice();
int rollDie();
void initDice(int dice[DICE]);
void rollDice(int dice[DICE], int keep[DICE]);
int selectDice(int dice[DICE], int keep[DICE]);
void displayRoll(int dice[DICE]);
void trimTrailing(char * str);
int isValid(char data[NAME]);
//Write the function declaration or prototype for functions
//4a-d
void initScorecard();
int selectCategory();
void updateScores();
void displayScoreCard();

// main function
int main()
{
    // call function welcomeScreen
    welcomeScreen();

    // seed the random function
    srand ((unsigned int) time (NULL));

    // call function playGame
    playGame();

    // program executed successfully
    return 0;
}

// welcomeScreen function displays the Yahtzee logo and rules of the game
void welcomeScreen ()
{
	printf ("\tY   Y    A    H   H TTTTT ZZZZZ EEEEE EEEEE\n");
	printf ("\t Y Y    A A   H   H   T      Z  E     E   \n");
	printf ("\t  Y    A   A  HHHHH   T     Z   EEE   EEE \n");
	printf ("\t  Y   A  A  A H   H   T    Z    E     E   \n");
	printf ("\t  Y   A     A H   H   T   ZZZZZ EEEEE EEEEE\n");
	printf ("\n");
	printf ("YAHTZEE GAME RULES\n\n");
    printf("\t 1. Five six-sided dice.\n");
    printf("\t 2. Players roll all five dice.\n");
    printf("\t 3. Players can roll selected dice three times per turn.\n");
    printf("\t 4. Player must score one of the 13 categories per turn.\n");
    printf("\t 5. Players alternate turns.\n");
    printf("\t 6. Game ends when all players score 13 categories.\n");
    printf("\t 7. Player with the highest score wins!\n");
}

void playGame()
{
    // arrays are inherently pointers to index 0 of the array

    //5a Change the data type of variable playerOne from a character array to struct Player
    struct Player playerOne; //5.a
    struct Player playerTwo; //5.b
    
    int currentPlayer = ONE;
    int loop = ZERO;
    int dice[DICE];
    int keep[DICE];

    // prompt player one for their name and store in array playerOne
    printf("\nPlayer One, enter your name\n");
    scanf("%s", playerOne.playerName); //5.c.i
    playerOne.playerNum = ONE; //5.c.ii
    initScorecard(playerOne.scoreCard); //5.c.iii

    // prompt player two for their name and store in array playerTwo
    printf("Player Two, enter your name\n");
    scanf("%s", playerTwo.playerName); //5.c.i
    
    playerTwo.playerNum = TWO; //5.c.ii
    initScorecard(playerTwo.scoreCard); //5.c.iii

    printf("%s and %s let's play Yahtzee!\n", playerOne.playerName, playerTwo.playerName); //5.c

    // iterate two times
    while(loop < TWO)
    {
        if(currentPlayer == playerOne.playerNum) //5.d.i
        {
            // prompt player it is their turn
            printf("%s it is your turn\n", playerOne.playerName); //5.d.ii

            // call function displayEmptyCard
            //displayEmptyCard(); //5.d.ii
            displayScoreCard(playerOne.scoreCard); //5.d.iv

            //call function displayDice
            //displayRandomDice();

            // call function initDice for arrays dice and keep
            initDice(dice);
            initDice(keep);

            // flush the standard input
            fflush(stdin);

            // call function rollDice
            rollDice(dice, keep);

            int category = selectCategory(); //5.d.v.1
            updateScores(dice, playerOne.scoreCard, category); //5.d.v.2
            displayScoreCard(playerOne.scoreCard); //5.d.v.3
            // switch players
            currentPlayer = playerTwo.playerNum; //5.d.vi
        }
        else if(currentPlayer == playerTwo.playerNum) //5.d.i
        {
            // prompt player it is their turn
            printf("\n%s it is your turn\n", playerTwo.playerName); //5.d.ii

            // call function displayEmptyCard
            //displayEmptyCard(); //5.d.iii
            displayScoreCard(playerTwo.scoreCard); //5.d.iv

            // call function displayDice
           //displayRandomDice();


            // call function initDice for arrays dice and keep
            initDice(dice);
            initDice(keep);

            fflush(stdin); 

            // call function rollDice
            rollDice(dice, keep);

            int category = selectCategory(); //5.d.v.1
            updateScores(dice, playerTwo.scoreCard, category); //5.d.v.2
            displayScoreCard(playerTwo.scoreCard); //5.d.v.3

            // switch players
            currentPlayer = playerOne.playerNum; //5.d.vi
        }

        // increment the loop control variable
        loop++;
    }
}

// function displayEmptyCard displays a hardcoded version of a Yahtzee card
void displayEmptyCard()
{
    printf("+----------------------------------+\n");
    printf("| UPPER SECTION  |  LOWER SECTION  |\n");
    printf("|----------------------------------|\n");
    printf("|----------------------------------|\n");
    printf("| Aces   |       | 3 Kind  |       |\n");
    printf("|----------------------------------|\n");
    printf("| Twos   |       | 4 Kind  |       |\n");
    printf("|----------------------------------|\n");
    printf("| Threes |       | Full Hs |       |\n");
    printf("|----------------------------------|\n");
    printf("| Fours  |       | Sm Str  |       |\n");
    printf("|----------------------------------|\n");
    printf("| Fives  |       | Lg Str  |       |\n");
    printf("|----------------------------------|\n");
    printf("| Sixes  |       | Yahtzee |       |\n");
    printf("|----------------------------------|\n");
    printf("| Total  |       | Chance  |       |\n");
    printf("|----------------------------------|\n");
    printf("| Bonus  |       | Total   |       |\n");
    printf("|----------------------------------|\n");
    printf("|----------------------------------|\n");
    printf("|             Game Total   |       |\n");
    printf("+----------------------------------+\n");
}

// function displayDice displays hardcoded dice
void displayDice()
{
    printf("\n+---+ +---+ +---+ +---+ +---+\n");
    printf("| 6 | | 3 | | 5 | | 2 | | 4 |\n");
    printf("+---+ +---+ +---+ +---+ +---+\n");
 }

 // function displayRandomDice displays a randomly generated dice for three rolls
void displayRandomDice()
{
    // looping variable
    int roll;
    // dice variables
    int die1;
    int die2;
    int die3;
    int die4;
    int die5;

    // roll three times
    for(roll = ZERO; roll < ROLLS; roll++)
    {
        die1 = rollDie();
        die2 = rollDie();
        die3 = rollDie();
        die4 = rollDie();
        die5 = rollDie();

        printf("Roll %d\n", (roll + 1));

        printf("+-----+ +-----+ +-----+ +-----+ +-----+\n");
        printf("|  %d  | |  %d  | |  %d  | |  %d  | |  %d  |\n", die1, die2, die3, die4, die5);
        printf("+-----+ +-----+ +-----+ +-----+ +-----+\n");
    }
}

 // randomly rolls a die
int rollDie()
{
    // declare and initialize variable
    int dieValue = rand() % SIX + ONE;
    // return the value
    return dieValue;
}

void initDice(int dice[DICE])
{
    // loop through the five dice
    for(int die = 0; die < DICE; die++)
    {
        // set each die to FALSE
        dice[die] = FALSE;
    }
}

void rollDice(int dice[DICE], int keep[DICE])
{
    int roll = ZERO;

    // iterate through the three rolls
    while(roll < ROLLS)
    {
        printf("Roll %d\n", (roll + 1));

        // iterate through the five dice
        for(int die = 0; die < DICE; die++)
        {
            // only roll dice that have not been selected to keep
            if(keep[die] == FALSE)
            {
                dice[die] = rollDie();
            }
        }

        // display the current roll
        displayRoll(dice);

        // prompt the user to select the dice to keep
        // if the selected dice are not valid, player needs to be prompted again
        // without increasing the roll number

        if(selectDice(dice, keep) == FALSE)
        {
            printf("Selected dice invalid, try again\n");
        }
        else
        {
            roll++;
        }
    } // end while loop for three rolls
}

// prompts player to select the dice they want to keep from their roll
int selectDice(int dice[DICE], int keep[DICE])
{
    // store the player's input
    char input[NAME];
    char data[NAME];

    // variable for each token in string data
    char * value;

    // looping control variable to force user to select valid die
    int valid = FALSE;

    // prompt the user
    printf("\nSelect dice to keep, enter values 1 through 5 with spaces between numbers\n");

    // read the input
    fgets(input, NAME, stdin);

    // remove any trailing spaces
    trimTrailing(input);

    // check if the input is valid before parsing
    strcpy(data, input);
    valid = isValid(data);

    // if the input is not valid, return false
    if(!valid)
        return FALSE;

    // call initDice() for the keep array for each request
    // since users can change their mind for each roll
    initDice(keep);

    // parse the string into each value
    // priming read for first value
    value = strtok(input, " ");

    // loop to end of input
    while(value != NULL )
    {
        int number = atoi(value);

        switch(number)
        {
            case ONE:
                keep[ZERO] = TRUE;
                valid = TRUE;
                break;
            case TWO:
                keep[ONE] = TRUE;
                valid = TRUE;
                break;
            case THREE:
                keep[TWO] = TRUE;
                valid = TRUE;
                break;
            case FOUR:
                keep[THREE] = TRUE;
                valid = TRUE;
                break;
            case FIVE:
                keep[FOUR] = TRUE;
                valid = TRUE;
                break;
            default:
                break;
        }

        // read the next value
        value = strtok(NULL, " ");
    }

    return valid;
}

void displayRoll(int dice[DICE])
{
    printf("+-------+ +-------+ +-------+ +-------+ +-------+\n");
    printf("|       | |       | |       | |       | |       |\n");

    for(int die = 0; die < DICE; die++)
    {
        printf("|   %d   | ", dice[die]);
    }

    printf("\n");
    printf("|       | |       | |       | |       | |       |\n");
    printf("+-------+ +-------+ +-------+ +-------+ +-------+\n");
    printf("   (1)       (2)       (3)       (4)       (5)   \n");
}

int isValid(char data[NAME])
{
    int valid = FALSE;
    char * value;

    // parse the string into each value
    // priming read for first value
    value = strtok(data, " ");

    // loop to end of input
    while(value != NULL )
    {
        // convert the string data to integer
        int number = atoi(value);

        // if data is valid, set valid to TRUE
        if(number >= ONE && number <= FIVE)
        {
            valid = TRUE;
        }
        // else data is invalid, set valid to FALSE and break out of the loop
        else
        {
            valid = FALSE;
            break;
        }

        value = strtok(NULL, " ");
    }

    return valid;
}

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

//6a-c
void initScorecard(int card[CATEGORY][COLS]) { 
    for (int row = 0; row < CATEGORY; ++row) {
        for (int column = 0; column < COLS; ++column) {
            if (column == ZERO) {
                card[row][column] = row;
            }
            else {
                card[row][column] = ZERO;
            }
        }
    }
    printf("This is the end of initScoreCard");
}

//7.a-f
int selectCategory() { //7.a-b
    int select = ZERO; //7.c
    int valid = FALSE; //7.d

    while (valid == FALSE) {
        printf("Select category for dice\n\n"); //7.e.a
        printf("0. Ones\n");
        printf("1. Twos\n");
        printf("2. Threes\n");
        printf("3. Fours\n");
        printf("4. Fives\n");
        printf("5. Sixes\n");
        printf("6. Three of a Kind\n");
        printf("7. Four of a Kind\n");
        printf("8. Full House\n");
        printf("9. Small Straight\n");
        printf("10. Large Straight\n");
        printf("11. Yahtzee\n");
        printf("12. Chance\n");

        scanf("%d", &select); //7.e.b
        fflush(stdin); //7.e.c

        if ((select >= 0) && (select <= 12)) { //7.d
            valid = TRUE; //7.d.i
        }
        else { //7.e
            printf("Your selection was invlaid\n"); //7.e.i
            valid = FALSE; //7.e.ii
        }
    }
    return select; //7.f
}

void updateScores(int dice[DICE], int scoreCard[CATEGORY][COLS], int category) { //8.a-b
        if (category == one) {
            printf("Scoring ONES...\n");
        }
        else if (category == two) {
            printf("Scoring TWOS...\n");
        }
        else if (category == three) {
            printf("Scoring THREES...\n");
        }
        else if (category == four) {
            printf("Scoring FOURS...\n");
        }
        else if (category == five) {
            printf("Scoring FIVES...\n");
        }
        else if (category == six) {
            printf("Scoring SIXES...\n");
        }
        else if (category == threekind) {
            printf("Scoring THREE OF A KIND...\n");
        }
        else if (category == fourkind) {
            printf("Scoring FOUR OF A KIND\n");
        }
        else if (category == fullhouse) {
            printf("Scoring FULL HOUSE...\n");
        }
        else if (category == smstr) {
            printf("Scoring SMALL STRAIGHT...\n");
        }
        else if (category == lgstr) {
            printf("Scoring LARGE STRAIGHT...\n");
        }
        else if (category == yahtzee) {
            printf("Scoring YAHTZEE...\n");
        }
        else if (category == chance) {
            printf("Scoring CHANCE...\n");
        }
    
}

void displayScoreCard(int scores[CATEGORY][COLS]) { //9.a-b
        printf("+----------------------------------+\n");
    printf("| UPPER SECTION  |  LOWER SECTION  |\n");
    printf("|----------------------------------|\n");
    printf("|----------------------------------|\n");
    printf("| Aces   |  %d   | 3 Kind  |  %d   |\n", scores[one][ONE], scores[threekind][ONE]);
    printf("|----------------------------------|\n");
    printf("| Twos   |  %d   | 4 Kind  |  %d   |\n", scores[two][ONE], scores[fourkind][ONE]);
    printf("|----------------------------------|\n");
    printf("| Threes |  %d   | Full Hs |  %d   |\n", scores[three][ONE], scores[fullhouse][ONE]);
    printf("|----------------------------------|\n");
    printf("| Fours  |  %d   | Sm Str  |  %d   |\n", scores[four][ONE], scores[smstr][ONE]);
    printf("|----------------------------------|\n");
    printf("| Fives  |  %d   | Lg Str  |  %d   |\n", scores[five][ONE], scores[lgstr][ONE]);
    printf("|----------------------------------|\n");
    printf("| Sixes  |  %d   | Yahtzee |  %d   |\n", scores[six][ONE], scores[yahtzee][ONE]);
    printf("|----------------------------------|\n");
    printf("| Total  |  %d   | Chance  |  %d   |\n", ZERO, scores[chance][ONE]);
    printf("|----------------------------------|\n");
    printf("| Bonus  |  %d   | Total   |  %d   |\n", ZERO, ZERO);
    printf("|----------------------------------|\n");
    printf("|----------------------------------|\n");
    printf("|             Game Total   |  %d   |\n", ZERO);
    printf("+----------------------------------+\n");
}