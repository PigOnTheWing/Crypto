#ifndef CRYPTO_FEISTEL_H
#define CRYPTO_FEISTEL_H

#define ROUND_CNT 4

#define KEY(K, i) (K >> i * 8)
#define FEISTEL(L, K) ((L << 9) ^ (~((K >> 11) & L)))

typedef unsigned long long uint64;
typedef unsigned int uint32;

void feistel_encrypt(uint64 *ptr, uint64 *K);
void feistel_decrypt(uint64 *ptr, uint64 *K);

#endif //CRYPTO_FEISTEL_H
