

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5NetworkAuth REQUIRED)


add_subdirectory(qmqtt_server)


set(qpubsubserver_srcs
    main.cpp

)


set(qpubsubserver_headers
    main.h
)

SET(qpubsubserver_resources

)

#This will compile .qrc files for Qt
QT5_ADD_RESOURCES(res_qpubsubserver ${qpubsubserver_resources})

#This will generate moc_* for Qt
QT5_WRAP_CPP(moc_srcs_qpubsubserver ${qpubsubserver_headers})

#Add includes
include_directories(
    ${MESSAGES_INCLUDES}
    ${QMQTT_INCLUDES}
    ${CMAKE_CURRENT_SOURCE_DIR}/qmqtt_server
)

add_executable(qpubsubserver
    ${qpubsubserver_srcs}
    ${qpubsubserver_headers}
    ${res_qpubsubserver}
    ${moc_srcs_qpubsubserver}
)

#Qt dependencies
qt5_use_modules(qpubsubserver Core Network NetworkAuth)
#Additional libraries
target_link_libraries(qpubsubserver qmqtt_server ${MESSAGES_LIBS})
