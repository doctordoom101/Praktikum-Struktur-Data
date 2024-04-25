//
// Created by Defanda on 24/04/2024.
//
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    system("cls");
    int data[8]= {8,27,9,20,10,1997,1996,100};
    int cari;
    int flag = 0;
    cout<<"Masukkan data yang ingin dicari = ";
    cin>>cari;
    for(int i = 0 ; i < 8 ; i++){
        if(data[i] == cari) flag = 1;
    }
    if(flag == 1)  {
        cout<<"Data ada ! \n" ;
    }
    else{
        cout<<"Data tidak ada ! \n";
    }
}
