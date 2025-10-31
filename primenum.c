#include<stdio.h>
int main() {
    int n,i;
    int prime;

    printf("Enter a number: \n");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d is not a prime number.\n", n);

    }
    else {
        for( i=2; i<n; i++) {
            if (n % i == 0) {
                printf("%d is not a prime number. \n", n);
                prime = 0;
                break;
            }
        }
        if  (prime) {
            printf("%d is a prime number. \n", n);
        }
    }

    return 0;
}


    


