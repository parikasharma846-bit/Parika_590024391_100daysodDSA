#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int max, min;

    // Input size
    scanf("%d", &n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min
    max = min = arr[0];

    // Find max and min
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Output result
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
