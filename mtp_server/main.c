#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>
#include <sys/ioctl.h>
#include "mtp_defs.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include "led.h"
#include "bt.h"
#include "als.h"
#include "carrier.h"
#define REBOOT_ON "reboot"
#define ROOT_ON "root"
#define CARRIER_INIT "./../../../home/root/a_init.sh"
typedef struct _mtp_cmd {
    char cmd_str[CMD_BUF_SZ];
    int (*func)(char *, char *);
} mtp_cmd;

int Reboot(char *ret, char *prmtr)
{
	LOGD("QCI", "%s", __func__);
	system(REBOOT_ON);
	strcpy(ret, "REBOOT=PASS");

	return 0;
}
int Root(char *ret, char *prmtr)
{
	LOGD("QCI", "%s", __func__);

	system(ROOT_ON);
	system(ROOT_ON);
	system(ROOT_ON);
	system(ROOT_ON);
	system(ROOT_ON);
	strcpy(ret, "ROOT=PASS");

	return 0;
}
int Carrier_init(char *ret, char *prmtr)
{
	LOGD("QCI", "%s", __func__);

	system(CARRIER_INIT);
	
	strcpy(ret, "CARRIER_INIT=PASS");

	return 0;
}

static mtp_cmd mtp_cmd_table[] =
{
    {"REBOOT", Reboot},
    {"ROOT", Root},
    {"CARRIER_INIT", Carrier_init},
//LED    
    {"LEDA_ON", Leda_On},
    {"LEDA_OFF", Leda_Off},
    {"LEDAB_R", Ledab_r},
    {"LEDAB_G", Ledab_g},
    {"LEDAB_B", Ledab_b},
    {"LEDAB_W", Ledab_w},
    {"LEDAB_O", Ledab_o},
//BT    
    {"BTPWR_ON", BT_TX_On},
    {"BTPWR_OFF", BT_TX_Off},
    {"BTMAC_READ",BT_MAC_Read },
    {"BTMAC_WRITE",BT_MAC_Write },
    {"BT_DEVICE",BT_Device },
    {"BT_HIGHT_PWR",BT_Hight_Pwr },
    {"BT_LOW_PWR",BT_Low_Pwr },
//ALS    
    {"ALS_I2C", Als_I2c},
    {"ALS_BL", Als_BL},
    {"ALS_LL", Als_LL},
    {"ALS_TMP_I2C", Als_Tmp_I2c},
    {"ALS_TMP_TEMPERATURE", Als_Tmp_Temperature},
//HDMI    
    {"CARRIER_HDMI", Carrier_HDMI},
//I2c detect    
    {"CARRIER_I2C_BMC150_G", Carrier_I2c_Bmc150_G},
    {"CARRIER_I2C_BMC150_M", Carrier_I2c_Bmc150_M},
    {"CARRIER_I2C_INA230", Carrier_I2c_Ina230},
    {"CARRIER_I2C_CX20921",Carrier_I2c_Cx20921 },
    {"CARRIER_I2C_TMP_48", Carrier_I2c_Tmp_48},
    {"CARRIER_I2C_TMP_4a", Carrier_I2c_Tmp_4a},
    {"CARRIER_I2C_EEPROM_57", Carrier_I2c_Eeprom_57},
    {"CARRIER_I2C_EEPROM_5f", Carrier_I2c_Eeprom_5f},
    {"CARRIER_I2C_DET_MIPI", Carrier_I2c_Det_MIPI},
//Touch    
    {"CARRIER_TOUCH_I2C", Carrier_Touch_I2c},
    {"CARRIER_TOUCH_LOAD_DRV", Carrier_Touch_Load_Drv},
    {"CARRIER_TOUCH_ULOAD_DRV", Carrier_Touch_Uload_Drv},
    {"CARRIER_TOUCH_SCREEN_TEST", Carrier_Touch_Screen_Test},
//Backlight    
    {"CARRIER_BL_EN_ON", Carrier_BL_En_On},
    {"CARRIER_BL_EN_OFF", Carrier_BL_En_Off},
    {"CARRIER_BL_PWM_DIM", Carrier_BL_Pwm_Dim},
    {"CARRIER_BL_PWM_FULL", Carrier_BL_Pwm_Full},
//LCD ON    
    {"CARRIER_LCD_ON", Carrier_Lcd_On},
    {"CARRIER_LCD_OFF", Carrier_Lcd_Off},
//TEMPERTAURE    
    {"CARRIER_TMP_TEMPERATURE_48", Carrier_Tmp_Temperature_48},
    {"CARRIER_TMP_TEMPERATURE_4a", Carrier_Tmp_Temperature_4a},
//CPLD &TPM    
    {"CARRIER_TPM_PART", Carrier_Tpm_Part},
    {"CARRIER_TPM_FW_V", Carrier_Tpm_FW_V},
    {"CARRIER_TPM_PCR", Carrier_Tpm_PCR},
    {"CARRIER_CPLD_PRESENT", Carrier_CPLD_Present},
    {"CARRIER_CPLD_VERSION", Carrier_CPLD_Version},
    {"CARRIER_HW_VERSION", Carrier_HW_Version},
//Audio    
    {"CARRIER_USB_AUDIO", Carrier_USB_Audio},
    {"CARRIER_SPEAKER_LEFT", Carrier_Speaker_Left},
    {"CARRIER_SPEAKER_RIGHT", Carrier_Speaker_Right},
    {"CARRIER_DMIC_RIGHT", Carrier_DMIC_Right},
    {"CARRIER_DMIC_R_PLAY", Carrier_DMIC_Right_Play},
    {"CARRIER_DMIC_LEFT", Carrier_DMIC_Left},
    {"CARRIER_DMIC_L_PLAY", Carrier_DMIC_Left_Play},
//HEALTH    
    {"CARRIER_HEALTH_R_VOG", Carrier_Health_R_VOG},
    {"CARRIER_HEALTH_R_CUR", Carrier_Health_R_CUR},
    {"CARRIER_HEALTH_R_PWR", Carrier_Health_R_PWR},
    {"CARRIER_HEALTH_TMP108_48", Carrier_Health_TMP108_48},
    {"CARRIER_HEALTH_TMP108_4a", Carrier_Health_TMP108_4a},
//BIOS    
    {"CARRIER_UPGRADE_BIOS", Carrier_SPI_Carrier},
    {"QSEVEN_UPGRADE_BIOS", Carrier_SPI_Qseven},
    {"CARRIER_BIOS_VERSION", Carrier_BIOS_Version},
    {"QSEVEN_BIOS_VERSION", Qseven_BIOS_Version},
//MAC  & Serial
    {"USB_CHECK", USB_Check},
    {"SERIAL_NUMBER_WRITE_SPI", Serial_Number_Write_SPI},
    {"SERIAL_NUMBER_READ_SPI", Serial_Number_Read_SPI},
    {"CARRIER_ETH_MAC_WRITE", Carrier_ETH_MAC_Write},
    {"QSEVEN_ETH_MAC_WRITE", Qseven_ETH_MAC_Write},
    {"CARRIER_ETH_MAC_READ", Carrier_ETH_MAC_Read},
    {"QSEVEN_ETH_MAC_READ", Qseven_ETH_MAC_Read},
 //RJ45   
    {"CARRIER_ETH_POE_SPEED", Carrier_Eth_Poe_Speed},
    {"CARRIER_ETH_POE_DEVICE", Carrier_Eth_Poe_Device},
    {"CARRIER_ETH_POE_DUPLEX", Carrier_Eth_Poe_Duplex},
    {"CARRIER_ETH_NPOE_SPEED", Carrier_Eth_NPoe_Speed},
    {"CARRIER_ETH_NPOE_DEVICE", Carrier_Eth_NPoe_Device},
    {"CARRIER_ETH_NPOE_DUPLEX", Carrier_Eth_NPoe_Duplex},
    {"READ_STREET_RESULT", Read_Street_Result},
    {"NFC_DETECT", Nfc_Detect},
    {"SERIAL_NUMBER_W_SMBIOS", Serial_Number_Write_SMBIOS},
    {"SERIAL_NUMBER_R_SMBIOS", Serial_Number_Read_SMBIOS},
    {"CARRIER_ETH_POE_AF_TYPE", Carrier_Eth_Poe_AF_Type},
    {"CARRIER_ETH_POE_AT_TYPE", Carrier_Eth_Poe_AT_Type},
    {"CARRIER_USB_EXT", Carrier_Usb_Ext},
    {"CARRIER_EMMC_INFO", Carrier_Emmc_Info},
    {"CARRIER_LEDB_NFC", Carrier_Ledb_Nfc},
    
};

