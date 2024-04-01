//
// Created by Defanda on 27/03/2024.
//
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Fungsi perkalian dua matriks
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    // Resultant matriks
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    // Perkalian matriks
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Fungsi untuk display matriks
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << setw(5) << elem << " ";
        }
        cout << endl;
    }
}

// fungsi untuk input elemen matriks
void inputMatrix(vector<vector<int>>& matrix, const string& matrix_name) {
    cout << "Masukkan elemen " << matrix_name << ":" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << "Baris " << i + 1 << ", kolom " << j + 1 << " = ";
            cin >> matrix[i][j];
        }
    }
}

int main() {
    cout << "##  Program C++ Perkalian Matriks  ##" << endl;
    cout << "=====================================" << endl << endl;

    int rows1, cols1, rows2, cols2;

    // Input jumlah baris dan kolom matriks pertama
    cout << "Masukkan jumlah baris matriks pertama: ";
    cin >> rows1;
    cout << "Masukkan jumlah kolom matriks pertama: ";
    cin >> cols1;

    // Input jumlah baris dan kolom matriks kedua
    cout << "Masukkan jumlah baris matriks kedua: ";
    cin >> rows2;
    cout << "Masukkan jumlah kolom matriks kedua: ";
    cin >> cols2;

    if (cols1 != rows2) {
        cout << "Error: Jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua." << endl;
        return 1;
    }

    // Input elemen matriks pertama
    vector<vector<int>> matrix1(rows1, vector<int>(cols1));
    inputMatrix(matrix1, "matriks pertama");

    // Input elemen matriks kedua
    vector<vector<int>> matrix2(rows2, vector<int>(cols2));
    inputMatrix(matrix2, "matriks kedua");

    // Display matriks
    cout << "\nMatriks Pertama:" << endl;
    displayMatrix(matrix1);

    cout << "\nMatriks Kedua:" << endl;
    displayMatrix(matrix2);

    // Perkalian matriks hasil
    vector<vector<int>> result = multiplyMatrices(matrix1, matrix2);

    // Display hasil
    cout << "\nMatriks Hasil:" << endl;
    displayMatrix(result);

    return 0;
}