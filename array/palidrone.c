#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0, j, length = 0;

    printf("\nEnter the string: ");
    fgets(str, sizeof(str), stdin); // Use fgets instead of gets for safety

    // Calculate the length of the string (excluding the newline character)
    length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0'; // Remove newline character if present
        length--; // Adjust length
    }

    i = 0;
    j = length - 1;

    while (i <= j) {
        if (str[i] == str[j]) {
            i++;
            j--;
        } else {
            break;
        }
    }

    if (i >= j) {
        printf("\nPALINDROME\n");
    } else {
        printf("\nNOT PALINDROME\n");
    }

    return 0;
}
