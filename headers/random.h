#ifndef CRYPTO_RANDOM_H
#define CRYPTO_RANDOM_H

#include <math.h>
#include <string.h>

struct periodic_values{
  int L;
  int l;
};

int is_prime(__uint32_t n);
void korobov_modification(double_t *sequence, __uint32_t length, __uint32_t U_0, double_t n);
__uint32_t find_periodic_values(const double_t *sequence, __uint32_t length, __uint32_t i1, struct periodic_values *pv);
double_t chi_metric(const double_t *sequence, __uint32_t length, __uint32_t *counts, __uint32_t M);

#endif //CRYPTO_RANDOM_H
