set(MODEL_SOURCES ./model/primitives.cc ./model/mesh.cc ./model/texture.cc)
set(CAMERA_SOURCES ./camera/camera.cc)
set(VIEWER_SOURCES ./viewer/ascii.cc)
set(RENDERER_SOURCES ./renderer/renderer.cc)

target_sources(${LIBRARY_NAME} PRIVATE ${MODEL_SOURCES} ${CAMERA_SOURCES}
                                       ${VIEWER_SOURCES} ${RENDERER_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})
