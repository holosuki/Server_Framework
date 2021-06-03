cmake_minimum_required(VERSION 3.20)
project(MSF)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

find_library(YAMLCPP yaml-cpp)
message("***", ${yaml-cpp})

set(LIB_SRC
	MSF/log.cc
	MSF/util.cc
	MSF/config.cc
	)

add_library(MSF SHARED ${LIB_SRC})
#add_library(MSF_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (MSF_static PROPERTIES OUTPUT_NAME "MSF")

add_executable(test tests/test.cc)
add_dependencies(test MSF)
target_link_libraries(test MSF ${YAMLCPP})

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config MSF)
target_link_libraries(test_config MSF ${YAMLCPP})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
