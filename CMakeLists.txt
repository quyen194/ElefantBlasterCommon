# CMakeList.txt : CMake project for ElefantBlasterProtocols.
# Include source and define project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# prevent installing to system directories.
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

# Declare the project
project ("ElefantBlasterProtocols" LANGUAGES C CXX)

if(MSVC)
    if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
        add_definitions(/MP)                # parallelize each target, unless Ninja is the generator
    endif()
endif()

# Create the library target
add_library(${PROJECT_NAME} STATIC)

# ========================================
# Run proto_generate.py during configure
# ========================================
find_package(Python3 REQUIRED COMPONENTS Interpreter)

execute_process(
    COMMAND ${Python3_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/proto_scripts/proto_generate.py"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    RESULT_VARIABLE PROTO_RESULT
)

if(NOT PROTO_RESULT EQUAL 0)
    message(FATAL_ERROR "Proto generation failed with exit code: ${PROTO_RESULT}")
endif()

message(STATUS "Proto generation completed successfully")

# Add include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/*.c"
    "${CMAKE_CURRENT_LIST_DIR}/*.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/*.hh"
    "${CMAKE_CURRENT_LIST_DIR}/*.cc"
)

# Add your sources to the target
target_sources(${PROJECT_NAME} PRIVATE
    ${SOURCE_FILES}
)

# Set the runtime library to be dynamic on MSVC builds
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY
        "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Build all libraries as static
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

include(FetchContent)

# abseil-cpp (Abseil C++ Common Libraries)
FetchContent_Declare(
    absl
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/abseil-cpp
)
FetchContent_MakeAvailable(absl)

# Protocol Buffers (protobuf)
set(protobuf_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(protobuf_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(protobuf_WITH_ZLIB OFF CACHE BOOL "" FORCE)
set(protobuf_BUILD_PROTOC_BINARIES OFF CACHE BOOL "" FORCE)
set(protobuf_INSTALL OFF CACHE BOOL "" FORCE)
set(protobuf_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(protobuf_MSVC_STATIC_RUNTIME OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    protobuf
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/protobuf
)
FetchContent_MakeAvailable(protobuf)
target_link_libraries(${PROJECT_NAME} PRIVATE protobuf::libprotobuf)

# aries_base (Common base library)
target_link_libraries(${PROJECT_NAME} PRIVATE aries_base)
