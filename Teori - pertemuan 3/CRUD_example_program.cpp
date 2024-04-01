//
// Created by Defanda on 01/04/2024.
//

#include "CRUD_example_program.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// Struct untuk data peminjaman buku
struct Peminjaman {
    string nama;
    string nim;
    string tanggalPeminjaman;
    string kodeBuku;
};

// Fungsi untuk menambah data peminjaman
void tambahData(Peminjaman arr[], int& size) {
    if (size >= MAX_SIZE) {
        cout << "Array penuh, tidak dapat menambah data lagi." << endl;
        return;
    }

    Peminjaman baru;

    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, baru.nama);
    cout << "Masukkan NIM: ";
    getline(cin, baru.nim);
    cout << "Masukkan tanggal peminjaman (dd/mm/yyyy): ";
    getline(cin, baru.tanggalPeminjaman);
    cout << "Masukkan kode buku (nomor rak-kategori, contoh: 1234-R): ";
    getline(cin, baru.kodeBuku);

    arr[size++] = baru;

    cout << "Data berhasil ditambahkan." << endl;
}

// Fungsi untuk mengedit data peminjaman
void editData(Peminjaman arr[], int size) {
    int index;
    cout << "Masukkan indeks data yang ingin diubah: ";
    cin >> index;

    if (index < 0 || index >= size) {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    Peminjaman& data = arr[index];

    cout << "Nama: " << data.nama << endl;
    cout << "NIM: " << data.nim << endl;
    cout << "Tanggal Peminjaman: " << data.tanggalPeminjaman << endl;
    cout << "Kode Buku: " << data.kodeBuku << endl;

    cout << "\nMasukkan data baru:" << endl;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, data.nama);
    cout << "NIM: ";
    getline(cin, data.nim);
    cout << "Tanggal peminjaman (dd/mm/yyyy): ";
    getline(cin, data.tanggalPeminjaman);
    cout << "Kode buku (nomor rak-kategori, contoh: 1234-R): ";
    getline(cin, data.kodeBuku);

    cout << "Data berhasil diubah." << endl;
}

// Fungsi untuk menghapus data peminjaman
void hapusData(Peminjaman arr[], int& size) {
    int index;
    cout << "Masukkan indeks data yang ingin dihapus: ";
    cin >> index;

    if (index < 0 || index >= size) {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    size--;

    cout << "Data berhasil dihapus." << endl;
}

// Fungsi untuk menampilkan data peminjaman
void tampilData(Peminjaman arr[], int size) {
    cout << "\nData Peminjaman Buku:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Data ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << arr[i].nama << endl;
        cout << "NIM: " << arr[i].nim << endl;
        cout << "Tanggal Peminjaman: " << arr[i].tanggalPeminjaman << endl;
        cout << "Kode Buku: " << arr[i].kodeBuku << endl;
        cout << endl;
    }
}

int main() {
    Peminjaman dataPeminjaman[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Edit Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Tampilkan Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tambahData(dataPeminjaman, size);
                break;
            case 2:
                editData(dataPeminjaman, size);
                break;
            case 3:
                hapusData(dataPeminjaman, size);
                break;
            case 4:
                tampilData(dataPeminjaman, size);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}