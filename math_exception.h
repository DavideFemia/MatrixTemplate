//
// Created by studu on 17/07/2018.
//

#ifndef LABORATORYPROJECT_MATH_EXCEPTION_H
#define LABORATORYPROJECT_MATH_EXCEPTION_H

#include "MatrixException.h"
#include <string>

class math_exception : public MatrixException {
public:
    math_exception(const std::string& msg="") : MatrixException(msg) {};
};

#endif //LABORATORYPROJECT_MATH_EXCEPTION_H
