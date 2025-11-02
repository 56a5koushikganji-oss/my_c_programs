#include <stdio.h>
int main() {
    int num1,num2,num3;
    int max,min;

    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    // Finding maximum
    max = num1;
    if(num2 > max) {
        max = num2;
    }
    if(num3 > max) {
        max = num3;
    }
    // Finding minimum
    min = num1;
    if(num2 < min) {
        min = num2;
    }
    if(num3 < min) {
        min = num3;
    }
    printf("Maximum number: %d\n", max);
    printf("Minimum number: %d\n", min);

    return 0;

}
