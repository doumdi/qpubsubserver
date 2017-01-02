PROJECT (qpubsubserver)

#include(CTest)
#include(CheckFunctionExists)

#Look for minimum cmake version
cmake_minimum_required(VERSION 3.0.2)

#DEFINITIONS POLICY, NEW SINCE 3.0.2
cmake_policy(SET CMP0043 NEW)

find_package(Qt5Core REQUIRED)

# compile in debug or release mode
IF(NOT CMAKE_BUILD_TYPE)
  #SET(CMAKE_BUILD_TYPE Release)
  SET(CMAKE_BUILD_TYPE Debug)
ENDIF(NOT CMAKE_BUILD_TYPE)

SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wall")

#Build external librairies
#need to git submodule init first.
add_subdirectory(modules)

#Next, let's generate messages
add_subdirectory(messages)

add_subdirectory(src)
