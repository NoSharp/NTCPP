cmake_minimum_required(VERSION 3.10)
project(NTCPP VERSION 1.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

if(UNIX)
    # hide non-exported symbols
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
endif()


set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(HORIZONSDK_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/libs/")

set(HORIZONSDK_LIBRARY "${PROJECT_SOURCE_DIR}/lib/libluaplugin.a")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)