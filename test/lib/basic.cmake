
set(VIDEO_TEST_NAME test_bozvideo_basic)

set(VIDEO_TEST_SOURCES
    basic.c
    )
    
add_executable(${VIDEO_TEST_NAME} 
    ${VIDEO_TEST_SOURCES}
    )
target_link_libraries(${VIDEO_TEST_NAME}
    bozvideo
    )