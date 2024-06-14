
// #include<iostream>
// using namespace std ;

// int f(int n,int sum)
// {
//     if(n==0) return sum;
//     return f(n-1,sum+n);

// }

// int main() {
//     int n;
//     cin>>n;
//     int sum=f(n,0);
//     cout<<sum<<endl;
//     return 0 ;
// }

// Factorial

// #include<iostream>
// using namespace std ;

// int fact(int n)
// {
//     if (n<=1) return 1;
//     return n*fact(n-1);
// }

// int main() {
//     int n;
//     cin>>n;
//     int ans=fact(n);
//     cout<<ans<<endl;
//     return 0 ;
// }

// Fibonacci

// #include<iostream>
// using namespace std ;

// int fibo(int n)
// {
//     if(n<=1) return n;
//     return fibo(n-1)+fibo(n-2);
// }

// int main() {
//     int n=fibo(8);
//     cout<<n<<endl;
//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<fibo(i)<<endl;
//     // }
    
//     return 0 ;
// }

// Array Reversal

// #include<bits/stdc++.h>
// using namespace std ;

// void rev(int i,int j,int *arr)
// {
//     if(i>=j) return;
//     swap(arr[i],arr[j]);
//     return rev(i+1,j-1,arr);
// }

// int main() {
//     int arr[]={2,4,6,8};
//     rev(0,3,arr);
//     for(int i=0;i<4;i++)
//     {
//         cout<<arr[i]<<endl;
//     }
//     return 0 ;
// }

#include<bits/stdc++.h>
using namespace std ;

void rev(int i,int j,int *arr)
{
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main() {
    int arr[]={2,4,6,8};
    // rev(0,3,arr);
    // for(int i=0;i<4;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    cout<<arr<<endl;
    cout<<arr+1<<endl;
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;

    return 0 ;
}