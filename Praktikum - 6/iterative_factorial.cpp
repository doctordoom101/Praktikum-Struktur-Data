//
// Created by Defanda on 08/05/2024.
//
#include <iostream>
using namespace std;
// Function to calculate the factorial of a number iteratively
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int bil;
    cout << "Enter a number: ";
    cin >> bil;

    cout << "Factorial sequence up to " << bil << ":" << endl;
    for (int i = 1; i <= bil; i++) {
        cout << "Factorial of " << i << ": " << factorial(i) << endl;
    }

    return 0;
}