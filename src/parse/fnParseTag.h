//
// Created by fenteale on 1/7/22.
//

#ifndef FENORAMA_FNPARSETAG_H
#define FENORAMA_FNPARSETAG_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>

enum tagHandleType {
    NULL_TAG,
    GOOD_TAG,
    IGNORE_TAG,
    IGNORE_ONCE_TAG
};

class fnParseTag {
protected:
    std::string _tagType;
    std::string _data;
    std::vector<std::shared_ptr<fnParseTag>> _subTags;

    tagHandleType _getTagType(const std::string &ttc) const;
public:
    fnParseTag(const std::string &data);
    void parseInside();
    void runAllSubTags();
};


#endif //FENORAMA_FNPARSETAG_H
