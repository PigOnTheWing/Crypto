#include "../headers/feistel.h"

void feistel_encrypt(uint64 *ptr, uint64 *K)
{
    uint32 *L_ptr = (uint32 *)ptr;
    uint32 L = *L_ptr;
    uint32 R = *(L_ptr + 1);
    uint32 prev_L = 0;

    for (int i = 0; i < ROUND_CNT; i++) {
        prev_L = L;
        L = FEISTEL(L, (uint32)KEY(*K, i)) ^ R;
        R = prev_L;
    }
    *L_ptr = R;
    *(L_ptr + 1) = L;
}

void feistel_decrypt(uint64 *ptr, uint64 *K) {
    uint32 *L_ptr = (uint32 *)ptr;
    uint32 L = *L_ptr;
    uint32 R = *(L_ptr + 1);
    uint32 prev_L = 0;

    for (int i = ROUND_CNT - 1; i >= 0; i--) {
        prev_L = L;
        L = FEISTEL(L, (uint32)KEY(*K, i)) ^ R;
        R = prev_L;
    }
    *L_ptr = R;
    *(L_ptr + 1) = L;
}

