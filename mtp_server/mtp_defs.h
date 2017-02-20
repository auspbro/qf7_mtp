#ifndef _MTP_DEFS_
#define _MTP_DEFS_

#include <stdio.h>

#define DEBUG

//#define IFNAME "eth0"
#define IFNAME "eth1"
//#define IFNAME "br0"
#define DUT_SERVER_ADDR	"10.10.10.6"
#define DUT_NET_MASK	"255.255.255.0"
#define DUT_SERVER_PORT	9734
#define REUSE_ENABLE	1
#define CMD_BUF_SZ	128
#define CMD_ERR "Command error "
#define IP_CHECK_DELAY	3
#define WIRE_PLUGGED	"1"

#define LOGE(_mod_name_, _fmt_, ...)\
	printf("[%s][ERROR] "_fmt_"\n",_mod_name_, ##__VA_ARGS__)

#ifdef DEBUG
#define LOGD(_mod_name_, _fmt_, ...)\
	printf("[%s] "_fmt_"\n",_mod_name_, ##__VA_ARGS__)
#else
#define LOGD(...)
#endif

#endif // End of _MTP_DEFS_
