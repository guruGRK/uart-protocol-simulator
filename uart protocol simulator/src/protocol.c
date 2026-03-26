#include  <stdio.h>
#include  "protocol.h"
#include  "command.h"

enum {
    START,
    READ_LENGTH,
    READ_COMMAND,
    READ_DATA,
    READ_CHECKSUM
};

static unsigned char length,cmd,data,checksum,calc_checksum;
static int state = START;

void  command_parse(unsigned char byte)
{
    switch(state)
    {
       case START:
           if(byte == 0xAA){
                calc_checksum = byte;
                state = READ_LENGTH;
           }
           break;

       case READ_LENGTH:
           length = byte;
           calc_checksum += byte;
           state = READ_COMMAND;
           break;

       case READ_COMMAND:
           cmd = byte;
           calc_checksum += byte;
           state = READ_DATA;
           break;

       case READ_DATA:
           data = byte;
           calc_checksum += byte;
           state = READ_CHECKSUM;
           break;

       case READ_CHECKSUM:
           checksum = byte;
           if(checksum == calc_checksum)
               handle_command(cmd,data);
           else
               printf("Checksum error");
           state = START;
           break;

    }
}




















