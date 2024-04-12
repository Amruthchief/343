#include "uart.h"

#include <stdio.h>
#include <string.h>

int main(){



    
    // Send data over UART
    uint8_t data_to_send[] = "Hello from app.c";
    uart_send(data_to_send, strlen((char *)data_to_send));
    
    // Receive data over UART
    uint8_t received_data[50];
    uart_receive(received_data, sizeof(received_data));
    
    // Process received data
    printf("Received data in app.c: %s\n", received_data);
    

    return 0;
}