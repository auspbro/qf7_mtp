// Cpp_Ex.cpp : Defines the entry point for the console application.
//
//********************************************************************************
//* Copyright (2011), Cypress Semiconductor Corporation.
//********************************************************************************
//* This software is owned by Cypress Semiconductor Corporation (Cypress)
//* and is protected by and subject to worldwide patent protection (United
//* States and foreign), United States copyright laws and international treaty
//* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
//* non-transferable license to copy, use, modify, create derivative works of,
//* and compile the Cypress Source Code and derivative works for the sole
//* purpose of creating custom software in support of licensee product to be
//* used only in conjunction with a Cypress integrated circuit as specified in
//* the applicable agreement. Any reproduction, modification, translation,
//* compilation, or representation of this software except as specified above 
//* is prohibited without the express, written permission of Cypress.
//********************************************************************************

#include "stdafx.h"
#include "windows.h"
#include "tchar.h"
#include "atlbase.h"
#include "conio.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "ppcom.h"

using namespace std;

IDispatch* pIDispatch = NULL;
std::string sErrorMsg;

//DispIDs for each function used in the Example
//They are initialized once after COM-object is created by GetDispIDsByName() function
DISPID dispID__StartSelfTerminator = 0;
DISPID dispID_OpenPort = 0;
DISPID dispID_ClosePort = 0;
DISPID dispID_GetPorts = 0;
DISPID dispID_SetPowerVoltage = 0;
DISPID dispID_PowerOn = 0;
DISPID dispID_PowerOff = 0;
DISPID dispID_SetProtocol = 0;
DISPID dispID_I2C_ResetBus = 0;
DISPID dispID_I2C_GetDeviceList = 0;
DISPID dispID_I2C_SetSpeed = 0;
DISPID dispID_I2C_GetSpeed = 0;
DISPID dispID_I2C_DataTransfer = 0;
DISPID dispID_I2C_SendData = 0;
DISPID dispID_I2C_ReadData = 0;
DISPID dispID_I2C_ReadDataFromReg = 0;
//----------------------------------------------------------------------------------------
// Auxiliary routines for working with Automation types
//----------------------------------------------------------------------------------------
int GetDispIDsByName()
{
	int hr = S_OK;
	LPOLESTR functionName;
	//_StartSelfTerminator
	functionName = L"_StartSelfTerminator";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID__StartSelfTerminator);
	if (FAILED(hr)) return hr;
	//OpenPort
	functionName = L"OpenPort";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_OpenPort);
	if (FAILED(hr)) return hr;
	//ClosePort
	functionName = L"ClosePort";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_ClosePort);
	if (FAILED(hr)) return hr;
	//GetPorts
	functionName = L"GetPorts";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_GetPorts);
	if (FAILED(hr)) return hr;
	//SetPowerVoltage
	functionName = L"SetPowerVoltage";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_SetPowerVoltage);
	if (FAILED(hr)) return hr;
	//PowerOn
	functionName = L"PowerOn";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_PowerOn);
	if (FAILED(hr)) return hr;
	//PowerOff
	functionName = L"PowerOff";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_PowerOff);
	if (FAILED(hr)) return hr;
	//SetProtocol
	functionName = L"SetProtocol";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_SetProtocol);
	if (FAILED(hr)) return hr;
	//Reset Bus
	functionName = L"I2C_ResetBus";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_ResetBus);
	if (FAILED(hr)) return hr;
	//I2C_GetDeviceList
	functionName = L"I2C_GetDeviceList";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_GetDeviceList);
	if (FAILED(hr)) return hr;
	//I2C_SetSpeed
	functionName = L"I2C_SetSpeed";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_SetSpeed);
	if (FAILED(hr)) return hr;
	//I2C_GetSpeed
	functionName = L"I2C_GetSpeed";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_GetSpeed);
	if (FAILED(hr)) return hr;
	//I2C_DataTransfer
	functionName = L"I2C_DataTransfer";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_DataTransfer);
	if (FAILED(hr)) return hr;
	//I2C_SendData
	functionName = L"I2C_SendData";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_SendData);
	if (FAILED(hr)) return hr;
	//I2C_ReadData
	functionName = L"I2C_ReadData";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_ReadData);
	if (FAILED(hr)) return hr;
	//I2C_ReadDataFromReg
	functionName = L"I2C_ReadDataFromReg";
	hr = pIDispatch->GetIDsOfNames(IID_NULL, &functionName, 1, LOCALE_SYSTEM_DEFAULT, &dispID_I2C_ReadDataFromReg);
	if (FAILED(hr)) return hr;
	return hr;
}

