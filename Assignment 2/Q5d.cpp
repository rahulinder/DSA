#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[size];

    cout << "Enter " << size << " elements for upper triangle (row-wise): ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\nUpper Triangular Matrix:\n";
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << " " << arr[index] << " ";
                index++;
            }
            else
            {
                cout << " 0 ";
            }
        }
        cout << endl;
    }

    return 0;
}