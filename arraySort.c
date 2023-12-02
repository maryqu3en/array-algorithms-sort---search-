
#include "main.h"

// fill array with random integer values -------------------------------
void fillRandom(int *arr, int size, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }
}


// swap two values -----------------------------------------------------
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


/*
Selection sort
Time complexity: O(N²)
*/
void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}


/*
Insertion sort
Time complexity: O(N²)
*/
void insertionSort(int *arr, int size)
{
    int pos, temp;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        pos = i;
        while ((pos > 0) && (arr[pos - 1] > temp))
        {
            arr[pos] = arr[pos - 1];
            pos = pos - 1;
        }
        arr[pos] = temp;
    }
}


/*
Bubble sort
Time complexity: O(N²)
*/
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}



/*
Merge sort
Time complexity: O(N log N)
*/
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays left[] and right[]
    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = low; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int low, int high) {
    if (low < high) {
        // Find the middle point of the array
        int mid = low + (high - low) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}


/*
Quick sort
Time complexity: O(N log N) (can degrade to O(N²) in worst case)
*/
int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] to place the pivot in its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the pivot index
}

// Function to implement the Quick Sort algorithm
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        // Partition the array, and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays on either side of the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}