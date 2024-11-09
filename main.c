#include "cs457_crypto.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   
    //Ask1 One time pad
    char plaintextAsk1[] = "Hello, World!My name is Christos";
    int length = sizeof(plaintextAsk1) - 1;
    char *key = key_gen(length);
    char *ciphertext;
    char *decrypted_text;

    printf("Text to crypt and decrypt: %s\n", plaintextAsk1);
    ciphertext = one_time_pad_encr(plaintextAsk1, key, length);
    printf("One-time pad Ciphertext: %s\n", ciphertext);
    decrypted_text = one_time_pad_decr(ciphertext, key, length);
    printf("One-time pad Decrypted text: %s\n\n", decrypted_text);

    free(ciphertext);
    free(decrypted_text);

    //Ask2 Affine
    char plaintextAsk2[] = "Hello, World!My name is Christos";
    char *affine_ciphertext;
    char *affine_decrypted_text;

    printf("Text to crypt and decrypt: %s\n", plaintextAsk2);
    affine_ciphertext = affine_encr(plaintextAsk2);
    printf("Affine-Cipher Ciphertext: %s\n", affine_ciphertext);
    affine_decrypted_text = affine_decr(affine_ciphertext);
    printf("Affine-Cipher Decrypted text: %s\n\n", affine_decrypted_text);

    //Ask4 Trithemius
    char plaintextAsk4[] = "Hello";
    char *trithemius_ciphertext;
    char *trithemius_decrypted_text;

    printf("Text to crypt and decrypt: %s\n", plaintextAsk4);
    trithemius_ciphertext = trithemius_encr(plaintextAsk4);
    printf("Trithemius Ciphertext: %s\n", trithemius_ciphertext);
    trithemius_decrypted_text = trithemius_decr(trithemius_ciphertext);
    printf("Trithemius Decrypted text: %s\n\n", trithemius_decrypted_text);

    free(trithemius_ciphertext);
    free(trithemius_decrypted_text);

    //Ask5 Scytale
    char plaintextAsk5[] = "I am hurt very badly help";
    char *encryptedScytale_text;
    char *decryptedScytale_text;

    printf("Text to crypt and decrypt: %s\n", plaintextAsk5);
    encryptedScytale_text = scytale_encr(plaintextAsk5, 5);
    printf("Scytale-Cipher Ciphertext: %s\n", encryptedScytale_text);
    decryptedScytale_text = scytale_decr(encryptedScytale_text, 5);
    printf("Scytale-Cipher Decrypted text: %s\n\n", decryptedScytale_text);

    free(encryptedScytale_text);
    free(decryptedScytale_text);

    //Ask6 Rail Fence
    char plaintextAsk6[] = "WE ARE DISCOVERED.RUN AT ONCE.";
    char *rail_ciphertext;
    char *rail_decrypted_text;

    printf("Text to crypt and decrypt: %s\n", plaintextAsk6);
    rail_ciphertext = rail_fence_encr(plaintextAsk6, 3);
    printf("Rail Fence Ciphertext: %s\n", rail_ciphertext);
    rail_decrypted_text = rail_fence_decr(rail_ciphertext, 3);
    printf("Rail Fence Decrypted text: %s\n", rail_decrypted_text);

    free(rail_ciphertext);
    free(rail_decrypted_text);


    free(key);
    return 0;
}

