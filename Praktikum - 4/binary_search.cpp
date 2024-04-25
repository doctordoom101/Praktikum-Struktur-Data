//
// Created by Defanda on 24/04/2024.
//
#include <iostream>

int data[10] = {1, 3, 4, 7, 12, 25, 40, 65, 78, 90};

int binary_search(int cari) {
    int a, b, c;
    int n = 10;
    a = 0;
    b = n - 1;
    int temu = 0;
    while (a <= b) {
        c = (a + b) / 2;
        if (data[c] == cari) {
            temu = 1;
            break;
        } else if (cari < data[c]) {
            b = c - 1;
        } else {
            a = c + 1;
        }
    }
    return temu; // Return 1 if found, 0 otherwise
}

int main() {
    int cari, hasil;
    std::cout << "Pencarian data dengan binary search \n\n";
    std::cout << "Masukan data yang ingin dicari = ";
    std::cin >> cari;
    hasil = binary_search(cari);
    if (hasil == 1) {
        std::cout << "Data ada!" << std::endl;
    } else {
        std::cout << "Data tidak ada!" << std::endl;
    }
    return 0;
}
