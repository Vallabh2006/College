#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& a, int key) {
    int low = 0, high = (int)a.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRec(const vector<int>& a, int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) return binarySearchRec(a, mid + 1, high, key);
    return binarySearchRec(a, low, mid - 1, key);
}

int main() {
    int n, key;
    cout << "Number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());  // binary search needs a sorted array
    cout << "Sorted array: ";
    for (int x : a) cout << x << " ";
    cout << "\nEnter element to search: ";
    cin >> key;

    int pos = binarySearch(a, key);
    if (pos != -1) cout << "Iterative: found at index " << pos << " (position " << pos + 1 << ")\n";
    else cout << "Iterative: not found\n";

    pos = binarySearchRec(a, 0, n - 1, key);
    if (pos != -1) cout << "Recursive: found at index " << pos << " (position " << pos + 1 << ")\n";
    else cout << "Recursive: not found\n";
    return 0;
}
