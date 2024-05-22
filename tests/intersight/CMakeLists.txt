include(GoogleTest)

set(MODEL_TEST_SOURCES ./model/test_primitives.cc)

add_executable(${TESTS_EXECUTABLE_NAME} ${MODEL_TEST_SOURCES})

target_link_libraries(${TESTS_EXECUTABLE_NAME} ${LIBRARY_NAME})
target_link_libraries(${TESTS_EXECUTABLE_NAME} GTest::gtest_main)

target_include_directories(${TESTS_EXECUTABLE_NAME} PUBLIC ${INCLUDE_DIR})

gtest_discover_tests(${TESTS_EXECUTABLE_NAME})

set_target_properties(${TESTS_EXECUTABLE_NAME}
                      PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
