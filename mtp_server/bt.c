#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bt.h"
#include "memory.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <errno.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#define string_len 50
#if 0
#define BT_TX_On_Cmd_1 "rfkill unblock all"
#define BT_TX_On_Cmd_2 "hciconfig hci0 up"
#define BT_TX_On_Cmd_3 "hcitool cmd 0x08 0x001e 0x00 0x25 0x00"
#define BT_TX_Off_Cmd "hcitool cmd 0x08 0x001f"
#else
#define BT_TX_On_Cmd_1 "./../../../home/root/Q_BT_TX_ONOFF.sh ON"
#define BT_TX_On_Cmd_2 "./../../../home/root/Q_BT_TX_ONOFF.sh OFF"
#define BT_BRCST_Cmd "./../../../home/root/Q_BT_TX_ONOFF.sh BRCST"
#define BT_MAC_WR_Cmd "./../../../home/root/Q_cfg_bt_mac.sh"
#define BT_HIGHT_PWR_Cmd "./../../../home/root/Q_leda_bt.sh BT_HIGHT_PWR"
#define BT_LOW_PWR_Cmd "./../../../home/root/Q_leda_bt.sh BT_LOW_PWR"
#define BT_DEVICE_Cmd "./../../../home/root/Q_leda_bt.sh BT_DEVICE"
#endif

int BT_Get_mac(char *bdaddr)
{
	struct hci_dev_info di = {0};
	int sock, i, adapter_id,ctl;

	if ((ctl = socket(AF_BLUETOOTH, SOCK_RAW, BTPROTO_HCI)) < 0) {
		perror("Can't open HCI socket.");
		return ERNODEV;
	}

	if (ioctl(ctl, HCIGETDEVINFO, (void *) &di)) {
		perror("Can't get device info");
		close(ctl);
		di.dev_id = hci_get_route(NULL);
		sock = hci_open_dev(di.dev_id);

		if(di.dev_id < 0 || sock < 0)
		{
			BTE("%s: sock[%d] %d: %s",
				__func__, sock, errno, strerror(errno));
			return ERNODEV;
		}

		BTD("%s: dev_id[%d], sock[%d]",__func__, di.dev_id, sock);

		hci_read_bd_addr(sock, &di.bdaddr, 1000);
		hci_close_dev(sock);
	}
#if 0
	BTD("%s: bdaddr: %02X%02X%02X%02X%02X%02X",
		__func__,
		di.bdaddr.b[5],
		di.bdaddr.b[4],
		di.bdaddr.b[3],
		di.bdaddr.b[2],
		di.bdaddr.b[1],
		di.bdaddr.b[0]);
#endif
	sprintf(bdaddr, "%02X%02X%02X%02X%02X%02X",
		di.bdaddr.b[5],
		di.bdaddr.b[4],
		di.bdaddr.b[3],
		di.bdaddr.b[2],
		di.bdaddr.b[1],
		di.bdaddr.b[0]);

	close(ctl);
	return 0;
}

int BT_TX_On(char *ret, char *prmtr)
{
	BTD("%s", __func__);

	system(BT_TX_On_Cmd_1);

	strcpy(ret, "BTPWR_ON=PASS");

	return 0;
}

int BT_TX_Off(char *ret, char *prmtr)
{
	BTD("%s", __func__);

	system(BT_TX_On_Cmd_2);

	strcpy(ret, "BTPWR_OFF=PASS");

	return 0;
}

int BT_MAC_Read(char *ret, char *prmtr)
{
	char bdaddr[BDADDR_LEN];
	char s1[BT_MAC_RET_LEN]="BTMAC_READ=";

	BTD("%s", __func__);
	//system(BT_BRCST_Cmd);
	if(!BT_Get_mac(bdaddr))
	{
		BTD("%s: BD addr: %s\n", __func__, bdaddr);
	}
	else
	{
		BTE("%s: Get bdaddr failed!\n", __func__);
		sprintf(bdaddr, "FAIL");
	}

	strcat(s1, bdaddr);
	strcpy(ret, s1);
	return 0;
}

int BT_MAC_Write(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [string_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	BTD("%s", __func__);

    	BTD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	BTD("cmd:[%s]",cmd_buf); 
    	BTD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", BT_MAC_WR_Cmd, prmtr_buf);
	system(command);

	pFile = fopen ("Q_BTMAC.txt" , "r");
	if(pFile==NULL) {
   		BTD("%s-Fail To Open File Q_BTMAC.txt!!", __func__);
   		strcpy(ret, "Q_BTMAC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , string_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	BTD("%s", string);
	strcpy(ret, string);

	return 0;
}

int BT_Device(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[20];
	char string [string_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	BTD("%s", __func__);

    	system(BT_DEVICE_Cmd);

	pFile = fopen ("Q_LEDA_BT.txt" , "r");
	if(pFile==NULL) {
   		BTD("%s-Fail To Open File Q_LEDA_BT.txt!!", __func__);
   		strcpy(ret, "Q_LEDA_BT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , string_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	BTD("%s", string);
	strcpy(ret, string);

	return 0;
}

int BT_Hight_Pwr(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char string [string_len];
	FILE * pFile;
	BTD("%s", __func__);

    	system(BT_HIGHT_PWR_Cmd);

	pFile = fopen ("Q_LEDA_BT.txt" , "r");
	if(pFile==NULL) {
   		BTD("%s-Fail To Open File Q_LEDA_BT.txt!!", __func__);
   		strcpy(ret, "Q_LEDA_BT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , string_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	BTD("%s", string);
	strcpy(ret, string);

	return 0;
}

int BT_Low_Pwr(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char string [string_len];
	FILE * pFile;
	BTD("%s", __func__);

    	system(BT_LOW_PWR_Cmd);

	pFile = fopen ("Q_LEDA_BT.txt" , "r");
	if(pFile==NULL) {
   		BTD("%s-Fail To Open File Q_LEDA_BT.txt!!", __func__);
   		strcpy(ret, "Q_LEDA_BT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , string_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	BTD("%s", string);
	strcpy(ret, string);

	return 0;
}


