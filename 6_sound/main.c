//System includes
#include <stdio.h>

//gbdk includes
#include <gb/gb.h>
#include <gb/sample.h>

void initSound() {

    //Sound registers must be written in this order!
    NR52_REG = 0x80;    // byte 0x80 enables sound.
    NR50_REG = 0x77;    // byte 0x77 sets volume to max, enabling full hardware control 
    NR51_REG = 0xFF;    // byte 0xFF selects which audio channels to use. Current value is all channels. One bit for L channel, one bit for R channel.

}

void gameloop () {
    while (1) {
        UBYTE input = joypad();
        if(input) {

            //0x16 - Channel 1, register 0 settings.
            //7     Unused
            //6-4   Sweep time (update rate) (If 0, sweep is off)
            //3     Sweep dir (1: decrease, 0: increase)
            //2-0   Sweep RtShift amount (If 0, sweep is off.)
            //0001 0110 is 0x16. Sweep time 1, sweep dir increase, shift amount per step 110 (6 dec)
            NR10_REG = 0x16;

            //0x40 - Channel 1, Register 1  - Wave pattern duty and sound length
            // Channels 1, 2, 4
            //7-6   Wave pattern duty cycle 0-3 (12.5%, 25%, 50%, 75%), duty cycle is how long a quad wave is "on" compared to "off" so 50% (2) is equal.
            //5-0   Sound length (Higher number = shorter sound)
            //0100 0000 is 0x40. Duty cycle 1 (25%), wave length 0 (Long)
            NR11_REG = 0x40;

            // chanel 1 register 2: Volume Envelope (Makes the volume get louder or quieter each "tick")
            // On Channels 1 2 and 4
            // 7-4	(Initial) Channel Volume
            // 3	Volume sweep direction (0: down; 1: up)
            // 2-0	Length of each step in sweep (if 0, sweeping is off)
            // NOTE: each step is n/64 seconds long, where n is 1-7	
            // 0111 0011 is 0x73, volume 7, sweep down, step length 3
            NR12_REG = 0x73;  

            // chanel 1 register 3: Frequency LSbs (Least Significant bits) and noise options
            // for Channels 1 2 and 3
            // 7-0	8 Least Significant bits of frequency (3 Most Significant Bits are set in register 4)
            NR13_REG = 0x00;   

            // chanel 1 register 4: Playback and frequency MSbs
            // Channels 1 2 3 and 4
            // 7	Initialize (trigger channel start, AKA channel INIT) (Write only)
            // 6	Consecutive select/length counter enable (Read/Write). When "0", regardless of the length of data on the NR11 register, sound can be produced consecutively.  When "1", sound is generated during the time period set by the length data contained in register NR11.  After the sound is ouput, the Sound 1 ON flag, at bit 0 of register NR52 is reset.
            // 5-3	Unused
            // 2-0	3 Most Significant bits of frequency
            // 1100 0011 is 0xC3, initialize, no consecutive, frequency = MSB + LSB = 011 0000 0000 = 0x300
            NR14_REG = 0xC3;

            delay(100);
        }
    }
}

void main () {

    initSound();
    gameloop();

}