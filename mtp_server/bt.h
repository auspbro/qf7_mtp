#ifndef _BT_H_
#define _BT_H_

#include "mtp_defs.h"

#define ERNODEV	(-1)

#define BT_DEBUG

#define BDADDR_LEN	12
#define BT_MAC_RET_LEN	32

#define BTE(...)\
	LOGE("BT", ##__VA_ARGS__)

#ifdef BT_DEBUG
#define BTD(...)\
	LOGD("BT", ##__VA_ARGS__)
#else
#define BTD(...)
#endif

int BT_TX_On(char* ret, char *prmtr);
int BT_TX_Off(char* ret, char *prmtr);
int BT_MAC_Read(char *ret, char *prmtr);
int BT_MAC_Write(char *ret, char *prmtr);
int BT_Device(char *ret, char *prmtr);
int BT_Hight_Pwr(char *ret, char *prmtr);
int BT_Low_Pwr(char *ret, char *prmtr);

#endif // End of _BT_H_

