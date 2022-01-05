//
// Created by fenteale on 10/31/21.
//

#ifndef FENORAMA_FNGUIMAIN_H
#define FENORAMA_FNGUIMAIN_H

#include <iostream>
#include <stdexcept>
#include "SDL2/SDL.h"
#include "fnFilesystem.h"
#include "fnParseMain.h"
#include "fnDefs.h"

class FNGui {
public:
    FNGui(); // blank construction WIP
    FNGui(SDL_Window *window, SDL_Renderer* renderer);

    void loadLayout(fs::path layoutPath, fnCi x, fnCi y, fnCi width, fnCi height);
    void process();
};

#endif //FENORAMA_FNGUIMAIN_H
