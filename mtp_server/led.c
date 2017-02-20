#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "led.h"

#define LED_On_Cmd "./../../../home/root/scripts/leds_configure.sh 0xFF 0x64"
#define LED_Off_Cmd "./../../../home/root/scripts/leds_configure.sh 0x00 0x64"
#define LEDAB_R_Cmd "./../../../home/root/Q_LED.sh 0xFF R"
#define LEDAB_G_Cmd "./../../../home/root/Q_LED.sh 0xFF G"
#define LEDAB_B_Cmd "./../../../home/root/Q_LED.sh 0xFF B"
#define LEDAB_O_Cmd "./../../../home/root/Q_LED.sh 0xFF O"
#define LEDAB_W_Cmd "./../../../home/root/Q_LED.sh 0xFF W"


#define s_len 50
int Leda_On(char *ret, char *prmtr)
{
	LEDD("%s", __func__);

	system(LED_On_Cmd);
	strcpy(ret, "LEDA_ON=PASS");

	return 0;
}

int Leda_Off(char *ret, char *prmtr)
{
	LEDD("%s", __func__);

	system(LED_Off_Cmd);
	strcpy(ret, "LEDA_OFF=PASS");

	return 0;
}

int Ledab_r(char *ret, char *prmtr)
{
	LEDD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [s_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	LEDD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	LEDD("cmd:[%s]",cmd_buf); 
    	LEDD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", LEDAB_R_Cmd, prmtr_buf);
	system(command);
	
	strcpy(ret, "LEDAB_R=PASS");

	return 0;
}

int Ledab_g(char *ret, char *prmtr)
{
	LEDD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [s_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	LEDD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	LEDD("cmd:[%s]",cmd_buf); 
    	LEDD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", LEDAB_G_Cmd, prmtr_buf);
	system(command);

	strcpy(ret, "LEDAB_G=PASS");

	return 0;
}

int Ledab_b(char *ret, char *prmtr)
{
	LEDD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [s_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	LEDD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	LEDD("cmd:[%s]",cmd_buf); 
    	LEDD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", LEDAB_B_Cmd, prmtr_buf);
	system(command);
	
	strcpy(ret, "LEDAB_B=PASS");

	return 0;
}

int Ledab_w(char *ret, char *prmtr)
{
	LEDD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [s_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	LEDD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	LEDD("cmd:[%s]",cmd_buf); 
    	LEDD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", LEDAB_W_Cmd, prmtr_buf);
	system(command);

	strcpy(ret, "LEDAB_W=PASS");

	return 0;
}

int Ledab_o(char *ret, char *prmtr)
{
	LEDD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [s_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	LEDD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	LEDD("cmd:[%s]",cmd_buf); 
    	LEDD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", LEDAB_O_Cmd, prmtr_buf);
	system(command);
	
	strcpy(ret, "LEDAB_O=PASS");

	return 0;
}
