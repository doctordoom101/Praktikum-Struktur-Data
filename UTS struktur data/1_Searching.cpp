//
// Created by Defanda on 20/05/2024.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string data[] = {"Zainab", "Yunarso", "Jojon", "Tinatun", "Qinanti", "Mintarso", "Janah", "Jonathan", "Junaidi"};
    int dataSize = sizeof(data) / sizeof(data[0]);
    vector<int> foundIndices;

    cout << "Isi Data Array:" << endl;
    cout << "Index : ";
    for (int i = 0; i < dataSize; i++) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Data  : ";
    for (int i = 0; i < dataSize; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    string searchLetters = "na";
    cout << "Data yang dicari Huruf huruf ke 3 dan 4 adalah : " << searchLetters << endl;

    for (int i = 0; i < dataSize; i++) {
        if (data[i].substr(2, 2) == searchLetters) {
            foundIndices.push_back(i);
        }
    }

    cout << "Data ditemukan pada index ke: ";
    for (int i = 0; i < foundIndices.size(); i++) {
        cout << foundIndices[i] << " ";
    }
    cout << endl;

    return 0;
}