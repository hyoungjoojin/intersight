cmake_minimum_required(VERSION 3.29)

set(PROJECT_NAME intersight)
set(VERSION 0.1)

project(
  ${PROJECT_NAME}
  VERSION ${VERSION}
  LANGUAGES CXX)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(TESTS_DIR "${PROJECT_SOURCE_DIR}/tests")
set(BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(COMPILE_OPTIONS -Wall -Werror -Wextra)

set(LIBRARY_NAME "${PROJECT_NAME}_library")
set(TESTS_EXECUTABLE_NAME "${PROJECT_NAME}_tests")
set(EXECUTABLE_NAME "${PROJECT_NAME}")

add_library(${LIBRARY_NAME})
add_subdirectory(${SOURCE_DIR}/${PROJECT_NAME})

set(SOURCES ${SOURCE_DIR}/main.cc)
add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                    ${BINARY_DIR})
target_compile_options(${EXECUTABLE_NAME} PUBLIC ${COMPILE_OPTIONS})

# googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
set(TESTS_EXECUTABLE_NAME "${PROJECT_NAME}_tests")
add_subdirectory(${TESTS_DIR}/${PROJECT_NAME})

set_target_properties(
  ${TESTS_EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                      "${PROJECT_SOURCE_DIR}/bin")
target_compile_options(${TESTS_EXECUTABLE_NAME} PUBLIC ${COMPILE_OPTIONS})
