#ifndef CRYPTO_BLOCK_CIPHER_H
#define CRYPTO_BLOCK_CIPHER_H

#include "feistel.h"

#define BLOCK_SIZE 8

void encrypt(char *ptr, uint64 *K, uint64 length);
void decrypt(char *ptr, uint64 *K, uint64 length);

#endif //CRYPTO_BLOCK_CIPHER_H
