#include "../headers/random.h"

int is_prime(__uint32_t n) {
    long i;

    for (i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void korobov_modification(double_t *sequence, __uint32_t length, __uint32_t U_0, double_t n) {
    int i, left = 0;
    long M = (long) pow(3, n);
    long p, p_desc = 2 * M, p_asc = p_desc;
    double R;

    while (!(left = is_prime(--p_desc)) && !is_prime(++p_asc));

    if (left) {
        p = p_desc;
    }
    else {
        p = p_asc;
    }

    M = p - M;

    for (i = 0; i < length; i++) {
        U_0 = (U_0 * M) % p;
        R = (double)U_0 / p;
        sequence[i] = R;
    }
}

__uint32_t find_periodic_values(const double_t *sequence, __uint32_t length, __uint32_t i1, struct periodic_values *pv) {
    __uint32_t i, i_l;
    double_t i1_num;

    if (length < i1) {
        return -1;
    }

    pv->l = 0;
    pv->L = 0;

    i1_num = sequence[i1];
    for (i = i1 + 1; i < length; i++) {
        if (sequence[i] == i1_num) {
            pv->l = i - i1;
            break;
        }
    }

    if (pv->l == 0) {
        return -1;
    }

    i = 0;
    i_l = pv->l;
    while (sequence[i++] != sequence[i_l++]);
    pv->L = i_l;

    return 0;
}

double_t chi_metric(const double_t *sequence, __uint32_t length, __uint32_t *counts, __uint32_t M) {
    __uint32_t i, j;
    double_t gap = 1.f / M, chi = 0.f, theoretical_chi = (double_t)length / M, tmp;

    memset(counts, 0, sizeof(__uint32_t) * M);

    for (i = 0; i < length; i++) {
        for (j = 0; j <= M; j++) {
            if (sequence[i] <= (double_t)(j + 1) / M) {
                counts[j]++;
                break;
            }
        }
    }

    for (i = 0; i < M; i++) {
        tmp = counts[i] - theoretical_chi;
        chi += (tmp * tmp) / theoretical_chi;
    }

    return chi;
}