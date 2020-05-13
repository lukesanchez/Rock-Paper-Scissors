/*******************************************************************
Program Name: Rock, Paper, Scissors

Description: This program allows a user to play the game Rock, Paper,
Scissors against the computer.             

Created by: Luke Sanchez	      	
Created on: Oct. 15 2019    
Last modified: Oct. 25 2019	
*******************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void flushScanf(void);
int UserInput(void);
int ComputersHand(void);
int GameLogic(int, int);

int main(void){  // main begin

  int numTies = 0, compWins = 0, userWins = 0, compHand = 0, userHand = 0, gameLogic = 0;

  srand(time(NULL)); //seeds random integer using computer's time in seconds. 
  
  printf("Welcome to Rock, Paper, Scissors vs Computer.\n");

  while (userHand != 4){
    compHand = ComputersHand();
    userHand = UserInput();
    gameLogic = GameLogic(compHand, userHand);

    switch (gameLogic){
      case 1: printf("Draw. Computer chooses Rock, You chose Rock.\n");
        numTies += 1;
        break;
      case 2: printf("Draw. Computer chooses Paper, You chose Paper.\n");
        numTies += 1;
        break;
      case 3: printf("Draw. Computer chooses Scissors, You chose Scissors.\n");
        numTies += 1;
        break;
      case 4: printf("You Win! Computer chooses Rock, You chose Paper.\n");
        userWins += 1;
        break;
      case 5: printf("You Lose. Computer chooses Rock, You chose Scissors.\n");
        compWins += 1;
        break;
      case 6: printf("You Lose. Computer chooses Paper, You chose Rock.\n");
        compWins += 1;
        break;
      case 7: printf("You Win! Computer chooses Paper, You chose Scissors.\n");
        userWins += 1;
        break;
      case 8: printf("You Win! Computer chooses Scissors, You chose Rock.\n");
        userWins += 1;
        break;
      case 9: printf("You Lose. Computer chooses Scissors, You chose Paper.\n");
        compWins += 1;
        break;
      case 10: printf("Thanks for playing!\n");
        break;
      case 11: 
        break;
      default: printf("Error, try again.\n");
        break;
    }
  }
  printf("\nYour wins: %d | Computer wins: %d | Ties: %d\n\n", userWins, compWins, numTies);
  return 0;
} // main end

/************************************************************
* Function: flushScanf() clears the input buffer when called
* after a scanf statement. Helps with erroneous user inputs. 
************************************************************/
void flushScanf(void){
  char c;
  while((c = getchar()) != '\n' && c != EOF)
  {
    ;
  }
}

/******************************************************
* Function Name: UserInput()
* Input Parameters: none
*
* Description: This function promts the user to enter
* a Char, then assigns the variable handNum with the 
* relevant value based on the entered Input. The else 
* statement takes care of invalid inputs. 
* 
* Return Value: int handNum, stored in userHand in main
*******************************************************/
int UserInput(void){
  int handNum = 0;
  char hand;
  
  printf("\nPlease enter R, P, S, or Q (for quit): ");
  scanf("%c", &hand);
  flushScanf();

  if (hand == 'R' || hand == 'r'){
    handNum = 1;
    }
  else if (hand == 'P' || hand == 'p'){
    handNum = 2;
  }
  else if (hand == 'S' || hand == 's'){
    handNum = 3;
  }
  else if (hand == 'Q' || hand == 'q'){
    handNum = 4;
  }
  else{
    handNum = 0;
    printf("Enter a valid choice.\n");
  }
return handNum;
}

/******************************************************
* Function Name: ComptersHand()
* Input Parameters: none
*
* Description: This function generates a random int
* from rand() function between 1-3, then assigns that 
* value to local variable int hand. 
* 
* Return Value: int hand, stored as compHand in main
*******************************************************/
int ComputersHand(void){
  int hand = rand() % 3 + 1;
return hand;
}

/******************************************************
* Function Name: GameLogic()
* Input Parameters: int comp, int user
*
* Description: This function evaluates both values of
* compHand and userHand, then assigns the variable 
* int gameLogic a value that is unique to that specific
* combination. The function also checks for the value 
* user == 4, which will exit the while loop in main.
* 
* Return Value: int gamelogic, Posible values: 1-11
*******************************************************/
int GameLogic(int comp, int user){
  int gameLogic = 0;

  if (comp == 1 && user == 1){
    gameLogic = 1;
  }
  else if (comp == 2 && user == 2){
    gameLogic = 2;
  }
  else if (comp == 3 && user == 3){
    gameLogic = 3;
  }
  else if (comp == 1 && user == 2){
    gameLogic = 4;
  }
  else if (comp == 1 && user == 3){
    gameLogic = 5;
  }
  else if (comp == 2 && user == 1){
    gameLogic = 6;
  }
  else if (comp == 2 && user == 3){
    gameLogic = 7;
  }
  else if (comp == 3 && user == 1){
    gameLogic = 8;
  }
  else if (comp == 3 && user == 2){
    gameLogic = 9;
  }
  else if (user == 4){
    gameLogic = 10;
  }
  else{
    gameLogic = 11;
  }
return gameLogic;
}
