#include <iostream>

using namespace std;

void push(int myArr[], int& top, int n) {

    if (top == n - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }

    int value;

    cout << "Enter value: ";
    cin >> value;

    top++;
    myArr[top] = value;
}

void pop(int myArr[], int& top) {

    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }

    cout << "Popped: " << myArr[top] << endl;

    top--;
}

void peek(int myArr[], int top) {

    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Top element: " << myArr[top] << endl;
}

void display(int myArr[], int top) {

    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack = { ";

    for (int i = top; i >= 0; i--) {
        cout << myArr[i] << " ";
    }

    cout << "}" << endl;
}

void input(int myArr[], int& top, int n) {

    int value;

    for (int i = 0; i < n; i++) {

        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        top++;
        myArr[top] = value;
    }
}

int main() {

    int top = -1, n;

    cout << "Enter size of Stack: ";
    cin >> n;

    int myArr[n];

    cout << "\nEnter stack elements:\n";
    input(myArr, top, n);


    char choice;

    while (true) {

        cout << endl << endl;
        cout << "(1) Push, (2) Pop, (3) Peek, (4) Display" << endl;
        cout << "(Q) Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;


        if (choice == '1') {
            push(myArr, top, n);
        }

        else if (choice == '2') {
            pop(myArr, top);
        }

        else if (choice == '3') {
            peek(myArr, top);
        }

        else if (choice == '4') {
            display(myArr, top);
        }

        else if (choice == 'q' || choice == 'Q') {
            break;
        }

        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}