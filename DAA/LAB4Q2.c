#include <stdio.h>
#include <limits.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubarraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];
    int mid = (low + high) / 2;
    return max(max(maxSubarraySum(arr, low, mid),
                   maxSubarraySum(arr, mid + 1, high)),
               maxCrossingSum(arr, low, mid, high));
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements separated by spaces:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxSum = maxSubarraySum(arr, 0, n - 1);
    printf("Maximum contiguous sum: %d\n", maxSum);
    return 0;
}