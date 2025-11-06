#include <stdio.h>
#include <math.h> // Required for pow() function

int main() {
    int num, originalNum, remainder, n = 0;
    int result = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Count the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num; // Reset originalNum to the input value

    // Calculate the sum of nth powers of individual digits
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n); // Use pow() from math.h
        originalNum /= 10;
    }

    // Check if the sum is equal to the original number
    if (result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
