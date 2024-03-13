#include<bits/stdc++.h>
using namespace std ;

int BinarySearch(vector<int>arr,int start,int end,int target)
{
    if(start<=end){
        int mid=start+((end-start))/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) return BinarySearch(arr,mid+1,end,target);
        else return BinarySearch(arr,start,mid-1,target);
        
    }
    return -1;
    
}

int main() {
    int n;
    cout<<"Enter the number of elements of array:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the values of array:"<<endl;
    for(auto &it:arr)
    {
        cin>>it;
    }
    int target;
    cout<<"Enter the target element:"<<endl;
    cin>>target;
    int ans=BinarySearch(arr,0,n-1,target);
    if(ans==-1) cout<<"Element not found"<<endl;
    else cout<<"Element found at index:"<<ans<<endl;
    return 0 ;
}