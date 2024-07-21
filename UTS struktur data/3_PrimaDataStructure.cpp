//
// Created by Defanda on 20/05/2024.
//
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 0;
    int num = 2;
    int sum = 0;

    cout << "STRUKTUR DATA PRIMA" << endl;

    while (count < 50) {
        if (isPrime(num)) {
            cout << num << ",";
            sum += num;
            count++;
        }
        num++;
    }

    cout << "\nTOTAL DERET PRIMA = " << sum << endl;
    cout << "RATA-RATA DERET PRIMA = " << static_cast<double>(sum) / 50 << endl;

    return 0;
}