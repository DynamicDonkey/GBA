//System includes
#include <stdio.h>
#include <gb/gb.h>

//General includes
#include "includes/GeneralUtil.c"
#include "includes/SoundUtil.c"

//Sprite includes
#include "sprites/snail.c"
#include "sprites/mazesprites.c"

//Map includes
#include "maps/mazemap.c"

UINT8 playerLocation[2];
const char blankMap[1] = {0x00};

UBYTE debug, hasKey, gameRunning;

void animateSprite(UINT8 spriteIndex, INT8 moveX, INT8 moveY) {
    while(moveX != 0) {
        scroll_sprite(spriteIndex, moveX < 0 ? -1 : 1, 0);
        moveX += (moveX < 0 ? 1 : -1);
        wait_vbl_done();
    }
    while(moveY != 0) {
        scroll_sprite(spriteIndex, 0, moveY < 0 ? -1 : 1);
        moveY += (moveY < 0 ? 1 : -1);
        wait_vbl_done();
    }
}

void initCharacter() {
    set_sprite_data(0,1,SnailTile);
    set_sprite_tile(0,0);
    playerLocation[0] = 16;
    playerLocation[1] = 24;
    move_sprite(0, playerLocation[0], playerLocation[1]);
}

void initDisplay() {
    set_bkg_data(0,4,MazeSprites);
    set_bkg_tiles(0,0,20,18,MazeMap1);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

}

UBYTE canPlayerMove(UINT8 newPlayerX, UINT8 newPlayerY) {
    UINT16 indexTopLeftX, indexTopLeftY, tileIndexTopLeft;
    UBYTE result;

    indexTopLeftX = (newPlayerX - 8) / 8;
    indexTopLeftY = (newPlayerY - 16) /8;
    tileIndexTopLeft = 20 * indexTopLeftY + indexTopLeftX;

    // if(debug) {
    //     printf("%u %u\n",(UINT16)(newPlayerX),(UINT16)(newPlayerY));
    //     printf("%u %u %u\n",(UINT16)indexTopLeftX,(UINT16)indexTopLeftY,(UINT16)tileIndexTopLeft);
    // }

    result = MazeMap1[tileIndexTopLeft] == blankMap[0];

    if(tileIndexTopLeft==321) {
        set_bkg_tiles(1,16,1,1,blankMap);
        hasKey = 1;
        result = 1;
    }
    else if(tileIndexTopLeft==263 & hasKey) {
        set_bkg_tiles(3,13,1,1,blankMap);
        result = 1;
    }
    else if(tileIndexTopLeft==340) {
        gameRunning = 0;
        HIDE_SPRITES;
        printf("\n \n \n \n \n \n \n \n \n      YOU WIN!");
        result = 1;
    }

    return result;
}

void gameloop() {
    while(gameRunning) {
        if(joypad() & J_LEFT) {
            if(canPlayerMove(playerLocation[0]-8,playerLocation[1])) {
                playerLocation[0] -=8;
                animateSprite(0,-8,0);
            }
        }
        else if(joypad() & J_RIGHT) {
            if(canPlayerMove(playerLocation[0]+8,playerLocation[1])) {
                playerLocation[0] +=8;
                animateSprite(0,+8,0);
            }
        }
        else if (joypad() & J_UP) {
            if(canPlayerMove(playerLocation[0],playerLocation[1]-8)) {
                playerLocation[1] -=8;
                animateSprite(0,0,-8);
            }
        }
        else if (joypad() & J_DOWN) {
            if(canPlayerMove(playerLocation[0],playerLocation[1]+8)) {
                playerLocation[1] +=8;
                animateSprite(0,0,+8);
            }
        }

        performantDelay(6);
    }
}

void main() {

    gameRunning = 1;
    initCharacter();
    initDisplay();
    initSound();
    gameloop();


}