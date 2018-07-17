//
// Created by studu on 17/07/2018.
//

#ifndef LABORATORYPROJECT_MATRIXEXCEPTION_H
#define LABORATORYPROJECT_MATRIXEXCEPTION_H

#include <stdexcept>
#include <string>

class MatrixException : public std::exception {
public:
    explicit MatrixException(const std::string& msg=""): _msg(msg) {};
    virtual ~MatrixException() noexcept {}

    virtual const char *what() const noexcept override {
        return _msg.c_str();
    };

private:
    std::string _msg;
};

#endif //LABORATORYPROJECT_MATRIXEXCEPTION_H
