#include <iostream>
using namespace std;

#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue() {
    int x;
    if ((rear + 1) % MAX == front) {
        cout << "Queue Overflow\n";
        return;
    }
    cout << "Enter value: ";
    cin >> x;

    if (front == -1) front = rear = 0;
    else rear = (rear + 1) % MAX;

    q[rear] = x;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Deleted: " << q[front] << endl;

    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        cout << "Queue is Empty\n";
        return;
    }

    int i = front;
    while (true) {
        cout << q[i] << ", ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int ch;
    do {
        cout << "\n1.Enqueue, 2.Dequeue, 3.Display, 4.Exit :";
        cin >> ch;

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);

    return 0;
}