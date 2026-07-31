#include <iostream>
#include <string>

using namespace std;

int pre(char sym) {

    if (sym == '^')
        return 3;

    if (sym == '*' || sym == '/')
        return 2;

    if (sym == '+' || sym == '-')
        return 1;

    return 0;
}


int main() {

    string infix;
    string postfix = "";

    char myArr[100], current;
    int top = -1;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {

        current = infix[i];

        if (isalnum(current)) {
            postfix += current;
        } else if (current == '(') {
            top++;
            myArr[top] = current;
        } else if (current == ')') {
            while (top != -1 && myArr[top] != '(') {
                postfix += myArr[top];
                top--;
            }
            top--;
        } else {
            while (top != -1 && myArr[top] != '(' && pre(myArr[top]) >= pre(current)) {
                postfix += myArr[top];
                top--;
            }
            top++;
            myArr[top] = current;
        }
    }

    while (top != -1) {

        postfix += myArr[top];
        top--;
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}