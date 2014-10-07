//
//  main.c
//  2-Player Math Game
//
//  Created by Jacob Cho on 2014-10-07.
//  Copyright (c) 2014 Jacob Cho. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Player {
    
    char *name;
    int lives;
    int score;
};

enum {
    addition,
    subtraction,
    multiplication,
    division
} Operator;

typedef struct Player Player;

int randNum(int n);
bool hasLives(Player a, Player b);
bool checkAnswer(int num1, int operator, int num2, int answer);
void playerTurn(Player player, int num1, int operator, int num2);

int main(int argc, const char * argv[]) {

    // Initialize Player A
    Player playerA;
    playerA.lives = 3;
    playerA.name = "Player 1";
    
    // Initialize Player B
    Player playerB;
    playerB.lives = 3;
    playerB.name = "Player 2";
    
    while (hasLives(playerA, playerB)) {
        
        int num1 = randNum(21);
        int num2 = randNum(21);
        int operator = randNum(4);
        char answer[10];
        int answerNum;
   
        // Player 1 takes a turn
        playerTurn(playerA, num1, operator, num2);
        fgets(answer,10,stdin);
        answerNum = atoi(answer);
        if (checkAnswer(num1, operator, num2, answerNum)) {
            playerA.score++;
            printf("Correct! Player 1 score is now: %d\n",playerA.score);
        }
        else {
            playerA.lives--;
            printf("Wrong! Player 1 lives is now: %d\n",playerA.lives);
        }
        
        // Player 2 takes a turn
        num1 = randNum(21);
        num2 = randNum(21);
        operator = randNum(4);
        playerTurn(playerB, num1, operator, num2);
        fgets(answer,10,stdin);
        answerNum = atoi(answer);
        if (checkAnswer(num1, operator, num2, answerNum)) {
            playerB.score++;
            printf("Correct! Player 2 score is now: %d\n",playerA.score);
        }
        else {
            playerB.lives--;
            printf("Wrong! Player 2 lives is now: %d\n",playerA.lives);
        }

    }
    
    printf("Game Over!\n");
    
    return 0;
}

int randNum(int n) {
    
    int r = (int)(arc4random() % n);
    
    return r;
}

bool hasLives(Player a, Player b) {
    
    Player playerA = a;
    Player playerB = b;
    
    if (playerA.lives == 0) {
        printf("Player A loses!\n");
        return false;
    }
    else if (playerB.lives == 0) {
        printf("Player B loses!\n");
        return false;
    }
    
    return true;
}

bool checkAnswer(int num1, int operator, int num2, int answer) {
    
    int sum;
    
    switch (operator) {
        case addition:
            sum = num1 + num2;
            if (answer == sum) {
                return true;
            }
            break;
        case subtraction:
            sum = num1 - num2;
            if (answer == sum) {
                return true;
            }
            break;
        case multiplication:
            sum = num1 * num2;
            if (answer == sum) {
                return true;
            }
            break;
        case division:
            if (num2 == 0) num2 = randNum(21);
            sum = num1 / num2;
            if (answer == sum) {
                return true;
            }
            break;
        default:
            return false;
            break;
    }
    return false;
}

void playerTurn(Player player, int num1, int operator, int num2) {
    
    switch (operator) {
        case addition:
            printf("%s: What does %d + %d equal?\n", player.name, num1, num2);
            break;
        case subtraction:
            printf("%s: What does %d - %d equal?\n", player.name, num1, num2);
            break;
        case multiplication:
            printf("%s: What does %d * %d equal?\n", player.name, num1, num2);
            break;
        case division:
            printf("%s: What does %d / %d equal?\n", player.name, num1, num2);
            break;
        default:
            break;
    }

}