void ConvertSA2ByteVector(VARIANT arrayIN, std::vector<BYTE> &vector)
{
	//Extract SA from VARIANT
	SAFEARRAY* psa;
	if (!(arrayIN.vt & VT_ARRAY)) { vector.resize(0); return; }
	if (arrayIN.vt & VT_BYREF)
		psa = *(arrayIN.pparray);
	else
		psa = arrayIN.parray;

	//Convert SA to vector
	long lLBound, lUBound;
	SafeArrayGetLBound(psa, 1, &lLBound);
	SafeArrayGetUBound(psa, 1, &lUBound);
	int size = lUBound - lLBound + 1;
	vector.resize(size);
	long i, j;
	for (j = 0, i = lLBound; i <= lUBound; i++, j++) {
		BYTE b;
		SafeArrayGetElement(psa, &i, &b);
		vector[j] = b;
	}
}

void ConvertSA2ByteVector(VARIANT arrayIN, std::vector<std::vector<LONG>> &vector)
{
	//Extract SA from VARIANT
	SAFEARRAY* psa;
	if (!(arrayIN.vt & VT_ARRAY)) { vector.resize(0); return; }
	if (arrayIN.vt & VT_BYREF)
		psa = *(arrayIN.pparray);
	else
		psa = arrayIN.parray;

	//Convert SA to vector
	long lLBound1, lUBound1;
	SafeArrayGetLBound(psa, 1, &lLBound1);
	SafeArrayGetUBound(psa, 1, &lUBound1);
	int size1 = lUBound1 - lLBound1 + 1;
	long lLBound2, lUBound2;
	SafeArrayGetLBound(psa, 2, &lLBound2);
	SafeArrayGetUBound(psa, 2, &lUBound2);
	int size2 = lUBound2 - lLBound2 + 1;
	vector.resize(size1);
	long i1, j1, i2, j2;
	for (j1 = 0, i1 = lLBound1; i1 <= lUBound1; i1++, j1++) {
		vector[j1].resize(size2);
		for (j2 = 0, i2 = lLBound2; i2 <= lUBound2; i2++, j2++) {
			long index[2] = { i1,i2 };
			long element;
			SafeArrayGetElement(psa, index, &element);
			vector[j1][j2] = element;
		}
	}
}

void ConvertByteVector2SA(std::vector<BYTE> vector, VARIANT *arrayOUT)
{
	SAFEARRAY* psa;
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = (ULONG)vector.size();
	psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
	for (UINT i = 0; i<vector.size(); i++) {
		SafeArrayPutElement(psa, (long *)&i, &vector[i]);
	}

	//return data in VARIANT
	VariantInit(arrayOUT);
	V_VT(arrayOUT) = VT_ARRAY | VT_UI1;
	V_ARRAY(arrayOUT) = psa;
}

void ConvertIntVector2SA(std::vector<int> vector, VARIANT *arrayOUT)
{
	SAFEARRAY* psa;
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = (ULONG)vector.size();
	psa = SafeArrayCreate(VT_I4, 1, rgsabound);
	for (UINT i = 0; i<vector.size(); i++) {
		SafeArrayPutElement(psa, (long *)&i, &vector[i]);
	}

	//return data in VARIANT
	VariantInit(arrayOUT);
	V_VT(arrayOUT) = VT_ARRAY | VT_I4;
	V_ARRAY(arrayOUT) = psa;
}

//----------------------------------------------------------------------------------
// COM-object's wrapping functions
//----------------------------------------------------------------------------------

