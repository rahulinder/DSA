#include <iostream>
using namespace std;

int main()
{
    const int n = 3;
    int matrix[n][n] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << "Transposed Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
