#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    int choice;
    float num1, num2, result;

    while (1) {
        // Display menu to the user
        displayMenu();
        
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Exit the loop if user chooses to quit
        if (choice == 5) {
            printf("\nThank you for using the calculator. Goodbye!\n");
            break;
        }

        // Check for valid choices
        if (choice >= 1 && choice <= 4) {
            // Taking input numbers from user
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);

            // Perform operation based on user's choice
            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                    break;
                case 2:
                    result = subtract(num1, num2);
                    printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                    break;
                case 3:
                    result = multiply(num1, num2);
                    printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                    break;
                case 4:
                    if (num2 != 0) {
                        result = divide(num1, num2);
                        printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                    } else {
                        printf("Error: Division by zero is not allowed.\n");
                    }
                    break;
            }
        } else {
            printf("Invalid choice. Please select an option from 1 to 5.\n");
        }

        // Separator for better readability
        printf("-------------------------------------------------\n");
    }

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n=============================\n");
    printf("      SIMPLE CALCULATOR      \n");
    printf("=============================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

// Function to perform addition
float add(float a, float b) {
    return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
    return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
    return a * b;
}

// Function to perform division
float divide(float a, float b) {
    return a / b;
}