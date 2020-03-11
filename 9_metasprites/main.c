#include <gb/gb.h>
#include <stdio.h>

#include "GameCharacter.c"

#include "GeneralUtil.c"

#include "sprites/GameSprites.c"

struct GameCharacter ship;
struct GameCharacter bug;

UBYTE SpriteSize = 8;


void moveGameCharacter(struct GameCharacter* character, UINT8 x, UINT8 y) {
    move_sprite(character->spriteids[0], x, y);
    move_sprite(character->spriteids[1], x+SpriteSize, y);
    move_sprite(character->spriteids[2], x, y+SpriteSize);
    move_sprite(character->spriteids[3], x+SpriteSize, y+SpriteSize);
}

void initPlayer() {

    ship.x      = 80;
    ship.y      = 130;
    ship.width  = 16;
    ship.height = 16;

    //Load ship sprites[4]
    set_sprite_tile(0,0);
    ship.spriteids[0] = 0;

    set_sprite_tile(1,1);
    ship.spriteids[1] = 1;

    set_sprite_tile(2,2);
    ship.spriteids[2] = 2;

    set_sprite_tile(3,3);
    ship.spriteids[3] = 3;
    moveGameCharacter(&ship, ship.x, ship.y);

}

void initBug() {

    bug.x      = 30;
    bug.y      = 0;
    bug.width  = 16;
    bug.height = 16;

    //Load bug sprites[4]
    set_sprite_tile(4,4);
    bug.spriteids[0] = 4;

    set_sprite_tile(5,5);
    bug.spriteids[1] = 5;

    set_sprite_tile(6,6);
    bug.spriteids[2] = 6;

    set_sprite_tile(7,7);
    bug.spriteids[3] = 7;
    moveGameCharacter(&bug, bug.x, bug.y);
    
}

void initDisplay() {
    set_sprite_data(0,8,GameSprites);
    SHOW_SPRITES;
    DISPLAY_ON;
}

void gameloop() {
    while(1) {
        UBYTE input = joypad();
        if(input & J_LEFT) {
            ship.x -= 2;
            moveGameCharacter(&ship, ship.x, ship.y);
        }
        if(input & J_RIGHT) {
            ship.x +=2;
            moveGameCharacter(&ship, ship.x, ship.y);
        }

        bug.y += 1;
        if(bug.y >= 160) {
            bug.y = 0;
            bug.x = ship.x;
        }
        moveGameCharacter(&bug, bug.x, bug.y);

        performantDelay(1);
    }
}

void main() {
    initPlayer();
    initBug();
    initDisplay();
    gameloop();

}