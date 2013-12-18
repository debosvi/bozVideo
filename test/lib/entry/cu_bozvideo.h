
#ifndef _CU_BOZVIDEO_ENTRY_H_
#define _CU_BOZVIDEO_ENTRY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Automated.h"

#include "boz-video-entry.h"

int init_suite1(void);
int clean_suite1(void);
void test_rootpath(void);
void test_new(void);
void test_delete(void);

#endif // _CU_BOZVIDEO_ENTRY_H_
