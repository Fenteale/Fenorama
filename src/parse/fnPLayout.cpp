//
// Created by fenteale on 1/4/22.
//

#include "fnPLayout.h"

FNPLayout::FNPLayout() : _objs() {
    //nothing for now
}

void FNPLayout::addObject(LayoutObjects objectToAdd) {
    _objs.emplace_back(objectToAdd);
}