#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

bool isEmpty(Node *top)
{
    if (top == nullptr)
        return true;
    else
        return false;
}

int size(Node* top)
{
    int s=0;
    Node* temp=top;
    while(temp!=nullptr)
    {
        s++;
        temp=temp->next;
    }
    return s;
}

Node *push(Node *top, int data)
{
    Node* node=new Node(data);
    if (top == nullptr)
        top = node;
    else
    {
        node->next = top;
        top = node;
    }
    return top;
}

void pop(Node *top)
{
    if (isEmpty(top))
        cout << "Stack Underflow" << endl;
    Node* temp=top;
    top=top->next;
    free(temp);
}

int peek(Node* top)
{
    if(isEmpty(top)) return -1;
    else return top->val;
}

void display(Node* top)
{
    Node* temp=top;
    while(temp!=nullptr)
    {
        cout<<temp->val<<endl;
        temp=temp->next;
    }
}

int main()
{
    Node* top=new Node(10);
    cout<<"Stack Empty:"<<isEmpty(top)<<endl;
    cout<<"Size:"<<size(top)<<endl;
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    cout<<"Size after 3 push:"<<size(top)<<endl;
    cout<<"Stack elements:"<<endl;
    display(top);
    cout<<"top:"<<peek(top)<<endl;
    pop(top);
    pop(top);
    cout<<"Size after 2 pop:"<<size(top)<<endl;
    cout<<"top:"<<peek(top)<<endl;
    pop(top);
    pop(top);
    cout<<"Stack Empty:"<<isEmpty(top)<<endl;
    return 0;
}
