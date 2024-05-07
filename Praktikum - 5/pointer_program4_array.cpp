//
// Created by Defanda on 02/05/2024.
//

#include <iostream>
#define MAX 5
using namespace std;

int main(){
    char nama[] = "Mia Kastina";
    char *pNama = nama;

    cout << "Nama : " << nama << endl;
    cout << "pNama : " << pNama << endl;
    pNama += 4;
    cout <<"\nSetelah nama += 4" << endl;
    cout << "Nama : " << nama << endl;
    cout << "pNama : " << pNama << endl;
}