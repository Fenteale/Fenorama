set(SOURCES
        fnParseMain.cpp
        fnParseMain.h
        fnPLayout.cpp
        fnParseMain.h)


add_library(fnParse ${SOURCES})

target_include_directories(fnParse PUBLIC ../util)