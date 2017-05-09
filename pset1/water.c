#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How long did you shower for?\n");
    int minutes = get_int();
    
    printf("Minutes: %d\n", minutes);
    printf("Bottles: %d\n", minutes * 12);
}