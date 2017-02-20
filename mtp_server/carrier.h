#ifndef _CARRIER_H_
#define _CARRIER_H_

#include "mtp_defs.h"

#define CARRIER_DEBUG

#define CARRIERE(...)\
	LOGE("CARRIER", ##__VA_ARGS__)

#ifdef CARRIER_DEBUG
#define CARRIERD(...)\
	LOGD("CARRIER", ##__VA_ARGS__)
#else
#define CARRIERD(...)
#endif

int Carrier_HDMI(char *ret, char *prmtr);
int Carrier_I2c_Bmc150_G(char *ret, char *prmtr);
int Carrier_I2c_Bmc150_M(char *ret, char *prmtr);
int Carrier_I2c_Ina230(char *ret, char *prmtr);
int Carrier_I2c_Cx20921(char *ret, char *prmtr);
int Carrier_I2c_Tmp_48(char *ret, char *prmtr);
int Carrier_I2c_Tmp_4a(char *ret, char *prmtr);
int Carrier_I2c_Eeprom_57(char *ret, char *prmtr);
int Carrier_I2c_Eeprom_5f(char *ret, char *prmtr);
int Carrier_I2c_Det_MIPI(char *ret, char *prmtr);
int Carrier_Touch_I2c(char *ret, char *prmtr);
int Carrier_Touch_Load_Drv(char *ret, char *prmtr);
int Carrier_Touch_Uload_Drv(char *ret, char *prmtr);
int Carrier_BL_En_On(char *ret, char *prmtr);
int Carrier_BL_En_Off(char *ret, char *prmtr);
int Carrier_BL_Pwm_Dim(char *ret, char *prmtr);
int Carrier_BL_Pwm_Full(char *ret, char *prmtr);
int Carrier_Lcd_On(char *ret, char *prmtr);
int Carrier_Lcd_Off(char *ret, char *prmtr);
int Carrier_Tmp_Temperature_48(char *ret, char *prmtr);
int Carrier_Tmp_Temperature_4a(char *ret, char *prmtr);
int Carrier_Tpm_Part(char *ret, char *prmtr);
int Carrier_Tpm_FW_V(char *ret, char *prmtr);
int Carrier_Tpm_PCR(char *ret, char *prmtr);
int Carrier_CPLD_Present(char *ret, char *prmtr);
int Carrier_CPLD_Version(char *ret, char *prmtr);
int Carrier_HW_Version(char *ret, char *prmtr);
int Carrier_USB_Audio(char *ret, char *prmtr);
int Carrier_Speaker_Left(char *ret, char *prmtr);
int Carrier_Speaker_Right(char *ret, char *prmtr);
int Carrier_DMIC_Left(char *ret, char *prmtr);
int Carrier_DMIC_Left_Play(char *ret, char *prmtr);
int Carrier_DMIC_Right(char *ret, char *prmtr);
int Carrier_DMIC_Right_Play(char *ret, char *prmtr);
int Carrier_Health_R_VOG(char *ret, char *prmtr);
int Carrier_Health_R_CUR(char *ret, char *prmtr);
int Carrier_Health_R_PWR(char *ret, char *prmtr);
int Carrier_Health_TMP108_48(char *ret, char *prmtr);
int Carrier_Health_TMP108_4a(char *ret, char *prmtr);
int Carrier_SPI_Carrier(char *ret, char *prmtr);
int Carrier_SPI_Qseven(char *ret, char *prmtr);
int Carrier_BIOS_Version(char *ret, char *prmtr);
int USB_Check(char *ret, char *prmtr);
int Serial_Number_Write_SPI(char *ret, char *prmtr);
int Serial_Number_Read_SPI(char *ret, char *prmtr);
int Carrier_ETH_MAC_Write(char *ret, char *prmtr);
int Qseven_ETH_MAC_Write(char *ret, char *prmtr);
int Carrier_ETH_MAC_Read(char *ret, char *prmtr);
int Qseven_ETH_MAC_Read(char *ret, char *prmtr);
int Qseven_BIOS_Version(char *ret, char *prmtr);
int Carrier_Eth_Poe_Speed(char *ret, char *prmtr);
int Carrier_Eth_Poe_Device(char *ret, char *prmtr);
int Carrier_Eth_Poe_Duplex(char *ret, char *prmtr);
int Carrier_Eth_NPoe_Speed(char *ret, char *prmtr);
int Carrier_Eth_NPoe_Device(char *ret, char *prmtr);
int Carrier_Eth_NPoe_Duplex(char *ret, char *prmtr);
int Read_Street_Result(char *ret, char *prmtr);
int Nfc_Detect(char *ret, char *prmtr);
int Serial_Number_Read_SMBIOS(char *ret, char *prmtr);
int Serial_Number_Write_SMBIOS(char *ret, char *prmtr);
int Carrier_Eth_Poe_AF_Type(char *ret, char *prmtr);
int Carrier_Eth_Poe_AT_Type(char *ret, char *prmtr);
int Carrier_Usb_Ext(char *ret, char *prmtr);
int Carrier_Touch_Screen_Test(char *ret, char *prmtr);
int Carrier_Emmc_Info(char *ret, char *prmtr);
int Carrier_Ledb_Nfc(char *ret, char *prmtr);
#endif // End of _CARRIER_H_

