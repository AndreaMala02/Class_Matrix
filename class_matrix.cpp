#include "class_matrix.h"
#include <fstream>
#include <iostream>

//template<typename T>

Matrix::Matrix(int n, int m, int f) {
    (*this).n = n;
    (*this).m = m;
    (*this).matrix = new double*[n];
    for(int i=0; i<n; i++) {
        (*this).matrix[i] = new double[m];
    }
    if(f==0) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                std::cout << "Inserire il valore nella cella: [" << i << "," << j << "] della matrice: " <<std::endl;
                std::cin >> (*this).matrix[i][j];
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                (*this).matrix[i][j] == 1;
            }
        }
    }
}

Matrix::Matrix(char* file_input) {
    std::fstream in;
    in.open(file_input, std::ios::in);
    in >> (*this).n;
    in >> (*this).m;
    (*this).matrix = new double*[n];
    for(int i=0; i<n; i++) {
        (*this).matrix[i] = new double[m];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            in >> (*this).matrix[i][j];
        }
    }
    in.close();
}

Matrix::~Matrix() {
    for(int i=0; i<m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}