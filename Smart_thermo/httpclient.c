#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUEST_SIZE 2048

// Function to create HTTP GET request
char* createGetRequest(const char* jsonData) {
    char* request = (char*)malloc(MAX_REQUEST_SIZE * sizeof(char));
    snprintf(request, MAX_REQUEST_SIZE, "GET /path HTTP/1.1\r\n"
                                         "Host: Thermostat_UIr\r\n"
                                         "Content-Type: application/json\r\n"
                                         "Content-Length: %zu\r\n"
                                         "%s",
             strlen(jsonData), jsonData);
    return request;
}

// Function to create HTTP POST request
char* createPostRequest(const char* jsonData) {
    char* request = (char*)malloc(MAX_REQUEST_SIZE * sizeof(char));
    snprintf(request, MAX_REQUEST_SIZE, "POST /path HTTP/1.1\r\n"
                                         "Host: Thermostat_UI\r\n"
                                         "Content-Type: application/json\r\n"
                                         "Content-Length: %zu\r\n"
                                         "%s",
             strlen(jsonData), jsonData);
    return request;
}
