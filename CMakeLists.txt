cmake_minimum_required(VERSION 3.5)
project("C++ OS lib")

if (NOT DEFINED LIBTYPE)
    set(LIBTYPE "SHARED")
endif(NOT DEFINED LIBTYPE)

string(TOUPPER ${LIBTYPE} LIBTYPE)
string(TOLOWER ${LIBTYPE} CONFIG_SUFFIX)

include_directories(./include ./include/config/${CONFIG_SUFFIX})

set(SRC "./src")

add_library(os ${LIBTYPE} ${SRC}/cwalk.c ${SRC}/os.cpp "${SRC}/path.cpp" ${SRC}/join.cpp)

set_target_properties(os PROPERTIES PUBLIC_HEADER install/${CONFIG_SUFFIX}/os.h)

install(TARGETS os
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libos)