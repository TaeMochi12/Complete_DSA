#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cout << "Enter the no. of elements:";
    cin >> n;
    int arr[10];
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search:";
    cin >> x;
    int start = 0;
    int end = n - 1;
    int mid;
    int flag = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            cout << "The element is found at index:" << mid << endl;
            flag = 1;
            break;
        }

        else if (arr[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (flag == 0)
        cout << "Element Not Found" << endl;

    return 0;
}