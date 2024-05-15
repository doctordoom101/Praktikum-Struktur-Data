//
// Created by Defanda on 15/05/2024.
//
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << "##  Program C++ Perkalian Matriks 3x3  ##" << endl;
    cout << "=========================================" << endl;
    cout << endl;

    int matriksA[3][3], matriksB[3][3], hasil[3][3] = {0};

    // isi elemen matriksA
    cout << "Masukan Nilai Matrix A" << endl;
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "Masukan Nilai MatrixA [" << i << "]" << "[" << j << "]: ";
            cin >> matriksA[i][j];
        }
    }

    // isi elemen matriksB
    cout << "Masukan Nilai Matrix B" << endl;
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "Masukan Nilai MatrixB [" << i << "]" << "[" << j << "]: ";
            cin >> matriksB[i][j];
        }
    }

    // proses perhitungan matriksA * matriksB
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                hasil[i][j] += (matriksA[i][k] * matriksB[k][j]);
            }
        }
    }

    // tampilkan matriks A, B dan hasil berdampingan
    cout << "Matriks A        Matriks B        Hasil Matriks A * B" << endl;
    for(int i = 0; i < 3; i++){
        // Tampilkan matriksA
        for(int j = 0; j < 3; j++){
            cout << setw(3) << matriksA[i][j] << " ";
        }
        cout << "    "; // spasi antara matriks

        // Tampilkan matriksB
        for(int j = 0; j < 3; j++){
            cout << setw(3) << matriksB[i][j] << " ";
        }
        cout << "    "; // spasi antara matriks

        // Tampilkan hasil matriks
        for(int j = 0; j < 3; j++){
            cout << setw(3) << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}