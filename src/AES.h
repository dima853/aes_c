// #ifndef AES_H
// #define AES_H

// #include <stdint.h>

// #define BLOCK_SIZE 16
// #define ROUNDS 10

// void sub_bytes(uint8_t state[4][4]);
// void shift_rows(uint8_t state[4][4]);
// void mix_column(uint8_t *col);
// uint8_t gmul(uint8_t a, uint8_t b);

// #endif
#ifndef AES_H
#define AES_H

#include <stdint.h>

#define BLOCK_SIZE 16
#define Nb 4        // Number of columns in state
#define Nk 8        // Number of 32-bit words in key (AES-256)
#define Nr 14       // Number of rounds (AES-256)
#define WORD_SIZE 4 // Bytes per word

// Key expansion functions
void keyExpansion(const uint8_t *key, uint8_t *expandedKey);
void rotWord(uint8_t word[4]);
void subWord(uint8_t word[4]);

// AES round functions
void addRoundKey(uint8_t state[4][4], const uint8_t roundKey[4][4]);
void subBytes(uint8_t state[4][4]);
void shiftRows(uint8_t state[4][4]);
void mixColumns(uint8_t state[4][4]);
void invSubBytes(uint8_t state[4][4]);
void invShiftRows(uint8_t state[4][4]);
void invMixColumns(uint8_t state[4][4]);

// Main AES functions
void aesEncrypt(const uint8_t *input, const uint8_t *key, uint8_t *output);
void aesDecrypt(const uint8_t *input, const uint8_t *key, uint8_t *output);

// Helper functions
uint8_t gmul(uint8_t a, uint8_t b);

#endif