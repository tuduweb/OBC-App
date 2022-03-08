set(OBC_DEVICE_DIR ${CMAKE_SOURCE_DIR}/src/implement/device/)

file(GLOB DEVICE_FILES ${OBC_DEVICE_DIR}/*/*)
#file(GLOB SRC_WIDGETS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/*)

set(OBC_DEVICE_SOURCES
    ${OBC_DEVICE_DIR}/mvcam/MVCAMDevice.hpp
    ${OBC_DEVICE_DIR}/mvcam/MVCAMDevice.cpp
    ${DEVICE_FILES}
)

message(${DEVICE_FILES})
