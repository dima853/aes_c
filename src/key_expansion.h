#ifndef KEY_EXPANSION_H
#define KEY_EXPANSION_H

#include "AES.h"

/**
 * Section 5.2 equation (5.10) of FIPS 197u1
 */
void rotWord(uint8_t *word);

/**
 * Section 5.2 equation (5.11) of FIPS 197u1
 */
void subWord(uint8_t *word);

/**
 * Section 5.2 Algorithm 2 of FIPS 197u1
 * Expects allocated byte arrays for key and expandedKey in right amount to the AES type
 */
void keyExpansion(uint8_t *key, uint8_t *expandedKey);

#endif