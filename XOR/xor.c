#include <stdio.h>
#include <stdint.h>

// Encrypts the given message using XOR encryption
void xor_cipher(char *msg, char key, size_t msg_len)
{
    for (size_t i = 0; i < msg_len; ++i)
    {
        msg[i] ^= key; // Perform XOR with the key on each character
    }
}

int main()
{
    // The original secret message in plaintext
    char secret_message[] = "Hello, World!";
    char key = 0x2B; // The key used for encryption

    // Encrypt the secret message using the XOR cipher
    xor_cipher(secret_message, key, sizeof(secret_message) - 1);

    // Print the encrypted message in plaintext
    printf("The encrypted message is: %s\n", secret_message);

    // Decrypt the secret message using the XOR cipher
    xor_cipher(secret_message, key, sizeof(secret_message) - 1);

    // Print the decrypted message in plaintext
    printf("The decrypted message is: %s\n", secret_message);

    return 0;
}
