#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa {
    char nama[31];  // Nama up to 30 characters
    char nim[11];   // NIM up to 10 characters
    float nilai;    // Nilai Struktur Data as float
    char grade;     // Grade as char
};

int main() {
    vector<Mahasiswa> dataMahasiswa;  // Vector to store Mahasiswa data
    char tambahLagi;

    do {
        cout << "==============" << endl;
        Mahasiswa mahasiswa;

        cout << "Nama (max 30 characters): ";
        cin.ignore();
        cin.getline(mahasiswa.nama, 31);  // Read up to 30 characters

        cout << "NIM (max 10 characters): ";
        cin.getline(mahasiswa.nim, 11);  // Read up to 10 characters

        cout << "Nilai Struktur Data: ";
        cin >> mahasiswa.nilai;

        if (mahasiswa.nilai >= 80 && mahasiswa.nilai <= 100) {
            mahasiswa.grade = 'A';
        } else if (mahasiswa.nilai >= 70 && mahasiswa.nilai <= 79) {
            mahasiswa.grade = 'B';
        } else if (mahasiswa.nilai >= 60 && mahasiswa.nilai <= 69) {
            mahasiswa.grade = 'C';
        } else if (mahasiswa.nilai >= 50 && mahasiswa.nilai <= 59) {
            mahasiswa.grade = 'D';
        } else {
            mahasiswa.grade = 'E';
        }

        // Add the mahasiswa data to the vector
        dataMahasiswa.push_back(mahasiswa);

        cout << "Tambah data? [y/n]: ";
        cin >> tambahLagi;
    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    // Display the table
    cout << left << setw(30) << "Nama" << "|"
         << setw(10) << "NIM" << "|"
         << setw(20) << "Nilai Struktur Data" << "|"
         << setw(5) << "Grade" << "|" << endl;
    cout << setfill('-') << setw(68) << "-" << setfill(' ') << endl;

    float totalNilai = 0;
    for (const Mahasiswa &mahasiswa : dataMahasiswa) {
        cout << left << setw(30) << mahasiswa.nama << "|"
             << setw(10) << mahasiswa.nim << "|"
             << setw(20) << fixed << setprecision(2) << mahasiswa.nilai << "|"
             << setw(5) << mahasiswa.grade << "|" << endl;
        totalNilai += mahasiswa.nilai;
    }

    // Calculate the average
    float rataRata = totalNilai / dataMahasiswa.size();

    // Display the average
    cout << setfill('-') << setw(68) << "-" << setfill(' ') << endl;
    cout << "Rata-rata Nilai: " << fixed << setprecision(2) << rataRata << endl;

    return 0;
}
