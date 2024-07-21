//
// Created by Defanda on 20/05/2024.
//
#include <iostream>

using namespace std;

void insertionSortAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        swap(arr[max_idx], arr[i]);
    }
}

int main() {
    int data[] = {25, 10, 7, 12, 12, 8, 20};
    int dataSize = sizeof(data) / sizeof(data[0]);

    cout << "Data Sebelum disort : ";
    for (int i = 0; i < dataSize; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    insertionSortAscending(data, dataSize);
    cout << "Data Setelah disort secara metode Insertion Sort Asending : ";
    for (int i = 0; i < dataSize; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    selectionSortDescending(data, dataSize);
    cout << "Data Setelah disort dengan metode Selection Sort Desending : ";
    for (int i = 0; i < dataSize; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}