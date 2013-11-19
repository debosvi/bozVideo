
#include "cu_bozvideo.h"

void test_init_args(void) {
    bozv_handle_t vh;
    int ret=0;

    ret=bozv_handle_open(&vh);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);

    vh=BOZV_HANDLE_ZERO;
    ret=bozv_handle_open(&vh);
    CU_ASSERT(ret == 0);
    CU_ASSERT(errno == 0);
    CU_ASSERT(vh != BOZV_HANDLE_ZERO);
}

void test_term_args(void) {
    bozv_handle_t vh, tvh;
    int ret=0;

    vh=BOZV_HANDLE_ZERO;
    ret=bozv_handle_close(&vh);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT(vh == BOZV_HANDLE_ZERO);

    vh=BOZV_HANDLE_ZERO;
    bozv_handle_open(&vh);
    ret=bozv_handle_close(&vh);
    CU_ASSERT(ret == 0);
    CU_ASSERT(errno == 0);
    CU_ASSERT(vh == BOZV_HANDLE_ZERO);

    vh=BOZV_HANDLE_ZERO;
    bozv_handle_open(&vh);
    tvh=vh;
    bozv_handle_close(&tvh);
    tvh=vh;
    ret=bozv_handle_close(&vh);
    CU_ASSERT(ret == -1);
    CU_ASSERT(errno == EINVAL);
    CU_ASSERT( vh != BOZV_HANDLE_ZERO);
}

