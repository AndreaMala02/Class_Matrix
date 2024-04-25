#include "class_matrix.h"
#include <iostream>

int main() {
    Matrix <int> c1("input.txt");
    Matrix <int> c2(3, 4, 1);
    Matrix <int> c3(3, 4, 0);
    c1.read_matrix_F("output.txt");
    c2.read_matrix_F("output.txt");
    c3.read_matrix_F("output.txt");
    c1.set(2, 2, 3);
    c1.read_matrix_F("output.txt");
    // c1.set(3, 3, 3);
    // c1.read_matrix_F("output.txt");
    int T = c1.get(2, 2);
    std::cout << "Il valore di T è: " << T << std::endl;
    // int Y = c1.get(3, 3); 
    // std::cout << "Il valore di Y è: " << Y << std::endl;
    //c1.~Matrix(); Da chiedere al prof perché non funziona
    //c2.~Matrix();
    //c3.~Matrix();
    return 0;
}