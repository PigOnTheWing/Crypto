#include "../headers/rsa.h"

#define MAX_LEN 1024
#define BLOCK_SIZE 4


__uint64_t find_phi(__uint64_t n) {
    __uint64_t phi = -1, i, p, q;

    for (i = (__uint64_t)sqrt(n); i > 1; i --) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            phi = (p - 1) * (q - 1);
        }
    }

    return phi;
}

__uint64_t mod_inv(__uint64_t a, __uint64_t m)
{
    __uint64_t b0 = m, t, q;
    __uint64_t x0 = 0, x1 = 1;
    if (m == 1) return 1;
    while (a > 1) {
        q = a / m;
        t = m, m = a % m, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

__uint64_t modular_pow(__uint64_t base, __uint64_t p, __uint64_t mod) {
    int res = 1;
    base = base % mod;

    if (base == 0) {
        return 0;
    }

    while (p > 0) {
        if (p & 1) {
            res = ((res % mod) * (base % mod)) % mod;
        }

        p = p >> 1;
        base = ((base % mod) * (base % mod)) % mod;
    }
    return res;
}


__uint8_t read_input(char *filename, char *input_arr, __uint64_t length) {
    FILE *fp_read;
    if ((fp_read = fopen(filename, "rb")) == NULL) {
        return -1;
    }

    while (fread(input_arr++, sizeof(char), 1, fp_read) == 1 || length--) ;

    return 0;
}

__int8_t write_output(char *filename, const char *output_arr, __uint64_t length) {
    const char *o_ptr;
    char letter;
    __uint8_t left, right;
    __uint64_t i;
    FILE* fp_write;

    if ((fp_write = fopen(filename, "w+")) == NULL) {
        return -1;
    }

    if (length & 1) {
        return -1;
    }

    for (i = 0, o_ptr = output_arr; i < length; i += 2, o_ptr += 2) {
        left = *o_ptr - '0';
        right = *(o_ptr + 1) - '0';

        letter = left * 10 + right;
        if (fwrite(&letter, sizeof(char), 1, fp_write) != 1) {
            return -1;
        }
    }

    return 0;
}


__int8_t decode(char *filename, __uint64_t n, __uint64_t e) {
    char input[MAX_LEN], num[BLOCK_SIZE + 1], output[MAX_LEN], *o_ptr = output;
    __uint64_t i = 0, d = 0, phi = 0, res = 0, str_len, base = 0;

    phi = find_phi(n);
    d = mod_inv(e, phi);

    memset(input, 0, MAX_LEN);
    memset(num, 0, BLOCK_SIZE + 1);
    read_input(filename, input, MAX_LEN);

    str_len = strlen(input);

    for (i = 0; i < str_len; i += BLOCK_SIZE) {
        strncpy(num, input + i, BLOCK_SIZE);
        base = strtol(num, NULL, 10);
        res = modular_pow(base, d, n);
        sprintf(o_ptr, "%lu", res);

        while (*o_ptr != 0) o_ptr++;

        memset(num, 0, BLOCK_SIZE + 1);
    }

    if (write_output("res.txt", output, strlen(output)) == -1) {
        return -1;
    }

    return 0;
}