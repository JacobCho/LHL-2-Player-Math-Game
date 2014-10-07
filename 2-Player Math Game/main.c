//
//  main.c
//  2-Player Math Game
//
//  Created by Jacob Cho on 2014-10-07.
//  Copyright (c) 2014 Jacob Cho. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Player {
    
    int lives;
};

typedef struct Player Player;

int randNum();

int main(int argc, const char * argv[]) {

    // Initialize Player A
    Player playerA;
    playerA.lives = 3;
    
    // Initialize Player B
    Player playerB;
    playerB.lives = 3;
    
    int r = randNum();
    
    printf("%d\n", r);
    
    return 0;
}

int randNum() {
    
    int r = (int)(arc4random()% 21);
    
    return r;
}
