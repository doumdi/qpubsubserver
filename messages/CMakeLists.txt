message(STATUS "Generating messages...")

FILE(GLOB messages RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

add_custom_target(all_messages SOURCES ${messages})

#Message files output directory, will create directory
set (output_directory ${CMAKE_CURRENT_BINARY_DIR}/messages)
file(MAKE_DIRECTORY ${output_directory})

message(STATUS "Output Directory : ${output_directory}")

set (generated_headers "")
set (generated_srcs "")

#Generate code using protoc compiler
foreach (file ${messages})

    message(STATUS "Processing : ${file}")

    get_filename_component (name_without_extension ${file} NAME_WE)
    set(output_header_file ${output_directory}/${name_without_extension}.pb.h)
    set(output_src_file ${output_directory}/${name_without_extension}.pb.cc)

    #Complete files to be compiled...
    list(APPEND generated_headers ${output_header_file})
    list(APPEND generated_srcs ${output_src_file})

    #Should execute protoc on each .proto files
    #Ex: protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/addressbook.proto

    add_custom_command(OUTPUT ${output_header_file} ${output_src_file}
                   COMMAND protoc -I=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=${output_directory} ${CMAKE_CURRENT_SOURCE_DIR}/${file}
                   DEPENDS ${file} protoc
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                   VERBATIM)
endforeach()

message (STATUS "Headers : ${generated_headers}")
message (STATUS "Sources : ${generated_srcs}")

include_directories(
    ${PROJECT_SOURCE_DIR}/modules/protobuf/src
    ${output_directory}
)

#compile library
add_library(lib_messages SHARED ${generated_headers} ${generated_srcs})
#Link with protobuf
target_link_libraries(lib_messages libprotobuf)

get_target_property(all_includes lib_messages INCLUDE_DIRECTORIES)

message (STATUS "includes : ${all_includes}")

set(MESSAGES_INCLUDES ${all_includes} CACHE INTERNAL "doc string")
set(MESSAGES_LIBS "lib_messages" CACHE INTERNAL "doc string")


