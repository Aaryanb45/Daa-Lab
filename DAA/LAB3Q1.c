/*INPUT:-PERMUTATION OF {1,2,.......,n}WITH ONE ELEMENT APPEARING TWICE,MAKING IT A SEQUENCE OF n+1 ELEMENTS
  OUTPUT:-IDENTIFY THE ELEMENT THAT APPEARS TWICE IN O(N)TIME AND O(1)SPACE COMPLEXITY
*/

#include <stdio.h>
#include <stdlib.h>

int SearchDuplicate(int arr[], int size) {
    int n = size - 1;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    int Natural_No_sum = (n * (n + 1)) / 2;
    int duplicated_element = sum - Natural_No_sum;
    return duplicated_element;
}

int main() {
    int size;
    printf("Enter Size: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (!array) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int duplicated_element = SearchDuplicate(array, size);
    printf("The duplicated element is: %d\n", duplicated_element);

    // Free allocated memory
    free(array);

    return 0;
}