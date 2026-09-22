#include <iostream>
#include <string>
using namespace std;

int pre(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix, postfix = "";
    char stack[100];
    int top = -1;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (char ch : infix) {
        if (isalpha(ch))
            postfix += ch;

        else if (ch == '(')
            stack[++top] = ch;

        else if (ch == ')') {
            while (stack[top] != '(')
                postfix += stack[top--];
            top--;
        }

        else {
            while (top != -1 && stack[top] != '(' &&
                   pre(stack[top]) >= pre(ch))
                postfix += stack[top--];

            stack[++top] = ch;
        }
    }

    while (top != -1)
        postfix += stack[top--];

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}