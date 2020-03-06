#include <stdio.h>
#include <string.h>
#include "headers/block_cipher.h"
#include "headers/random.h"

#define MAX_SEQUENCE_LENGTH 1024

int main()
{
    char test_num[MAX_SEQUENCE_LENGTH] = "s;vie,bhfjdhruegcndj";
    uint64 test_K = 10000010101010100;
    printf("%s, %llu - number, K before encryption\n", test_num, test_K);
    encrypt((char *)&test_num, &test_K, strlen(test_num));
    printf("%s, %llu - number, K after encryption\n", test_num, test_K);
    decrypt((char *)&test_num, &test_K, strlen(test_num));
    printf("%s, %llu - number, K after decryption\n", test_num, test_K);


    int sequence[MAX_SEQUENCE_LENGTH];
    lemer(sequence, MAX_SEQUENCE_LENGTH, 7, 7, 7, 10);
    for (int i = 0; i < 10; i++) printf("%d\n", sequence[i]);
    return 0;
}