long ppStartSelfTerminator(long ClientProcessID)
{
	DISPID dispid = dispID__StartSelfTerminator;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 1;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_I4;
	dispparams.rgvarg[0].lVal = ClientProcessID;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppOpenPort(std::string portName, std::string &strError)
{
	DISPID dispid = dispID_OpenPort;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	USES_CONVERSION;
	BSTR bstrPort = ::SysAllocString(A2W(portName.c_str()));
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_BSTR;
	dispparams.rgvarg[1].bstrVal = bstrPort;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);


	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrPort);
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppClosePort(std::string &strError)
{
	DISPID dispid = dispID_ClosePort;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 1;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppGetPorts(std::vector<std::string> &portNames, std::string &strError)
{
	DISPID dispid = dispID_GetPorts;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	VARIANT varPorts;
	VariantInit(&varPorts);
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_VARIANT | VT_BYREF;
	dispparams.rgvarg[1].pvarVal = &varPorts;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);
	USES_CONVERSION;
	strError = W2A(bstrError);
	//Translate Result into std::vector<std::string>
	long lLBound, lUBound;
	SAFEARRAY* psa = varPorts.parray;
	SafeArrayGetLBound(psa, 1, &lLBound);
	SafeArrayGetUBound(psa, 1, &lUBound);
	int size = lUBound - lLBound + 1;
	portNames.resize(size);
	long i, j;
	for (j = 0, i = lLBound; i <= lUBound; i++, j++) {
		BSTR bPort;
		SafeArrayGetElement(psa, &i, &bPort);
		USES_CONVERSION;
		portNames[j] = W2A(bPort);
	}
	//Free allocated resources
	delete[] pArg;
	VariantClear(&varPorts);
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

void SetErrorMsg(std::string errorMsg)
{
	errorMsg = sErrorMsg;
}

std::string GetErrorMsg()
{
	return sErrorMsg;
}

long ppSetPowerVoltage(std::string voltage, std::string &strError)
{
	DISPID dispid = dispID_SetPowerVoltage;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	USES_CONVERSION;
	BSTR bstrVoltage = ::SysAllocString(A2W(voltage.c_str()));
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_BSTR;
	dispparams.rgvarg[1].bstrVal = bstrVoltage;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrVoltage);
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppPowerOn(std::string &strError)
{
	DISPID dispid = dispID_PowerOn;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 1;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppPowerOff(std::string &strError)
{
	DISPID dispid = dispID_PowerOff;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 1;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppSetProtocol(enumInterfaces protocol, std::string &strError)
{
	DISPID dispid = dispID_SetProtocol;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_I4;
	dispparams.rgvarg[1].lVal = protocol;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppI2C_ResetBus(std::string &strError)
{
	DISPID dispid = dispID_I2C_ResetBus;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 1;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppI2C_GetDeviceList(std::vector<BYTE> &devices, std::string &strError)
{
	DISPID dispid = dispID_I2C_GetDeviceList;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	VARIANT varDevices;
	VariantInit(&varDevices);
	BSTR bstrError = 0;

	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_VARIANT | VT_BYREF;
	dispparams.rgvarg[1].pvarVal = &varDevices;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	ConvertSA2ByteVector(varDevices, devices);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);
	VariantClear(&varDevices);

	return vaResult.lVal;
}

long ppI2C_SetSpeed(enumI2Cspeed speed, std::string &strError)
{
	DISPID dispid = dispID_I2C_SetSpeed;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_I4;
	dispparams.rgvarg[1].lVal = speed;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppI2C_GetSpeed(long &speed, std::string &strError)
{
	DISPID dispid = dispID_I2C_GetSpeed;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 2;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Initialize parameters
	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_I4 | VT_BYREF;
	dispparams.rgvarg[1].plVal = &speed;
	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);

	return vaResult.lVal;
}

long ppI2C_DataTransfer(long deviceAddr, long mode, long readLen, std::vector<BYTE> dataIN, std::vector<BYTE> &dataOUT, std::string &strError)
{
	DISPID dispid = dispID_I2C_DataTransfer;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 6;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);

	//Initialize parameters
	VARIANT dOUT;
	VariantInit(&dOUT);

	//Convert dataIN into SafeArray
	VARIANT dIN;
	ConvertByteVector2SA(dataIN, &dIN);

	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_VARIANT | VT_BYREF;
	dispparams.rgvarg[1].pvarVal = &dOUT;
	dispparams.rgvarg[2].vt = VT_ARRAY | VT_UI1;
	dispparams.rgvarg[2].parray = dIN.parray;
	dispparams.rgvarg[3].vt = VT_I4;
	dispparams.rgvarg[3].lVal = readLen;
	dispparams.rgvarg[4].vt = VT_I4;
	dispparams.rgvarg[4].lVal = mode;
	dispparams.rgvarg[5].vt = VT_I4;
	dispparams.rgvarg[5].lVal = deviceAddr;

	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	ConvertSA2ByteVector(dOUT, dataOUT);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);
	VariantClear(&dOUT);
	VariantClear(&dIN);

	return vaResult.lVal;
}

long ppI2C_SendData(long deviceAddr, std::vector<BYTE> dataIN, std::string &strError)
{
	DISPID dispid = dispID_I2C_SendData;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 3;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);

	//Convert dataIN into SafeArray
	VARIANT dIN;
	ConvertByteVector2SA(dataIN, &dIN);

	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_ARRAY | VT_UI1;
	dispparams.rgvarg[1].parray = dIN.parray;
	dispparams.rgvarg[2].vt = VT_I4;
	dispparams.rgvarg[2].lVal = deviceAddr;

	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);
	VariantClear(&dIN);

	return vaResult.lVal;
}

