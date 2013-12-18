
set(CU_BOZV_MAIN_TEST_NAME cu_bozv_main)

set(CU_TEST_SOURCES
    cu_suite.c
    cu_main.c
    cu_init_term.c
    )
    
add_executable(${CU_BOZV_MAIN_TEST_NAME} 
    ${CU_TEST_SOURCES}
    )
target_link_libraries(${CU_BOZV_MAIN_TEST_NAME}
    bozv_main
    cunit
    )
