//
// Created by Defanda on 08/05/2024.
//
#include <iostream>
using namespace std;

int fibo(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main(){
    int bil;

    cout << "program faktorial dengan rekursif" << endl;
    cout << endl;
    cout << "masukkan bilangan bulat : ";
    cin >> bil;
    for(int i = 0; i<=bil; i++){
        cout << fibo(i) << " ";
    }
}