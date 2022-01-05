//
// Created by fenteale on 1/4/22.
//

#ifndef FENORAMA_FNPLAYOUT_H
#define FENORAMA_FNPLAYOUT_H

#include <vector>

enum LayoutObjects {
    NO_OBJECT,
    DIVIDER,
    TEXT_OBJECT,
    IMAGE_OBJECT
};

class FNPLayout {
private:
    std::vector<LayoutObjects> _objs;
public:
    FNPLayout();
    void addObject(LayoutObjects objectToAdd);
};


#endif //FENORAMA_FNPLAYOUT_H
