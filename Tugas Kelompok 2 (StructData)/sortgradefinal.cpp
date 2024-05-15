//
// Created by Defanda on 15/05/2024.
//
////
//// Created by Defanda on 08/12/2023.
////
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double uts;
    double uas;
    double tugas;
    double nilai;
    char grade;
};

// Fungsi untuk menukar dua objek Mahasiswa
void swap(Mahasiswa &a, Mahasiswa &b) {
    Mahasiswa temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk melakukan bubble sort berdasarkan NIM
void bubbleSort(vector<Mahasiswa> &dataMahasiswa) {
    int n = dataMahasiswa.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dataMahasiswa[j].nim > dataMahasiswa[j + 1].nim) {
                swap(dataMahasiswa[j], dataMahasiswa[j + 1]);
            }
        }
    }
}

// Fungsi untuk menam
// layTable(const vector<Mahasiswa> &dataMahasiswa) {
    cout << left << setw(20) << "Nama" << setw(15) << "NIM" << setw(10) << "UTS" << setw(10) << "UAS" << setw(10) << "Tugas" << setw(10) << "Nilai" << "Grade" << endl;
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;

    for (const Mahasiswa &mahasiswa : dataMahasiswa) {
        cout << left << setw(20) << mahasiswa.nama << setw(15) << mahasiswa.nim << setw(10) << mahasiswa.uts << setw(10) << mahasiswa.uas
             << setw(10) << mahasiswa.tugas << setw(10) << fixed << setprecision(2) << mahasiswa.nilai << mahasiswa.grade << endl;
    }
}

int main() {
    vector<Mahasiswa> dataMahasiswa;  // Gunakan vektor untuk menyimpan data

    char tambahLagi;

    do {
        cout << "==============" << endl;
        Mahasiswa mahasiswa;

        cout << "Nama : ";
        cin.ignore();
        getline(cin, mahasiswa.nama);

        cout << "NIM : ";
        cin >> mahasiswa.nim;

        cout << "Nilai UTS : ";
        cin >> mahasiswa.uts;

        cout << "Nilai UAS : ";
        cin >> mahasiswa.uas;

        cout << "Nilai Tugas : ";
        cin >> mahasiswa.tugas;

        // Menghitung nilai dan grade
        mahasiswa.nilai = (30.0 / 100) * mahasiswa.uts + (50.0 / 100) * mahasiswa.uas + (20.0 / 100) * mahasiswa.tugas;

        if (mahasiswa.nilai >= 80 && mahasiswa.nilai <= 100) {
            mahasiswa.grade = 'A';
        } else if (mahasiswa.nilai >= 68 && mahasiswa.nilai <= 79) {
            mahasiswa.grade = 'B';
        } else if (mahasiswa.nilai >= 56 && mahasiswa.nilai <= 67) {
            mahasiswa.grade = 'C';
        } else if (mahasiswa.nilai >= 46 && mahasiswa.nilai <= 55) {
            mahasiswa.grade = 'D';
        } else {
            mahasiswa.grade = 'E';
        }

        // Menambahkan data ke vektor
        dataMahasiswa.push_back(mahasiswa);

        cout << "Tambah data? [y/n]: ";
        cin >> tambahLagi;
    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    // Menampilkan tabel sebelum diurutkan
    cout << "Data Mahasiswa Sebelum Diurutkan:" << endl;
    displayTable(dataMahasiswa);

    // Mengurutkan data berdasarkan NIM
    bubbleSort(dataMahasiswa);

    // Menampilkan tabel setelah diurutkan
    cout << "\nData Mahasiswa Setelah Diurutkan Berdasarkan NIM:" << endl;
    displayTable(dataMahasiswa);

    return 0;
}
