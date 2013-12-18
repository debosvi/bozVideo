
#include "cu_bozvideo.h"

void test_rootpath(void) {
    int ret=0;

    ret=bozv_entry_set_rootpath(NULL);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EFAULT);

//     vh=BOZV_HANDLE_ZERO;
//     ret=bozv_handle_open(&vh);
//     CU_ASSERT(ret == 0);
//     CU_ASSERT(errno == 0);
//     CU_ASSERT(vh != BOZV_HANDLE_ZERO);
}

