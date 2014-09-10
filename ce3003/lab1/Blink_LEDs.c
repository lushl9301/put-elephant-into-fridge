//************************************************
//   Blink_LEDs.c CE3003’s Lab #1 sample program
//   This program blinks the LEDs on the DE0 board
//
//************************************************
#include <stdint.h>                                // for ISO C99 data type declaration

#define DE0_LEDs (uint32_t * )(0xA0000000)  // Address of LEDs on DE0 (lowest 10 bits)

int main (void){ 
    int32_t i ;	
    
    *DE0_LEDs = 0x3FF;                 // turn on all LEDs 
    
    while(1) {
        for (i=0;i<0x2FFFFF;i++);      // delay		
        *DE0_LEDs ^= 0x3FF;            // toggle all LEDs
    }
}
