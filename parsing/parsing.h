/*
 * Copyright (c) 2020 KOLIBREE Limited. All rights reserved.
 * Author : Toujani Akrem
 * émail: akrem.ing@gmail.com
 */

#ifndef _PARSING_H_
#define _PARSING_H_

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#define ERROR	-1
#define SUCCES	0
#define	BLE_PACKET_LENGTH	7

typedef struct BleDataField BleDataField;
struct BleDataField
{
    uint16_t	CompanyIdCode;
    bool 		IsDocked;
	uint32_t	OwnerDeviceId;
};


uint16_t parseBleDataFieldCb(void* buffer, BleDataField* BleField);
uint16_t writeBleDataField(void* buffer, BleDataField* BleField);



#endif /* _PARSING_H_ */
