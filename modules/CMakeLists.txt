#Will verbose protobuf CMake.
set(protobuf_VERBOSE ON)

#Disable tests for now...
set(protobuf_BUILD_TESTS OFF)
add_subdirectory(protobuf/cmake)

#Building qmqtt
#This should be moved somewhere else
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)

add_definitions(-DQT_NO_CAST_TO_ASCII)
add_definitions(-DQT_NO_CAST_FROM_ASCII)
add_definitions(-DQT_BUILD_MQTT_LIB)

file(GLOB qmqtt_headers RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/qmqtt/src/mqtt/*.h")
#message(STATUS "qmqtt_headers : ${qmqtt_headers}")

file(GLOB qmqtt_srcs RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/qmqtt/src/mqtt/*.cpp")
#message(STATUS "qmqtt_srcs : ${qmqtt_srcs}")

#This will generate moc_* for Qt
QT5_WRAP_CPP(qmqtt_moc_srcs ${qmqtt_headers})

#Add include directory
include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/qmqtt/src/mqtt)

#Build the library
add_library(qmqtt SHARED ${qmqtt_headers} ${qmqtt_srcs} ${qmqtt_moc_srcs})
#Handle Qt dependencies
qt5_use_modules(qmqtt Core Network)

#cached variables
set(QMQTT_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/qmqtt/src/mqtt CACHE INTERNAL "doc string")
set(QMQTT_LIBS "qmqtt" CACHE INTERNAL "doc string")

