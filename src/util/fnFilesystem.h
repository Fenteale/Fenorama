//
// Created by fenteale on 12/31/21.
//
//pretty much copy-pasted from here https://github.com/Walaryne/oflauncher-stainless/blob/master/src/shared/util/OFFilesystem.h

#ifndef FENORAMA_FNFILESYSTEM_H
#define FENORAMA_FNFILESYSTEM_H

#if __cplusplus >= 201703L || _MSVC_LANG >= 201703L
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#endif //FENORAMA_FNFILESYSTEM_H
