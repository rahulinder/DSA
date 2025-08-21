#include <iostream>
using namespace std;
int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;
        for (int k = 0; k < j; k++)
        {
            if (arr[i] == arr[k])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            arr[j] = arr[i];
            j++;
        }
    }
    return j;
}
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "New size: " << newSize << endl;
    return 0;
}
