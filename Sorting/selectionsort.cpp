
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[6], n = 6, temp;
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array elements are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {

            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    cout << "Sorted Array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}