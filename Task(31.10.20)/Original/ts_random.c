#include<stdint.h>
#include<stdlib.h>

//random double value from 0 to 1.0
double ts_random()
{
    static __thread unsigned int seed = 0;
    if(seed == 0)
    {
        seed = (uintptr_t)&seed;
    }
    return (double)rand_r(&seed)/RAND_MAX;
}
