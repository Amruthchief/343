#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "states.h"
#include "jsmn.h"

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};
struct User users[MAX_USERS];
int userCount = 0;

// Define global variables and functions as needed

void signup() {
    if (userCount >= MAX_USERS) {
        printf("Sorry, maximum number of users reached.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    printf("Signup successful!\n");
    userCount++;
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    printf("Invalid username or password!\n");
    return 0;
}





void displayStatus() {
    printf("Thermostat status: On\n");
    // Add code to display other status information
}

void displayTemperature() {
    printf("Current temperature: 25°C\n"); // Example temperature, replace with actual value
}

char* adjustTemperature() {
    int temperature;
    printf("Enter the new temperature: ");
    scanf("%d", &temperature);

    char json[50]; // Adjust the size as needed
    sprintf(json, "{\"temperature\": %d}", temperature);

    return strdup(json); // Returns a copy of the JSON string
}

void displayPresets() {
    printf("Presets:\n");
    printf("1. Comfort\n");
    printf("2. Energy Saving\n");
    printf("3. Vacation\n");
    // Add more presets if needed
}
