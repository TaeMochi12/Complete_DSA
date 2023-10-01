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

void enqueuerear(int x)
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
    else if(r==4)  //if rear is at the last index so we have to insert on the first index
    {
        r=0;
        deque[r]=x;
    }
    else{       //if r is anywhere in the middle
        r++;
        deque[r]=x;
    }
}

void display()
{   if(f==-1 && r==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        int i=f;
    while(i!=r)
    {
        cout<<deque[i]<<" ";
        i=(i+1)%5;  //so that after 4, it again starts from 0
    }
    cout<<deque[r]; //to print the value at r as due to the condition i!=r the value at r willbe left to be printed
    cout<<endl;
    }
    
}

void getfront()
{
    if(f==-1 && r==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<deque[f]<<endl;
    }
}
void getrear()
{
    if(f==-1 && r==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<deque[r]<<endl;
    }
}

void dequeuefront()
{
  if(f==-1 && r==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(f==r)     //when there is only one element in the deque
    {
        f=-1;
        r=-1;
        cout<<"The dequeued value:"<<deque[f]<<endl;
    } 
    else if(f==4)   //when the front is at the last index
    {
        cout<<"The dequeued value:"<<deque[f]<<endl;
        f=0;
    } 
    else
    {
        cout<<"The dequeued value:"<<deque[f]<<endl;
        f++;
    }
}
void dequeuerear()
{
  if(f==-1 && r==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(f==r)     //when there is only one element in the deque
    {
        f=-1;
        r=-1;
        cout<<"The dequeued value:"<<deque[r]<<endl;
    } 
    else if(r==0)   //when the front is at the last index
    {
        cout<<"The dequeued value:"<<deque[r]<<endl;
        r=4;  //can't do r-- so now r will point to the last index
    } 
    else
    {
        cout<<"The dequeued value:"<<deque[r]<<endl;
        r--;
    }
}

int main() {
    enqueuefront(2);
    enqueuefront(5);
    enqueuerear(-1);
    enqueuerear(0);
    enqueuefront(7);
    enqueuefront(4);
    display();
    getfront();
    getrear();
    dequeuefront();
    dequeuerear();
    dequeuefront();
    display();

    return 0 ;
}