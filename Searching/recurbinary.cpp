#include<bits/stdc++.h>
using namespace std ;

void BinarySearch(vector<int>arr,int start,int end,int target)
{
    if(start<=end){
        int mid=start+((end-start))/2;
        if(arr[mid]==target) 
        {
            cout<<"Value found at index:"<<mid<<endl;
        }
        else if(target<arr[mid]) BinarySearch(arr,start,mid-1,target);
        else BinarySearch(arr,mid+1,end,target);
    }
    else cout<<"Element not found"<<endl;
    
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
    BinarySearch(arr,0,n-1,target);
    return 0 ;
}