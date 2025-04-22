/*Design and impletement c/c++ program to sort a given set of integer elements using merge sort method and compute its time complexity Run
the program for varied values of n> 5000, and record the time taken to sort. plot a graph of time versus n.The elements can be read from a
file or can be generated using the random number generator.*/
//It is comes under divide and conqure method.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int*, int, int);
void merge(int*, int, int, int);
int n;

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int size = high - low + 1;
    int *b = (int*) malloc(size * sizeof(int));

    if (!b) {
        printf("Memory allocation failed\n");
        return;
    }

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    
    while (i <= mid) {
        b[k++] = a[i++];
    }
    
    while (j <= high) {
        b[k++] = a[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = b[k];
    }

    free(b);
}

int main() {
    int *arr, i;
    clock_t start, end;
    double time_taken;

    printf("\n**MERGE SORT PROGRAM**\n");
    printf("\nEnter the number of elements to be sorted:\n");
    scanf("%d", &n);
    
    arr = (int*) malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    printf("\nArray elements before sorting:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
        printf("%5d", arr[i]);
    }

    printf("\nArray elements to be sorted are:\n");
    for (i = 0; i < n; i++)
        printf("%5d", arr[i]);

    start = clock();
    mergesort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\nThe sorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n\nThe time taken to sort %d elements is %.6f sec\n", n, time_taken);

    free(arr);
    return 0;
}

