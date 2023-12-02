/*
Linear search
Time complexity: O(1) in best case
                 O(N) in worst case
*/

#include "main.h"

int linearSearch(int arr[], int size, int x)
{
    for(int i = 0; i<size; i++)
    {
        if (arr[i] == x) 
            return i;
    }
    return -1;
}