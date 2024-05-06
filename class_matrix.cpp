#include "class_matrix.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template<class T>
Matrix<T>::Matrix() {
    (*this).cont = 0;
    (*this).n = 2;
    (*this).m = 2;
    (*this).matrix = new T*[n];
    for(int i=0; i<n; i++) {
        (*this).matrix[i] = new T[m];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            (*this).matrix[i][j] = 0; 
        }
    }
}
template Matrix<int>::Matrix();
template Matrix<float>::Matrix();
template Matrix<double>::Matrix();

template <class T>
Matrix<T>::Matrix(int n, int m, int f) {
    (*this).cont = 0;
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
    else if(f==1) {
        srand(time(0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                (*this).matrix[i][j] = rand()%101;
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
    (*this).cont = 0;
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
    if((*this).cont == 0) {
        for(int i=0; i<n; i++) {
            delete[] (*this).matrix[i];
            (*this).cont = 1;
        }
        delete[] (*this).matrix; 
    }
    else {
        std::cout << "L'oggetto è già stato eliminato! Non si può eliminare nuovamente!" << std::endl;
    }
}
template Matrix<int>::~Matrix();
template Matrix<float>::~Matrix();
template Matrix<double>::~Matrix();

// template <class T>
// Matrix<T>::Matrix(Matrix& copy_matrix) {
//     copy_matrix.n = (*this).n;
//     copy_matrix.m = (*this).m;
//     copy_matrix.matrix = matrix;
// }
// template Matrix<int>::Matrix(Matrix& matrix);
// template Matrix<float>::Matrix(Matrix& matrix);
// template Matrix<double>::Matrix(Matrix& matrix);

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

template <class T>
void Matrix<T>::read_matrix_F(char* file_output) {
    std::fstream out;
    out.open(file_output, std::ios::app);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            out << (*this).matrix[i][j] << " ";
        }
        out << std::endl;
    }
    out << std::endl;
    out.close();
}

template void Matrix<int>::read_matrix_F(char*);
template void Matrix<float>::read_matrix_F(char*);
template void Matrix<double>::read_matrix_F(char*);

template <class T>
int Matrix<T>::set(int a, int b, T x) {
    if(a<(*this).n && b<(*this).m) {
        (*this).matrix[a][b] = x;
        return 0;
    }
    else{
        std::cout << "La dimensione specificata non è presente nella matrice!" << std::endl;
        return -1;
    }
}

template int Matrix<int>::set(int, int, int);
template int Matrix<float>::set(int, int, float);
template int Matrix<double>::set(int, int, double);

template <class T>
T Matrix<T>::get(int a, int b) {
    if(a<(*this).n && b<(*this).m) {
        return (*this).matrix[a][b]; 
    }
    else {
        std::cout << "La dimensione specificata non è presente nella matrice!" << std::endl;
        return -1;
    }
}

template int Matrix<int>::get(int, int);
template float Matrix<float>::get(int, int);
template double Matrix<double>::get(int, int);

// template <class T>
// void Matrix<T>::operator!() {
//     T c = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) {

//         }
//     }
    
//     c = (*this).m;
//     (*this).m = (*this).n;
//     (*this).n = c;
// }

// template void Matrix<int>::operator!();
// template void Matrix<float>::operator!();
// template void Matrix<double>::operator!();  

// template <class T>
// Matrix Matrix<T>::operator+(const Matrix& a, const Matrix& b) {
//     Matrix res(a.n, a.m);
//     if(a.n == b.n && a.m == b.m) {
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 res[i][j] = a[i][j] + b[i][j];
//             }
//         }
//         return res;
//     }
//     else {
//         return res;
//     }
     
// }

// template Matrix Matrix<int>::operator+(const Matrix& a, const Matrix& b);
// template Matrix Matrix<float>::operator+(const Matrix& a, const Matrix& b);
// template Matrix Matrix<double>::operator+(const Matrix& a, const Matrix& b);