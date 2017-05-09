#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int height;
    
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
        
        for (int j = 1; j < height - i; j++)    
        {
            printf(" ");
        }
        
        do {
            printf("#");
            x++;
        } while (x < i + 1);
        
        printf("  ");
        
        do {
            printf("#");
            y++;
        } while (y < i + 1);
        
        printf("\n");
    }
}