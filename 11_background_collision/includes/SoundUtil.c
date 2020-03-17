#include <stdio.h>
#include <gb/gb.h>

enum SoundEffect {SFX_stop = 0, SFX_jump = 1, SFX_fail = 2, SFX_explode = 3};

void initSound() {
    NR52_REG = 0x80;    // byte 0x80 enables sound.
    NR50_REG = 0x77;    // byte 0x77 sets volume to max, enabling full hardware control 
    NR51_REG = 0xFF;    // byte 0xFF selects which audio channels to use. Current value is all channels. One bit for L channel, one bit for R channel.
}

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
    
    //Game over sound
    if(sound == SFX_fail) {
        NR30_REG = 0x80;
        NR31_REG = 0x00;
        NR32_REG = 0x60;
        NR33_REG = 0xd6;   
        NR34_REG = 0xc6;
    }
    
    //Explode sound
    if(sound == SFX_explode) {
        NR41_REG = 0x0C;
        NR42_REG = 0xC0;
        NR43_REG = 0x67;
        NR44_REG = 0xC0; 
    }
}