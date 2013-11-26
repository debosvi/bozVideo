
find_package(Qt5WebKitWidgets REQUIRED)
include_directories(${Qt5WebKitWidgets_INCLUDE_DIRS})

set(FACT_HDRS 
    BozWebpage.h
    )

set(FACT_SRCS 
    main.cpp 
    BozWebpage.cpp
    )

QT5_WRAP_CPP(${FACTORYNAME}_HEADERS_MOC ${FACT_HDRS})

add_executable(${FACTORYNAME}
    ${FACT_SRCS}
    ${${FACTORYNAME}_HEADERS_MOC}
    )
target_link_libraries(${FACTORYNAME} 
    ${Qt5WebKitWidgets_LIBRARIES}
    ${PLUGINPLAYER_NAME}
    )

install(TARGETS ${FACTORYNAME} RUNTIME DESTINATION ${BINARY_INSTALL_DIR})
