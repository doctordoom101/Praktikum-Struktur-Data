//
// Created by Defanda on 02/05/2024.
//
#include <iostream>
using namespace std;

int main(){
    int x, y; int *px;
    x = 89;
    y = x;
    px = &x;
    cout << "nilai x = " << x << endl;
    cout << "nilai y = " << y << endl;
    cout << "nilai px = " << px << endl;
    cout << "nilai px = " << *px << endl;
}