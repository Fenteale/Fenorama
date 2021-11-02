#include(../src/CMakeLists.txt)

set(SOURCES
        main.cpp)

add_executable(main_test ${SOURCES})

target_link_libraries(main_test LINK_PUBLIC fenorama)