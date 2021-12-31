set(SOURCES
        fnGuiMain.cpp
        fnGuiMain.h)


add_library(fnGui ${SOURCES})

target_include_directories(fnGui PRIVATE ../util)