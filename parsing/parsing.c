
/*
 * Copyright (c) 2020 KOLIBREE Limited. All rights reserved.
 * Author : Toujani Akrem
 * émail: akrem.ing@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"

/*********************************************************************//**
 * @brief       parse Ble Data Field 
 *              
 *
 * @param[in]   buffer
 * @param[in]   BleField
 *
 * @return      SUCCES/ERROR
 ***********************************************************************/
uint16_t parseBleDataFieldCb(void* buffer, BleDataField* BleField)
{

	if((buffer == NULL) || BleField == NULL){
		printf("parseBleDataFieldCb : buffer OR BleField \" NULL\"\n");
		return ERROR;
	}	
	/* Initializing parsser pointer */
	char* ptr = (char*)buffer;			

	/* Reading company Id Code Field  */
	BleField->CompanyIdCode = (*ptr) >> 8;
	ptr++;
	BleField->CompanyIdCode += *ptr;
	
	/* Reading IsDocked Field  */
	BleField->IsDocked = *((uint16_t*)ptr);

	ptr++;
	if(*ptr == 0){
		BleField->IsDocked = false;
	}
	else{
		BleField->IsDocked = true;
	}
	
	/* Reading OwnerDeviceId Field  */
	ptr++;
	BleField->OwnerDeviceId = (*ptr) >> 24;
	ptr++;
	BleField->OwnerDeviceId += (*ptr) >> 16;
	ptr++;
	BleField->OwnerDeviceId += (*ptr) >> 8;
	ptr++;
	BleField->OwnerDeviceId += (*ptr);
	
	return SUCCES;
}

/*********************************************************************//**
 * @brief       write Ble Data buffer 
 *              
 *
 * @param[in]   buffer
 * @param[in]   BleField
 *
 * @return      SUCCES/ERROR
 ***********************************************************************/
uint16_t writeBleDataField(void* buffer, BleDataField* BleField)
{
	if((buffer == NULL) || BleField == NULL){
		printf("writeBleDataField : buffer OR BleField \" NULL\"\n");
		return ERROR;
	}

	char* tmpBuf = (char*)buffer;	

	/* Writing OwnerDeviceId Field  */
	tmpBuf[0] = (char)(BleField->CompanyIdCode && 0x00FF) << 8;
	tmpBuf[1] = (BleField->CompanyIdCode && 0xFF00);

	/* Writing IsDocked Field  */
	tmpBuf[2] = BleField->IsDocked;

	/* Writing CompanyIdCode Field  */
	tmpBuf[3] = (char)(BleField->CompanyIdCode  && 0x000000FF) << 24;
	tmpBuf[4] = (char)(BleField->OwnerDeviceId  && 0x0000FF00) << 16;
	tmpBuf[5] = (char)(BleField->OwnerDeviceId  && 0x00FF0000) << 8;
	tmpBuf[6] = (char)(BleField->OwnerDeviceId  && 0xFF000000);

	return SUCCES;
}






