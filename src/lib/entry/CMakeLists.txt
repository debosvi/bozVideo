
set(BOZV_ENTRY_PUBLIC bozv_entry)

add_library(${BOZV_ENTRY_PUBLIC} SHARED
    bozv_entry_internal.c
    _bozv_entry_check_rootpath.c
    bozv_entry_set_rootpath.c
    bozv_entry_new.c
    bozv_entry_delete.c
    )
    
target_link_libraries(${BOZV_ENTRY_PUBLIC}
#     unixonacid datastruct random stdcrypto 
    stddjb
    )