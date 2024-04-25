//
// Created by Defanda on 24/04/2024.
//
#include <iostream>
#include <algorithm> // untuk mengurutkan array
#include <vector>
using namespace std;

int main() {
    int n, x;

    cout << "Pencarian data dengan binary search \n\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah data tidak valid! Program berhenti." << endl;
        return 1;
    }

    int a[n]; // Membuat array dengan panjang yang ditentukan oleh pengguna

    cout << "Masukkan " << n << " angka secara berurutan (harus dalam urutan non-decreasing):\n" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan angka ke-" << i + 1 << " : ";
        cin >> a[i];
    }

    // Mengurutkan array sebelum melakukan binary search
    sort(a, a + n);

    cout << "\nData yang akan dicari : ";
    cin >> x;

    // Implementasi binary search
    int low = 0, high = n - 1;
    vector<int> indices;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            // Mencari semua kemunculan ke kiri dari yang pertama ditemukan
            int left = mid;
            while (left >= 0 && a[left] == x) {
                indices.push_back(left);
                left--;
            }

            // Mencari semua kemunculan ke kanan dari yang pertama ditemukan
            int right = mid + 1;
            while (right < n && a[right] == x) {
                indices.push_back(right);
                right++;
            }

            break; // Tidak perlu mencari lebih lanjut
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!indices.empty()) {
        for (int idx : indices) {
            cout << "Data ditemukan pada posisi: " << idx + 1 << endl;
        }
        cout << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}
