#include <stdio.h>
#include <stdbool.h> // For boolean variable type

#define SIZE 4 // The amount of digits in the PIN code.

// Function prototypes
int inputCode(int*);
int encryptCode(int*);
int decryptCode(int*);
void displayAttempts();
 
bool encrypted = false; // for checking if the PIN is encrypted or not.
bool correctcode = false;

int correct = 0; // Tracking attempts
int incorrect = 0;

int access_code[SIZE] = {4,5,2,3}; // Default encrypted code to compare to.
int currentCode[SIZE] = {0,0,0,0}; // The current code 

int main()
{

    int option;

    printf("Menu\n");

    do { // Main menu loop
        printf("\n");
        printf("1. Enter code.\n");
        printf("2. Encrypt and Verify.\n");
        printf("3. Decrypt code.\n");
        printf("4. Display entries.\n");
        printf("5. Exit.\n");

        scanf("%d", &option); // Read user input

        switch(option) { // Handle the user input
            case 1:
                inputCode(currentCode); // Enter the code into the array
                break;
            case 2:
                encryptCode(currentCode); // Encrypt the code and verify if it matches
                break;
            case 3:
                decryptCode(currentCode); // Decrypt the code
                break;
            case 4:
                displayAttempts(); // Display the results from tracking
                break;
            case 5:
                printf("Option 5 selected\n");
                break;
            default:
                break;
        }
    }
    while (option != 5); // Exit if the user enters option 5

    return 0;
}

int inputCode(int* array) {

    printf("Enter a code one digit at a time (Press enter after each digit): \n");

    encrypted = false; // Reset these values for each entry
    correctcode = true;

    for (int i = 0; i < SIZE; i++) {

        scanf("%d", (array + i)); // Enter values into the given array

        if ((*(array + i) > 9) || ( *(array + i) < 0)) { // If the entered digit is not between 0-9

            printf("The number you entered was too large, please re enter the number:\n"); 
            i--; // Re run this part of the loop

        }

    }

}
                                        
int encryptCode(int *array) {

    if (encrypted == false) { // If the code is not already encrypted. 

        int temp; // Temp variable for swapping

        temp = (*(array + 2));
        (*(array + 2)) = *(array); // Swap the 1st and 3rd values
        *(array) = temp;

        temp = (*(array + 3));
        (*(array + 3)) = (*(array + 1)); // Swap the 2nd and 4th values
        (*(array + 1)) = temp;

        for (int i = 0; i < SIZE; i++) {

            (*(array + i)) += 1; // Increment all values by 1

            if ((*(array + i)) > 9) {

                (*(array + i)) = 0; // If it is higher than nine, roll the value back to 0.

            }

        }

        encrypted = true; 

        for (int i = 0; i < SIZE; i++) {

            if ( (*(array + i)) != (*(access_code + i))) { // Compare the values of the two arrays
                
                printf("Wrong code entered\n"); // If they do not match, flag it 
                correctcode = false;
                incorrect++; // Tracking
                i = SIZE; // Break out of the for loop

            }

        }

        if (correctcode == true) {

            printf("Correct code entered\n"); // If they do match, display the message.
            correct++;

        }
 
    }   
    else { // If the pin is already encrypted

        printf("\nYour pin is already encrypted.\n");

    }

}

int decryptCode(int *array) {

    if (encrypted == true) {

        int temp;

        temp = (*(array + 2));
        (*(array + 2)) = *(array); // Swapping 1st and 3rd the values once again
        *(array) = temp;

        temp = (*(array + 3));
        (*(array + 3)) = (*(array + 1)); // Swapping the 2nd and 4th values once again
        (*(array + 1)) = temp;

        for (int i = 0; i < SIZE; i++) {

            (*(array + i)) -= 1; // Decrement all values in the array by 1
            
            if ((*(array + i)) < 0) {

                (*(array + i)) = 9; // If the value goes below 0, roll back to 9;

            }

        }

        encrypted = false;

        printf("Your decrypted code: ");

        for (int i = 0; i < SIZE; i++) {

            printf("%d", (*(array + i))); // Display the values of the array

        }

    }   
    else {
        
        printf("\nYour PIN is already decrypted.\n");

    }
}

void displayAttempts() {

    printf("Incorrect attempts: %d\nCorrect attempts: %d\n", incorrect, correct); // Display the results of the tracking

}
