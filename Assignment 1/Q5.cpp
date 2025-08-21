#include <iostream>
using namespace std;

int main()
{
    int rows = 3, cols = 4;
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int rowSum[rows] = {0};
    int colSum[cols] = {0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rowSum[i] += arr[i][j];
        }
    }

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            colSum[j] += arr[i][j];
        }
    }

    cout << "Row sums: ";
    for (int i = 0; i < rows; i++)
    {
        cout << rowSum[i] << " ";
    }
    cout << endl;

    cout << "Column sums: ";
    for (int j = 0; j < cols; j++)
    {
        cout << colSum[j] << " ";
    }
    cout << endl;

    return 0;
}
