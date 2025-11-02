#include <stdio.h>
int main() {
    int a,b;
    printf("Enter the numbers(a,b): ");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    // Swapping logic using addition and subtraction
    a = a + b;// Step 1: a now holds the sum of a and b
    b = a - b;// Step 2: b holds the original value of a(sum - original b)
    a = a - b;// Step 3: a now holds the original value of b(sum - original a)

    printf("After swapping : a = %d, b = %d\n", a, b);
    return 0;
}
