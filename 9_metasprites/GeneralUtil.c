#include <gb/gb.h>
#include <stdio.h>

/*  
 *      Alternative to the delay(int); function, which pauses the entire system
 *      for a specified amount in ms.
 *      This function only pauses the current function for the specified int value
 *      argument which is how many times the screen refreshes until the following
 *      code is ran.
 */ 
void performantDelay(UINT8 numloops) {
    UINT8 i;
    for(i = 0; i< numloops; i++) {
        wait_vbl_done();
    }
}