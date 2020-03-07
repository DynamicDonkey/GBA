#include <stdio.h>
#include <gb/gb.h>

enum SoundEffect {SFX_stop = 0, SFX_jump = 1};

//This function is used to play a sound. See util.c for the list of sounds and corresponding integer values.
void playSound(UINT8 sound) {

    //No sound, used for debug.
    if(sound == SFX_stop) {
        NR10_REG = 0x00;
        NR11_REG = 0x00;
        NR12_REG = 0x00;
        NR13_REG = 0x00;   
        NR14_REG = 0x00;
    }

    //Jump sound
    if(sound == SFX_jump) {
        NR10_REG = 0x16;
        NR11_REG = 0x40;
        NR12_REG = 0x73;
        NR13_REG = 0x00;   
        NR14_REG = 0xC3;
    }

    //Print a message to the screen if the sound doesnt exist.
    else {
        printf("Sound doesn't exist!\n");
    }

}