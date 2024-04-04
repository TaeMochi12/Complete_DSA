// floor : greatest number smaller or equal to the target element

#include<bits/stdc++.h>
using namespace std ;

int floor(int n,int arr[],int target)
{
    int s=0;
    int e=n-1;
    int ans=-1;   // if target is smaller than the last element of array then the floor index will be before the starting of the array
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
}

int main() {
    int arr[7]={4,8,12,46,66,66,84};
    int target;
    cout<<"Enter the target element:";
    cin>>target;
    int ans=floor(7,arr,target);
    if(ans!=-1) cout<<"Floor of "<<target<<" found at index:"<<ans<<endl;
    else cout<<"No floor"<<endl;
    return 0 ;
}