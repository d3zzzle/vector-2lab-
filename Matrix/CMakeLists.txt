file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${matrix} ${srcs} ${hdrs})

target_link_libraries(${matrix} ${matrixlib})