long ppI2C_ReadData(long deviceAddr, long readLen, std::vector<BYTE> &dataOUT, std::string &strError)
{
	DISPID dispid = dispID_I2C_ReadData;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 4;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);

	//Initialize parameters
	VARIANT dOUT;
	VariantInit(&dOUT);

	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_VARIANT | VT_BYREF;
	dispparams.rgvarg[1].pvarVal = &dOUT;
	dispparams.rgvarg[2].vt = VT_I4;
	dispparams.rgvarg[2].lVal = readLen;
	dispparams.rgvarg[3].vt = VT_I4;
	dispparams.rgvarg[3].lVal = deviceAddr;

	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	ConvertSA2ByteVector(dOUT, dataOUT);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);
	VariantClear(&dOUT);

	return vaResult.lVal;
}

long ppI2C_ReadDataFromReg(long deviceAddr, std::vector<byte> ReadAddress, long readLen, std::vector<BYTE> &dataOUT, std::string &strError)
{
	DISPID dispid = dispID_I2C_ReadDataFromReg;
	// Set up parameters
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof(DISPPARAMS));
	dispparams.cArgs = 5;
	// Allocate memory for parameters
	VARIANTARG* pArg = new VARIANTARG[dispparams.cArgs];
	dispparams.rgvarg = pArg;
	memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);
	//Convert dataIN into SafeArray
	VARIANT dIN;
	ConvertByteVector2SA(ReadAddress, &dIN);
	//Initialize parameters
	VARIANT dOUT;
	VariantInit(&dOUT);

	BSTR bstrError = 0;
	dispparams.rgvarg[0].vt = VT_BSTR | VT_BYREF;
	dispparams.rgvarg[0].pbstrVal = &bstrError;
	dispparams.rgvarg[1].vt = VT_VARIANT | VT_BYREF;
	dispparams.rgvarg[1].pvarVal = &dOUT;
	dispparams.rgvarg[2].vt = VT_I4;
	dispparams.rgvarg[2].lVal = readLen;
	dispparams.rgvarg[3].vt = VT_ARRAY | VT_UI1;
	dispparams.rgvarg[3].parray = dIN.parray;
	dispparams.rgvarg[4].vt = VT_I4;
	dispparams.rgvarg[4].lVal = deviceAddr;

	//Init Result (Return Value)
	VARIANTARG vaResult;
	VariantInit(&vaResult);

	HRESULT hr;
	hr = pIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD,
		&dispparams, &vaResult, NULL, NULL);

	USES_CONVERSION;
	strError = W2A(bstrError);
	ConvertSA2ByteVector(dOUT, dataOUT);
	//Free allocated resources
	delete[] pArg;
	::SysFreeString(bstrError);
	VariantClear(&dOUT);
	VariantClear(&dIN);

	return vaResult.lVal;
}

//----------------------------------------------------------------------------------
// Usage Example
//----------------------------------------------------------------------------------

long OpenPort()
{
	long hr;
	//Open Port - get first MiniProg3 port in the ports list
	std::vector<std::string> ports;
	hr = ppGetPorts(ports, sErrorMsg);
	if (!SUCCEEDED(hr)) return hr;

	if (ports.size() <= 0)
	{
		sErrorMsg = "Connect any Programmer to PC";
		return -1;
	}

	//Port should be opened just once to connect Programmer device (MiniProg1/3,etc).
	//After that you can use Chip-/Programmer- specific APIs as long as you need.
	//No need to repoen port when you need to acquire chip 2nd time, just call Acquire() again.
	//This is true for all other APIs which get available once port is opened.
	//You have to call OpenPort() again if port was closed by ClosePort() method, or 
	//when there is a need to connect to other programmer, or
	//if programmer was physically reconnected to USB-port.

	std::string portName = ports[0];
	hr = ppOpenPort(portName, sErrorMsg);
	return hr;
}

long ClosePort()
{
	long hr;
	std::string sErrorMsg;

	hr = ppClosePort(sErrorMsg);

	return hr;
}

