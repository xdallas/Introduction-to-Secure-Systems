#include "cs457_crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Ask1 One time pad
char *key_gen(int length)
{
    char *key = malloc(length);
    FILE *urandom = fopen("/dev/urandom", "rb");
    fread(key, 1, length, urandom);
    fclose(urandom);
    return key;
}

// Every character of the plaintext is XORed with the corresponding character of the key
char *one_time_pad_encr(char *plaintext, char *key, int length)
{
    char *ciphertext = malloc(length);
    int i;
    for (i = 0; i < length; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
    ciphertext[length] = '\0';
    return ciphertext;
}

// Every character of the ciphertext is XORed with the corresponding character of the key
char *one_time_pad_decr(char *ciphertext, char *key, int length)
{
    char *plaintext = malloc(length);
    int i;
    for (i = 0; i < length; i++)
    {
        plaintext[i] = ciphertext[i] ^ key[i];
    }
    plaintext[length] = '\0';
    return plaintext;
}

// Ask2 Affine

// The encryption function for the affine cipher first converts the plaintext to numbers, and then applies the encryption function
char *affine_encr(char *plaintext)
{
    int i;
    char x;
    char y;
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        x = plaintext[i];
        if (x >= 'a' && x <= 'z')
        {
            x = x - 'a';
            y = (5 * x + 8) % 26;
            plaintext[i] = 'a' + y;
        }
        else if (x >= 'A' && x <= 'Z')
        {
            x = x - 'A';
            y = (5 * x + 8) % 26;
            plaintext[i] = 'A' + y;
        }
        else if (x == ' ')
        {
            plaintext[i] = ' ';
        }
    }
    return plaintext;
}

// The decryption function for the affine cipher first converts the ciphertext to numbers, and then applies the decryption function
char *affine_decr(char *ciphertext)
{
    int i;
    char x;
    char y;
    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        x = ciphertext[i];
        if (x >= 'a' && x <= 'z')
        {
            x = x - 'a';
            y = (21 * (x - 8)) % 26;
            if (y < 0)
            {
                y = y + 26;
            }
            ciphertext[i] = 'a' + y;
        }
        else if (x >= 'A' && x <= 'Z')
        {
            x = x - 'A';
            y = (21 * (x - 8)) % 26;
            if (y < 0)
            {
                y = y + 26;
            }
            ciphertext[i] = 'A' + y;
        }
        else if (x == ' ')
        {
            ciphertext[i] = ' ';
        }
    }
    return ciphertext;
}

// Ask4 Trithemius

// The encryption function for the Trithemius cipher shifts the letters of the plaintext by a counter
char *trithemius_encr(char *plaintext)
{
    char *ciphertext = malloc(200 * sizeof(char));
    int counter = 0;
    int i = 0;
    // The counter is incremented by 1 for each letter of the plaintext
    while (plaintext[i] != '\0')
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = 'A' + (plaintext[i] - 'a' + counter) % 26;
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + counter) % 26;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
        counter++;
        i++;
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

// The decryption function for the Trithemius cipher shifts the letters of the ciphertext by a counter
char *trithemius_decr(char *ciphertext)
{
    char *plaintext = malloc(200 * sizeof(char));
    int counter = 0;
    int i = 0;
    // The counter is incremented by 1 for each letter of the ciphertext
    while (ciphertext[i] != '\0')
    {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
        {
            plaintext[i] = 'a' + (ciphertext[i] - 'a' - counter) % 26;
            if (plaintext[i] < 'a')
            {
                plaintext[i] = plaintext[i] + 26;
            }
        }
        else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
        {
            plaintext[i] = 'A' + (ciphertext[i] - 'A' - counter) % 26;
            if (plaintext[i] < 'A')
            {
                plaintext[i] = plaintext[i] + 26;
            }
        }
        else if (ciphertext[i] == ' ')
        {
            plaintext[i] = ' ';
        }
        else
        {
            plaintext[i] = ciphertext[i];
        }
        counter++;
        i++;
    }
    plaintext[i] = '\0';
    return plaintext;
}

