// Implement a program that, given a person’s name, prints a person’s initials, per the below.

// $ ./initials
// Regulus Arcturus Black
// RAB

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string();
    
    // Check if sting is null
    if (s != NULL)
    {
        // If the first character in the string is not space, print out the first initial
        if (s[0] != ' ')
        {
            printf ("%c", toupper(s[0]));
        }
        
        // Iterate through the string
        for (int i = 0, n = strlen(s); i < n - 1; i++)
        {
            // Check for the next initial
            if (s[i] == ' ' && s[i+1] != ' ')
            {
                printf ("%c", toupper(s[i+1]));
            }
        }
    }
    
    // End with a new line, as per spec
    printf ("\n");
}