#include<iostream>
using namespace std ;

class Queue
{
    private:
        int front;
        int rear;
        int arr[5];
    
    public:
        Queue()
        {
            front=-1;
            rear=-1;
            for(int i=0;i<5;i++)
            {
                arr[i]=0;
            }
        }

        bool isEmpty()
        {
            if(front==-1 && rear==-1) return true;
            else return false;
        }

        bool isFull()
        {
            if(rear==4) return true;
            else return false;
        }

        
};

int main() {
    Queue q1;
    int option;
    do
    {
        cout<<"What operations do you want to perform? Select Option number. Enter 0 to exit."<<endl;
        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. Clear Screen"<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:

        }
    } while (option!=0);
    
    return 0 ;
}
