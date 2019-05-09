/**************************************************************
AUTHOR: CIAN DOYLE / C18430304
CREATION DATE: 29/10/2018
LAST UPDATED AS OF: 11/11/2018

PROGRAM DESCRIPTION:
This is a simple terminal program which allows the user to have a 4 digit PIN which they can do various things with
The program displays a text menu which provides the user with 4 different options:

Option 1: The user is asked to enter a 4 digit PIN and the program will check if it matches their current PIN. The
program will display the appropriate message and return to the menu.

Option 2: The user may change their PIN from the default of 1234. They are asked to enter a new PIN, then re-enter it
to confirm that they did not make any mistakes typing the new PIN. It will then check that these two PINs match. If
they match, the program will store the new PIN in the PIN array. If they do not match, their PIN will not be changed.
Both outcomes will result in their respective messages displayed on screen, and returning to the menu.

Option 3: The program will display the amount of times the user has correctly and incorrectly entered their PIN
using option 1.

Option 4: This will terminate the program.

Program written in Atom and compiled using the 'gpp-compiler' package for Atom.
***************************************************************/

#include <stdio.h>
#include <stdbool.h> // Needed for boolean data type.

#define PIN_DIGITS 4 // The amount of digits in the PIN. A client may want to change how many digits are in a PIN is in the future.

int main () {

    // Initializing variables
    int PIN[PIN_DIGITS] = {1, 2, 3, 4}; // Assuming the user has the default PIN of 1234
    int PINCheck[PIN_DIGITS] = {};
    int newPIN[PIN_DIGITS] = {};
    int newPINCheck[PIN_DIGITS] = {};
    int selection = 0;
    int correct = 0; // Tracking correct entries
    int incorrect = 0; // Tracking incorrect entries
    int i; // For loop counter

    bool PINMatch;
    bool newPINMatch;
    bool invalidNum; // Used for error handling

    printf("**All entries must be on a new line. When entering a PIN, hit enter after every digit.**\n\n");

    // Main menu loop
    do {

        printf("ATM MENU\n\n");
        printf("1. Verify your PIN\n");
        printf("2. Change your PIN\n");
        printf("3. Display correct and incorrect PIN entries\n");
        printf("4. Exit\n");

        scanf("%d", &selection); // Reading which option user wishes to select.

        switch (selection) {
            // If option 1 (Verify PIN) is selected
            case 1:
                PINMatch = true; // Assumes the PIN matches from the start, but once an incorrect number is found in the PIN, it will be set to false.
                printf("Enter your PIN: \n");

                for(i = 0; i < PIN_DIGITS; i++) {

                    scanf("%d", &PINCheck[i]); // Read input for 4 numbers

                }

                for(i = 0; i < PIN_DIGITS; i++) {

                    if (PIN[i] != PINCheck[i]) {

                        printf("\nThe PIN entered was incorrect.\n\n");
                        incorrect++;
                        PINMatch = false; // Do not execute the below if statement.
                        i = PIN_DIGITS + 1; // End the for loop, as there's no need to check other numbers if one does not match.

                    }

                }

                if (PINMatch == true) { // PINMatch is assumed to be true, so this will execute if the above loop verifies that all numbers entered match the stored PIN.

                    printf("\nThe PIN you enter was correct.\n\n");
                    correct++;

                }

                break;
            // If option 2 (Change PIN) is selected
            case 2:
                newPINMatch = true;
                invalidNum = false;
                printf("Please enter a new PIN:\n");

                for(i = 0; i < PIN_DIGITS; i++) {

                    scanf("%d", &newPIN[i]);

                    if (newPIN[i] < 0 || newPIN[i] > 9) { // If the user entered a digit that is not between 0 and 9

                        printf("\nError: Your PIN may only consist of digits 0 - 9.\n\n");
                        invalidNum = true;

                    }

                    if (invalidNum == true) {

                        i = PIN_DIGITS + 1; // Break out of the for loop

                    }

                } // End for

                if (invalidNum == false) { // If the user did not enter any invalid numbers, continue to second entry.

                    printf("Please re-enter the new PIN for confirmation:\n");

                    for(i = 0; i < PIN_DIGITS; i++) {

                        scanf("%d", &newPINCheck[i]);

                    } // End for

                    for(i = 0; i < PIN_DIGITS; i++) {

                        if (newPIN[i] != newPINCheck[i]) {

                            printf("\nThe PINs entered do not match. Your PIN has not been changed.\n\n");
                            newPINMatch = false;
                            i = PIN_DIGITS + 1; // Break out of for loop.

                        } // End if

                    } // End for

                    if (newPINMatch == true) { // If the two entered PINs match, change the pin

                        printf("\nYour PIN has successfully been changed!\n\n");

                        for (i = 0; i < PIN_DIGITS; i++) {

                            PIN[i] = newPIN[i]; // Changing the PIN to what the user requested.

                        } // End for

                    } // End if

                } // End if

                break;
            // If option 3 (Display PIN entries) is selected
            case 3:
                printf("\nCorrect PIN entries: %d\nIncorrect PIN entries %d\n\n", correct, incorrect);
                break;
            // If option 4 is selected, do nothing and break out of loop.
            case 4:
                break;
            // If the user selects any other invalid option
            default:
                printf("\nError: Invalid option selected, please try again.\n\n");
                break;

            } // End of switch

        } // End of do/while loop
        while (selection != 4); // Loop will end if the user selects option 4, terminating the program

    return 0;
}
