#include <iostream>
using namespace std;

int main(){
    int a, i;
    int b[5] = ;
    
    for(a=0; a<5; a++){
        cout << "masukkan data ke " << a << ": ";
        cin >> b[a];
    }
    
    // getc();
    cout << "\n\ntampilan data dalam variaebl array[5]\n";
    
    for(i=0; i<5; i++){
        cout <<"\ntampilan data ke :" << i+1 << "= ";
        cout << b[i];
    }
    
    return 0;
}