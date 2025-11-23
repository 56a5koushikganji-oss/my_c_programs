#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    // Prompt the user to enter the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    // Iterate to generate and print each term of the series
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // The first two terms are 0 and 1
        } else {
            // Calculate the next term by summing the previous two
            next = first + second;
            // Update the previous two terms for the next iteration
            first = second;
            second = next;
        }
        printf("%d ", next); // Print the current term
    }
    printf("\n");

    return 0;
}
