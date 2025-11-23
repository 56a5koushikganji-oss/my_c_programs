#include <stdio.h>
#include <string.h>
// function to insert a substring into a string at a specified position 
void insertSubstring(char mainstr[], char substr[], int position)
{
    int mainlen = strlen(mainstr);
    int sublen = strlen(substr);
    // Shift the part of the main string after the position to make space for the substring
    for (int i = mainlen; i >= position; i--) {
        mainstr[i + sublen] = mainstr[i];
    }
    // Insert the substring at the specified position
    for (int i = 0; i < sublen; i++) {
        mainstr[position + i] = substr[i];
    }
}
int main() 
{
    char mainstr[100], substr[50];
    int position;
    printf("Enter the main string: ");
    gets(mainstr);
    printf("Enter the substring to insert: ");
    gets(substr);
    printf("Enter the position to insert the substring: ");
    scanf("%d", &position);
    insertSubstring(mainstr, substr, position);
    printf("String after insertion: %s\n", mainstr);
    return 0;
}
    