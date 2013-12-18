
set(CU_BOZV_ENTRY_TEST_NAME cu_bozv_entry)

set(CU_TEST_SOURCES
    cu_suite.c
    cu_main.c
    cu_rootpath.c
    )
    
add_executable(${CU_BOZV_ENTRY_TEST_NAME} 
    ${CU_TEST_SOURCES}
    )
    
target_link_libraries(${CU_BOZV_ENTRY_TEST_NAME}
    bozv_entry
    cunit
    )
