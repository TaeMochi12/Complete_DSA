#include <iostream>
using namespace std;
int main()
{
    int arr[6], n = 6, i, j;
    int key;
    cout << "Enter array elements:" << endl;
    for (int k = 0; k < n; k++)
    {
        cin >> arr[k];
    }
    cout << "Unsorted Array:" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << endl;
    }
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Sorted Array:" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << endl;
    }
    return 0;
}