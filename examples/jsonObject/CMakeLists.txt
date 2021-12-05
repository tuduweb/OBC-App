file(GLOB_RECURSE CPPS  ./*.cpp )

add_executable(jsonObject ${CPPS})

target_link_libraries(jsonObject obc_baselib)

# PRIVATE Qt${QT_VERSION_MAJOR}::Core
# Qt${QT_VERSION_MAJOR}::Widgets
# Qt${QT_VERSION_MAJOR}::SerialPort
# Qt${QT_VERSION_MAJOR}::Quick
# Qt${QT_VERSION_MAJOR}::WebSockets
# Qt${QT_VERSION_MAJOR}::Network