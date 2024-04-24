#include "class_matrix.h"

int main() {
    Matrix <int> c1("input.txt");
    Matrix <int> c2(3, 4, 1);
    Matrix <int> c3(3, 4, 0);
    c1.read_matrix();
    c2.read_matrix();
    c3.read_matrix();
    return 0;
}