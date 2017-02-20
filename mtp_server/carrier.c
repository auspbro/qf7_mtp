#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carrier.h"


#define Carrier_HDMI_Cmd "./../../../home/root/Q_carrier_hdmi.sh"
#define Carrier_I2c_Bmc150_G_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 10"
#define Carrier_I2c_Bmc150_M_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 12"
#define Carrier_I2c_Ina230_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 40"
#define Carrier_I2c_Cx20921_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 41"
#define Carrier_I2c_Tmp_48_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 48"
#define Carrier_I2c_Tmp_4a_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 4a"
#define Carrier_I2c_Eeprom_57_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 57"
#define Carrier_I2c_Eeprom_5f_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 5f"
#define Carrier_I2c_Det_MIPI_Cmd "./../../../home/root/Q_carrier_i2c_detect.sh 68"
#define Carrier_Touch_I2c_Cmd "./../../../home/root/Q_carrier_touch.sh CARRIER_TOUCH_I2C"
#define Carrier_Touch_Load_Drv_Cmd "./../../../home/root/Q_carrier_touch.sh CARRIER_TOUCH_LOAD_DRV"
#define Carrier_Touch_Uload_Drv_Cmd "./../../../home/root/Q_carrier_touch.sh CARRIER_TOUCH_ULOAD_DRV"
#define Carrier_Touch_Screen_Test_Cmd "./../../../home/root/Q_carrier_touch.sh TOUCH_SCREEN_TEST"
#define Carrier_BL_En_On_Cmd "./../../../home/root/Q_carrier_backlight.sh CARRIER_BL_EN_ON"
#define Carrier_BL_En_Off_Cmd "./../../../home/root/Q_carrier_backlight.sh CARRIER_BL_EN_OFF"
#define Carrier_BL_Pwm_Dim_Cmd "./../../../home/root/Q_carrier_backlight.sh CARRIER_BL_PWM_DIM"
#define Carrier_BL_Pwm_Full_Cmd "./../../../home/root/Q_carrier_backlight.sh CARRIER_BL_PWM_FULL"
#define Carrier_Lcd_On_Cmd "./../../../home/root/Q_carrier_lcd.sh CARRIER_LCD_ON"
#define Carrier_Lcd_Off_Cmd "./../../../home/root/Q_carrier_lcd.sh CARRIER_LCD_OFF"
#define Carrier_Tmp_Temperature_48_Cmd "./../../../home/root/Q_carrier_tmp108.sh CARRIER_TMP_TEMPERATURE 48"
#define Carrier_Tmp_Temperature_4a_Cmd "./../../../home/root/Q_carrier_tmp108.sh CARRIER_TMP_TEMPERATURE 4a"
#define Carrier_Tpm_Part_Cmd "./../../../home/root/Q_carrier_tpm.sh CARRIER_TPM_PART"
#define Carrier_Tpm_FW_V_Cmd "./../../../home/root/Q_carrier_tpm.sh CARRIER_TPM_FW_V"
#define Carrier_Tpm_PCR_Cmd "./../../../home/root/Q_carrier_tpm.sh CARRIER_TPM_PCR"
#define Carrier_CPLD_Present_Cmd "./../../../home/root/Q_carrier_cpld.sh CARRIER_CPLD_PRESENT"
#define Carrier_CPLD_Version_Cmd "./../../../home/root/Q_carrier_cpld.sh CARRIER_CPLD_VERSION"
#define Carrier_HW_Version_Cmd "./../../../home/root/Q_carrier_cpld.sh CARRIER_HW_VERSION"
#define Carrier_USB_Audio_Cmd "./../../../home/root/Q_carrier_usb_audio.sh"
#define Carrier_Speaker_Left_Cmd "./../../../home/root/Q_carrier_speaker.sh left"
#define Carrier_Speaker_Right_Cmd "./../../../home/root/Q_carrier_speaker.sh right"
#define Carrier_DMIC_Left_Cmd "./../../../home/root/Q_carrier_dmic.sh left_rec"
#define Carrier_DMIC_Left_Play_Cmd "./../../../home/root/Q_carrier_dmic.sh left_rec_play"
#define Carrier_DMIC_Right_Cmd "./../../../home/root/Q_carrier_dmic.sh right_rec"
#define Carrier_DMIC_Right_Play_Cmd "./../../../home/root/Q_carrier_dmic.sh right_rec_play"
#define Carrier_Health_R_VOG_Cmd "./../../../home/root/Q_carrier_health.sh CARRIER_HEALTH_R_VOG"
#define Carrier_Health_R_CUR_Cmd "./../../../home/root/Q_carrier_health.sh CARRIER_HEALTH_R_CUR"
#define Carrier_Health_R_PWR_Cmd "./../../../home/root/Q_carrier_health.sh CARRIER_HEALTH_R_PWR"
#define Carrier_Health_TMP108_48_Cmd "./../../../home/root/Q_carrier_health.sh CARRIER_HEALTH_TMP108 48"
#define Carrier_Health_TMP108_4a_Cmd "./../../../home/root/Q_carrier_health.sh CARRIER_HEALTH_TMP108 4a"
#define Carrier_SPI_Carrier_Cmd "./../../../home/root/Q_cfg_carrier_spi.sh carrier"
#define Carrier_SPI_Qseven_Cmd "./../../../home/root/Q_cfg_carrier_spi.sh qseven"
#define USB_Check_Cmd "./../../../home/root/Q_USB_check.sh"
#define Serial_Number_Write_SPI_Cmd "./../../../home/root/Q_cfg_eeprom_serial.sh write"
#define Serial_Number_Read_SPI_Cmd "./../../../home/root/Q_cfg_eeprom_serial.sh read"
#define Carrier_ETH_MAC_Write_Cmd "./../../../home/root/Q_cfg_eth_mac.sh CARRIER"
#define Qseven_ETH_MAC_Write_Cmd "./../../../home/root/Q_cfg_eth_mac.sh QSEVEN"
#define Carrier_ETH_MAC_Read_Cmd "./../../../home/root/Q_carrier_eth_mac_read.sh CARRIER"
#define Qseven_ETH_MAC_Read_Cmd "./../../../home/root/Q_carrier_eth_mac_read.sh QSEVEN"
#define Carrier_BIOS_Version_Cmd "./../../../home/root/Q_carrier_spi.sh CARRIER"
#define Qseven_BIOS_Version_Cmd "./../../../home/root/Q_carrier_spi.sh QSEVEN"
#define Carrier_Eth_Poe_Device_Cmd "./../../../home/root/Q_carrier_eth_pri.sh DEVICE"
#define Carrier_Eth_Poe_Speed_Cmd "./../../../home/root/Q_carrier_eth_pri.sh SPEED"
#define Carrier_Eth_Poe_Duplex_Cmd "./../../../home/root/Q_carrier_eth_pri.sh DUPLEX"
#define Carrier_Eth_NPoe_Device_Cmd "./../../../home/root/Q_carrier_eth_sec.sh DEVICE"
#define Carrier_Eth_NPoe_Speed_Cmd "./../../../home/root/Q_carrier_eth_sec.sh SPEED"
#define Carrier_Eth_NPoe_Duplex_Cmd "./../../../home/root/Q_carrier_eth_sec.sh DUPLEX"
#define Nfc_Detect_Cmd "./../../../home/root/Q_NFC.sh"
#define Serial_Number_Write_SMBIOS_Cmd "./../../../home/root/Q_cfg_smbios.sh WRITE_SN"
#define Serial_Number_Read_SMBIOS_Cmd "./../../../home/root/Q_cfg_smbios.sh READ_SN"
#define Carrier_Eth_Poe_AF_Type_Cmd "./../../../home/root/Q_carrier_poe_type.sh AF"
#define Carrier_Eth_Poe_AT_Type_Cmd "./../../../home/root/Q_carrier_poe_type.sh AT"
#define Carrier_Usb_Ext_Cmd "./../../../home/root/Q_carrier_usb_ext.sh"
#define Carrier_Emmc_Info_Cmd "./../../../home/root/Q_carrier_emmc_info.sh"
#define Carrier_Ledb_Nfc_Cmd "./../../../home/root/Q_ledb_nfc.sh"

