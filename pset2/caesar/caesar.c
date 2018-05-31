#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> // int atoi(string str); converts a string to an integer
#include <ctype.h> // int isalpha(int c); checks if character is an alphabetic letter
#include <string.h> // int strlen(string str);
/**
 * Encrypts messages using Caesar’s cipher.
 * Usaege: ./caesar <key>
 */
#define NUM_ALPHA           26
#define ASCII_UPPER_START   65
#define ASCII_UPPER_END     90
#define ASCII_LOWER_START   97
#define ASCII_LOWER_END     122
void printCipher(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
    int key = atoi(argv[1]); // assume positive integer per specification
    if (key == 0)
    {
        printf("Usage: ./caesar <key>. <key> must be a positive integer.\n");
        return 2;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    printCipher(plaintext, key);
    return 0;
}

void printCipher(string plaintext, int key)
{
    key = key % NUM_ALPHA; // handle key that is larger than 26
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // A-Z
        if (plaintext[i] >= ASCII_UPPER_START && plaintext[i] <= ASCII_UPPER_END)
        {
            //TODO: is there a better way to do this?
            char c = (char)((int)plaintext[i] - ASCII_UPPER_START + key) % NUM_ALPHA + ASCII_UPPER_START;

            printf("%c", c);
        }
        // a-z
        else if (plaintext[i] >= ASCII_LOWER_START && plaintext[i] <= ASCII_LOWER_END)
        {
            char c = (char)((int)plaintext[i] - ASCII_LOWER_START + key) % NUM_ALPHA + ASCII_LOWER_START;
            printf("%c", c);
        }
        // non-alphabetic character
        else
        {
            printf("%c", (plaintext[i]));
        }
    }
    printf("\n");
}
