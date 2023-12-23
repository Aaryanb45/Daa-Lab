/*INPUT:-PERMUTATION OF {1,2,.......,n}WITH TWO ELEMENT APPEARING TWICE,MAKING IT A SEQUENCE OF n+2 ELEMENTS
  OUTPUT:-IDENTIFY THE ELEMENT THAT APPEARS TWICE IN O(N)TIME AND O(1)SPACE COMPLEXITY
*/
#include <stdio.h>

void findDuplicates(int arr[], int n) {
    int XOR = 0;

    for (int i = 0; i < n + 2; i++) {
        XOR ^= arr[i];
    }

    int rightmost_set_bit = XOR & -XOR;

    int x = 0, y = 0;

    for (int i = 0; i < n + 2; i++) {
        if (arr[i] & rightmost_set_bit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    printf("The two elements that appear twice are: %d and %d\n", x, y);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sequence[n+2];
    printf("Enter the sequence of %d elements (with two elements appearing twice):\n", n+2);
    for (int i = 0; i < n + 2; i++) {
        scanf("%d", &sequence[i]);
    }

    findDuplicates(sequence, n);

    return 0;
}