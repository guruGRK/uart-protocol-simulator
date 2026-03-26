#include  <stdio.h>
#include  "command.h"

void  send_response(unsigned char status,unsigned char data)
{
    switch(status)
    {
       case 0x00:
           printf("Status: Success\nData: %2X\n",data);
           break;
       case 0xFF:
           printf("Status: Failed\n");
           break;
    }
}

void handle_command(unsigned char cmd,unsigned char data)
{
    switch(cmd)
    {
       case 0x01:
           if(data == 1)
                printf("LED ON\n");
            else
                printf("LED OFF\n");
            send_response(0x00, data);         //0x00 Success
            break;

        case 0x02:
        {
            unsigned char temp = 30;
            printf("Temperature: %d\n", temp);
            send_response(0x00, temp);
            break;
        }

        default:
            printf("Unknown\n");
            send_response(0xFF, 0x00);
            break;
    }
}