static bool checklink(void)
{
	int netfd;
	char sys_net[] = "/sys/class/net/"IFNAME"/carrier";
	char plugged[] = {"0"};

	if ((netfd = open(sys_net, O_RDONLY)) == -1)
	{
		LOGE("QCI", "%s is not a vaild device.n", sys_net);
		return false;
	}
	else
	{
		read(netfd, plugged, 2);
		close(netfd);
	}

	if(!strncmp(plugged, WIRE_PLUGGED, strlen(WIRE_PLUGGED)))
	{
//		LOGD("QCI", "%s: wire is plugged:%s", __func__,plugged);
		return true;
	}
	else
	{
//		LOGD("QCI", "%s: wire is unplugged:%s", __func__,plugged);
		return false;
	}

}

static void *checkIPThread(void *ptr)
{
	struct ifreq ifr = {0};
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
	struct sockaddr_in* addr = (struct sockaddr_in*)&ifr.ifr_addr;
	char dev_addr[INET_ADDRSTRLEN] = {0};
	bool flag_unplugged = checklink();

	LOGD("QCI", "%s", __func__);

	pthread_detach(pthread_self());

	strncpy(ifr.ifr_name, IFNAME, IFNAMSIZ);
	ifr.ifr_addr.sa_family = AF_INET;

	if(flag_unplugged)
		LOGD("QCI", "%s: wire is un-plugged", __func__);

	while(1)
	{
		if(checklink())
		{
			if(flag_unplugged)
			{
				LOGD("QCI", "%s: wire is plugged", __func__);

				// Get current IP address
				ioctl(fd, SIOCGIFADDR, &ifr);
				inet_ntop(AF_INET, &addr->sin_addr, dev_addr, INET_ADDRSTRLEN);
				LOGD("QCI", "IP Address %s", dev_addr);

				if(strncmp(dev_addr, DUT_SERVER_ADDR, strlen(DUT_SERVER_ADDR)))
				{
					LOGD("QCI", "Set IP Address to %s", DUT_SERVER_ADDR);
					inet_pton(AF_INET, DUT_SERVER_ADDR, &addr->sin_addr);
					ioctl(fd, SIOCSIFADDR, &ifr);

					LOGD("QCI", "Set Net Mask to %s", DUT_NET_MASK);
					inet_pton(AF_INET, DUT_NET_MASK, &addr->sin_addr);
					ioctl(fd, SIOCSIFNETMASK, &ifr);

					ioctl(fd, SIOCGIFFLAGS, &ifr);
					ifr.ifr_flags |= (IFF_UP | IFF_RUNNING);
					ioctl(fd, SIOCSIFFLAGS, &ifr);
				}
				else
					flag_unplugged = false;
			}
		}
		else
		{
			if(!flag_unplugged)
				LOGD("QCI", "%s: wire is un-plugged", __func__);

			flag_unplugged = true;
		}
		sleep(IP_CHECK_DELAY);
	}
}

