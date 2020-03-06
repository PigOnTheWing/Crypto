#include "../headers/random.h"

void lemer(int *sequence, int length, int U_0, int M, int C, int p) {
    int i;

    for (i = 0; i < length; i++) {
        U_0 = (U_0 * M + C) % p;
        sequence[i] = U_0;
    }
}