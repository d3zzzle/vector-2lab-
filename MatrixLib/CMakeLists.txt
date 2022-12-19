file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${matrixlib} STATIC ${srcs} ${hdrs})