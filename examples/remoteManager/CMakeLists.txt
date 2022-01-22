file(GLOB_RECURSE CPPS  ./*.cpp )

add_executable(remoteManager ${CPPS} ${OBC_BASE_SOURCES})

target_link_libraries(remoteManager obc_baselib)

# PRIVATE Qt${QT_VERSION_MAJOR}::Core
# Qt${QT_VERSION_MAJOR}::Widgets
# Qt${QT_VERSION_MAJOR}::SerialPort
# Qt${QT_VERSION_MAJOR}::Quick
# Qt${QT_VERSION_MAJOR}::WebSockets
# Qt${QT_VERSION_MAJOR}::Network