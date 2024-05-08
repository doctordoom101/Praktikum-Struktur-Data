//
// Created by Defanda on 08/05/2024.
//
#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "masukkan bilangan: ";
    cin >> n;

    cout << "bilangan prima antara 1 sampai " << n << ":" << endl;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }

    return 0;
}