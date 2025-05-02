#include "AES.h"
#include "AES.c"

#define WORD_BYTE_SIZE = 4;

void rotWord(uint8_t *word[4])
{
    uint8_t temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}

void subWord(uint8_t *word[4])
{
    for (int i = 0; i < 4; i++)
    {
        word[i] = sbox[word[i]];
    }
}

/*
    Nb (number of blocks) 4x4 matrix,
    Nk (number of key word) - 8 for 256 aes,
    Nr (number of rounds) - 14 for 256 aes;
*/
void keyExpansion(uint8_t *key, uint8_t *expandedKey)
{
    uint8_t temp[WORD_SIZE];

    memcpy(expandedKey, key, Nk * WORD_SIZE);

    for (int i = Nk; i < Nb * (Nr + 1); i++)
    {
        memcpy(temp, &expandedKey[(i - 1) * WORD_SIZE], WORD_SIZE);

        if (i % Nk == 0)
        {
            rotWord(temp);
            subWord(temp);
            temp[0] ^= rcon[i / Nk - 1];
        }
        else if (Nk > 6 && i % Nk == 4)
        {
            subWord(temp);
        }

        for (int j = 0; j < WORD_SIZE; j++)
        {
            expandedKey[i * WORD_SIZE + j] = expandedKey[(i - Nk) * WORD_SIZE + j] ^ temp[j];
        }
    }
    printExpandedKey(expandedKey, 256);
}