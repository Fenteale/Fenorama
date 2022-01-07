set(SOURCES
        fnParseMain.cpp
        fnParseMain.h
        fnPLayout.cpp
        fnPLayout.h
        fnParseTag.cpp
        fnParseTag.h)


add_library(fnParse ${SOURCES})

target_include_directories(fnParse PUBLIC ../util)