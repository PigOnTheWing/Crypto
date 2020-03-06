#include "../headers/block_cipher.h"

void encrypt(char *ptr, uint64 *K, uint64 length) {
    uint64 i = 0;
    uint64 block_cnt = length / BLOCK_SIZE;
    uint64 *block_ptr = (uint64 *)ptr, *init_vector = K;

    if (length % BLOCK_SIZE)
        block_cnt++;

    for (i = 0; i < block_cnt; block_ptr++, i++) {
        *block_ptr = *init_vector ^ *block_ptr;
        feistel_encrypt(block_ptr, init_vector);
        init_vector = block_ptr;
    }
}

void decrypt(char *ptr, uint64 *K, uint64 length) {
    uint64 i = 0;
    uint64 block_cnt = length / BLOCK_SIZE;
    uint64 *block_ptr = (uint64 *)ptr, init_vector = *K, pre_cipher;

    if (length % BLOCK_SIZE)
        block_cnt++;

    for (i = 0; i < block_cnt; block_ptr++, i++) {
        pre_cipher = *block_ptr;
        feistel_decrypt(block_ptr, &init_vector);
        *block_ptr = init_vector ^ *block_ptr;
        init_vector = pre_cipher;
    }
}