//
// Created by Defanda on 02/05/2024.
//
#include <iostream>
using namespace std;

int main(){
    int x;
    int *px; //pointer ke variabel
    int **ppx; //pointer ke pointer

    x = 175;
    px = &x;
    ppx = &px;
    cout << "nilai x = " << x << endl;
    cout << "nilai px = " << *px << endl;
    cout << "nilai ppx = " << *ppx << endl;
}