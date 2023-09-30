#include<iostream>
using namespace std ;

int  deque[5];
int f=-1,r=-1; //f:front,r:rear

void enqueuefront(int x)
{
    if((f==0&&r==4) || (f=r+1))
    {
        cout<<"Queue is full"<<endl;
    }
    else if(f==-1 && r==-1) //when there is no element in queue
    {
        f=0;
        r=0;
        deque[f]=x;
    }
    else if(f==0)  //when f is already on the first index
    {
        f=4;
        deque[f]=x;
    }
    else{
        f--;  //ex: if its on 2nd index then enqueue at 1st index
        deque[f]=x;
    }
}

int main() {
    
    return 0 ;
}