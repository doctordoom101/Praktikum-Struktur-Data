#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void display_data(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int find_data(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void insert_data(vector<int>& arr, int data, size_t index) {
    arr.insert(arr.begin() + index, data);
}

void delete_data(vector<int>& arr, int target) {
    arr.erase(remove(arr.begin(), arr.end(), target), arr.end());
}

vector<int> quick_sort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;
    for (int x : arr) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            middle.push_back(x);
        else
            right.push_back(x);
    }
    vector<int> sorted_arr = quick_sort(left);
    sorted_arr.insert(sorted_arr.end(), middle.begin(), middle.end());
    vector<int> right_sorted = quick_sort(right);
    sorted_arr.insert(sorted_arr.end(), right_sorted.begin(), right_sorted.end());
    return sorted_arr;
}

vector<int> exchange_sort(vector<int> arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

int main() {
    vector<int> data = {45, 16, 10, 25, 11, 80, 62, 18, 20, 37};

    // a. Display data
    cout << "Output Point A." << endl;
    display_data(data);

    // b. Find data 18
    cout << "\nOutput Point B." << endl;
    int target = 18;
    int index = find_data(data, target);
    if (index != -1) {
        cout << "Data " << target << " found at index array ke " << index << " atau (Data[" << index << "]=" << target << ")" << endl;
    } else {
        cout << "\nData " << target << " not found." << endl;
    }

    // c. Insert data 100 at index 5
    cout << "\nOutput Point C." << endl;
    cout << "Sebelum di insert adalah ";
    display_data(data);
    insert_data(data, 100, 5);
    cout << "Setelah di insertkan data 100 adalah ";
    display_data(data);

    // d. Delete data 62
    cout << "\nOutput Point D." << endl;
    cout << "Data Sebelum dihapus data 62 adalah ";
    display_data(data);
    delete_data(data, 62);
    cout << "Data Setelah dihapus data 62 adalah ";
    display_data(data);

    // e. Sort data with Quick-Sort and Exchange-Sort
    cout << "\nOutput Point E." << endl;
    cout << "Data Sebelum diurutkan adalah ";
    display_data(data);

    vector<int> sorted_data_quick = quick_sort(data);
    cout << "Data Setelah diurutkan dengan metode Quick-Sort adalah ";
    display_data(sorted_data_quick);

    vector<int> sorted_data_exchange = exchange_sort(data);
    cout << "Data Setelah diurutkan dengan metode Exchange-Sort adalah ";
    display_data(sorted_data_exchange);

    // f. Compare sorting methods
    cout << "\nOutput Point F." << endl;
    cout << "Data Sebelum diurutkan adalah ";
    display_data(data);
    cout << "Data Setelah diurutkan dengan metode Quick-Sort adalah ";
    display_data(sorted_data_quick);
    cout << "Data Setelah diurutkan dengan metode Exchange-Sort adalah ";
    display_data(sorted_data_exchange);

    // Measure execution time for Quick-Sort
    auto start_quick = chrono::steady_clock::now();
    sorted_data_quick = quick_sort(data); // Reuse existing variable
    auto end_quick = chrono::steady_clock::now();
    cout << "Durasi yang dibutuh Quick-Sort: " << chrono::duration<double, milli>(end_quick - start_quick).count() << " ms" << endl;

    // Measure execution time for Exchange-Sort
    auto start_exchange = chrono::steady_clock::now();
    sorted_data_exchange = exchange_sort(data); // Reuse existing variable
    auto end_exchange = chrono::steady_clock::now();
    cout << "Durasi yang dibutuhkan Exchange-Sort: " << chrono::duration<double, milli>(end_exchange - start_exchange).count() << " ms" << endl;

    return 0;
}
