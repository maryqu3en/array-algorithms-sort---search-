/*
Binary search 
Time complexity: O(1) in best case
                 O(log N) in worst case
*/

#include "main.h"

int middle(int h, int l)
{
    return l + (h - l) / 2;
}

// itertaive approach

int binarySearch(int arr[], int size, int x)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = middle(high, low);

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// recursive approach

int binarySearch_recursive(int arr[], int high, int low, int x)
{
    if (low > high) {
        return -1;
    }

    int mid = middle(high, low);
    if (x == arr[mid])
        return mid;
    else if (x < arr[mid])
        return binarySearch_r(arr, mid-1, low, x);

    return binarySearch_r(arr, high, mid+1, x);
}