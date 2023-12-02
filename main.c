#include "main.h"
#include <stdio.h>


int main()
{
    int arr[] = {1, 2, 9, 12, 25};
    int n = 5;
    int x = 9;
    printf("\nElement found at index: %d", binarySearch_i(arr, n, x));
    printf("\nElement found at index: %d", binarySearch_r(arr, n, 0, x));

    printf("\n\n\n");
}