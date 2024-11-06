cmake_minimum_required(VERSION 3.5)
project("C++ OS lib" VERSION 1.3.0)

if (NOT DEFINED LIBTYPE)
    set(LIBTYPE "SHARED")
endif(NOT DEFINED LIBTYPE)

string(TOUPPER ${LIBTYPE} LIBTYPE)
string(TOLOWER ${LIBTYPE} CONFIG_SUFFIX)

if (${LIBTYPE} STREQUAL "SHARED")
    set(SRC "")
elseif(${LIBTYPE} STREQUAL "STATIC")
    set(SRC "")
else()
    message(FATAL_ERROR "expected LIBTYPE to be STATIC or SHARED, not ${LIBTYPE}")
endif(${LIBTYPE} STREQUAL "SHARED")

include_directories(./include/${CONFIG_SUFFIX})

set(SRC "./src")

add_library(os ${LIBTYPE} ${SRC}/cwalk.c ${SRC}/os.cpp "${SRC}/path.cpp" ${SRC}/join.cpp
            ${SRC}/listdir.cpp)

set_target_properties(os PROPERTIES PUBLIC_HEADER include/${CONFIG_SUFFIX}/os.h)
set_target_properties(os PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(os PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS os
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libos)