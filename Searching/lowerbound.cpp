#include<bits/stdc++.h>
using namespace std ;

int lowerbound(int n,int arr[],int target)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]>=target)
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
    int ans=lowerbound(7,arr,target);
    if(ans!=-1) cout<<"Lowerbound of "<<target<<" found at index:"<<ans<<endl;
    else cout<<"No lowerbound"<<endl;
    return 0 ;
}