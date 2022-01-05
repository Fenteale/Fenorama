//
// Created by fenteale on 10/31/21.
//

#include "fnGuiMain.h"

FNGui::FNGui() {
    std::cout << "FNGui object created." << std::endl;
}

FNGui::FNGui(SDL_Window *window, SDL_Renderer *renderer) {
    if(window == nullptr)
        throw std::runtime_error("SDL_Window pointer invalid.");
    if(renderer == nullptr)
        throw std::runtime_error("SDL_Renderer invalid.");
    std::cout << "FNGui object created with SDL2 support." << std::endl;
}

void FNGui::loadLayout(fs::path layoutPath, fnCi x, fnCi y, fnCi width, fnCi height) {
    if(!fs::is_regular_file(layoutPath))
        throw std::runtime_error("Given path is not a file.");
    else
        std::cout << "Loading layout file: " << layoutPath.string() << std::endl;

    FNParse fileParse(layoutPath);
}

void FNGui::process() {
    //nothing for now
}