//
// Created by Defanda on 19/06/2024.
//
#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    void push(int value) {
        stack.push_back(value);
        cout << "Elemen " << value << " telah ditambahkan ke stack." << endl;
    }

    void pop() {
        if (stack.empty()) {
            cout << "Stack kosong, tidak ada elemen untuk di-pop." << endl;
        } else {
            int value = stack.back();
            stack.pop_back();
            cout << "Elemen " << value << " telah di-pop dari stack." << endl;
        }
    }

    void display() {
        if (stack.empty()) {
            cout << "Stack kosong." << endl;
        } else {
            cout << "Isi stack: ";
            for (int i = stack.size() - 1; i >= 0; --i) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }

    void clear() {
        stack.clear();
        cout << "Stack telah dibersihkan." << endl;
    }
};

void menu() {
    cout << "Menu Program Stack:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Clear" << endl;
    cout << "5. Exit" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Stack stack;
    int choice, value;

    do {
        menu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Masukkan nilai yang akan di-push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                stack.clear();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}
