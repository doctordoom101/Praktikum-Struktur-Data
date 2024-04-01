//
// Created by Defanda on 27/03/2024.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "##  Program C++ Perkalian Matriks 2x2  ##" << endl;
    cout << "=========================================" << endl;
    cout << endl;

    int matriksA[2][2], matriksB[2][2], matriksHasil[2][2] = {0};
    int i,j,k;

    // proses input elemen matriksA
    cout << "  Input Matriks A  "<< endl;
    cout << "-------------------"<< endl;
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2; j++){
            cout << "Baris " <<i+1<<", kolom "<<j+1<< " = ";
            cin >> matriksA[i][j];
        }
    }
    cout << endl;

    // proses input elemen matriksB
    cout << "  Input Matriks B  "<< endl;
    cout << "-------------------"<< endl;
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2; j++){
            cout << "Baris " <<i+1<<", kolom "<<j+1<< " = ";
            cin >> matriksB[i][j];
        }
    }
    cout << endl;

    // tampilkan isi matriksA
    cout << "Matriks A: " << endl;
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2; j++){
            cout << setw(3) << matriksA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // tampilkan isi matriksB
    cout << "Matriks B: " << endl;
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2; j++){
            cout << setw(3) << matriksB[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // proses perhitungan matriksA * matriksB
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2; j++){
            for(k = 0; k < 2; k++){
                matriksHasil[i][j] = matriksHasil[i][j] + (matriksA[i][k] * matriksB[k][j]);
            }
        }
    }

    // tampilkan isi matriksHasil
    cout << "Matriks A * Matriks B: " << endl;
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2; j++){
            cout << setw(3) << matriksHasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
