#include <stdio.h>
#include <stdlib.h>

int main() {
    double* numbers = NULL;
    int size = 0;
    double sum = 0.0;
    double average = 0.0;
    char choice;
    do {
        double number;
        printf("Enter a number:");
        scanf("%lf", &number);

        double* temp = realloc(numbers, (size + 1) * sizeof(double));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            free(numbers);
            return 1;
        }
        numbers = temp;

        numbers[size] = number;
        size++;

        sum += number;
        average = sum / size;

        printf("List of numbers:");
        for (int i = 0; i < size; i++) {
            printf("\n%lf", numbers[i]);
        }

        printf("\nUpdated average is: %lf", average);

        printf("\nMore numbers? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y');

    free(numbers); // Free allocated memory
    return 0;
}