#ifndef CRYPTO_FREQUENCY_ANALYSIS_H
#define CRYPTO_FREQUENCY_ANALYSIS_H

#include <string.h>
#include <math.h>
#include <stdlib.h>

struct known_pair {
  char alphabet_letter;
  char text_letter;
};

struct frequency_pair {
  char letter;
  float frequency;
};

void find_frequencies(const char *text, int length, struct frequency_pair *a, int alphabet_length, struct frequency_pair *frequencies);
void decipher(struct frequency_pair *text_frequencies, struct frequency_pair *alphabet_frequencies, int alphabet_length, char *text, int length, struct known_pair *kp, int kp_length);

#endif //CRYPTO_FREQUENCY_ANALYSIS_H
