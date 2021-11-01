file(GLOB_RECURSE CPPS  ./*.cpp )

add_executable(socket ${CPPS})

target_link_libraries(socket obc_baselib)
