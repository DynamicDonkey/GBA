#include <gb/gb.h>

//Generic character structure: id, position, graphics.
struct GameCharacter {

    UBYTE spriteids[4]; //All chars use 4 sprites in this project.
    UINT8 x;
    UINT8 y;
    UINT8 width;
    UINT8 height;

};