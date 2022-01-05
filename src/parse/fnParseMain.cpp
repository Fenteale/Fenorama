//
// Created by fenteale on 1/3/22.
//

#include "fnParseMain.h"

FNParse::FNParse(fs::path layoutToLoad) : _lc(), _inSmallDiv(false), _level(0) {
    std::fstream f;
    f.open(layoutToLoad, std::fstream::in);
    std::string line;
    bool ignoreTag = false;

    std::cout << "Outputting raw file input." << std::endl;

    while( getline(f, line) ) {
        std::string important;
        bool inTag = false;
        for (auto c : line) {
            if (!inTag) {
                if (!std::isspace(c)) {
                    if (_recognizedTag(c))
                        inTag = true;
                    else {
                        std::cout << "PARSE ERROR: TAG NOT RECOGNIZED" << std::endl;
                        inTag = false;
                    }
                }
            } else {
                if (_recognizedTag(c))
                    inTag = false;
                else
                    important += c;
            }
        }
        std::cout << "IMPORTANT: " << important << std::endl;
        std::cout << line << std::endl;
        if(important.rfind("!DOCTYPE", 0) == 0) {
            std::cout << "!DOCTYPE tag detected. Ignoring." << std::endl;
        } else if (important.rfind("html", 0) == 0 || important.rfind("/html", 0) == 0 ) {
            std::cout << "html tag detected. Ignoring." << std::endl;
        } else if (important.rfind("head", 0) == 0) {
            std::cout << "head tag detected. Ignoring." << std::endl;
        }
    }
}

bool FNParse::_recognizedTag(const char &c) const {
    switch (c) {
        case '<':
        case '>':
            return true;
        default:
            return false;
    }
}