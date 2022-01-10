//
// Created by fenteale on 1/3/22.
//

#ifndef FENORAMA_FNPARSEMAIN_H
#define FENORAMA_FNPARSEMAIN_H

#include <string>
#include <iostream>
#include <fstream>
#include "fnFilesystem.h"
#include "fnPLayout.h"
#include "fnParseTag.h"

class FNParse {
public:
    FNParse(fs::path layoutToLoad);
private:
    FNPLayout _lc;
    bool _inSmallDiv;
    int _level;


    //tagdetected
};


#endif //FENORAMA_FNPARSEMAIN_H
