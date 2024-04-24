#include "class_matrix.h"
#include <fstream>
#include <iostream>

template <class T>
Matrix<T>::Matrix(int n, int m, int f) {
    int flag = 0;
    (*this).n = n;
    (*this).m = m;
    (*this).matrix = new T*[n];
    for(int i=0; i<n; i++) {
        (*this).matrix[i] = new T[m];
    }
    if(f==0) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
               (*this).matrix[i][j] = 1; 
            }
        }
    }
    else {
        flag++;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                std::cout << "Inserire il valore nella cella: [" << i << "," << j << "] della matrice: " <<std::endl;
                std::cin >> (*this).matrix[i][j];
            }
        }
    }
    if(flag==1) {
        std::cout << std::endl;
    }
}
template Matrix<int>::Matrix(int, int, int);
template Matrix<float>::Matrix(int, int, int);
template Matrix<double>::Matrix(int, int, int);

template <class T>
Matrix<T>::Matrix(char* file_input) {
    std::fstream in;
    in.open(file_input, std::ios::in);
    in >> (*this).n;
    in >> (*this).m;
    (*this).matrix = new T*[n];
    for(int i=0; i<n; i++) {
        (*this).matrix[i] = new T[m];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            in >> (*this).matrix[i][j];
        }
    }
    in.close();
}
template Matrix<int>::Matrix(char*);
template Matrix<float>::Matrix(char*);
template Matrix<double>::Matrix(char*);

template <class T>
Matrix<T>::~Matrix() {
    for(int i=0; i<m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
template Matrix<int>::~Matrix();
template Matrix<float>::~Matrix();
template Matrix<double>::~Matrix();

template <class T>
void Matrix<T>::read_matrix() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cout << (*this).matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template void Matrix<int>::read_matrix();
template void Matrix<float>::read_matrix();
template void Matrix<double>::read_matrix();