long I2C_CheckDevice(int deviceAddress)
{
	int hr;

	//Port Initialization
	//Setup Power - "3.3V" and internal
	hr = ppSetPowerVoltage("3.3", sErrorMsg);
	if (!SUCCEEDED(hr)) return hr;

	//Power On
	hr = ppPowerOn(sErrorMsg);
	if (!SUCCEEDED(hr)) return hr;

	//Set protocol, connector and frequency
	hr = ppSetProtocol(enumInterfaces::I2C, sErrorMsg); //I2C-protocol
	if (!SUCCEEDED(hr)) return hr;

	//Reset bus
	hr = ppI2C_ResetBus(sErrorMsg);
	cout << "Reset bus!" << endl;

	//Sleep script for 100 milliseconds
	Sleep(100);

	//Set I2C speed
	hr = ppI2C_SetSpeed(enumI2Cspeed::CLK_100K, sErrorMsg);
	if (!SUCCEEDED(hr)) return hr;
	cout << "Set speed: 100K!" << endl;

	//Get device list
	std::vector<byte> devices;
	hr = ppI2C_GetDeviceList(devices, sErrorMsg);
	if (!SUCCEEDED(hr))
	{
		sErrorMsg = "Failed to enumerate I2C devices";
		return hr;
	}

	//Power Off
	hr = ppPowerOff(sErrorMsg);
	//if (!SUCCEEDED(hr)) return hr;

	//Show devices
	if (devices.size() == 0)
	{
		sErrorMsg = "No devices found";
		return hr;
	}

	printf("\nDevice Lists:\n");
	for (BYTE i = 0; i < devices.size(); i++)
	{
		printf("0x%X ", devices[i]);

		if ((devices[i] == deviceAddress)&&deviceAddress)
		{
			printf("\n\nResult: PASS\n");
			return hr;
		}
	}

	if(deviceAddress)
		printf("\n\nResult: Failed!\n");
	else
		cout << endl << endl;

	return hr;
}

long Execute(int addr)
{
	int hr;

	//Open Port - get last (connected) port in the ports list
	hr = OpenPort();
	if (!SUCCEEDED(hr)) return hr;

	//Check if Device exists
	hr = I2C_CheckDevice(addr);

	//Close the Port, so it is available for other apps
	ClosePort();

	return hr;
}



int main(int argc, char *argv[])
{
	HRESULT hr = 0;
	cout << "Initializing COM" << endl;
	if (FAILED(CoInitialize(NULL)))
	{
		//	cout << "Unable to initialize COM" << endl;
		cout << "[QCI] Failed - Unable to initialize COM" << endl;
		return 0;
	}

	//Use Version Independent Prog ID to instantiate COM-object
	wchar_t progid[] = L"PSoCProgrammerCOM.PSoCProgrammerCOM_Object";
	//For version dependent Prog ID use below commented line, but update there COM-object version (e.g. 14)
	//wchar_t progid[] = L"PSoCProgrammerCOM.PSoCProgrammerCOM_Object.14";

	CLSID clsid;
	hr = ::CLSIDFromProgID(progid, &clsid);
	if (FAILED(hr))
	{
		//	cout << "Failed to get class id for PSoC Programmer COM object !" << endl;
		cout << "[QCI] Failed - Failed to get class id for PSoC Programmer COM object !" << endl;
		CoUninitialize();
		return 0;
	}

	hr = ::CoCreateInstance(clsid, NULL, CLSCTX_SERVER, IID_IDispatch, (void**)&pIDispatch);
	if (FAILED(hr))
	{
		//cout << "Failed to create instance of PSoC Programmer COM object !" << endl;
		cout << "[QCI] Fail - Failed to create instance of PSoC Programmer COM object !" << endl;
		CoUninitialize();
		return 0;
	}
	hr = GetDispIDsByName();
	if (FAILED(hr))
	{
		//cout <<"Failed to get DispIDs of used methods";
		cout << "[QCI] Fail - Failed to get DispIDs of used methods";
		CoUninitialize();
		return 0;
	}

	ppStartSelfTerminator(GetCurrentProcessId());
	std::string str;

	//Execute actual task of the example
	if (argc > 1)
	{
		char buf[256] = { 0 };
		strncat_s(buf, argv[1], strlen(argv[1]));

		//	printf("[QCI] buf[%s] len[%d]\n", buf, strlen(buf));
		int addr = strtol(buf, NULL, 16);
		//printf("[QCI] I2C addr[0x%X] \n", addr);
		hr = Execute(addr);
	}
	else
	{
		hr = Execute(0);
		return 0;
	}


	if (SUCCEEDED(hr)) str = "Succeeded!";
	else { str = "Failed! "; str.append(sErrorMsg); }
	cout << str.c_str() << endl;
	cout << "Shutting down COM" << endl;

	pIDispatch->Release();
	CoUninitialize();

	return 0;
}