#include<iostream>
using namespace std ;

class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode(int val)
    {
        this->val=val;
        next=nullptr;
    }
};

void display(ListNode* head)
{
    ListNode *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

ListNode* reverse(ListNode *head)
{
    ListNode* current=head,*temp=head,*prev=nullptr;
    while(current!=nullptr)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    return prev;
}

int main() {
    ListNode *head=new ListNode(10);
    head->next=new ListNode(20);
    head->next->next=new ListNode(30);
    head->next->next->next=new ListNode(40);
    display(head);
    ListNode* newhead=reverse(head);
    display(newhead);
    return 0 ;
}