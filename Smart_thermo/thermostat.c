#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // for strcmp
#include <unistd.h> // for read function
#include <fcntl.h> // for open function
#include <errno.h> // for errno

#define MAX_LINE_LENGTH 2048
#define FILE_CHECK_INTERVAL 5 // Check file every 5 seconds

bool isFileUpdated(const char *filename, const char *content) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return false;
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return false; // File is empty
    }

    fclose(file);
    return strcmp(line, content) != 0; // Compare current content with previous content
}

void readThermostatData(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading file %s: %s\n", filename, strerror(errno));
    }

    fclose(file);
}

int main() {
    const char *filename = "thermostat.txt";
    char buffer[MAX_LINE_LENGTH];
    char prevContent[MAX_LINE_LENGTH] = "";

    while (true) {
        // Read content from file
        readThermostatData(filename, buffer);

        // Check if file is updated
        if (isFileUpdated(filename, prevContent)) {
            printf("File %s has been updated. New content:\n%s\n", filename, buffer);
            strcpy(prevContent, buffer); // Update previous content
        }


        sleep(FILE_CHECK_INTERVAL); // Wait before checking file again
    }

    return 0;
}
