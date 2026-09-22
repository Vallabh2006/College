#include <iostream>
using namespace std;

int q[5], f = -1, r = -1;

void enqueue() {

    if (r == 4) return cout << "Overflow\n", void();
    
    int x;

    cout << "Enter Value: ";
    cin >> x;

    if (f == -1) f = 0;
    q[++r] = x;

    cout << endl;
}

void dequeue() {
    if (f == -1) return cout << "Underflow\n", void();
    cout << q[f++] << endl;
    if (f > r) f = r = -1;
    cout << endl;
}

void display() {
    if (f == -1) return cout << "\nEmpty\n", void();
    for (int i = f; i <= r; i++) {
        cout << q[i] << ", ";
    }
    cout << endl << endl;
}

int main() {
    int c;
    do {
        cout << "1.Enqueue 2.Dequeue 3.Display 4.Exit: ";
        cin >> c;
        if (c == 1) enqueue();
        else if (c == 2) dequeue();
        else if (c == 3) display();
        else break;
    } while (c != 4);
}