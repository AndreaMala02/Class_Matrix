#ifndef CLASS_MATRIX_H
#define CLASS_MATRIX_H

template <class T>
class Matrix{
    protected:
    int cont;
    int n;
    int m;
    T** matrix;
    public:
    Matrix();
    Matrix(int n, int m, int f=0); //Costruttore che genera una matrice di 1 se f==0, randomica (fra 0 e 100) se f==1, o di ciò che viene inserito da terminale se f!=0 e f!=1
    Matrix(char* file_input); //Costruttore che legge una matrice da file, 
                              //il file deve essere così composto: prima righa contentente numero righe e colonne della matrice separati da uno spazio
                              //le successive devono contenere gli elementi della matrice separando le colonne per spazi e le righe per "a capi"
    //Matrix(Matrix& copy_matrix);
    ~Matrix();
    //Matrix& operator=(const Matrix& matrix); 
    void read_matrix();
    void read_matrix_F(char* file_output);
    int set(int a, int b, T x);
    T get(int a, int b);

};

#endif