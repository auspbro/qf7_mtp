#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "als.h"
#define result_len 50
#define ALS_On_Cmd "./../../../home/root/Q_als_als.sh ALS_I2C"
#define ALS_BL_Cmd "./../../../home/root/Q_als_als.sh ALS_BL"
#define ALS_LL_Cmd "./../../../home/root/Q_als_als.sh ALS_LL"
#define ALS_TMP_TEMPERATURE_Cmd "./../../../home/root/Q_als_tmp108.sh ALS_TMP_TEMPERATURE"
#define ALS_TMP_I2C_Cmd "./../../../home/root/Q_als_tmp108.sh ALS_TMP_I2C"
 
int Als_I2c(char *ret, char *prmtr)
{
	ALSD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(ALS_On_Cmd);

	pFile = fopen ("Q_ALS.txt" , "r");
	if(pFile==NULL) {
   		ALSD("%s-Fail To Open File Q_ALS.txt!!", __func__);
   		strcpy(ret, "ALS_I2C_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	ALSD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Als_BL(char *ret, char *prmtr)
{
	ALSD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(ALS_BL_Cmd);

	pFile = fopen ("Q_ALS.txt" , "r");
	if(pFile==NULL) {
   		ALSD("%s-Fail To Open File Q_ALS.txt!!", __func__);
   		strcpy(ret, "ALS_BL_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	ALSD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Als_LL(char *ret, char *prmtr)
{
	ALSD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(ALS_LL_Cmd);

	pFile = fopen ("Q_ALS.txt" , "r");
	if(pFile==NULL) {
   		ALSD("%s-Fail To Open File Q_ALS.txt!!", __func__);
   		strcpy(ret, "ALS_LL_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	ALSD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Als_Tmp_I2c(char *ret, char *prmtr)
{
	ALSD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(ALS_TMP_I2C_Cmd);

	pFile = fopen ("Q_ALS_TMP.txt" , "r");
	if(pFile==NULL) {
   		ALSD("%s-Fail To Open File Q_ALS_TMP.txt!!", __func__);
   		strcpy(ret, "ALS_TMP_I2C_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	ALSD("%s", string);
	strcpy(ret, string);

	return 0;
}

int Als_Tmp_Temperature(char *ret, char *prmtr)
{
	ALSD("%s", __func__);
	FILE * pFile;
    	char string [result_len];
	system(ALS_TMP_TEMPERATURE_Cmd);

	pFile = fopen ("Q_ALS_TMP.txt" , "r");
	if(pFile==NULL) {
   		ALSD("%s-Fail To Open File Q_ALS_TMP.txt!!", __func__);
   		strcpy(ret, "ALS_TMP_TEMPERATURE_FILE=FAIL");
   		return 0;
 	}else {
        if ( fgets (string , result_len , pFile) != NULL )
            puts (string);
        fclose (pFile);
    }
    	ALSD("%s", string);
	strcpy(ret, string);

	return 0;
}

