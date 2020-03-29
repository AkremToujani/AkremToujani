/*
 * Copyright (c) 2020 KOLIBREE Limited. All rights reserved.
 * Author : Toujani Akrem
 * émail: akrem.ing@gmail.com
 */

#include <check.h>               
#include "parsing.h"        
#include <stdlib.h>


START_TEST(test_parse_write_buffer) {

	void* buffer= (char*)malloc(BLE_PACKET_LENGTH * sizeof(char*)); 
	BleDataField* BleField = (BleDataField*)malloc(sizeof(BleDataField));

	ck_assert_int_eq(parseBleDataFieldCb(buffer, BleField), SUCCES);
	ck_assert_int_eq(writeBleDataField(buffer, BleField), SUCCES);

	free(buffer);
	free(BleField);

} END_TEST


Suite *parseWrite_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("ParseWrite");
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_parse_write_buffer);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int no_failed = 0;                   
	Suite *s;                            
	SRunner *runner;                     

	s = parseWrite_suite();                   
	runner = srunner_create(s);          

	srunner_run_all(runner, CK_NORMAL);  
	no_failed = srunner_ntests_failed(runner); 
	srunner_free(runner);                      
	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}
