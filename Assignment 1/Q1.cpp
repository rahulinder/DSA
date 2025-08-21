#include <iostream>
using namespace std;

void menu_dispay()
{
    cout << "1. Create\n";
    cout << "2. Display\n";
    cout << "3. Insert\n";
    cout << "4. Delete\n";
    cout << "5. Linear Search\n";
    cout << "6. Exit\n";
}

int main()
{
    int *arr = nullptr;
    int size;
    int choice;

    while (true)
    {
        menu_dispay();

        cout << "Enter the choice(1-6)\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
        { // creation of array
            cout << "Enter the size of array: ";
            cin >> size;
            arr = new int[size];
            cout << "Enter the elements of array: \n";
            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }
            break;
        }
        case 2:
        { // DISPLAY
            if (size == 0)
            {
                cout << "Array is empty!\n";
            }
            else
            {
                cout << "Array elements: ";
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 3:
        { // insertion
            if (size == 0)
            {
                cout << "Create an array first ";
            }
            else
            {
                int pos, val;
                cout << "Enter the position of element: \n";
                cin >> pos;
                cout << "Enter the element: \n";
                cin >> val;
                if (pos < 1 || pos > size + 1)
                {
                    cout << "Invalid position";
                }
                else
                {
                    for (int i = size; i > pos; i--)
                    {
                        arr[i] = arr[i - 1];
                    }

                    arr[pos] = val;
                }
            }
        }
        case 4:
        { // deletion of element
            if (size == 0)
            {
                cout << "Array is empty";
            }
            else
            {
                int pos;
                cout << "Enter the position of element to delete";
                cin >> pos;
                if (pos < 1 || pos > size)
                {
                    cout << "Invalid position";
                }
                else
                {
                    for (int i = pos; i < size; i++)
                    {
                        arr[i] = arr[i + 1];
                    }
                }
            }
        }
        }
    }
}
