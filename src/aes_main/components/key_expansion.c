#include "AES.h"
#include "AES.c"

#define WORD_BYTE_SIZE

void rotWord(uint8_t *word)
{
    uint8_t temp = word[0];
    for (int i = 0; i < 3; i++)
    {
        word[i] = word[i + 1];
    }
    word[3] = temp;
}

void subWord(uint8_t *word)
{
    for (int i = 0; i < WORD_BYTE_SIZE; i++)
    {
        word[i] = sbox[word[i]];
    }
}