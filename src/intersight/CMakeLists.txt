set(MODEL_SOURCES ./model/primitives.cc ./model/mesh.cc)
set(CAMERA_SOURCES ./camera/camera.cc)

target_sources(${LIBRARY_NAME} PRIVATE ${MODEL_SOURCES} ${CAMERA_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})
