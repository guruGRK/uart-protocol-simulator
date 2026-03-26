#ifndef  COMMAND_H
#define  COMMAND_H

void  send_response(unsigned char status,unsigned char data);
void  handle_command(unsigned char cmd,unsigned char data);

#endif // COMMAND_H
