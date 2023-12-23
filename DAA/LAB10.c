/*
Instead of 2 elements being repeated, 
you need to solve it for 3 elements being repeated and therefore making it a sequence of n+3 integers.*/

#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int arr[], int n) {
    int a1 = arr[0];
    int a2 = arr[0];

    // Phase 1: Detect if there is a cycle
    do {
        a1 = arr[a1];
        a2 = arr[arr[a2]];
    } while (a1 != a2);

    // Phase 2: Find the start of the cycle (duplicate element)
    a1 = arr[0];
    while (a1 != a2) {
        a1 = arr[a1];
        a2 = arr[a2];
    }

    return a2;
}

int main() {
    int n, i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 3) * sizeof(int));

    printf("Enter the elements of the sequence: \n");
    for (i = 0; i < n + 3; i++)
        scanf("%d", &arr[i]);

    int duplicate = findDuplicate(arr, n + 3);

    printf("The element that appears thrice is: %d\n", duplicate);

    free(arr);

    return 0;
}