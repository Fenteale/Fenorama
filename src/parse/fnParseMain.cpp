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

    bool inTag = false;
    int tagStart = 0;
    std::string currentTag = "";
    std::string toIgnoreTo = "";
    bool ignoreTag = true;

    std::cout << "Outputting raw file input." << std::endl;
    std::cout << fdata << std::endl;

    for (int i=0; i < fdata.length(); i++) {
        if(!inTag) {
            if(fdata[i] == '<') {
                std::cout << "TAG DETECTED: ";
                inTag = true;
                tagStart = i;
            }
        } else {
            if(fdata[i] == '>') {
                inTag = false;
                currentTag = fdata.substr(tagStart, i-tagStart);
                std::cout << currentTag << std::endl;
            }
        }
        if (_ignoredTag(currentTag)) {
            toIgnoreTo = "</" + currentTag.substr(1, currentTag.length()-1);
            std::cout << "SHOULD BE IGNORING TO " << toIgnoreTo << std::endl;
            ignoreTag=true;
        } else {
            ignoreTag = false;
        }
    }
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

bool FNParse::_ignoredTag(const std::string &ttc) const {
    std::string ignoredTags[] = {
            "<head",
            //"<html",
            "<!DOCTYPE"
    };
    std::string ignoredTagsOnce[] = {
            "<!DOCTYPE"
    };
    std::string goodTags[] = {
            "<body"
    };
    std::string nullTags[] = {
            "<html"
    };
    bool toIgnore = false;
    for (auto t : ignoredTags) {
        if (ttc.length() >= t.length()) {
            if (ttc.substr(0, t.length()) == t) {
                toIgnore = true;
                break;
            }
        }
    }
    return toIgnore;
}