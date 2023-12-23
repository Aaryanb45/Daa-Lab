#include <stdio.h>

int findDuplicate(int arr[], int n) {
    int sum = 0;
    
    for (int i = 0; i < n + 1; i++) {
        sum += arr[i];
    }
    int expectedSum = (n * (n + 1)) / 2;
    int duplicate = sum - expectedSum;
    
    return duplicate;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int arr[n + 1];
    printf("Enter the permutation:\n");
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &arr[i]);
    }
    
    int duplicate = findDuplicate(arr, n);
    printf("The element appearing twice is: %d\n", duplicate);
    
    return 0;
}