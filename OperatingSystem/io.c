#include "io.h"
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

 #define FB_HIGH_BYTE_COMMAND    14
    #define FB_LOW_BYTE_COMMAND     15
void fb_move_cursor(unsigned short pos){
    outb(FB_COMMAND_PORT,FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,(pos >> 8) & 0x00FF);
    outb(FB_COMMAND_PORT,FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,pos & 0x00FF);
}


#define SERIAL_COM1_BASE 0x3F8

#define SERIAL_FIFO_COMMAND_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)


#define SERIAL_LINE_ENABLE_DLAB      0x80

void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
{
    outb(SERIAL_LINE_COMMAND_PORT(com),
        SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
        (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
        divisor & 0x00FF);


} 
void serial_configure_line(unsigned short com)
    {
        /* Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
         * Content: | d | b | prty  | s | dl  |
         * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
         */
        outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
    }