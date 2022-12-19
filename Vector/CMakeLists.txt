file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${vector} ${srcs} ${hdrs})

target_link_libraries(${vector} ${vectorlib})