int main(int argc, char **argv)
{
	int count=0;
	pthread_t thread;

	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	char cmd_buf[CMD_BUF_SZ] = {0};
	char result_buf[CMD_BUF_SZ] = {0};
	int reuse = REUSE_ENABLE;
	unsigned int cmd_id = 0;
	unsigned int m_cmd_num;

	LOGD("QCI", "MTP Start");

	m_cmd_num = sizeof(mtp_cmd_table)/sizeof(mtp_cmd_table[0]);
	pthread_create(&thread, NULL , checkIPThread , NULL);


	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
	{
		LOGE("QCI", "setsockopt(SO_REUSEADDR) failed");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(DUT_SERVER_PORT);
	server_len =  sizeof(server_addr);
	bind(server_sockfd, (struct sockaddr *)&server_addr,
					server_len);
	listen(server_sockfd, 5);

	while(1)
	{
		LOGD("QCI", "Server waiting...");

		client_len = sizeof(client_addr);
		client_sockfd = accept(server_sockfd,
						(struct sockaddr *)&client_addr, &client_len);

		read(client_sockfd, cmd_buf, CMD_BUF_SZ);
		LOGD("QCI", "Recv char[%s]", cmd_buf);

		strcpy(result_buf, CMD_ERR);
		for(cmd_id=0; cmd_id<m_cmd_num; cmd_id++)
		{
			if(mtp_cmd_table[cmd_id].cmd_str != NULL)
			{
				if(!strncmp(cmd_buf, mtp_cmd_table[cmd_id].cmd_str,
										strlen(mtp_cmd_table[cmd_id].cmd_str)))
				{	
					mtp_cmd_table[cmd_id].func(result_buf,cmd_buf);
					break;
				}
			}
		}

		if(strlen(result_buf))
		{
			LOGD("QCI", "Send result [%s]", result_buf);
			write(client_sockfd, result_buf, strlen(result_buf));
		}
		close(client_sockfd);
	}

	return 0;
}
