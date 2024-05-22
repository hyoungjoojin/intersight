set(MODEL_SOURCES ./model/primitives.cc)

target_sources(${LIBRARY_NAME} PRIVATE ${MODEL_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})
