//
// Created by Defanda on 05/06/2024.
//
#include <iostream>
using namespace std;

struct Node {
    int angka;
    Node *next;
} *baru, *kepala = NULL, *ekor = NULL, *tampil, *hapus, *tambah, *a, *b;

// fungsi untuk menginputkan data
void gerbong() {
    int nilai;
    cout << "\nMasukkan nilai: ";
    cin >> nilai;
    baru = new Node;
    baru->angka = nilai;
    baru->next = NULL;
}

// fungsi untuk menambah depan
void tambah_depan() {
    gerbong();
    if (kepala == NULL) {
        kepala = baru;
        ekor = baru;
    } else {
        baru->next = kepala;
        kepala = baru;
    }
}

// fungsi untuk menambah belakang
void tambah_belakang() {
    gerbong();
    if (kepala == NULL) {
        kepala = baru;
        ekor = baru;
    } else {
        ekor->next = baru;
        ekor = baru;
    }
}

// fungsi untuk menampilkan data
void muncul() {
    if (kepala == NULL) {
        cout << "Data kosong\n";
    } else {
        tampil = kepala;
        while (tampil != NULL) {
            cout << tampil->angka << " ";
            tampil = tampil->next;
        }
        cout << endl;
    }
}

// fungsi untuk menambah tengah
void tambah_tengah() {
    int masuk;
    gerbong();
    cout << "\nData yang ada: ";
    muncul();

    cout << "\nIngin dimasukkan setelah data: ";
    cin >> masuk;
    if (kepala == NULL) {
        kepala = baru;
        ekor = baru;
    } else {
        tambah = kepala;
        while (tambah != NULL && tambah->angka != masuk) {
            tambah = tambah->next;
        }
        if (tambah != NULL) {
            baru->next = tambah->next;
            tambah->next = baru;
            if (baru->next == NULL) {
                ekor = baru;
            }
        } else {
            cout << "Data tidak ditemukan.\n";
            delete baru; // Prevent memory leak
        }
    }
}

// fungsi untuk menghapus depan
void hapus_depan() {
    if (kepala == NULL) {
        cout << "\nData kosong\n";
    } else {
        cout << "\nApakah Anda yakin ingin menghapus data " << kepala->angka << "? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            hapus = kepala;
            kepala = kepala->next;
            delete hapus;
            if (kepala == NULL) {
                ekor = NULL;
            }
        }
    }
}

// fungsi untuk menghapus belakang
void hapus_belakang() {
    if (kepala == NULL) {
        cout << "\nData kosong\n";
    } else if (kepala == ekor) {
        cout << "\nApakah Anda yakin ingin menghapus data " << kepala->angka << "? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            delete kepala;
            kepala = ekor = NULL;
        }
    } else {
        hapus = kepala;
        while (hapus->next != ekor) {
            hapus = hapus->next;
        }
        cout << "\nApakah Anda yakin ingin menghapus data " << ekor->angka << "? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            delete ekor;
            ekor = hapus;
            ekor->next = NULL;
        }
    }
}

// fungsi untuk menghapus tengah
void hapus_tengah() {
    if (kepala == NULL) {
        cout << "\nData kosong\n";
    } else {
        int hps;
        cout << "\nData yang ada: ";
        muncul();
        cout << "\nIngin menghapus nilai berapa: ";
        cin >> hps;
        hapus = kepala;

        if (hapus->angka == hps) {
            hapus_depan();
        } else {
            while (hapus != NULL && hapus->angka != hps) {
                a = hapus;
                hapus = hapus->next;
            }
            if (hapus != NULL) {
                cout << "\nApakah Anda yakin ingin menghapus data " << hapus->angka << "? (y/n): ";
                char ch;
                cin >> ch;
                if (ch == 'y' || ch == 'Y') {
                    a->next = hapus->next;
                    if (hapus == ekor) {
                        ekor = a;
                    }
                    delete hapus;
                }
            } else {
                cout << "Data tidak ditemukan.\n";
            }
        }
    }
}

int main() {
    int pilih;
    do {
        cout << "\n1. tambah depan";
        cout << "\n2. tambah belakang";
        cout << "\n3. tambah tengah";
        cout << "\n4. hapus depan";
        cout << "\n5. hapus belakang";
        cout << "\n6. hapus tengah";
        cout << "\n7. tampil";
        cout << "\n8. keluar...";
        cout << "\nMasukkan pilihan: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambah_depan();
                break;
            case 2:
                tambah_belakang();
                break;
            case 3:
                tambah_tengah();
                break;
            case 4:
                hapus_depan();
                break;
            case 5:
                hapus_belakang();
                break;
            case 6:
                hapus_tengah();
                break;
            case 7:
                muncul();
                break;
            case 8:
                cout << "Keluar...\n";
                exit(0);
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (true);

    return 0;
}
