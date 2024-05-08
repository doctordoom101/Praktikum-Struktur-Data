//
// Created by Defanda on 08/05/2024.
//
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int factorial(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main() {
    int bil;

    cout << "program faktorial dengan rekursif" << endl;
    cout << endl;
    cout << "masukkan bilangan bulat : ";
    cin >> bil;
    cout << factorial(bil);
}