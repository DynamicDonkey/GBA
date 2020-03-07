//System includes
#include <stdio.h>

//gbdk includes
#include <gb/gb.h>
#include <gb/font.h>

//My includes
#include "init.c"
#include "GeneralUtil.c"
#include "SoundUtil.c"


BYTE jumping;           //Determines if the player is currently jumping. 1 == yes, 0 == no.

UINT8 gravity = -2;     //Current speed of gravity, in pixels.
UINT8 jumpSpeed;        //Determines how fast the jump is performed.

UINT8 floorYPos = 100;  //Arbitrary number right now, need proper collision detection.

INT8 wouldHitSurface(UINT8 projectedYPos) {
    if(projectedYPos >= floorYPos) {
        return floorYPos;
    }
    return -1;
}

void jump(UINT8 spriteID, UINT8 spriteLocation[2]) {

    INT8 possibleSurfaceY;

    if(jumping == 0) {
        jumping = 1;
        jumpSpeed = 12;
        playSound(SFX_jump);

    }

    jumpSpeed = jumpSpeed + gravity;

    spriteLocation[1] = spriteLocation[1] - jumpSpeed;
    possibleSurfaceY = wouldHitSurface(spriteLocation[1]);

    if(possibleSurfaceY > -1) {
        jumping = 0;
        move_sprite(spriteID,spriteLocation[0], possibleSurfaceY);
    }
    else {
        move_sprite(spriteID,spriteLocation[0], spriteLocation[1]);
    }
}

void gameloop() {
    while(1) {
        UBYTE input = joypad();
        if(input & J_LEFT) {
            playerLocation[0] = playerLocation[0] - 2;
            move_sprite(0, playerLocation[0], playerLocation[1]);
        }
        if(input & J_RIGHT) {
            playerLocation[0] = playerLocation[0] + 2;
            move_sprite(0, playerLocation[0], playerLocation[1]);
        }
        if((input & J_A) || jumping == 1) {
            jump(0,playerLocation);
        }
        performantDelay(2);
    }
}

void main() {
    initDisplay();
    initSound();
    initCharacter();
    gameloop();
}