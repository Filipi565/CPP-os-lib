cmake_minimum_required(VERSION 3.5)
project("C++ OS lib" VERSION 1.3.1)

if (NOT DEFINED LIBTYPE)
    set(LIBTYPE "SHARED")
endif(NOT DEFINED LIBTYPE)

string(TOUPPER ${LIBTYPE} LIBTYPE)
string(TOLOWER ${LIBTYPE} CONFIG_SUFFIX)

if (${LIBTYPE} STREQUAL "SHARED")
    add_definitions(-D__OS_SHARED)
elseif(${LIBTYPE} STREQUAL "STATIC")
    set(SRC "") # just a placeholder
else()
    message(FATAL_ERROR "expected LIBTYPE to be STATIC or SHARED, not ${LIBTYPE}")
endif(${LIBTYPE} STREQUAL "SHARED")

add_definitions(-D__OS_LIB_EXPORT)

include_directories(./include)

set(SRC "./src")

add_library(os ${LIBTYPE} ${SRC}/cwalk.c ${SRC}/os.cpp "${SRC}/path.cpp" ${SRC}/join.cpp
            ${SRC}/listdir.cpp)

set_target_properties(os PROPERTIES PUBLIC_HEADER include/os.h)
set_target_properties(os PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(os PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS os
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libos)