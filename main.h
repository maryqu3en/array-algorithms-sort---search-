// include prototypes here then include this file in main.c

// search algorithms ---------------------------------------------------------
int middle(int h, int l);
int binarySearch(int arr[], int size, int x);
int binarySearch_recursive(int arr[], int high, int low, int x);
int linearSearch(int arr[], int size, int x);


// array sort algorithms -----------------------------------------------------
void fillRandom(int *arr, int size, int max);
void swap(int *x, int *y);
void selectionSort(int *arr, int size);
void insertionSort(int *arr, int size);
void bubbleSort(int *arr, int size);
void merge(int arr[], int low, int mid, int high);
void mergeSort(int *arr, int left, int right);
int partition(int *arr, int low, int high);
void quickSort(int *arr, int left, int right);

