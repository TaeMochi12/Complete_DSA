#include <iostream>
using namespace std;
void linear_search(int a[], int n)
{
    int temp = 0;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == n)
        {
            cout << "Element found at location:" << i << endl;
            temp = 1;
        }
    }
    if (temp == 0)
    {
        cout << "No element found" << endl;
    }
}
int main()
{
    int arr[5] = {12, 67, 66, 90, 66};
    int elem;
    cout << "Please enter the element to search:";
    cin >> elem;
    linear_search(arr, elem);
    return 0;
}