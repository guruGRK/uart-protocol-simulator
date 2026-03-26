#include  <stdio.h>
#include  "protocol.h"

int main()
{
    unsigned char packet1[]={0xAA,0x01,0x01,0x01,0xAD};
    unsigned char packet2[]={0xAA,0x01,0x02,0x00,0xAD};

    int size1 = sizeof(packet1)/sizeof(packet1[0]);
    int size2 = sizeof(packet2)/sizeof(packet2[0]);

    printf("\tLED test\n");
    for(int i=0;i<size1;i++)
    {
        command_parse(packet1[i]);
    }

    printf("\tSensor Test\n");
    for(int i=0;i<size2;i++)
    {
        command_parse(packet2[i]);
    }
    return 0;
}
