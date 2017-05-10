// Implement a program that prints out a double half-pyramid of a specified height, per the below.
// $ ./mario
// Height: 4
//   #  #
//   ##  ##
//  ###  ###
// ####  ####

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int height;
    
    // Check the height input according to spec
    while(true) {
        printf("How tall would you like your half pyramids to be? \n");
        height = get_int();
        if (height > -1 && height < 24)
        {
            break;    
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        int x = 0;
        int y = 0;
        
        // Pring spaces
        for (int j = 1; j < height - i; j++)    
        {
            printf(" ");
        }
        
        // Print the first half pyramid
        do {
            printf("#");
            x++;
        } while (x < i + 1);
        
        // Print spaces
        printf("  ");
        
        
        // Print the second half pyramid
        do {
            printf("#");
            y++;
        } while (y < i + 1);
        
        printf("\n");
    }
}