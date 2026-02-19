#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int x, y;

    // Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    // Output result
    printf("%d %d", x, y);

    return 0;
}
