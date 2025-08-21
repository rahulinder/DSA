#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[100];

    cout << "Enter the elements of array: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
