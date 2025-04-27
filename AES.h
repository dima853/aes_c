#ifndef AES_H
#define AES_H

#include <stdint.h>

#define BLOCK_SIZE 16
#define ROUNDS 10

// Объявления функций
void sub_bytes(uint8_t state[4][4]);
void shift_rows(uint8_t state[4][4]);
void mix_column(uint8_t *col);
uint8_t gmul(uint8_t a, uint8_t b);

#endif