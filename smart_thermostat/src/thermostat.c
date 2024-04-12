#include "headerfiles/uart.h"

// Function in thermostat.c to handle received UART data
void handle_uart_data(uint8_t *data, uint32_t length) {
    // Process received data
    printf("Received data in thermostat.c: %s\n", data);
}

int main() {
 
    // Send data over UART
    uint8_t data_to_send[] = "Hello from thermostat.c";
    uart_send(data_to_send, strlen((char *)data_to_send));
    
    // Receive data over UART
    uint8_t received_data[50];
    uart_receive(received_data, sizeof(received_data));
    
    // Process received data
    handle_uart_data(received_data, sizeof(received_data));
    
    return 0;
}