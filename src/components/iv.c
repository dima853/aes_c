#define BLOCK_SIZE

int secure_encrypt(const unsigned char *plaintext, int plaintext_len,
                   const unsigned char *key,
                   unsigned char **iv, int *iv_len,
                   unsigned char **ciphertext, int *ciphertext_len)
{
    *iv_len = BLOCK_SIZE * iv = malloc(*iv_len);
    if (!*iv)
        return -1;

    *ciphertext_len = plaintext_len;
    *ciphertext = malloc(*ciphertext_len);
    if (!*ciphertext)
    {
        free(*iv);
        return -1;
    }

    if (RAND_bytes(*iv, *iv_len) != 1)
    {
        free(*iv);
        free(*ciphertext);
        return -1;
    }

    aes_cbc_encrypt(plaintext, plaintext_len, key, *iv, *ciphertext);

    return 0;
}