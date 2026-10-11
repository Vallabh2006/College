#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);

    cout << "Bubble sort    : ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void selectionSort(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx]) minIdx = j;
        swap(a[i], a[minIdx]);
    }

    cout << "Selection sort : ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int& x : a) cin >> x;

    cout << "\nOriginal array : ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    bubbleSort(a);
    selectionSort(a);
    return 0;
}