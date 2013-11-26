# set(CMAKE_C_FLAGS "-pipe -O2 -Wall -W -D_REENTRANT -fPIC")
# set(CMAKE_CXX_FLAGS "-pipe -O2 -Wall -W -D_REENTRANT -fPIC")

#add_definitions(-Wno-unused-variable -Wno-unused-parameter)
#add_definitions(-Wno-cast-qual -Wno-missing-declarations)

find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(SOURCES 
    QBozAbstractVidPlayer.cpp
    QBozQtAVVidPlayer.cpp
)

set(HEADERS
    ../include/QBozAbstractVidPlayer.h
    ../include/QBozQtAVVidPlayer.h
)

QT5_WRAP_CPP(${PLUGINPLAYER_NAME}_HEADERS_MOC ${HEADERS})
#QT5_ADD_RESOURCES(OUT_RCS theme.qrc)

add_library(${PLUGINPLAYER_NAME} SHARED ${${PLUGINPLAYER_NAME}_HEADERS_MOC} ${SOURCES} ${OUT_RCS})
target_link_libraries(${PLUGINPLAYER_NAME}
#    stddjb
#    pthread
    ${Qt5Widgets_LIBRARIES}
#     QtAV
)

install(TARGETS ${PLUGINPLAYER_NAME} LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR})

