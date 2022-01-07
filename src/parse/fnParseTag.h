//
// Created by fenteale on 1/7/22.
//

#ifndef FENORAMA_FNPARSETAG_H
#define FENORAMA_FNPARSETAG_H

#include <string>
#include <iostream>

class fnParseTag {
protected:
    std::string tagType;
    std::string data;
public:
    fnParseTag(std::string tagType, std::string data);
    void parseInside();
};


#endif //FENORAMA_FNPARSETAG_H
