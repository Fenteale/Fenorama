//
// Created by fenteale on 1/7/22.
//

#include "fnParseTag.h"

enum parseState {
    TAG_NOT_FOUND,
    TAG_START_FOUND,
    IGNORE_TAG_UNTIL_END,
    IGNORE_TAG_ONCE,
    CAPTURING
};

fnParseTag::fnParseTag(const std::string &data)
    : /* _tagType(tagType) idk yet ,*/ _data(data) {
    //nothing for now
}

void fnParseTag::parseInside() {
    parseState currState = TAG_NOT_FOUND;
    int tagStart = 0;
    int captureStart = 0;
    int captureEnd = _data.length()-1;
    std::string currentTag = "";
    std::string endTag = "";
    bool ignoreTag = true;

    std::cout << "Outputting raw file input." << std::endl;
    std::cout << _data << std::endl;

    for (int i=0; i < _data.length(); i++) {
        switch (currState) {
            case TAG_NOT_FOUND:
                if(_data[i] == '<') {
                    std::cout << "TAG DETECTED: ";
                    currState = TAG_START_FOUND;
                    tagStart = i;
                }
                break;
            case TAG_START_FOUND:
                if(_data[i] == '>') {
                    //currState = CAPTURE_START;
                    currentTag = _data.substr(tagStart, i-tagStart);
                    std::cout << currentTag << std::endl;
                    endTag = "</" + currentTag.substr(1, currentTag.find(" ")-1);
                    switch(_getTagType(currentTag)) {
                        case IGNORE_TAG:
                            std::cout << "SHOULD BE IGNORING TO " << endTag << std::endl;
                            currState = IGNORE_TAG_UNTIL_END;
                            break;
                        case IGNORE_ONCE_TAG:
                            std::cout << "IGNORING: " << currentTag << std::endl;
                            currState = TAG_NOT_FOUND;
                            break;
                        default:
                            captureStart = i+1;
                            currState = CAPTURING;
                            break;
                    }
                }
                break;
            case IGNORE_TAG_UNTIL_END:
                if(_data[i] == '<') {
                    if(_data.substr(i, endTag.length()-1) == endTag) {
                        i += endTag.length()-1;
                        currState = TAG_NOT_FOUND;
                    }
                }
                break;
            case CAPTURING:
                if(_data[i] == '<') {
                    std::string toCheck = _data.substr(i, endTag.length());
                    if(toCheck == endTag) {
                        captureEnd = i-1;
                        //_subTags.emplace_back()
                        i += endTag.length()-1;
                        currState = TAG_NOT_FOUND;
                    }
                }
        }

    }
    std::cout << "To be focking sent to sub thing:" << std::endl;
    std::cout << _data.substr(captureStart, captureEnd-captureStart) << std::endl;
}

tagHandleType fnParseTag::_getTagType(const std::string &ttc) const {
    std::string ignoredTags[] = {
            "<head"
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
    //tagHandleType ttype = NULL_TAG;
    for (auto &t : ignoredTags) {
        if (ttc.length() >= t.length()) {
            if (ttc.substr(0, t.length()) == t) {
                return IGNORE_TAG;
                //ttype = IGNORE_TAG;
                //break;
            }
        }

    }
    for (auto &t : ignoredTagsOnce) {
        if (ttc.length() >= t.length()) {
            if (ttc.substr(0, t.length()) == t) {
                return IGNORE_ONCE_TAG;
            }
        }
    }
    for (auto &t : goodTags) {
        if (ttc.length() >= t.length()) {
            if (ttc.substr(0, t.length()) == t) {
                return GOOD_TAG;
            }
        }
    }
    for (auto &t : nullTags) {
        if (ttc.length() >= t.length()) {
            if (ttc.substr(0, t.length()) == t) {
                return NULL_TAG;
            }
        }
    }
    return NULL_TAG;
}

void fnParseTag::runAllSubTags() {
        for(auto &t : _subTags) {
            t->parseInside();
            t->runAllSubTags();
        }
    }