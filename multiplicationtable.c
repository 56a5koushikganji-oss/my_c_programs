#include <stdio.h>
int main() {
    int num,rows,i;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("\nMultiplication Table for %d:\n", num);
    for (i = 1; i <= rows; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return 0;

}
