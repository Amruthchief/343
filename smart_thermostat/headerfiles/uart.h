#ifndef UART
#define UART
#include <stdint.h>

// #tx uart data
void uart_send(uint8_t *data, uint32_t length);
// #rx uart data
void uart_recieve(uint8_t *data, uint32_t length);


#endif