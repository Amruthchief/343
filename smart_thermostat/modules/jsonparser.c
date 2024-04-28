#include <stdio.h>
#include <stdlib.h>
#include "../headerfiles/cJSON/cJSON.h"

int main() {
    // Open JSON file
    FILE *fp = fopen("temp.json", "r");
    if (fp == NULL) {
        perror("Error opening JSON file");
        exit(EXIT_FAILURE);
    }

    // Read JSON file contents
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *json_buffer = (char *)malloc(file_size + 1);
    fread(json_buffer, 1, file_size, fp);
    json_buffer[file_size] = '\0';
    fclose(fp);

    // Parse JSON
    cJSON *root = cJSON_Parse(json_buffer);
    if (root == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error parsing JSON: %s\n", error_ptr);
        }
        exit(EXIT_FAILURE);
    }

    // Print JSON
    char *json_string = cJSON_Print(root);
    printf("JSON:\n%s\n", json_string);

    // Cleanup
    free(json_buffer);
    free(json_string);
    cJSON_Delete(root);

    return 0;
}
