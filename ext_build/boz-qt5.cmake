
find_path(BOZ_QT5_QMAKE_PATH qmake
	PATHS /opt/qt52 /opt/qt51 /usr/lib/i386-linux-gnu/qt5
	PATH_SUFFIXES bin
	DOC "Find QT5 Qmake tool"
	NO_DEFAULT_PATH 
	NO_CMAKE_PATH 
	NO_CMAKE_SYSTEM_PATH
	)

if("${BOZ_QT5_QMAKE_PATH}" STREQUAL "")
	message(FATAL_ERROR "Don't find any Qt5 qmake tool")
endif()

string(REPLACE "/bin" "" BOZ_QT5_BASE_PATH_TMP ${BOZ_QT5_QMAKE_PATH})
string(STRIP "${BOZ_QT5_BASE_PATH_TMP}" BOZ_QT5_BASE_PATH)
unset(BOZ_QT5_BASE_PATH_TMP)

set(BOZ_QT5_QMAKE_BIN ${BOZ_QT5_QMAKE_PATH}/qmake)

message(STATUS "Qt5 base path: ${BOZ_QT5_BASE_PATH}")
message(STATUS "Qt5 qmake: ${BOZ_QT5_QMAKE_BIN}")

execute_process(COMMAND ${BOZ_QT5_QMAKE_BIN} -v OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/qmake.txt)
execute_process(COMMAND tail -n 1  ${CMAKE_CURRENT_BINARY_DIR}/qmake.txt OUTPUT_VARIABLE QMAKE_TMP)
string(REPLACE " " ";" QMAKE_TMP2 ${QMAKE_TMP})
list(GET QMAKE_TMP2 3 QMAKE_TMP3)
string(STRIP "${QMAKE_TMP3}" QMAKE_VERSION)
list(GET QMAKE_TMP2 5 QMAKE_TMP3)
string(STRIP "${QMAKE_TMP3}" QMAKE_WHERE)
unset(QMAKE_TMP3)
unset(QMAKE_TMP2)
unset(QMAKE_TMP)
file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/qmake.txt)

message(STATUS "Qmake version: ${QMAKE_VERSION}")
message(STATUS "Qmake where: ${QMAKE_WHERE}")

set(BOZ_QT5_CMAKE_FIND_DIR ${QMAKE_WHERE}/cmake)
message(STATUS "Qt5 cmake dir: ${BOZ_QT5_CMAKE_FIND_DIR}")
