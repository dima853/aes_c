#include "AES.h"
#include "AES.c"

#define WORD_BYTE_SIZE = 4;

void rotWord(uint8_t word[4])
{
    uint8_t temp = word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = temp;
}

void subWord(uint8_t word[4])
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
    uint8_t Nb = 4, Nk = 8, Nr = 14;

    uint8_t temp[WORD_BYTE_SIZE]

        for (int i = 0; i < Nk; i++)
    {
        for (int bw = 0; bw < WORD_BYTE_SIZE; bw++)
        {
            expandedKey[i * WORD_BYTE_SIZE + bw] = key[i * WORD_BYTE_SIZE + bw];
        }
    }

    for (int i = Nk; i < Nb * (Nr + 1); i++)
    {
        for (int wb = 0; wb < WORD_BYTE_SIZE; wb++)
        {
            temp[wb] = expandedKey[(i - 1) * WORD_BYTE_SIZE + wb];
        }

        if (i % Nk == 0)
        {
            rotWord(temp);
            subWord(temp);
            temp[0] ^= rcon[i / Nk];
        }

        for (int wb = 0; wb < WORD_BYTE_SIZE; wb++)
        {
            expandedKey[i * WORD_BYTE_SIZE + wb] = expandedKey[(i - Nk) * WORD_BYTE_SIZE + wb] ^ temp[wb];
        }
    }
    printExpandedKey(expandedKey, type);
}