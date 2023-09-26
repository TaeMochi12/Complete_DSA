#include<iostream>
using namespace std ;

class CircularQueue
{
    private:
        int front;
        int rear;
        int arr[5];
        int itemCount;
    
    public:
        CircularQueue()
        {
            itemCount=0;
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
            if((rear+1)%5==front) return true;
            else return false;
        }

        void enqueue(int val)
        {
            if(isFull())
            {
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(isEmpty())
            {
                rear=0;
                front=0;
                arr[rear]=val;
            }
            else
            {
                rear=(rear+1)%5;
                arr[rear]=val;
            }
            //instead of writing arr[rear]=val 2 times.. we can also write it here collectively for both else if and else
            
                itemCount++;
        }

        int dequeue()
        {
            int x;
            if(isEmpty())
            {
                cout<<"The queue is empty"<<endl;
                return 0;
            }
            else if(front==rear)
            {
                x=arr[front];
                arr[front]=0;
                rear=-1;
                front=-1;
                itemCount--;
                return x;
            }
            else
            {
                x=arr[front];
                arr[front]=0;
                front=(front+1)%5;
                itemCount--;
                return x;
            }
        }

        int count()
        {
            return (itemCount);
        }

        void display()
        {
            cout<<"All values in the Queue are-"<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

int main() {
    CircularQueue q1;
    int option,value;
    do
    {
        cout<<"What operations do you want to perform? Select Option number. Enter 0 to exit."<<endl;
        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enqueue operation\nEnter an iten to Enqueue in the queue"<<endl;
                cin>>value;
                q1.enqueue(value);
                break;
            case 2:
                cout<<"Dequeue operation\nDequeued value:"<<q1.dequeue()<<endl;
                break;
            case 3:
                if(q1.isEmpty())
                {
                    cout<<"Queue is empty"<<endl;
                }
                else
                {
                    cout<<"Queue is not empty"<<endl;
                }
                break;
            case 4:
                if(q1.isFull())
                {
                    cout<<"Queue is full"<<endl;
                }
                else
                {
                    cout<<"Queue is not full"<<endl;
                }
                break;
            case 5:
                cout<<"Count operation\nCount of items in Queue:"<<q1.count()<<endl;
                break;
            case 6:
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<<"Enter an appropriate option number"<<endl;
        }
    } while (option!=0);
    
    return 0 ;
}
