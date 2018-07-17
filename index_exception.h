//
// Created by studu on 17/07/2018.
//

#ifndef LABORATORYPROJECT_INDEX_EXCEPTION_H
#define LABORATORYPROJECT_INDEX_EXCEPTION_H

#include "MatrixException.h"
#include <string>

class index_exception : public MatrixException {
public:
    index_exception(const std::string& msg="") : MatrixException(msg) {};
};

#endif //LABORATORYPROJECT_INDEX_EXCEPTION_H
