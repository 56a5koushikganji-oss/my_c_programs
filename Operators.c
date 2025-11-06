
#include <stdio.h>

int main() {
   
    int a, b, c;
    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    // Arthimetic Operators
    printf("Arithmetic Operators:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);

    // Relational Operators
    printf("\nRational Operators :\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    printf("a >= b: %d\n", a >= b);
    printf("a <= b: %d\n", a <= b);

    // Logical Operators
    printf("\nLogical Operators :\n");
    printf("(a > b) && (b > 0) : %d\n", (a > b) && (b > 0));
    printf("(a < b) || (b > 0) : %d\n", (a > b) && (b > 0));
    printf("!(a == b): %d\n", !( a == b));

    // Bitwise Operators
    printf(" \n Bitwise operators :\n");
    printf("a & b = %d\n", a % b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf(" ~a = %d\n", ~a );
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n", a >> 1);

    // Assignment Operators 
    printf("\nAssignment Operators;\n ");
    c = a;
    printf("c = %d\n", c);
    c += b;
    printf("c += b ? %d\n", c);
    c -= b;
    printf("c -= b ? %d\n", c);
    c *= b;
    printf("c *= b ? %d\n", c);
    c /= b;
    printf("c /= b ? %d\n", c);
    c %= b;
    printf("c %%= b ? %d\n", c);

    // Increment and Decrement
    printf("\nIncrement / Decrement");
    printf("a++ = %d\n", a++); // post-increment
    printf("After a++ ? a = %d\n",a);
    printf("++a = %d\n", ++a); // pre-increment
    printf("b-- = %d\n", b--); // post-decrement
    printf("After b-- ? b = %d\n",b);
    printf("--b = %d\n", --b); // pre-decrement

    // Conditional (Ternary) Operator
    printf("\nConditional Operator");
    int max = (a > b) ? a : b;
    printf("Max of a and b is %d\n", max);

    return 0;
}






