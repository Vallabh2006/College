#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> myArr)
{
    cout << "Array = { ";

    for (int i = 0; i < myArr.size(); i++)
    {
        cout << myArr[i] << " ";
    }

    cout << "}" << endl;
}

void input(vector<int>& myArr)
{
    for (int i = 0; i < myArr.size(); i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> myArr[i];
    }
}

void insertion(vector<int>& myArr, int position, int value)
{
    myArr.insert(myArr.begin() + position, value);
}

void deletion(vector<int>& myArr, int position)
{
    myArr.erase(myArr.begin() + position);
}


int search(vector<int> myArr, int value)
{
    for (int i = 0; i < myArr.size(); i++)
    {
        if (myArr[i] == value)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    int size, position, value, result;

    cout << "Enter number of elements: ";
    cin >> size;

    vector<int> myArr(size);

    input(myArr);

    cout << "\nOriginal array:" << endl;
    display(myArr);

    cout << "\nEnter positionition for insertion: ";
    cin >> position;

    cout << "Enter value: ";
    cin >> value;

    insertion(myArr, position, value);

    cout << "After insertion:" << endl;
    display(myArr);


    cout << "\nEnter positionition for deletion: ";
    cin >> position;

    deletion(myArr, position);

    cout << "After deletion:" << endl;
    display(myArr);


    cout << "\nEnter value to search: ";
    cin >> value;

    result = search(myArr, value);

    if (result == -1) {
        cout << "Element not found.";
    } else {
        cout << "Element found at index " << result;
    }

    cout << endl;

    return 0;
}