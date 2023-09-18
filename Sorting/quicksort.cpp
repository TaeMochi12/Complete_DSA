#include <iostream>
using namespace std;
int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;         
    for (int i = s; i <= e - 1; i++)
    {

        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);      //the smaller elements will pe placed in the starting
            pIndex++;
        }
    }
    swap(arr[e], arr[pIndex]);      //the pivot element will move to a position before which all the elements will be smaller than pivot
    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = Partition(arr, s, e);       //for partitioning and sorting
        QuickSort(arr, s, p - 1);           //calling QS for left partition
        QuickSort(arr, p + 1, e);           //calling QS for the right partition
    }
}

int main()
{
    int n;
    int arr[10];
    cout << "Enter the size of the array:";
    cin >> n;
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}