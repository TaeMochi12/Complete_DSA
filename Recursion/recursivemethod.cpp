#include<iostream>
using namespace std ;

int sum(int num)
{
    if(num!=0)
    {
        return (num+sum(num-1));    //sum() function calls itself
    }
    else
    {
        return num;
    }
}

int main() {
    int n;
    cout<<"Enter number till which you want the sum of natural numbers to be calculated:";
    cin>>n;
    int total=sum(n);
    cout<<endl<<"Sum of natural numbers from 1 to "<<n<<" is "<<total<<endl;
    return 0 ;
}