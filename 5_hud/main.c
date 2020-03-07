//System includes
#include <stdio.h>

//gbdk includes
#include <gb/gb.h>
#include <gb/font.h>

//Sprite includes
#include "sprites/background.c"

//Map includes
#include "maps/testmap1.c"
#include "maps/windowmap.c"


void setBackgroundData() {
    set_bkg_data(37,7,BackgroundTiles);
    set_bkg_tiles(0,0,40,18,TestMap1);
    
    SHOW_BKG;
    DISPLAY_ON;
}

void showHUD() {
    set_win_tiles(0,0,5,1,WindowMap);
    move_win(7,120);
    SHOW_WIN;
}

void gameloop() {

    while(1) {
        scroll_bkg(1,0);
        delay(50);
    }
}

void main() {

    font_t min_font;

    font_init();
    min_font = font_load(font_min); //36 tiles
    font_set(min_font);

    setBackgroundData();
    showHUD();
    gameloop();
}