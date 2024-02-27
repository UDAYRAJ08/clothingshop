#include <stdio.h>

void displayInWords(int *num);

int main() {
    int number;

    printf("Enter an integer between 1 and 999: ");
    scanf("%d", &number);

    // Check if the entered number is within the specified range
    if (number < 1 || number > 999) {
        printf("Please enter a valid number between 1 and 999.\n");
        return 1; // Exit with an error code
    }

    displayInWords(&number);

    return 0;
}

void displayInWords(int *num) {
    // Arrays to store words for units, tens, and hundreds
    char *units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    int hundreds = *num / 100;
    int tensDigit = (*num % 100) / 10;
    int unitsDigit = *num % 10;

    printf("In words: ");

    if (hundreds > 0) {
        printf("%s Hundred ", units[hundreds]);
    }

    if (tensDigit == 1) {
        printf("%s ", teens[unitsDigit]);
    } else {
        if (tensDigit > 1) {
            printf("%s ", tens[tensDigit]);
        }
        if (unitsDigit > 0) {
            printf("%s ", units[unitsDigit]);
        }
    }

    printf("\n");
}
