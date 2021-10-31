set(SOURCES
        fenorama.h)

set(FEN_LIBRARIES
        fnGui)

add_subdirectory(gui)

add_library(fenorama ${SOURCES})

target_link_libraries(fenorama LINK_PUBLIC ${FEN_LIBRARIES})