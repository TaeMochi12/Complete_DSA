// Sum of digits

// 1st pattern: f(n,something)
#include<iostream>
using namespace std ;

int SumOfDigits(int n,int sum)
{
    if(n/10==0)
    {
        sum+=n;
        return sum; 
    }
    else return SumOfDigits(n/10,sum+n%10);
}

// 2nd pattern: something+f(n)
int SumOfDigits2(int n)
{
    if(n==0)
    {
       return 0;
    }
    else return n%10+SumOfDigits2(n/10);
}


// Reverse a number
int Reversed(int n,int reversed_number=0)
{
    if(n==0) return reversed_number;
    else return Reversed(n/10,reversed_number*10+n%10);
}

int main() {
    int n;
    cin>>n;
    // int sum=SumOfDigits(n,0);
    int sum=SumOfDigits2(n);
    cout<<"Sum of Digits:"<<sum<<endl;
    cout<<"Reversed:"<<Reversed(n)<<endl;
    return 0 ;
}