// Ask5 Scytale

// The encryption function for the Scytale cipher writes the plaintext in a matrix with a number of columns equal to the rod diameter
char *scytale_encr(char *plaintext, int rod_diam)
{
    // Remove spaces and special characters
    int length = strlen(plaintext);
    char *cleaned_plaintext = malloc((length + 1) * sizeof(char));
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            cleaned_plaintext[count] = plaintext[i];
            count++;
        }
    }
    cleaned_plaintext[count] = '\0';

    length = strlen(cleaned_plaintext);
    int rows = ceil((double)length / rod_diam);

    char *ciphertext = malloc((length + rows) * sizeof(char));
    int count2 = 0;

    // The ciphertext is obtained by reading the matrix by columns
    for (int i = 0; i < rod_diam; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            int index = i + j * rod_diam;
            if (index < length)
            {
                ciphertext[count2] = cleaned_plaintext[index];
                count2++;
            }
        }
    }

    ciphertext[count2] = '\0';
    free(cleaned_plaintext);
    return ciphertext;
}

// The decryption function for the Scytale cipher writes the ciphertext in a matrix with a number of rows equal to the rod diameter
char *scytale_decr(char *ciphertext, int rod_diam)
{
    int length = strlen(ciphertext);
    int rows = ceil((double)length / rod_diam);

    char *plaintext = malloc((length + 1) * sizeof(char));
    int count2 = 0;

    // The plaintext is obtained by reading the matrix by rows
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rod_diam; j++)
        {
            int index = j * rows + i;
            if (index < length)
            {
                plaintext[count2] = ciphertext[index];
                count2++;
            }
        }
    }

    plaintext[count2] = '\0';
    return plaintext;
}

// Ask6 Rail Fence

// The encryption function for the Rail Fence cipher writes the plaintext in a matrix with a number of rows equal to the number of rails
char *rail_fence_encr(char *plaintext, int rails)
{
    // Remove spaces and punctuation
    char *clean_plaintext = malloc(strlen(plaintext) * sizeof(char));
    int clean_count = 0;
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            clean_plaintext[clean_count++] = plaintext[i];
        }
    }
    clean_plaintext[clean_count] = '\0';

    int length = strlen(clean_plaintext);
    char *ciphertext = malloc((length + rails) * sizeof(char));
    int count = 0;
    // The ciphertext is obtained by reading the matrix by rows
    for (int i = 0; i < rails; i++)
    {
        for (int j = i; j < length; j = j + rails * 2 - 2)
        {
            ciphertext[count] = clean_plaintext[j];
            count++;
            if (i > 0 && i < rails - 1 && j + (rails - i - 1) * 2 < length)
            {
                ciphertext[count] = clean_plaintext[j + (rails - i - 1) * 2];
                count++;
            }
        }
        if (i < rails - 1)
        {
            ciphertext[count] = ' ';
            count++;
        }
    }
    ciphertext[count] = '\0';
    free(clean_plaintext);
    return ciphertext;
}

// The decryption function for the Rail Fence cipher writes the ciphertext in a matrix with a number of rows equal to the number of rails
char *rail_fence_decr(char *ciphertext, int rails)
{
    int length = strlen(ciphertext);
    char *plaintext = malloc((length + 1) * sizeof(char));
    int cycle_length = 2 * (rails - 1);
    int count = 0;

    // The plaintext is obtained by reading the matrix by rows
    for (int i = 0; i < length; i = i + cycle_length)
    {
        plaintext[i] = ciphertext[count];
        count++;
    }
    for (int i = 1; i < rails - 1; i++)
    {
        for (int j = i; j < length; j = j + cycle_length)
        {
            plaintext[j] = ciphertext[count++];
            if (j + cycle_length - 2 * i < length)
            {
                plaintext[j + cycle_length - 2 * i] = ciphertext[count];
                count++;
            }
        }
    }
    for (int i = rails - 1; i < length; i = i + cycle_length)
    {
        plaintext[i] = ciphertext[count];
        count++;
    }

    plaintext[length] = '\0';
    return plaintext;
}
