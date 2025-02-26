LAB3 for RTS ENGR 432

This is the transmission and ADC measurement code, not the LCD and UART receive code.

Part 1 initially complete. 
Sending ADC data from PA4 over USART2 PD5 and PD6 pins. 
ADC data is 12 bits, so data is split across two 8 bit UART transmissions. 
See timer_loop() function to see how this is split. Transmissions occur every 10mS as per tim14.
