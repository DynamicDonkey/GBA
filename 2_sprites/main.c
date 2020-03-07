//System
#include <gb/gb.h>
#include <stdio.h>

//Sprites
#include "sprites/SmileSprites.c"

//It's the main function. Program starts here, ends when the cart is removed, emulator is closed, etc.
void main () {

    //Creates an unsigned 8-bit integer using given name, starting at 0.
    //This is used for animation starting at the game loop, `while(1){}`
    UINT8 currentSpriteIndex = 0;
    unsigned int rec = 0;           //DEBUG - Create an insigned int to store how many times the gameloop has run.

    //Sets the sprite data.
    //0 is the index of which tile it is, 2 is how many there are, and Smiler is the name of the sprite. 
    //See SmileSprites.c/.h
    set_sprite_data(0, 2, Smiler);
    //Sets the initial position of the sprite.
    move_sprite(0, 88, 78);
    //Show all sprites.
    SHOW_SPRITES;

    //Game loop stuff. Right now this handles sprite animation and scrolling, which happens every 1000 milliseconds.
    //Every 1000 ms, the sprite index is set to 1, then 0. currentSpriteIndex holds the current frame of animation.
    while(1) {
        rec++;
        if(currentSpriteIndex==0) {
            currentSpriteIndex = 1;         //currentSpriteIndex = 1 : :)

        }
        else {
            currentSpriteIndex = 0;         //currentSpriteIndex = 0 : :|
        }
        //Sets the sprite data to the currentSpriteIndex, causing the face of the sprite to change from :| to :). Cute if you ask me <3
        set_sprite_tile(0, currentSpriteIndex);
        delay(1000);
        //Scrolls the sprite by 10 pixels every 1000 ms.
        scroll_sprite(0, 10, 0);

        printf("%d\n", rec);    //DEBUG - Print how many times the gameloop has run.
    }

}