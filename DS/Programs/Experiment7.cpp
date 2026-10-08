#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class CircularList {
    Node* last;
public:
    CircularList() : last(nullptr) {}

    void insertBeginning(int val) {
        Node* n = new Node(val);
        if (!last) { last = n; n->next = n; }
        else { n->next = last->next; last->next = n; }
        cout << val << " inserted at beginning.\n";
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!last) { last = n; n->next = n; }
        else { n->next = last->next; last->next = n; last = n; }
        cout << val << " inserted at end.\n";
    }

    void insertAfter(int key, int val) {
        if (!last) { cout << "List is empty.\n"; return; }
        Node* cur = last->next;
        do {
            if (cur->data == key) {
                Node* n = new Node(val);
                n->next = cur->next;
                cur->next = n;
                if (cur == last) last = n;
                cout << val << " inserted after " << key << ".\n";
                return;
            }
            cur = cur->next;
        } while (cur != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void deleteFirst() {
        if (!last) { cout << "List is empty.\n"; return; }
        Node* first = last->next;
        cout << "Deleted first node: " << first->data << "\n";
        if (first == last) last = nullptr;
        else last->next = first->next;
        delete first;
    }

    void deleteLast() {
        if (!last) { cout << "List is empty.\n"; return; }
        cout << "Deleted last node: " << last->data << "\n";
        if (last->next == last) { delete last; last = nullptr; return; }
        Node* cur = last->next;
        while (cur->next != last) cur = cur->next;
        cur->next = last->next;
        delete last;
        last = cur;
    }

    void deleteAfter(int key) {
        if (!last) { cout << "List is empty.\n"; return; }
        Node* cur = last->next;
        do {
            if (cur->data == key) {
                Node* target = cur->next;
                if (target == cur) {
                    cout << "No other node after " << key << ".\n";
                    return;
                }
                cout << "Deleted node: " << target->data << "\n";
                cur->next = target->next;
                if (target == last) last = cur;
                delete target;
                return;
            }
            cur = cur->next;
        } while (cur != last->next);
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (!last) { cout << "List is empty.\n"; return; }
        Node* cur = last->next;
        cout << "List: ";
        do {
            cout << cur->data << " -> ";
            cur = cur->next;
        } while (cur != last->next);
        cout << "(back to " << last->next->data << ")\n";
    }
};

int main() {
    CircularList list;
    int choice, val, key;
    do {
        cout << "\n--- Circular Linked List Menu ---\n"
             << "1. Insert at beginning\n2. Insert at end\n3. Insert after a given node\n"
             << "4. Delete first node\n5. Delete last node\n6. Delete node after a given node\n"
             << "7. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; list.insertBeginning(val); break;
            case 2: cout << "Value: "; cin >> val; list.insertEnd(val); break;
            case 3: cout << "After which node? "; cin >> key;
                    cout << "Value: "; cin >> val; list.insertAfter(key, val); break;
            case 4: list.deleteFirst(); break;
            case 5: list.deleteLast(); break;
            case 6: cout << "Delete node after which node? "; cin >> key; list.deleteAfter(key); break;
            case 7: list.display(); break;
            case 0: cout << "Bye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
