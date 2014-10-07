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
    
    int lives;
    int score;
};

typedef struct Player Player;

int randNum();
bool hasLives(Player a, Player b);
bool checkAnswer(int num1, int num2, int answer);

int main(int argc, const char * argv[]) {

    // Initialize Player A
    Player playerA;
    playerA.lives = 3;
    
    // Initialize Player B
    Player playerB;
    playerB.lives = 3;
    
    while (hasLives(playerA, playerB)) {
        
        int num1 = randNum();
        int num2 = randNum();
        char answer[10];
        int answerNum;
        
        printf("Player 1: What does %d plus %d equal?\n", num1, num2);
        fgets(answer,10,stdin);
        answerNum = atoi(answer);
        if (checkAnswer(num1, num2, answerNum)) {
            playerA.score++;
            printf("Correct! Your score is now: %d\n",playerA.score);
        }
        else {
            playerA.lives--;
            printf("Wrong! Your lives is now: %d\n",playerA.lives);
        }
        
    }
    
    printf("Game Over!\n");
    
    return 0;
}

int randNum() {
    
    int r = (int)(arc4random()% 21);
    
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

bool checkAnswer(int num1, int num2, int answer) {
    
    int sum = num1 + num2;
    
    if (answer == sum) {
        return true;
    }
    
    return false;
    
}
