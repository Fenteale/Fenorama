#include(../src/CMakeLists.txt)

set(SOURCES
        main.cpp)

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
find_library(SDL2_LIBRARY SDL2)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(main_test ${SOURCES})

target_link_libraries(main_test LINK_PUBLIC fenorama ${SDL2_LIBRARY})