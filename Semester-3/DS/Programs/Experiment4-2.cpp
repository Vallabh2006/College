#include <iostream>
#include <string>
using namespace std;

int power(int a, int b) {
    int r = 1;
    while (b--) r *= a;
    return r;
}

int main() {
    string p;
    int s[100], top = -1;

    cout << "Enter Postfix Expression: ";
    getline(cin, p);

    for (int i = 0; i < p.length();) {
        if (p[i] == ' ') {
            i++;
            continue;
        }

        if (p[i] >= '0' && p[i] <= '9') {
            int n = 0;
            while (i < p.length() && p[i] >= '0' && p[i] <= '9')
                n = n * 10 + p[i++] - '0';
            s[++top] = n;
        } else {
            int b = s[top--], a = s[top--], r;
            switch (p[i++]) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/': r = a / b; break;
                case '^': r = power(a, b); break;
            }
            s[++top] = r;
        }
    }

    cout << "Result: " << s[top] << endl;
    return 0;
}