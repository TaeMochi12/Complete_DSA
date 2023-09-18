#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l; // i is the first index of the left array,j is the first index of the right array,k is the first    index of the temp array
    int temp[20];                // temporary array to store the sorted array
    while (i <= m && j <= r)     // for comparing the elements of left and the right sub arrays
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i]; // if the element of left subarray is smaller or equal to right sub array then put it in the temp array
            i++;
            k++; // then increment temp's index to the next and increment the left array's index to the next for comparison of next element with the right subarray's element
        }
        else
        {
            temp[k] = arr[j]; // if the element of right subarray is smaller than the left sub array then put it in the temp array
            j++;
            k++; // then increment temp's index to the next and increment the right array's index to the next for comparison of next element with the left subarray's element
        }
    }
    while (i <= m) // if the right sub-array gets exhausted then put the remaining elements of the left sub-array as it is in the temp array as they'll be already sorted in the lower steps
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) // if the left sub-array gets exhausted then put the remaining elements of the right sub-array as it is in the temp array as they'll be already sorted in the lower steps
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p]; // assign the sorted elements from the temporary array to the orginal array
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;      // for calculating the current middle element
        mergeSort(arr, l, m);     // for dividing the left part of array till we get single element arrays
        mergeSort(arr, m + 1, r); // for dividing the right part of array till we get single element arrays
        merge(arr, l, m, r);      // after getting the left and right divided arrays we merge the two parts after sorting
    }
}

int main()
{
    int arr[10];
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}