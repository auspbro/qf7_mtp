#ifndef _LED_H_
#define _LED_H_

#include "mtp_defs.h"

#define LED_DEBUG

#define LEDE(...)\
	LOGE("LED", ##__VA_ARGS__)

#ifdef LED_DEBUG
#define LEDD(...)\
	LOGD("LED", ##__VA_ARGS__)
#else
#define LEDD(...)
#endif

int Leda_On(char* ret, char *prmtr);
int Leda_Off(char* ret, char *prmtr);
int Ledab_r(char *ret, char *prmtr);
int Ledab_g(char *ret, char *prmtr);
int Ledab_b(char *ret, char *prmtr);
int Ledab_w(char *ret, char *prmtr);
int Ledab_o(char *ret, char *prmtr);

#endif // End of _LED_H_
