
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(BOZV_MAIN_PUBLIC bozv_main)
add_library(${BOZV_MAIN_PUBLIC} SHARED
    bozv_internal.c
    bozv_open.c
    bozv_close.c
    )
    
target_link_libraries(${BOZV_MAIN_PUBLIC}
    unixonacid datastruct random stdcrypto stddjb
    )