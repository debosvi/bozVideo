
set(CU_TEST_NAME cu_bozvideo)

set(CU_TEST_SOURCES
    cu_suite.c
    cu_main.c
    cu_init_term.c
    )
    
add_executable(${CU_TEST_NAME} 
    ${CU_TEST_SOURCES}
    )
target_link_libraries(${CU_TEST_NAME}
    bozvideo
    cunit
    )
