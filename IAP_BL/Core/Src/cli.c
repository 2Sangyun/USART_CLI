/*
 * cli.c
 *
 *  Created on: Jul 21, 2022
 *      Author: 유지현
 */


#include <stdio.h>
#include <string.h>

#include "cli.h"



char cmd_buf[MAX_CMD_BUFFER_LENGTH];
char tmp_buf[MAX_CMD_BUFFER_LENGTH];


void CliInit(UART_HandleTypeDef* huart)
{
	QueueInit(&que);
	UartInit(huart);
	CommandInit();
	CliDisplayInfo();
}


void CliDisplayInfo()
{
	printf("===========================================================================\r\n");
	printf("* Created on: 2022-07-15\r\n");
	printf("* Author: sangyun\r\n");
	printf("* Uart CLI Ver 1.0\r\n");
	printf("===========================================================================\r\n");
}


void CliDo(UART_HandleTypeDef* huart)
{
	memset(cmd_buf, 0x00, MAX_CMD_BUFFER_LENGTH);

	UartTransmitBuffer(huart, (uint8_t *)"CMD>>", 6);

	if(UartReceiveBuffer(huart, (uint8_t *)cmd_buf, MAX_CMD_BUFFER_LENGTH) == 0){
		return;
	}
	CLiParseCmdLine(huart, cmd_buf);
	HAL_Delay(10);

}


void CLiParseCmdLine(UART_HandleTypeDef* huart, char* cmd_line)
{
	static const char *delim = " \f\n\r\t\v";
	char* tok;
	char* next_ptr;
	char *argv[5]= {0,};
	uint8_t argc = 0;

	//char tmp_line[MAX_CMD_BUFFER_LENGTH];
	memset(tmp_buf, 0x00, sizeof(tmp_buf));

	memcpy(tmp_buf, cmd_line, strlen(cmd_line));

	tok = strtok_r(tmp_buf, delim, &next_ptr);

	while(tok){
		argv[argc++] = tok;
		tok = strtok_r(NULL, delim, &next_ptr);
	}

	CliMatchCommand(argc, argv);
}


void CliMatchCommand(uint8_t argc, char* argv[])
{
	CommnadDo(argc, argv);
}






