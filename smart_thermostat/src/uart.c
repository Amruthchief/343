#include "headerfiles\uart.h"
#include <stdio.h>
#include <string.h>



void uart_send(uint8_t *data, uint32_t length){
    printf("Uart Tx: %s\n", data);
}

void uart_recieve(uint8_t *buffer, uint32_t length){
    strcpy((char *)buffer, "Uart Rx\n");
}
