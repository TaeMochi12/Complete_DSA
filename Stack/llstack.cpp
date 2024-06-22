#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
       top=NULL;
    }

    int getSize()
    {
        int count = 0;

        Node *trev = top;

        while (trev != NULL)

        {

            trev = trev->next;

            count = count + 1;
        }

        return count;
    }

    bool isEmpty()
    {
        // Write your code here
        return top==nullptr;
    }

    void push(int data)
    {
        // Write your code here
        Node *temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if(top==NULL) return -1;
        int val=top->data;
        Node* temp=top;
        top = top->next;
        delete temp;
        return val;
    }

    int getTop()
    {
        // Write your code here
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Size:"<<s.getSize()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getTop()<<endl;
    cout<<"Empty:"<<s.isEmpty()<<endl;
    return 0;
}