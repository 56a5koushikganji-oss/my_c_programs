#include<stdio.h>
#include<math.h> // For pow() function used in 

int main() {
    float principal, rate, time;
    float simpleInterest, compoundInterest;

    // Input
    printf("Enter Principal amount: ");
    scanf("%f", &principal);

    printf("Enter Annual Interest Rate (in %%): ");
    scanf("%f", &rate);

    printf("Enter Time (in years): ");
    scanf("%f", &time);

    //Calculate Simple Interest 
    simpleInterest = (principal * rate * time) / 100;

    //Calculate Compound Interest 
    compoundInterest = principal * pow((1+ rate / 100), time) - principal;

    //Output
    printf("\nSimpal Interest = %2f\n", simpleInterest);
    printf("Compound Interest = %2f\n", compoundInterest);

    return 0;
    
}



