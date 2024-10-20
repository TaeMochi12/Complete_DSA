#include <iostream>
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

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int length(Node* head)
{
    int len=0;
    Node* temp=head;
    while(temp!=nullptr)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

Node* reverse(Node* head)
{
    Node* current=head;
    Node* temp=head;
    Node* prev=nullptr;
    while(current!=nullptr)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    return prev;
}

Node* insert(Node* head, Node* node, int k)
{
    if(head==nullptr) head=node;
    else
    {
        if(k==0)
        {
            node->next=head;
            head=node;
        }
        else if(k==length(head)-1)
        {
            Node* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=node;
        }
        else{
            Node* temp=head;
            int p=0;
            while(p<k-1)
        }
    }
}

int main()
{

    return 0;
}