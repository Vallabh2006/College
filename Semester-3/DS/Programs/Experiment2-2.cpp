#include <iostream>

using namespace std;

void callByValue(int x) {
    x = x + 10;
    cout << "Inside Call by Value: " << x << endl;
}

void callByReference(int& x) {
    x = x + 10;
    cout << "Inside Call by Reference: " << x << endl;
}

int main() {

    int a = 10;
    int b = 10;

    cout << "Before Call by Value: " << a << endl;
    
    callByValue(a);
    cout << "After Call by Value: " << a << endl << endl;
    cout << "Before Call by Reference: " << b << endl;

    callByReference(b);
    cout << "After Call by Reference: " << b << endl;

    return 0;
}