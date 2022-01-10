//
// Created by fenteale on 1/3/22.
//

#include "fnParseMain.h"

FNParse::FNParse(fs::path layoutToLoad) : _lc(), _inSmallDiv(false), _level(0) {
    std::fstream f;
    f.open(layoutToLoad, std::ios::in | std::ios::binary);
    std::size_t size = fs::file_size(layoutToLoad);
    std::string fdata(size, '\0');
    f.read(fdata.data(), size);

    fnParseTag rootTag(fdata);
    rootTag.parseInside();
    /*
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
    */
}

