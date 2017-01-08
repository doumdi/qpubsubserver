#Will create additional library to be linked with original qmqtt lib.
#This is for testing

add_custom_target(qmqtt_server_readme SOURCES README.md)

include_directories(
    ${QMQTT_INCLUDES})


add_definitions(-DQT_NO_CAST_TO_ASCII)
add_definitions(-DQT_NO_CAST_FROM_ASCII)
add_definitions(-DQT_BUILD_MQTT_LIB)

set(qmqtt_server_headers
    qmqtt_server.h
)

set(qmqtt_server_srcs
    qmqtt_server.cpp
)

#This will generate moc_* for Qt
QT5_WRAP_CPP(qmqtt_server_moc_srcs ${qmqtt_server_headers})

#Create library
add_library(qmqtt_server SHARED ${qmqtt_server_srcs} ${qmqtt_server_headers} ${qmqtt_server_moc_srcs})
qt5_use_modules(qmqtt_server Core Network)
target_link_libraries(qmqtt_server ${QMQTT_LIBS})
