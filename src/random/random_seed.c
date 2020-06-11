#include "random_seed.h"
#include "../sha3/fips202.h"

void randombytesFromSeed(const unsigned char* seed, unsigned char* random_array, unsigned long long nbytes) {
    shake256(random_array, nbytes, seed, 32);
}