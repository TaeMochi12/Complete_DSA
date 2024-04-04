// Upperbound : Smallest no. greater than the target element

#include<bits/stdc++.h>
using namespace std ;

int upperbound(int n,int arr[],int target)
{
    int s=0;
    int e=n-1;
    int ans=n;    // if target is greater the last element of array then the upperbound index will be out of the array
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]>target)
        {
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    return ans;
}

int main() {
    int arr[7]={4,8,12,46,66,66,84};
    int target;
    cout<<"Enter the target element:";
    cin>>target;
    int ans=upperbound(7,arr,target);
    if(ans!=-1) cout<<"Upperbound of "<<target<<" found at index:"<<ans<<endl;
    return 0 ;
}