#define result_len 50

int Carrier_HDMI(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_HDMI_Cmd);

	pFile = fopen ("Q_CARRIER_HDMI.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_HDMI.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_HDMI_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Bmc150_G(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Bmc150_G_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Bmc150_M(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Bmc150_M_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Ina230(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Ina230_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Cx20921(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Cx20921_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Tmp_48(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Tmp_48_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Tmp_4a(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Tmp_4a_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Eeprom_57(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Eeprom_57_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Eeprom_5f(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Eeprom_5f_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_I2c_Det_MIPI(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_I2c_Det_MIPI_Cmd);

	pFile = fopen ("Q_CARRIER_I2C_DETECT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_I2C_DETECT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_I2C_DETECT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Touch_I2c(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Touch_I2c_Cmd);

	pFile = fopen ("Q_CARRIER_TOUCH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TOUCH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TOUCH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Touch_Load_Drv(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Touch_Load_Drv_Cmd);

	pFile = fopen ("Q_CARRIER_TOUCH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TOUCH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TOUCH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Touch_Uload_Drv(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Touch_Uload_Drv_Cmd);

	pFile = fopen ("Q_CARRIER_TOUCH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TOUCH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TOUCH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Touch_Screen_Test(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Touch_Screen_Test_Cmd);

	pFile = fopen ("Q_CARRIER_TOUCH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TOUCH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TOUCH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);
	return 0;
}

int Carrier_BL_En_On(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_BL_En_On_Cmd);

	pFile = fopen ("Q_CARRIER_BACKLIGHT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_BACKLIGHT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_BACKLIGHT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_BL_En_Off(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_BL_En_Off_Cmd);

	pFile = fopen ("Q_CARRIER_BACKLIGHT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_BACKLIGHT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_BACKLIGHT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}
int Carrier_BL_Pwm_Dim(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_BL_Pwm_Dim_Cmd);

	pFile = fopen ("Q_CARRIER_BACKLIGHT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_BACKLIGHT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_BACKLIGHT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_BL_Pwm_Full(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_BL_Pwm_Full_Cmd);

	pFile = fopen ("Q_CARRIER_BACKLIGHT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_BACKLIGHT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_BACKLIGHT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Lcd_On(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Lcd_On_Cmd);

	pFile = fopen ("Q_CARRIER_LCD.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_LCD.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_LCD_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Lcd_Off(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Lcd_Off_Cmd);

	pFile = fopen ("Q_CARRIER_LCD.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_LCD.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_LCD_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Tmp_Temperature_48(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Tmp_Temperature_48_Cmd);

	pFile = fopen ("Q_CARRIER_TMP.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TMP.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TMP_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Tmp_Temperature_4a(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Tmp_Temperature_4a_Cmd);

	pFile = fopen ("Q_CARRIER_TMP.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TMP.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TMP_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Tpm_Part(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Tpm_Part_Cmd);

	pFile = fopen ("Q_CARRIER_TPM.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TPM.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TPM_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Tpm_FW_V(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Tpm_FW_V_Cmd);

	pFile = fopen ("Q_CARRIER_TPM.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TPM.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TPM_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Tpm_PCR(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Tpm_PCR_Cmd);

	pFile = fopen ("Q_CARRIER_TPM.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_TPM.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_TPM_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_CPLD_Present(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_CPLD_Present_Cmd);

	pFile = fopen ("Q_CARRIER_CPLD.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_CPLD.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_CPLD_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_CPLD_Version(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_CPLD_Version_Cmd);

	pFile = fopen ("Q_CARRIER_CPLD.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_CPLD.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_CPLD_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_HW_Version(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_HW_Version_Cmd);

	pFile = fopen ("Q_CARRIER_CPLD.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_CPLD.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_CPLD_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_USB_Audio(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_USB_Audio_Cmd);

	pFile = fopen ("Q_CARRIER_USB_AUDIO.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_USB_AUDIO.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_USB_AUDIO_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Speaker_Left(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Speaker_Left_Cmd);

	pFile = fopen ("Q_CARRIER_SPEAKER.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_SPEAKER.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_SPEAKER_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Speaker_Right(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Speaker_Right_Cmd);

	pFile = fopen ("Q_CARRIER_SPEAKER.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_SPEAKER.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_SPEAKER_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_DMIC_Left(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_DMIC_Left_Cmd);
	sleep(1);
	pFile = fopen ("Q_CARRIER_DMIC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_DMIC.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_DMIC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_DMIC_Left_Play(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_DMIC_Left_Play_Cmd);
	sleep(1);
	pFile = fopen ("Q_CARRIER_DMIC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_DMIC.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_DMIC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_DMIC_Right(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_DMIC_Right_Cmd);
	sleep(1);
	pFile = fopen ("Q_CARRIER_DMIC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_DMIC.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_DMIC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_DMIC_Right_Play(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_DMIC_Right_Play_Cmd);
	sleep(1);
	pFile = fopen ("Q_CARRIER_DMIC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_DMIC.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_DMIC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Health_R_VOG(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Health_R_VOG_Cmd);
	pFile = fopen ("Q_CARRIER_HEALTH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_HEALTH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_HEALTH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Health_R_CUR(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Health_R_CUR_Cmd);
	pFile = fopen ("Q_CARRIER_HEALTH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_HEALTH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_HEALTH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Health_R_PWR(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Health_R_PWR_Cmd);
	pFile = fopen ("Q_CARRIER_HEALTH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_HEALTH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_HEALTH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Health_TMP108_48(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Health_TMP108_48_Cmd);
	pFile = fopen ("Q_CARRIER_HEALTH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_HEALTH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_HEALTH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Health_TMP108_4a(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Health_TMP108_4a_Cmd);
	pFile = fopen ("Q_CARRIER_HEALTH.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_HEALTH.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_HEALTH_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_SPI_Carrier(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	FILE * pFile;
	char *command[30];
    	char string [result_len];
    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Carrier_SPI_Carrier_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("CARRIER_QSEVEN_BIOS.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File CARRIER_QSEVEN_BIOS.txt!!", __func__);
   		strcpy(ret, "CARRIER_QSEVEN_BIOS_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_SPI_Qseven(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	FILE * pFile;
	char *command[30];
    	char string [result_len];
    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Carrier_SPI_Qseven_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("CARRIER_QSEVEN_BIOS.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File CARRIER_QSEVEN_BIOS.txt!!", __func__);
   		strcpy(ret, "CARRIER_QSEVEN_BIOS_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_BIOS_Version(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[30];
	char string [result_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Carrier_BIOS_Version_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("BIOS_CARRIER.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File BIOS_CARRIER.txt!!", __func__);
   		strcpy(ret, "BIOS_CARRIER_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}


int USB_Check(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(USB_Check_Cmd);
	pFile = fopen ("Q_CARRIER_USB.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_USB.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_USB_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Serial_Number_Write_SPI(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[30];
	char string [result_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Serial_Number_Write_SPI_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("Q_EEPROM_SERIAL.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_EEPROM_SERIAL.txt!!", __func__);
   		strcpy(ret, "Q_EEPROM_SERIAL_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Serial_Number_Read_SPI(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char string [result_len];
	FILE * pFile;

	CARRIERD("%s", __func__);
	system(Serial_Number_Read_SPI_Cmd);
	pFile = fopen ("Q_EEPROM_SERIAL.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_EEPROM_SERIAL.txt!!", __func__);
   		strcpy(ret, "Q_EEPROM_SERIAL_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_ETH_MAC_Write(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[30];
	char string [result_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Carrier_ETH_MAC_Write_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("Q_CARRIER_ETH_MAC_W.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_MAC_W.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_MAC_W_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Qseven_ETH_MAC_Write(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[30];
	char string [result_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Qseven_ETH_MAC_Write_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("Q_QSEVEN_ETH_MAC_W.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_QSEVEN_ETH_MAC_W.txt!!", __func__);
   		strcpy(ret, "Q_QSEVEN_ETH_MAC_W_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_ETH_MAC_Read(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char string [result_len];
	FILE * pFile;
	
	CARRIERD("%s", __func__);
	system(Carrier_ETH_MAC_Read_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_MAC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_MAC.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_MAC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Qseven_ETH_MAC_Read(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char string [result_len];
	FILE * pFile;

	CARRIERD("%s", __func__);
	system(Qseven_ETH_MAC_Read_Cmd);
	pFile = fopen ("Q_QSEVEN_ETH_MAC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_QSEVEN_ETH_MAC.txt!!", __func__);
   		strcpy(ret, "Q_Qseven_ETH_MAC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Qseven_BIOS_Version(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[30];
	char string [result_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Qseven_BIOS_Version_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("BIOS_QSEVEN.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File BIOS_QSEVEN.txt!!", __func__);
   		strcpy(ret, "BIOS_QSEVEN_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}


int Carrier_Eth_Poe_Speed(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_Poe_Speed_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_POE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_POE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_POE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Eth_Poe_Device(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_Poe_Device_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_POE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_POE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_POE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}
int Carrier_Eth_Poe_Duplex(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_Poe_Duplex_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_POE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_POE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_POE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Eth_NPoe_Speed(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_NPoe_Speed_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_NPOE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_POE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_NPOE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Eth_NPoe_Device(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_NPoe_Device_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_NPOE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_NPOE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_NPOE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}
int Carrier_Eth_NPoe_Duplex(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_NPoe_Duplex_Cmd);
	pFile = fopen ("Q_CARRIER_ETH_NPOE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_ETH_NPOE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_ETH_NPOE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}


int Read_Street_Result(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *file_name[30];
	char string [result_len];
	FILE * pFile;
	memset(&file_name,0,sizeof(file_name));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(file_name, "%s %s", prmtr_buf, "_street_result.txt");
	pFile = fopen (file_name , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File %s!!", __func__,file_name);
   		strcpy(ret, "Street_result_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}


int Nfc_Detect(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Nfc_Detect_Cmd);
	sleep(6);
	system("\r\n");
	pFile = fopen ("Q_NFC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_NFC.txt!!", __func__);
   		strcpy(ret, "Q_NFC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Serial_Number_Write_SMBIOS(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char *command[30];
	char string [result_len];
	FILE * pFile;
	memset(&command,0,sizeof(command));

	CARRIERD("%s", __func__);

    	CARRIERD("cmd_buf [%s]", prmtr);
    	cmd_buf = strtok_r(prmtr," ", &prmtr_buf);
    	CARRIERD("cmd:[%s]",cmd_buf); 
    	CARRIERD("parameter:[%s]",prmtr_buf);
    	sprintf(command, "%s %s", Serial_Number_Write_SMBIOS_Cmd, prmtr_buf);
	system(command);
	pFile = fopen ("Q_SN_SMBIOS.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_SN_SMBIOS.txt!!", __func__);
   		strcpy(ret, "Q_SN_SMBIOS_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Serial_Number_Read_SMBIOS(char *ret, char *prmtr)
{
	char *cmd_buf= NULL, *prmtr_buf= NULL;
	char string [result_len];
	FILE * pFile;

	CARRIERD("%s", __func__);
	system(Serial_Number_Read_SMBIOS_Cmd);
	pFile = fopen ("Q_SN_SMBIOS.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_SN_SMBIOS.txt!!", __func__);
   		strcpy(ret, "Q_SN_SMBIOS_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Eth_Poe_AF_Type(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_Poe_AF_Type_Cmd);
	pFile = fopen ("Q_CARRIER_POE_TYPE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_POE_TYPE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_POE_TYPE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Eth_Poe_AT_Type(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Eth_Poe_AT_Type_Cmd);
	pFile = fopen ("Q_CARRIER_POE_TYPE.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_POE_TYPE.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_POE_TYPE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Usb_Ext(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Usb_Ext_Cmd);
	pFile = fopen ("Q_CARRIER_USB_EXT.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_USB_EXT.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_USB_EXT_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Emmc_Info(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Emmc_Info_Cmd);
	pFile = fopen ("Q_CARRIER_EMMC_INFO.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_EMMC_INFO.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_EMMC_INFO_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Carrier_Ledb_Nfc(char *ret, char *prmtr)
{
	CARRIERD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(Carrier_Ledb_Nfc_Cmd);
	pFile = fopen ("Q_CARRIER_LEDB_NFC.txt" , "r");
	if(pFile==NULL) {
   		CARRIERD("%s-Fail To Open File Q_CARRIER_LEDB_NFC.txt!!", __func__);
   		strcpy(ret, "Q_CARRIER_LEDB_NFC_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	CARRIERD("%s", string);
	strcpy(ret, string);

	return 0;
}

