cmake_minimum_required(VERSION 2.8)
project(MSF)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

set(LIB_SRC
	MSF/log.cc
	)

add_library(MSF SHARED ${LIB_SRC})
#add_library(MSF_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (MSF_static PROPERTIES OUTPUT_NAME "MSF")

add_executable(test tests/test.cc)
add_dependencies(test MSF)
target_link_libraries(test MSF)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
