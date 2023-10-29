cmake_minimum_required(VERSION 3.21)
project(tinyrpc CXX)

set(CMAKE_CXX_COMPILER /usr/bin/c++)

# *.cc
aux_source_directory(${PROJECT_SOURCE_DIR}/tinyrpc/comm COMM)
aux_source_directory(${PROJECT_SOURCE_DIR}/tinyrpc/coroutine COR)
aux_source_directory(${PROJECT_SOURCE_DIR}/tinyrpc/net NET)
aux_source_directory(${PROJECT_SOURCE_DIR}/tinyrpc/net/tcp TCP)
aux_source_directory(${PROJECT_SOURCE_DIR}/tinyrpc/net/tinypb TINYPB)
#
# set(COXTX ${PROJECT_SOURCE_DIR}/tinyrpc/coroutine/coctx_swap.S)
#
add_library(tinyrpc ${COMM} ${COR} ${NET}  ${TCP} ${TINYPB} ${COXTX})
# # install(TARGETS tinyrpc DESTINATION ${PATH_LIB})
#
#
# find_package(Protobuf REQUIRED)
# if (${PROTOBUF_FOUND})
#   message("protobuf found")
# else ()
#   message(FATAL_ERROR "Cannot find Protobuf")
# endif ()
#
#
# set(LIBS
#     tinyrpc
#     ${Protobuf_LIBRARY}
#     pthread
# )
include_directories(${PROJECT_SOURCE_DIR}/tinyrpc/include)
add_executable(test test.cpp)
