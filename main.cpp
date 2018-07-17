#include <iostream>
using namespace std;

#include "Matrix.h"

int main() {
    Matrix<float> C(2, 3, {3, 5, 1, 0, 4, 7});

    try {
        Matrix<float> B(3, 2, {1, 4, 1, 0, 2, 6,8});
    }
    catch(index_exception& e){
        cout<<e.what()<<endl;
    }

    cout<<endl;

    Matrix<float> B(3, 2, {1, 4, 1, 0, 2, 6});

    cout << "C =" << endl;
    for (int i = 0; i < C.getRows(); i++) {
        cout << "  ";
        for (int j = 0; j < C.getColumns(); j++) {
            cout << C.getValue(i, j) << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "B =" << endl;
    for (int i = 0; i < B.getRows(); i++) {
        cout << "  ";
        for (int j = 0; j < B.getColumns(); j++) {
            cout << B.getValue(i, j) << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "C.getRows() = " << C.getRows() << endl;
    cout << "C.getColumns() = " << C.getColumns() << endl;

    cout << endl;

    cout << "B.getRows() = " << B.getRows() << endl;
    cout << "B.getColumns() = " << B.getColumns() << endl;

    cout << endl;

    Matrix<float> product = C * B;
    cout << "C * B =" << endl;
    for (int i = 0; i < product.getRows(); i++) {
        cout << "  ";
        for (int j = 0; j < product.getColumns(); j++) {
            cout << product.getValue(i, j) << " ";
        }
        cout << endl;
    }

    cout<<endl;

    try {
        product*=B;
    }
    catch(math_exception& e){
        cout<<e.what()<<endl;
    }

    cout << endl;

    cout << "C.transpose()" << endl;
    C.transpose();
    cout << "C =" << endl;
    for (int i = 0; i < C.getRows(); i++) {
        cout << "  ";
        for (int j = 0; j < C.getColumns(); j++) {
            cout << C.getValue(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
