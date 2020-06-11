/********************************************************************************************
* Hardware-based random number generation function
*
* It uses /dev/urandom in Linux and CNG's BCryptGenRandom function in Windows
*********************************************************************************************/ 

#include "random.h"
#include <stdlib.h>
#if defined(__WINDOWS__)
    #include <windows.h>
    #include <bcrypt.h>
#elif defined(__NIX__)
    #include <unistd.h>
    #include <fcntl.h>
    static int lock = -1;
#endif

#define passed 0 
#define failed 1


static __inline void delay(unsigned int count)
{
    while (count--) {}
}
