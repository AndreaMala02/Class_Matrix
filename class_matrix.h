#ifndef CLASS_MATRIX.H
#define CLASS_MATRIX.H

//template <typename T>

class Matrix{
    protected:
    int n;
    int m;
    double** matrix;
    public:
    Matrix(int n, int m, int f=0); //Costruttore che genera una matrice di 1 o di ciò che viene inserito da terminale
    Matrix(char* file_input); //Costruttore che legge una matrice da file, 
                              //il file deve essere così composto: prima righa contentente numero righe e colonne della matrice separati da uno spazio
                              //le successive devono contenere gli elementi della matrice separando le colonne per spazi e le righe per "a capi"
    ~Matrix();
};

#endif