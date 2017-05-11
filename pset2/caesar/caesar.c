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
        printf ("Usage: ./caesar k\n");
        return 1;
    }
    
    // Convert the second argument(the shift) into an integer "k"
    int k = atoi(argv[1]);
    
    // Ask user and store the plain text
    printf ("plaintext: ");
    string p = get_string();
    
    printf ("ciphertext: ");
    
    // Iterate through input
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // Check if the char is a letter
        if (isalpha(p[i]))
        {
            // Shift the char if its lower case
            if (islower(p[i]))
            {
                printf ("%c", 'a' + (p[i] + k - 'a') % 26);
            } 
            
            // Shift the char if its upper case
            if (isupper(p[i]))
            {
                printf ("%c", 'A' + (p[i] + k - 'A') % 26);
            }
        } 
        // Print characters that are not letters as is
        else
        {
            printf ("%c", p[i]);
        }
    }
    
    printf ("\n");
}