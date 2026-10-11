#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& a, int key) {
    int low = 0, high = a.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());
    cout << "Sorted array: ";
    for (int x : a) cout << x << " ";

    cout << "\nEnter element to search: ";
    cin >> key;

    int pos = binarySearch(a, key);
    if (pos != -1)
        cout << "Found at index " << pos << " (position " << pos + 1 << ")\n";
    else
        cout << "Element not found\n";

    return 0;
}
