#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    cout << "Enter the number of Elements in the Array: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> nums[i];
    }

    int* ptr = &nums[0];

    cout << "\nArray in reverse order: ";

    for (int i = n - 1; i >= 0; i--) {
        cout << *(ptr + i) << " ";
    }

    cout << endl;

    return 0;
}