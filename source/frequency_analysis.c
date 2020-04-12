#include "../headers/frequency_analysis.h"

#define SIGN(x) (x > 0) - (x < 0)

int comp(const void *a, const void *b) {
    const struct frequency_pair *arg1 = a, *arg2 = b;
    float delta = arg1->frequency - arg2->frequency;
    return -1 * (SIGN(delta)) * ceilf(fabsf(delta));
}

int complete_sort(struct frequency_pair *alphabet, struct frequency_pair *text, int alphabet_len) {
    int i, j, count = 0;
    struct frequency_pair tmp;

    for (i = 0; i < alphabet_len; i++) {
        for (j = count; j < alphabet_len; j++) {
            if (text[i].frequency == alphabet[j].frequency && i != j) {
                tmp = text[i];
                text[i] = text[count];
                text[count] = tmp;

                tmp = alphabet[j];
                alphabet[j] = alphabet[count];
                alphabet[count] = tmp;

                count++;
                break;
            }
        }
    }
    return count;
}

void find_frequencies(const char *text, int length, struct frequency_pair *a, int alphabet_length, struct frequency_pair *frequencies) {
    float char_cnt;
    char *i;
    struct frequency_pair *j;

    for (j = a; j < a + alphabet_length; j++, frequencies++) {
        char_cnt = 0;
        for (i = strchr(text, (int)j->letter); i < text + length; i++) {
            if (i == NULL) {
                break;
            }

            if (*i == j->letter) {
                char_cnt++;
            }
        }
        frequencies->frequency = char_cnt * 100 / (float)length;
        frequencies->letter = j->letter;
    }
}
void decipher(struct frequency_pair *text_frequencies, struct frequency_pair *alphabet_frequencies, int alphabet_length, char *text, int length, struct known_pair *kp, int kp_length) {
    int j, count = 0;
    char *i;
    struct known_pair *kp_ptr;
    struct frequency_pair *alphabet_ptr, *text_ptr;

    find_frequencies(text, length, alphabet_frequencies, alphabet_length, text_frequencies);

    count = complete_sort(alphabet_frequencies, text_frequencies, alphabet_length);
    qsort(alphabet_frequencies + count, alphabet_length - count, sizeof(struct frequency_pair), comp);
    qsort(text_frequencies + count, alphabet_length - count, sizeof(struct frequency_pair), comp);

    for (i = text; i < text + length; i++) {
        for (j = 0, kp_ptr = kp; j < kp_length; j++, kp_ptr++) {
            if (*i == kp_ptr->text_letter) {
                *i = kp_ptr->alphabet_letter;
                break;
            }
        }
        for (j = 0, alphabet_ptr = alphabet_frequencies, text_ptr = text_frequencies; j < alphabet_length; j++, alphabet_ptr++, text_ptr++) {
            if (*i == text_ptr->letter) {
                *i = alphabet_ptr->letter;
                break;
            }
        }
    }
}