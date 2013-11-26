set(CMAKE_PREFIX_PATH ${BOZ_QT5_CMAKE_FIND_DIR})

add_definitions(-fPIC)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/vidplayer)

set(PLUGINPLAYER_NAME playerwidget)
set(FACTORYNAME "bozWebplugin")

include_directories(qtvidplayer/src/engine)
include_directories(qtvidplayer/src/engine/QtAV)

add_subdirectory(factory)
add_subdirectory(vidplayer)

