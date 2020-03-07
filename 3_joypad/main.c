//System includes
#include <stdio.h>
#include <gb/gb.h>

//Sprite includes.
#include "sprites/SmileSprites.c"

void main() {

    // Create the variable for the gameloop function, type void and takes no arguments.
    void gameloop(void);

    // Creates an unsigned 8 bit integer with a value of 0 by the name of currentSpriteIndex, useless
    //in this file but it's good to keep it here for animations later down the line.
    UINT8 currentSpriteIndex = 0;

    //Sets the sprite data.
    //0 is the index of which tile it is, 2 is how many there are, and Smiler is the name of the sprite. 
    //See SmileSprites.c/.h
    set_sprite_data(0,2,Smiler);
    set_sprite_tile(0,0);
    //Sets the initial position of the sprite.
    move_sprite(0,88,78);
    //Show all sprites loaded.
    SHOW_SPRITES;
    //Call the gameloop function, written below.
    gameloop();
}

void gameloop() {

    //While loop that is always checking for controls. Up, down, left, right, etc. each by 10 pixels.
    while(1) {
        switch(joypad()) {
            case J_LEFT:
                scroll_sprite(0,-10,0); //Left is negative X, second number.
                break;
            case J_RIGHT:
                scroll_sprite(0,10,0); //Right is positive X, second number.
                break;
            case J_UP:
                scroll_sprite(0,0,-10); //Up is negative Y, third number.
                break;
            case J_DOWN:
                scroll_sprite(0,0,10);  //Down is positive Y, fourth number.
                break;
        }
        //Only run the gameloop once every 1/10 of a second.
        delay(100);
    }
}