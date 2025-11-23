#include <stdio.h>
#include <stdbool.h>

// Function to calculate the sum of individual digits
int sum_of_digits(int n) {
    int sum = 0;
    int temp = n;

    while (temp != 0) {
        sum += temp % 10;   // Add the last digit to the sum
        temp /= 10;         // Remove the last digit
    }
    return sum;
}

// Function to test if a number is a palindrome
bool is_palindrome(int n) {
    int reversed_n = 0;
    int original_n = n;

    while (n != 0) {
        reversed_n = reversed_n * 10 + n % 10;  // Build the reversed number
        n /= 10;                                // Remove the last digit
    }

    // Check if the original number is equal to its reverse
    return original_n == reversed_n;
}

int main() {
    int number;

    // Prompt user for input and validate it is a positive integer
    do {
        printf("Enter a positive integer: ");
        if (scanf("%d", &number) != 1 || number <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n'); 
        }
    } while (number <= 0);

    // Calculate and display the sum of digits
    int sum = sum_of_digits(number);
    printf("Sum of individual digits of %d is: %d\n", number, sum);

    // Perform and display the palindrome test
    if (is_palindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}

