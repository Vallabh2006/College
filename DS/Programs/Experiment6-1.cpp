#include <iostream>
#include <sstream>
using namespace std;

struct myNode {
    int data;
    myNode *next;
};

myNode *head = NULL;

void insertBeg(int value) {
    myNode *p = new myNode{value, head};
    head = p;
}

void insertEnd(int value) {
    myNode *p = new myNode{value, NULL};

    if (!head) {
        head = p;
        return;
    }

    myNode *t = head;
    while ((*t).next)
        t = (*t).next;

    (*t).next = p;
}

void insertAfter(int key, int value) {
    myNode *t = head;

    while (t && (*t).data != key)
        t = (*t).next;

    if (!t) return;

    myNode *p = new myNode{value, (*t).next};
    (*t).next = p;
}

void display() {
    myNode *t = head;

    while (t) {
        cout << (*t).data << ", ";
        t = (*t).next;
    }

    cout << "Null";
}

int main() {
    int n, value, key, i = 0, arr[100];
    char choice;
    string input;

    cout << "Enter number of nodes: ";
    cin >> n;
    cin.ignore();

    cout << "Enter values (2 6 4 .. n): ";
    getline(cin, input);

    stringstream ss(input);
    while (i < n && ss >> arr[i])
        i++;

    i = 0;
    while (i < n) {
        insertEnd(arr[i]);
        i++;
    }

    while (true) {
        cout << "\n1) Insert Front, 2) Insert Rear, 3) Insert After, 4) Display, Q) Quit";
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 'q' || choice == 'Q')
            break;

        if (choice == '4') {
            display();
            cout << "\n";
            continue;
        }

        if (choice == '1' || choice == '2' || choice == '3') {
            cout << "Value: ";
            cin >> value;
        }

        if (choice == '1')
            insertBeg(value);
        else if (choice == '2')
            insertEnd(value);
        else if (choice == '3') {
            cout << "Insert after: ";
            cin >> key;
            insertAfter(key, value);
        }
    }

    return 0;
}