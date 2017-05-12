#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check to ensure there are only 2 arguments (the name of the file and the shift)
    if (argc != 2)
    {
        printf ("Usage: ./vigenere k\n");
        return 1;
    }
    
    // Check each key to ensure they are all letters
    for (int j = 0, m = strlen(argv[1]); j < m; j++)
    {
        if (!isalpha(argv[1][j]))
        {
            printf ("Usage: ./vigenere k");
            return 1;
        }
    }
    
    // Declare variables
    string shift_word = argv[1];
    char shift_key;
    int len = strlen(argv[1]);
    int k = 0; // The shift number forward
    int i = 0; // The counter for the shift word iteration
    int l = 0; // The counter for the total input p iteration
    
    // Ask user and store the plain text
    printf ("plaintext: ");
    string p = get_string();
    int p_len = strlen(p);
    
    printf ("ciphertext: ");
    
    // Iterate through input
    while (true)
    {
        // Check if the char is a letter
        if (isalpha(p[l]))
        {
            // Shift the char if its lower case
            if (islower(p[l]))
            {
                shift_key = shift_word[i % len];
                if (islower(shift_key))
                {
                    k = shift_key - 97;
                }
                else{
                    k = shift_key - 65;
                }
                printf ("%c", 'a' + (p[l] + k - 'a') % 26);
                i++;
            } 
            
            // Shift the char if its upper case
            if (isupper(p[l]))
            {
                shift_key = shift_word[i % len];
                if (islower(shift_key))
                {
                    k = shift_key - 97;
                }
                else{
                    k = shift_key - 65;
                }
                printf ("%c", 'A' + (p[l] + k - 'A') % 26);
                i++;
            }
        } 
        // Print characters that are not letters as is
        else
        {
            printf ("%c", p[l]);
        }
        
        l++;
        
        if (l >= p_len)
        {
            printf ("\n");
            return 0;
            break;
        }
    }
}