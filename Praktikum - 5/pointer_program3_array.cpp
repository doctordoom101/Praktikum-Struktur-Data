//
// Created by Defanda on 02/05/2024.
//
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int a[MAX];
    int *pa = a;

    for (int i = 0; i < MAX; i++) {
        cout << "Masukkan Nilai " << i + 1 << " : ";
        cin >> a[i];
    }
    cout << endl;

    for (int i = 0; i < MAX; i++) {
        cout << "nilai a[" << i << "] = " << *pa << endl;
        pa++;
    }
    return 0;
}
