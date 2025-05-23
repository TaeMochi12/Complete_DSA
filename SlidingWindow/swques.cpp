// ॐ नमः शिवाय
#include <bits/stdc++.h>
using namespace std;

/* जय भवानी । हर हर महादेव। */

/*
* Find maximum subarray sum of size k

-> arr[5] = {1 ,2, 3,4,5};
-> window sizw => k
*/

int maximumSubarraySum(int arr[], int size, int k)
{

    int sum = 0;
    int maxSum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (i >= k - 1)
        {
            maxSum = max(maxSum, sum);
            sum -= arr[i - (k - 1)];
        }
    }

    return maxSum;
}



int minimumSumWindowSize(int arr[] , int size , int targetSum){
        int j=0;
        int sum=0;
        int mini=INT_MAX;
        for(int i=0;i<size;i++)
        {
            sum+=arr[i];
            while(sum>=targetSum)
            {
                mini=min(mini,i-j+1);
                sum-=arr[j];
                j++; 
            }
        }
        if(mini==INT_MAX) return 0;
        else return mini;
}


int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    int k = 3;
    cout << maximumSubarraySum(arr, size, k)<<endl;
    cout<<"Minimum window size for target sum:"<<minimumSumWindowSize(arr,size,3);

    return 0;
}
