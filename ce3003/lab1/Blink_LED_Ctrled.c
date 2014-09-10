//**************************************
//**************************************
//    WARNING
//
//This code is not the same as required
//Please do not follow
//
//**************************************
//**************************************
#include <stdint.h>

#define DE0_LEDs (uint32_t * )(0xA0000000)  // Address of LEDs on DE0 (lowest 10 bits)
#define DE0_SLIDE_SW (volatile uint32_t * )(0xA0001000)

int main (void){ 
    int32_t i ;	
    
    *DE0_LEDs = 0x155;                 // turn on right half LEDs 
    
    while(1) {
        if (1 & *DE0_SLIDE_SW) {
            ; 
        } else {
            for (i=0;i<0x2FFFFF;i++);      // delay		
            *DE0_LEDs ^= 0x3FF;            // toggle all LEDs
        }
    }
}
