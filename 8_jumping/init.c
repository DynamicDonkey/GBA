//System includes
#include <stdio.h>

//gbdk includes
#include <gb/gb.h>
#include <gb/font.h>

//Sprite includes
#include "sprites/CharacterSprite.c"

//Creates a variable that stores the player location, used to set arbitrarily right now
//but will be set dynamically later. 
INT8 playerLocation[2];

/* 
 *      Initialize the display and fonts for printf();
 *      along with turn the display on as a safeguard and
 *      load all sprites available.
 */
void initDisplay() {

    font_t min_font;

    font_init();
    min_font = font_load(font_ibm); //36 tiles
    font_set(min_font);

    DISPLAY_ON;
    SHOW_SPRITES;
    printf("Display init\n");
}

/*
 *      Set the cpu registers to enable sound, set to max volume, and which audio channels to use.
 *      Calling this function is all that is required to enable sound.
 */
void initSound() {
    NR52_REG = 0x80;    // byte 0x80 enables sound.
    NR50_REG = 0x77;    // byte 0x77 sets volume to max, enabling full hardware control 
    NR51_REG = 0xFF;    // byte 0xFF selects which audio channels to use. Current value is all channels. One bit for L channel, one bit for R channel.
    printf("Sound init\n");
}

/*
 *      Initialize a basic character with sprite from CharacterSprite[]
 *      and an arbitrary location of 10,100.
 */
void initCharacter() {
    set_sprite_data(0,8,CharacterSprite);
    set_sprite_tile(0,0);
    playerLocation[0] = 10;
    playerLocation[1] = 100;
    move_sprite(0, playerLocation[0], playerLocation[1]);
    printf("Player init\n");
}