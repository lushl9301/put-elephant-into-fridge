//************************************************
//   Blink_LEDs.c CE3003’s Lab #1 sample program
//   This program blinks the LEDs on the DE0 board
//
//************************************************
#include <stdint.h>                                // for ISO C99 data type declaration

#define DE0_7SEG_DISP (uint32_t *)(0xA0004000)// Address of LEDs on DE0 (lowest 10 bits)
#define DE0_SLIDE_SW (volatile uint32_t * )(0xA0001000)
uint8_t sevenSegCode[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int main (void){ 
    int a, b;
    while(1) {
        
        a = *DE0_SLIDE_SW & 0x0F;
        b = (*DE0_SLIDE_SW & 0x3C0) >> 6;
        a += b;
        b = (int)a / 10;
        a = (int)a % 10;
        //DE0_7SEG_DISP = sevenSegCode[*DE0_SLIDE_SW & 0x3FF];
	
        //*DE0_7SEG_DISP = sevenSegCode[b] << 8;
        *DE0_7SEG_DISP = sevenSegCode[b] << 8 | sevenSegCode[a];
    }
}
