#include <iostream>
#include <string>
using namespace std;

int pre(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void push(char stack[], int &top, char value) {
    stack[++top] = value;
}

char pop(char stack[], int &top) {
    return stack[top--];
}

char peek(char stack[], int top) {
    return stack[top];
}

int main() {

    string infix, postfix = "";
    char stack[100];
    int top = -1;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (char ch : infix) {

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            postfix += ch;

        else if (ch == '(')
            push(stack, top, ch);

        else if (ch == ')') {
            while (peek(stack, top) != '(')
                postfix += pop(stack, top);

            pop(stack, top);
        }

        else {
            while (top != -1 && peek(stack, top) != '(' && pre(peek(stack, top)) >= pre(ch)) {
                postfix += pop(stack, top);
            }

            push(stack, top, ch);
        }
    }

    while (top != -1) {
        postfix += pop(stack, top);
    }
    
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}