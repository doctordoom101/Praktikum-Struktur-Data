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

        cout << "tambah data? [y/n]: ";
        cin >> tambahLagi;
    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    // Menampilkan tabel
    cout << "Nama|" << setw(5) << "NIM|" << setw(5) << "UTS|" << setw(5) << "UAS|" << setw(5) << "Tugas|" << setw(5) << "Nilai|" << setw(5) << "Grade|" << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

    for (const Mahasiswa &mahasiswa : dataMahasiswa) {
        cout << mahasiswa.nama << setw(5) << mahasiswa.nim << setw(5) << mahasiswa.uts << setw(5) << mahasiswa.uas << setw(5) << mahasiswa.tugas
             << setw(5) << mahasiswa.nilai << setw(5) << mahasiswa.grade << endl;
    }

    return 0;
}
