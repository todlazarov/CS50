/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <string.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Declare variables
    int len = n;
    int middle = len / 2;
    int left = 0;
    int right = len;
    
    if (n <= 0) {
        return false;
    }
    
    while (len > 0)
    {
        if (value == values[middle])
        {
            return true;
        }
        else if (value > values[middle])
        {
            left = middle + 1;
            middle = (right + left) / 2;
            len = right - left + 1;
        }
        else if (value < values[middle])
        {
            right = middle - 1;
            middle = middle - 1;
            len = right - left + 1;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Find the maximum number in the array
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }
    // Declare variables
    int * count_arr = calloc(max, sizeof(int));
    int * arr2 = calloc(max, sizeof(int));
    int counter = 0;
    int idx = 0;
    
    // Set 0s for each index in the counting array
    for (int i = 0; i < n; i++)
    {
        count_arr[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count_arr[values[i]] = count_arr[values[i]] + 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        counter += count_arr[i+1];
        count_arr[i+1] = counter;
    }
    
    for (int i = n; i >= 0; i--)
    {
        idx = count_arr[values[i]];
        arr2[idx] = values[i];
    }
    
    values = arr2;
    
    return ;
}
