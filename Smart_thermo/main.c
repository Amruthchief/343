#include <stdio.h>
#include <string.h>
#include "states.h"


int main() {
    int loggedIn = 0;
    do {
        printf("Choose an option:\n");
        printf("1. Login\n");
        printf("2. Signup\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loggedIn = login();
                break;
            case 2:
                signup();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (loggedIn) {
            int option;
            do {
                printf("Choose an option:\n");
                printf("Status :\n");
                displayStatus();

                printf("1. Display Temperature\n");
                printf("2. Adjust Temperature\n");
                printf("3. Presets\n");
                printf("4. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &option);

                switch (option) {
                    case 1:
                        displayTemperature();
                        break;
                    case 2: {
                        char* adjustedTempJSON = adjustTemperature();



                        printf("Adjusted temperature JSON: %s\n", adjustedTempJSON);
                        break;
                    }
                    case 3:
                        displayPresets();
                        break;
                    case 4:
                        printf("Logging out...\n");
                        loggedIn = 0;
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            } while (option != 4);
        }
    } while (loggedIn !=-1);

    return 0;
}

