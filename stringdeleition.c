#include <stdio.h>
#include <string.h>
void deleteChars(char str[], int position, int numChars)
{
    int len = strlen(str);
    // Shift the part of the string after the deleted characters to the left
    for (int i = position; i <= len; i++) {
        str[i] = str[i + numChars];
    }
}
int main() 
{
    char str[100];
    int position, numChars;
    printf("Enter the string: ");
    gets(str);
    printf("Enter the position to delete from (starting from 0): ");
    scanf("%d", &position);
    printf("Enter the number of characters to delete: ");
    scanf("%d", &numChars);
    deleteChars(str, position, numChars);
    printf("String after deletion: %s\n", str);
    return 0;
}    
