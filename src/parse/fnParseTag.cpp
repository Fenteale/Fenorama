//
// Created by fenteale on 1/7/22.
//

#include "fnParseTag.h"

fnParseTag::fnParseTag(std::string tagType, std::string data)
    : tagType(tagType), data(data) {
    //nothing for now
}

void fnParseTag::parseInside() {
    for(auto ch : data) {
        if(ch == '<')
            std::cout << "TAG DETECTED" << std::endl;
    }
}