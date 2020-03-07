//System includes
#include <stdio.h>
#include <gb/gb.h>

//Sprite includes
#include "sprites/background.c"

//Map includes.
#include "maps/testmap1.c"

//Function which handles setting the background data, such as the tiles and currently loaded map.
//Also shows the background which was just loaded, then just in case, turns the display on. 
//The final call is just a safety mechanism.
void setBackgroundData() {
    //Sets the background tileset to BackgroundTiles[] found in sprites/background.c, and sets how many tiles there are in the file.
    set_bkg_data(0,7,BackgroundTiles);
    //Sets the loaded background to TestMap1[] found in maps/testmap1.c. Sets the width and height was well to 40x18, used for scrolling.
    set_bkg_tiles(0,0,40,18,TestMap1);
    
    //Show the loaded background from set_bkg_data/tiles.
    SHOW_BKG;
    //Safety mechanism that makes sure the display is on and refreshing.
    DISPLAY_ON;
}

//Gameloop function. Basic logic happens here. In the case of this program, this handles scrolling
//the background every 50ms.
void gameloop() {
    //The ACTUAL gameloop is a while loop that is always true. Since 1 is always 1, the condition is always met.
    while(1) {
        //Scrolls the background set in setBackgroundData() left 1 pixel.
        scroll_bkg(1,0);
        //scroll_bkg(1,0) happens every 50ms
        delay(50);
    }
}

//Main function, where the program begins.
void main() {

    //Calls the setBackgroundData() function which does as advertised. Sets the textures and sets the current map.
    setBackgroundData();
    //Calls the gameloop() function, which in this case just scrolls the background left by 1 pixel every 50ms.
    gameloop();
}