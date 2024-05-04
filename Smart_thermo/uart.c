#include "uart.h"

int uart_init() {
    // Run the socat command to create the UART device
    // system("socat -d -d pty,raw,echo=0 pty,raw,echo=0");

    // Open the UART device and return the file descriptor
    int uart_fd = open("thermostat.txt", O_WRONLY | O_TRUNC);
    return uart_fd;
}

int uart_send(int uart_fd, const char *data) {
    // Write data to the UART device
    // printf("data == %s",data);
    int bytes_sent = write(uart_fd, data, strlen(data));
    return bytes_sent;
}


bool uart_receive(int uart_fd, char *buffer, size_t size) {
    ssize_t bytes_read = read(uart_fd, buffer, size);
    if (bytes_read < 0) {
        perror("Error reading from UART device");
        return false;
    }
    
    return true;
}

void uart_close(int uart_fd) {
    // Close the UART device
    close(uart_fd);
}


void Uart_Tx(const char *http_packet){
    int uart_fd = uart_init();

    if (uart_fd < 0) {
        fprintf(stderr, "Failed to initialize UART\n");
        return; // Corrected return type to match function signature
    }
    
    printf("\nSending Data through UART..\n");

    int bytes_sent = uart_send(uart_fd, http_packet);
    if (bytes_sent < 0) {
        fprintf(stderr, "Failed to send JSON data over UART\n");
        close(uart_fd); // Added to close UART in case of error
        return; // Corrected return type to match function signature
    }
    
    uart_close(uart_fd);
    printf("\nData transmitted to Thermostat :) \n");
}
