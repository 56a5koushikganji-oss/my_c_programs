#include <stdio.h>
int main() {
    int n,a = 0,b = 1,next,i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fobonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;

}