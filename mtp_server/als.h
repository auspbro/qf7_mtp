#ifndef _ALS_H_
#define _ALS_H_

#include "mtp_defs.h"

#define ALS_DEBUG

#define ALSE(...)\
	LOGE("ALS", ##__VA_ARGS__)

#ifdef ALS_DEBUG
#define ALSD(...)\
	LOGD("ALS", ##__VA_ARGS__)
#else
#define ALSD(...)
#endif

int Als_I2c(char* ret, char *prmtr);
int Als_BL(char *ret, char *prmtr);
int Als_LL(char *ret, char *prmtr);
int Als_Tmp_I2c(char *ret, char *prmtr);
int Als_Tmp_Temperature(char *ret, char *prmtr);

#endif // End of _ALS_H_

