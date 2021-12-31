set(SOURCES
        fenorama.h)

set(FEN_LIBRARIES
        fnGui
        fnUtil)

add_subdirectory(gui)
#add_subdirectory(util)

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
find_library(SDL2_LIBRARY SDL2)

include_directories(${SDL2_INCLUDE_DIR})

add_library(fenorama ${SOURCES})

target_link_libraries(fenorama LINK_PUBLIC ${FEN_LIBRARIES} ${SDL2_LIBRARY})