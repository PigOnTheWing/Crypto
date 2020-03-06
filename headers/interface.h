#ifndef INTERFACE_H
#define INTERFACE_H

typedef unsigned long long uint64;
typedef unsigned int uint32;

void encrypt(char *ptr, uint64 *K, uint64 length);
void decrypt(char *ptr, uint64 *K, uint64 length);

#endif //INTERFACE_H