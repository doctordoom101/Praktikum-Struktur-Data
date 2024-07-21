//
// Created by Defanda on 20/05/2024.
//
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Mahasiswa {
    string Nim;
    string Nama;
    int QuizStruData1;
    int QuizStruData2;
    float Rata2QuizStruData;
    string Predikat;
};

void inputData(Mahasiswa* mhs) {
    cout << "NIM: ";
    cin >> mhs->Nim;
    cout << "Nama: ";
    cin.ignore(); // To ignore the newline character left by previous cin
    getline(cin, mhs->Nama);
    cout << "Quiz Struktur Data 1: ";
    cin >> mhs->QuizStruData1;
    cout << "Quiz Struktur Data 2: ";
    cin >> mhs->QuizStruData2;

    mhs->Rata2QuizStruData = (mhs->QuizStruData1 + mhs->QuizStruData2) / 2.0;

    if (mhs->Rata2QuizStruData >= 88) {
        mhs->Predikat = "Cumlaude";
    } else if (mhs->Rata2QuizStruData >= 77 && mhs->Rata2QuizStruData < 88) {
        mhs->Predikat = "Memuaskan";
    } else if (mhs->Rata2QuizStruData >= 60 && mhs->Rata2QuizStruData < 77) {
        mhs->Predikat = "Cukup";
    } else {
        mhs->Predikat = "Tidak Lulus";
    }
}

void tampilkanData(Mahasiswa* mhs, int n) {
    cout << "Daftar Nilai MK Struktur Data Anggota Kelompok Belajar Struktur Data" << endl;
    cout << string(90, '=') << endl;
    cout << left << setw(3) << "No" << setw(15) << "NIM" << setw(25) << "Nama" << setw(30) << "Rata2 Quiz Struktur Data" << setw(12) << "Predikat" << endl;
    cout << string(90, '=') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(3) << i + 1 << setw(15) << mhs[i].Nim << setw(25) << mhs[i].Nama << setw(30) << fixed << setprecision(2) << mhs[i].Rata2QuizStruData << setw(12) << mhs[i].Predikat << endl;
    }
    cout << string(90, '=') << endl;
}

int main() {
    int n;
    cout << "Jumlah mahasiswa: ";
    cin >> n;

    Mahasiswa* mhs = new Mahasiswa[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data Mahasiswa ke-" << i + 1 << endl;
        inputData(&mhs[i]);
    }

    tampilkanData(mhs, n);

    int countCumlaude = 0;
    int countMemuaskan = 0;
    int countCukup = 0;

    for (int i = 0; i < n; i++) {
        if (mhs[i].Predikat == "Cumlaude") {
            countCumlaude += 1;
        } else if (mhs[i].Predikat == "Memuaskan") {
            countMemuaskan += 1;
        } else if (mhs[i].Predikat == "Cukup") {
            countCukup += 1;
        }
    }

    cout << "Jumlah yang predikat 'Cumlaude': " << countCumlaude << " Orang" << endl;
    cout << "Jumlah yang predikat 'Memuaskan': " << countMemuaskan << " Orang" << endl;
    cout << "Jumlah yang predikat 'Cukup': " << countCukup << " Orang" << endl;

    delete[] mhs; // Clean up dynamically allocated memory

    return 0;
}
